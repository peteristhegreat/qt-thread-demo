#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include <QMessageBox>
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Worker *worker = new Worker;
    worker->moveToThread(&workerThread);
    connect(&workerThread, SIGNAL(finished()), this, SLOT(onWorkFinished()));
    connect(&workerThread, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(ui->pushButton, SIGNAL(clicked()), worker, SLOT(doWork()));
//    connect(worker, SIGNAL(resultReady(QString)), this, SLOT(handleResults(QString)));
    connect(worker, SIGNAL(progress(int)), ui->progressBar, SLOT(setValue(int)));
    connect(worker, SIGNAL(showErrorMessage(QString)), this, SLOT(showErrorMessage(QString)));

    connect(ui->cancelButton, SIGNAL(clicked()), worker, SLOT(cancel()), Qt::DirectConnection);
    workerThread.start();
}

void MainWindow::showErrorMessage(QString msg)
{
    QMessageBox::warning(this, qApp->applicationName(), msg);
}


MainWindow::~MainWindow()
{
    workerThread.quit();
    workerThread.wait();
    delete ui;
}

void MainWindow::onWorkFinished()
{
    qDebug() << Q_FUNC_INFO;
}
