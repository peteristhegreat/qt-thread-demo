#include "processutils.h"
#include <QProcess>

ProcessUtils::ProcessUtils(QObject *parent) : QObject(parent)
{

}

QString ProcessUtils::runCommand(QString cmd)
{
    QProcess p;
    p.start(cmd);

    bool finished = p.waitForFinished(5000);

    this->setStdOut(p.readAllStandardOutput());
    this->setStdErr(p.readAllStandardError());
    this->setExitCode(p.exitCode());

    QStringList report;
    if(!finished && p.error() == QProcess::Timedout)
    {
        report << "Command failed to finish:"
               << "\"" + cmd + "\"";
        p.kill();
        if(exitCode() == 0)
            this->setExitCode(-1);
    }
    else if(!m_stdErr.isEmpty() || p.exitCode() != 0 || !finished)
    {
        report << "Command exited with errors:"
               << "\"" + cmd + "\""
               << "exit code: " + QString::number(p.exitCode())
               << "error string: " + p.errorString()
               << "stdErr: " + m_stdErr;
        if(exitCode() == 0)
            this->setExitCode(-1);
    }
    if(report.size() > 0)
        emit showErrorMessage(report.join("\n\n"));
    return m_stdOut;
}
