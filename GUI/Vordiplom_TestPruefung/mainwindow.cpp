#include "mainwindow.h"
#include "eventhandler.h"

#include<QPushButton>
#include<QLabel>

#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QDebug>

#include <QPainter>
#include <QLineEdit>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(300,300);

    titleLabel = new QLabel("App Title");
    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout();

    AddButton = new QPushButton("Add");
    ClearButton = new QPushButton("Clear");
    SortButton = new QPushButton("Sort");

    LineEdit = new QLineEdit();



    List = new QListWidget();
    List->setMinimumHeight(130);

    hbox->addWidget(AddButton);
    hbox->addWidget(ClearButton);

    vbox->addWidget(titleLabel);
    vbox->addWidget(LineEdit);
    vbox->addLayout(hbox);
    vbox->addWidget(List);
    vbox->addWidget(SortButton);


    vbox->addWidget(titleLabel);

    setLayout(vbox);


    eventhandler *handler = new eventhandler(this);
    QObject::connect(AddButton,SIGNAL(clicked()),handler,SLOT(OnAddButtonClicked()));

    //QObject::connect(ResetButton, SIGNAL(clicked()),handler,SLOT(onResetButtonClicked()));

}

MainWindow::~MainWindow()
{

}

void OnAddButtonClicked() {
    //qDebug() << LineEdit->text;

}
