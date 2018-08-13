#include "mywidget.h"
#include "eventhandler.h"

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>

#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QDebug>

#include <QPainter>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>

#include <QDebug>
#include <vector>

using namespace std;


MyWidget::MyWidget(QWidget *parent)
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

    // Connect the event handlers

    eventhandler *handler = new eventhandler(this);
    QObject::connect(AddButton, SIGNAL(clicked(bool)),handler,SLOT(OnButtonAddClicked()));
    QObject::connect(ClearButton, SIGNAL(clicked(bool)),handler,SLOT(OnButtonClearClicked()));
    QObject::connect(SortButton, SIGNAL(clicked(bool)),handler,SLOT(OnButtonSortClicked()));




}

MyWidget::~MyWidget()
{

}


void MyWidget::OnButtonAddClicked(){

    QString text = LineEdit->text();

    QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
    if (re.exactMatch(text) && text.isEmpty() == false){

        // Add text to list
        new QListWidgetItem(LineEdit->text(), List);

        // Clear textbox
        LineEdit->clear();
    }

}
void MyWidget::OnButtonClearClicked(){

    // Clear List
    List->clear();
}
void MyWidget::OnButtonSortClicked(){

    // Declare the array to keep the values
    vector<int> temparray;

    // Gather the item's value
    for(int i = 0; i < List->count();i++) {
        temparray.push_back(List->item(i)->text().toInt());
    }

    sort(temparray.begin(), temparray.end());

    // Clear the list
    List->clear();

    for(int i = 0; i<temparray.size();i++) {
        // Add text to list
        new QListWidgetItem(QString::number(temparray.at(i)), List);
    }

}
