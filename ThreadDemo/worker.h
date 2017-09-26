#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>

class Worker : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool abort READ hasStopped WRITE setAbort NOTIFY abortChanged)
public:
    explicit Worker(QObject *parent = 0);

    bool hasStopped() const
    {
        QMutexLocker locker(m_mutex);
        return m_abort;
    }

signals:
    void resultReady(const QString &result);
    void progress(int);
    void showErrorMessage(QString);

    void abortChanged(bool abort);

public slots:
    void cancel()
    {
        qDebug() << Q_FUNC_INFO;
        this->setAbort(true);
    }

    void doWork();

    void setAbort(bool abort)
    {
        QMutexLocker locker(m_mutex);
        if (m_abort == abort)
            return;

        m_abort = abort;
        emit abortChanged(abort);
    }

private:
    bool m_abort;
    QMutex * m_mutex;
};

#endif // WORKER_H
