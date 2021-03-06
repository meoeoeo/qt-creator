/****************************************************************************
**
** Copyright (C) 2016 BlackBerry Limited. All rights reserved.
** Contact: BlackBerry (qt@blackberry.com)
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

#include "qnxconstants.h"
#include "qnxutils.h"
#include "qnxversionnumber.h"

#include <utils/fileutils.h>
#include <utils/environment.h>

#include <projectexplorer/abi.h>

#include <debugger/debuggeritemmanager.h>

#include <QVariant>

namespace ProjectExplorer
{
    class Kit;
    class ToolChain;
}

namespace Qnx {
namespace Internal {

class QnxToolChain;
class QnxQtVersion;

class QnxConfiguration
{
public:
    QnxConfiguration();
    QnxConfiguration(const Utils::FilePath &sdpEnvFile);
    QnxConfiguration(const QVariantMap &data);

    Utils::FilePath envFile() const;
    Utils::FilePath qnxTarget() const;
    Utils::FilePath qnxHost() const;
    Utils::FilePath qccCompilerPath() const;
    Utils::EnvironmentItems qnxEnv() const;
    QnxVersionNumber version() const;
    QVariantMap toMap() const;

    bool isValid() const;

    QString displayName() const;
    bool activate();
    void deactivate();
    bool isActive() const;
    bool canCreateKits() const;
    Utils::FilePath sdpPath() const;

    QList<ProjectExplorer::ToolChain *> autoDetect(
            const QList<ProjectExplorer::ToolChain *> &alreadyKnown);

private:
    QList<ProjectExplorer::ToolChain *> findToolChain(
            const QList<ProjectExplorer::ToolChain *> &alreadyKnown,
            const ProjectExplorer::Abi &abi);

    QStringList validationErrors() const;

    void setVersion(const QnxVersionNumber& version);

    void readInformation();

    void setDefaultConfiguration(const Utils::FilePath &envScript);

    QString m_configName;

    Utils::FilePath m_envFile;
    Utils::FilePath m_qnxConfiguration;
    Utils::FilePath m_qnxTarget;
    Utils::FilePath m_qnxHost;
    Utils::FilePath m_qccCompiler;
    Utils::EnvironmentItems m_qnxEnv;
    QnxVersionNumber m_version;

    class Target
    {
    public:
        Target(const ProjectExplorer::Abi &abi, const Utils::FilePath &path)
            : m_abi(abi), m_path(path)
        {
        }

        QString shortDescription() const;
        QString cpuDir() const;

        ProjectExplorer::Abi m_abi;
        Utils::FilePath m_path;
        Utils::FilePath m_debuggerPath;
    };

    QList<Target> m_targets;

    QnxQtVersion *qnxQtVersion(const Target &target) const;

    void createTools(const Target &target);
    QVariant createDebugger(const Target &target);
    QnxToolChain *createToolChain(const Target &target);
    void createKit(const Target &target, QnxToolChain *toolChain, const QVariant &debugger);

    const Target *findTargetByDebuggerPath(const Utils::FilePath &path) const;

    void updateTargets();
    void assignDebuggersToTargets();
};

} // Internal
} // Qnx
