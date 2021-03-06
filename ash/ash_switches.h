// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ASH_ASH_SWITCHES_H_
#define ASH_ASH_SWITCHES_H_

#include "ash/ash_export.h"

#include "build/build_config.h"

namespace ash {
namespace switches {

// Note: If you add a switch, consider if it needs to be copied to a subsequent
// command line if the process executes a new copy of itself.  (For example,
// see chromeos::LoginUtil::GetOffTheRecordCommandLine().)

// Please keep alphabetized.
ASH_EXPORT extern const char kAshAnimateFromBootSplashScreen[];
ASH_EXPORT extern const char kAshConstrainPointerToRoot[];
ASH_EXPORT extern const char kAshCopyHostBackgroundAtBoot[];
ASH_EXPORT extern const char kAshDebugShortcuts[];
ASH_EXPORT extern const char kAshDebugShowPreferredNetworks[];
ASH_EXPORT extern const char kAshDefaultWallpaperIsOem[];
ASH_EXPORT extern const char kAshDefaultWallpaperLarge[];
ASH_EXPORT extern const char kAshDefaultWallpaperSmall[];
ASH_EXPORT extern const char kAshDisableAlternateFrameCaptionButtonStyle[];
ASH_EXPORT extern const char kAshDisableAlternateShelfLayout[];
#if defined(OS_CHROMEOS)
ASH_EXPORT extern const char kAshDisableAudioDeviceMenu[];
#endif
ASH_EXPORT extern const char kAshDisableAutoMaximizing[];
ASH_EXPORT extern const char kAshDisableDockedWindows[];
ASH_EXPORT extern const char kAshDisableDragAndDropAppListToLauncher[];
ASH_EXPORT extern const char kAshDisableDragOffShelf[];
ASH_EXPORT extern const char kAshDisableOverviewMode[];
#if defined(OS_CHROMEOS)
ASH_EXPORT extern const char kAshDisableUsbChargerNotification[];
ASH_EXPORT extern const char kAshEnableAudioDeviceMenu[];
#endif
ASH_EXPORT extern const char kAshEnableAdvancedGestures[];
ASH_EXPORT extern const char kAshEnableAlternateFrameCaptionButtonStyle[];
ASH_EXPORT extern const char kAshEnableBrightnessControl[];
ASH_EXPORT extern const char kAshEnableImmersiveFullscreenForAllWindows[];
ASH_EXPORT extern const char kAshEnableImmersiveFullscreenForBrowserOnly[];
#if defined(OS_LINUX)
ASH_EXPORT extern const char kAshEnableMemoryMonitor[];
#endif
#if defined(OS_CHROMEOS)
ASH_EXPORT extern const char kAshEnableMagnifierKeyScroller[];
ASH_EXPORT extern const char kAshEnableMultiUserTray[];
#endif
ASH_EXPORT extern const char kAshEnableSoftwareMirroring[];
ASH_EXPORT extern const char kAshEnableSystemSounds[];
ASH_EXPORT extern const char kAshEnableTrayDragging[];
ASH_EXPORT extern const char kAshForceMirrorMode[];
ASH_EXPORT extern const char kAshGuestWallpaperLarge[];
ASH_EXPORT extern const char kAshGuestWallpaperSmall[];
ASH_EXPORT extern const char kAshHideNotificationsForFactory[];
ASH_EXPORT extern const char kAshHostWindowBounds[];
ASH_EXPORT extern const char kAshOverviewDelayOnAltTab[];
ASH_EXPORT extern const char kAshSecondaryDisplayLayout[];
ASH_EXPORT extern const char kAshMultipleSnapWindowWidths[];
ASH_EXPORT extern const char kAshTouchHud[];
ASH_EXPORT extern const char kAshUseAlternateShelfLayout[];
ASH_EXPORT extern const char kAshUseFirstDisplayAsInternal[];
ASH_EXPORT extern const char kAuraLegacyPowerButton[];
#if defined(OS_WIN)
ASH_EXPORT extern const char kForceAshToDesktop[];
#endif

// Returns true if the alternate visual style for the caption buttons (minimize,
// maximize, restore, close) should be used.
ASH_EXPORT bool UseAlternateFrameCaptionButtonStyle();

// Returns true if the alternate shelf layout should be used.
ASH_EXPORT bool UseAlternateShelfLayout();

// Returns true if items can be dragged off the shelf to unpin.
ASH_EXPORT bool UseDragOffShelf();

// Returns true if all windows (barring frameless apps) can be put into
// immersive fullscreen via <F4>.
ASH_EXPORT bool UseImmersiveFullscreenForAllWindows();

// Returns true if multiple user icons are allowed in the tray.
ASH_EXPORT bool UseMultiUserTray();

// Returns true if overview mode should be activated for window switching.
ASH_EXPORT bool UseOverviewMode();

// Returns true if docked windows feature is enabled.
ASH_EXPORT bool UseDockedWindows();

// Returns true if we should show the audio device switching UI.
ASH_EXPORT bool ShowAudioDeviceMenu();

#if defined(OS_CHROMEOS)
// Returns true if a notification should appear when a low-power USB charger
// is connected.
ASH_EXPORT bool UseUsbChargerNotification();
#endif

}  // namespace switches
}  // namespace ash

#endif  // ASH_ASH_SWITCHES_H_
