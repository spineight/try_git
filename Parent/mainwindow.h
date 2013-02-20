#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <windows.h>
#include <QMessageBox> // interaction with user, reporting on errors
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_btn_StartChildProcess_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
