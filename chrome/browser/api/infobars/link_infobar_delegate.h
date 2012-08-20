// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_API_INFOBARS_LINK_INFOBAR_DELEGATE_H_
#define CHROME_BROWSER_API_INFOBARS_LINK_INFOBAR_DELEGATE_H_

#include "base/basictypes.h"
#include "base/compiler_specific.h"
#include "base/string16.h"
#include "chrome/browser/api/infobars/infobar_delegate.h"

class InfoBarTabHelper;

// An interface derived from InfoBarDelegate implemented by objects wishing to
// control a LinkInfoBar.
class LinkInfoBarDelegate : public InfoBarDelegate {
 public:
  // Returns the message string to be displayed in the InfoBar. |link_offset|
  // is the position where the link should be inserted.
  virtual string16 GetMessageTextWithOffset(size_t* link_offset) const = 0;

  // Returns the text of the link to be displayed.
  virtual string16 GetLinkText() const = 0;

  // Called when the Link is clicked. The |disposition| specifies how the
  // resulting document should be loaded (based on the event flags present when
  // the link was clicked). If this function returns true, the infobar is then
  // immediately closed. Subclasses MUST NOT return true if in handling this
  // call something triggers the infobar to begin closing.
  virtual bool LinkClicked(WindowOpenDisposition disposition);

 protected:
  explicit LinkInfoBarDelegate(InfoBarTabService* infobar_service);
  virtual ~LinkInfoBarDelegate();

 private:
  // InfoBarDelegate:
  virtual InfoBar* CreateInfoBar(InfoBarTabService* infobar_service) OVERRIDE;
  virtual LinkInfoBarDelegate* AsLinkInfoBarDelegate() OVERRIDE;

  DISALLOW_COPY_AND_ASSIGN(LinkInfoBarDelegate);
};

#endif  // CHROME_BROWSER_API_INFOBARS_LINK_INFOBAR_DELEGATE_H_

