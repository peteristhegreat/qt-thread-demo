#include "worker.h"
#include "processutils.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
    m_mutex = new QMutex();
}

void Worker::doWork()
{
    this->setAbort(false);
    ProcessUtils pu;
    QObject::connect(& pu, SIGNAL(showErrorMessage(QString)), this, SIGNAL(showErrorMessage(QString)));

    int i = 0;

    QString retVal = pu.runCommand("sleep 1");

    emit progress(i++);

    pu.runCommand("sleep 1");

    if(pu.exitCode() != 0 || this->hasStopped()) return;

    emit progress(i++);

    pu.runCommand("sleep 1");

    if(pu.exitCode() != 0 || this->hasStopped()) return;

    emit progress(i++);

    pu.runCommand("sleep 1");

    if(pu.exitCode() != 0 || this->hasStopped()) return;

    emit progress(i++);

    pu.runCommand("sleep 1");

    if(pu.exitCode() != 0 || this->hasStopped()) return;

    emit progress(i++);

    pu.runCommand("sleep 1");

    if(pu.exitCode() != 0 || this->hasStopped()) return;

    emit progress(i++);

    pu.runCommand("notepad");

    if(pu.exitCode() != 0 || this->hasStopped()) return;

    emit progress(i++);

    pu.runCommand("sleep 1");

    if(pu.exitCode() != 0 || this->hasStopped()) return;

    emit progress(i++);

    pu.runCommand("sleep 1");

    if(pu.exitCode() != 0 || this->hasStopped()) return;

    emit progress(i++);

    pu.runCommand("sleep 1");

    if(pu.exitCode() != 0 || this->hasStopped()) return;

    emit progress(i++);

    pu.runCommand("sleep 1");

    if(pu.exitCode() != 0 || this->hasStopped()) return;

    emit progress(i++);

    pu.runCommand("sleep 1");

    if(pu.exitCode() != 0 || this->hasStopped()) return;

    emit progress(i++);

    pu.runCommand("sleep 1");

    if(pu.exitCode() != 0 || this->hasStopped()) return;

    emit progress(i++);

}
