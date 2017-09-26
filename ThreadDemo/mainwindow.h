#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onWorkFinished();
    void showErrorMessage(QString);
private:
    Ui::MainWindow *ui;
    QThread workerThread;
};

#endif // MAINWINDOW_H
