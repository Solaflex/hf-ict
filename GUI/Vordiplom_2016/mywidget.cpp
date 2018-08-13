#include "mywidget.h"
#include <QDebug>

#include<QHBoxLayout>
#include<QVBoxLayout>

#include <QPushButton>
#include <QLabel>
#include <eventhandler.h>
#include <QMessageBox>
#include <string>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{

    setFixedSize(220,100);



    QVBoxLayout *vbox = new QVBoxLayout();

    titleLabel = new QLabel("<h1>Prime Checker</h1>");
    LineEdit = new QLineEdit();
    CheckButton = new QPushButton("Add");

    vbox->addWidget(titleLabel);
    vbox->addWidget(LineEdit);
    vbox->addWidget(CheckButton);

    setLayout(vbox);

    eventhandler *handler = new eventhandler(this);
    QObject::connect(CheckButton, SIGNAL(clicked(bool)),handler,SLOT(OnCheckButtonClicked()));


}

MyWidget::~MyWidget()
{

}


void MyWidget::CheckPrime(){

    std::string giventext = LineEdit->text().toStdString();
    int isdigit = std::all_of(giventext.begin(), giventext.end(), ::isdigit);

    if(isdigit){
        int originalnumber = std::stoi(giventext);
        int number =  std::stoi(giventext);

        bool isPrime = true;

        for(int i = 2; i <= number / 2; ++i)
        {
          if(number % i == 0)
          {
              isPrime = false;
              break;
          }
        }

        std::string text = (std::to_string(originalnumber) + " is prime number: " + std::to_string(isPrime));
        QMessageBox msgBox;
        msgBox.setFixedWidth(200);
        msgBox.setText(QString::fromStdString(text));
        msgBox.setWindowTitle("Result");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    } else {
        std::string text = ("the number you entered is invalid");
        QMessageBox msgBox;
        msgBox.setFixedWidth(200);
        msgBox.setText(QString::fromStdString(text));
        msgBox.setWindowTitle("Wrong Number");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();

    }


}
