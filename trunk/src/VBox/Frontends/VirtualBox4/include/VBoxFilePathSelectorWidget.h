/** @file
 *
 * VBox frontends: Qt GUI ("VirtualBox"):
 * VirtualBox Qt extensions: VBoxFilePathSelectorWidget class declaration
 */

/*
 * Copyright (C) 2008 Sun Microsystems, Inc.
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 *
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa
 * Clara, CA 95054 USA or visit http://www.sun.com if you need
 * additional information or have any questions.
 */

#ifndef __VBoxFilePathSelectorWidget_h__
#define __VBoxFilePathSelectorWidget_h__

#include "QIWithRetranslateUI.h"

/* Qt includes */
#include <QComboBox>

class QFileIconProvider;
class QAction;

class VBoxFilePathSelectorWidget: public QIWithRetranslateUI<QComboBox>
{
    Q_OBJECT;

public:

    enum SelectorMode
    {
        PathMode = 0,
        FileMode
    };

    VBoxFilePathSelectorWidget (QWidget *aParent = 0);
   ~VBoxFilePathSelectorWidget();

    void setMode (SelectorMode aMode);
    SelectorMode mode() const;

    void setResetEnabled (bool aEnabled);
    bool isResetEnabled () const;

    void setNoneToolTip (const QString &aText);
    void setSelectToolTip (const QString &aText);
    void setResetToolTip (const QString &aText);

    bool isModified() const;

public slots:

    void setPath (const QString &aPath);
    QString path() const;

signals:

    void selectPath();
    void resetPath();

protected:

    void resizeEvent (QResizeEvent *aEvent);
    void retranslateUi();

private slots:

    void onActivated (int aIndex);
    void copyToClipboard();

private:

    QIcon defaultIcon() const;
    QString filePath() const;
    QString shrinkText (int aWidth) const;
    void refreshText();

    /* Private member vars */
    QFileIconProvider *mIconProvider;
    QAction *mCopyAction;
    SelectorMode mMode;
    QString mPath;
    QString mNoneStr;
    QString mNoneTip;
};

#endif /* __VBoxFilePathSelectorWidget_h__ */

