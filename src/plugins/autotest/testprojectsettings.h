/****************************************************************************
**
** Copyright (C) 2019 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include <projectexplorer/project.h>

namespace Autotest {
namespace Internal {

class TestProjectSettings : public QObject
{
    Q_OBJECT
public:
    TestProjectSettings(ProjectExplorer::Project *project);
    ~TestProjectSettings();

    void setUseGlobalSettings(bool useGlobal);
    bool useGlobalSettings() const { return m_useGlobalSettings; }
    void setRunAfterBuild(bool enabled) {m_runAfterBuild = enabled; }
    bool runAfterBuild() const { return m_runAfterBuild; }
    void setActiveFrameworks(const QMap<Core::Id, bool> enabledFrameworks)
    { m_activeTestFrameworks = enabledFrameworks; }
    QMap<Core::Id, bool> activeFrameworks() const { return m_activeTestFrameworks; }
    void activateFramework(const Core::Id &id, bool activate);
private:
    void load();
    void save();

    ProjectExplorer::Project *m_project;
    bool m_useGlobalSettings = true;
    bool m_runAfterBuild = false;
    QMap<Core::Id, bool> m_activeTestFrameworks;
};

} // namespace Internal
} // namespace Autotest
