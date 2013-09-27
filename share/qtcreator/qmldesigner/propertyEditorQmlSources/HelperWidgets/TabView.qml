/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

import QtQuick 2.1
import QtQuick.Controls 1.0 as Controls
import QtQuick.Controls.Styles 1.1

Controls.TabView {
    id: root

    property color textColor: "#eee"
    frameVisible: false
    style: TabViewStyle {
        frameOverlap: 0
        frame: Item { }
        tab: Rectangle {
            color: styleData.selected ? "#eee" : "#444"
            implicitWidth: root.width/root.count + 2
            implicitHeight: 21
            Text {
                id: text
                anchors.centerIn: parent
                text: styleData.title
                renderType: Text.NativeRendering
                color: styleData.selected ? "#000" : "#fff"
            }
            Rectangle {
                anchors.fill: parent
                opacity: 0.10
                gradient: Gradient {
                    GradientStop {color: '#fff' ; position: 0}
                    GradientStop {color: '#000' ; position: 1}
                }
            }
            Rectangle {
                color: "#666"
                width: parent.width
                height: 1
            }
            Rectangle {
                color: "#333"
                width: parent.width
                height: 1
                anchors.bottom: parent.bottom
            }
        }
    }
}
