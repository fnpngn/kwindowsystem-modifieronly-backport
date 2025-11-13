/*
    SPDX-FileCopyrightText: 2001 Ellis Whitehead <ellis@kde.org>

    Win32 port:
    SPDX-FileCopyrightText: 2004 Jarosław Staniek <staniek@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "kkeyserver_x11.h"

#include "platforms/xcb/kwindowsystem_xcb_debug.h"

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <private/qtx11extras_p.h>
#else
#include <QX11Info>
#endif

#define XK_MISCELLANY
#define XK_XKB_KEYS
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysymdef.h>
#include <xcb/xcb_keysyms.h>
#define X11_ONLY(arg) arg, // allows to omit an argument

// #define KKEYSERVER_DEBUG 1

namespace KKeyServer
{
#if KWINDOWSYSTEM_BUILD_DEPRECATED_SINCE(5, 38)
bool symXToKeyQt(uint keySym, int *keyQt)
{
    return symXModXToKeyQt(keySym, 0, keyQt) & ~Qt::KeyboardModifierMask;
}
#endif
} // end of namespace KKeyServer block
