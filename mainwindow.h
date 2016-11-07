#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    //void MainWindow::getdata(int num);
    ~MainWindow();
public slots:
    void buttonGroup_handler(int num);
    void getdata(int num);

private:
    Ui::MainWindow *ui;

    QButtonGroup *buttonGroup;
    bool flag;
    int opsflag;
    QString firstNum;
    QString secondNum;
};

#endif // MAINWINDOW_H
