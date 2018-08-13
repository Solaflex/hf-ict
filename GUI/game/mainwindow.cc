#include "mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    MainWidget *widget = new MainWidget();
    setCentralWidget(widget);
    this->setFixedSize(1000, 650);
}
