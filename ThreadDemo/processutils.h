#ifndef PROCESSUTILS_H
#define PROCESSUTILS_H

#include <QObject>

class ProcessUtils : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString stdErr READ stdErr WRITE setStdErr NOTIFY stdErrChanged)
    Q_PROPERTY(QString stdOut READ stdOut WRITE setStdOut NOTIFY stdOutChanged)
    Q_PROPERTY(int exitCode READ exitCode WRITE setExitCode NOTIFY exitCodeChanged)

    QString m_stdErr;

    QString m_stdOut;

    int m_exitCode;

public:
    explicit ProcessUtils(QObject *parent = 0);

    QString runCommand(QString cmd);
//    QString runCommandWithStreams(QString cmd);
    QString stdErr() const
    {
        return m_stdErr;
    }

    QString stdOut() const
    {
        return m_stdOut;
    }

    int exitCode() const
    {
        return m_exitCode;
    }

signals:
    void failedToFinish(QString);
    void showErrorMessage(QString);
    void stdErrChanged(QString stdErr);

    void stdOutChanged(QString stdOut);

    void exitCodeChanged(int exitCode);

public slots:
    void setStdErr(QString stdErr)
    {
        if (m_stdErr == stdErr)
            return;

        m_stdErr = stdErr;
        emit stdErrChanged(stdErr);
    }
    void setStdOut(QString stdOut)
    {
        if (m_stdOut == stdOut)
            return;

        m_stdOut = stdOut;
        emit stdOutChanged(stdOut);
    }
    void setExitCode(int exitCode)
    {
        if (m_exitCode == exitCode)
            return;

        m_exitCode = exitCode;
        emit exitCodeChanged(exitCode);
    }
};

#endif // PROCESSUTILS_H
