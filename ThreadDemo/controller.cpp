//#include "controller.h"
//#include "worker.h"
//#include <QMessageBox>
//#include <QApplication>

//Controller::Controller(QObject *parent) : QObject(parent)
//{
//    Worker *worker = new Worker;
//    worker->moveToThread(&workerThread);
//    connect(&workerThread, SIGNAL(finished()), worker, SLOT(deleteLater()));
//    connect(this, SIGNAL(operate(QString)), worker, SLOT(doWork(QString)));
//    connect(worker, SIGNAL(resultReady(QString)), this, SLOT(handleResults(QString)));
//    connect(worker, SIGNAL(progress(int)),
//    workerThread.start();
//}

//Controller::~Controller()
//{
//    workerThread.quit();
//    workerThread.wait();
//}

//void Controller::showErrorMessage(QString msg)
//{
//    QMessageBox::warning(this, qApp->applicationName(), msg);
//}
