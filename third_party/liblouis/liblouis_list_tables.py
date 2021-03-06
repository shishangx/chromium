#!/usr/bin/env python
# Copyright 2013 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import os
import re
import sys

import json
import optparse

# Matches the include statement in the braille table files.
INCLUDE_RE = re.compile(r"^\s*include\s+([^#\s]+)")


def Error(msg):
  print >> sys.stderr, 'liblouis_list_tables: %s' % msg
  sys.exit(1)


def ToNativePath(pathname):
  return os.path.sep.join(pathname.split('/'))


def LoadTablesFile(filename):
  with open(ToNativePath(filename), 'r') as fh:
    return json.load(fh)


def FindFile(filename, directories):
  for d in directories:
    fullname = '/'.join([d, filename])
    if os.path.isfile(ToNativePath(fullname)):
      return fullname
  Error('File not found: %s' % filename)


def GetIncludeFiles(filename):
  result = []
  with open(ToNativePath(filename), 'r') as fh:
    for line in fh.xreadlines():
      match = INCLUDE_RE.match(line)
      if match:
        result.append(match.group(1))
  return result


def ProcessFile(output_set, filename, directories):
  fullname = FindFile(filename, directories)
  if fullname in output_set:
    return
  output_set.add(fullname)
  for include_file in GetIncludeFiles(fullname):
    ProcessFile(output_set, include_file, directories)


def DoMain(argv):
  "Entry point for gyp's pymod_do_main command."
  parser = optparse.OptionParser()
  # Give a clearer error message when this is used as a module.
  parser.prog = 'liblouis_list_tables'
  parser.set_usage('usage: %prog [options] listfile')
  parser.add_option('-D', '--directory', dest='directories',
                    action='append', help='Where to search for table files')
  (options, args) = parser.parse_args(argv)

  if len(args) != 1:
    parser.error('Expecting exactly one argument')
  if not options.directories:
    parser.error('At least one --directory option must be specified')

  tables = LoadTablesFile(args[0])
  output_set = set()
  for table in tables:
    ProcessFile(output_set, table['fileName'], options.directories)
  return '\n'.join(output_set)


def main(argv):
  print DoMain(argv[1:])


if __name__ == '__main__':
  try:
    sys.exit(main(sys.argv))
  except KeyboardInterrupt:
    Error('interrupted')
