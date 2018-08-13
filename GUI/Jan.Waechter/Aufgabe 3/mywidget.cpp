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
    setFixedSize(250,200);



    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout();


    titel = new QLabel("<h1>Password Generator</h1");
    vbox->addWidget(titel);


    Row1Text = new QLabel("Length");
    Row1Slider = new QSlider(Qt::Horizontal, this);
    Row1Slider->setValue(10);
    Row1Slider->setMaximum(20);
    Row1Slider->setMinimum(6);
    hbox->addWidget(Row1Text);
    hbox->addWidget(Row1Slider);
    vbox->addLayout(hbox);


    Row2Checkbox = new QCheckBox("A..Za..z", this);
    Row2Checkbox->setChecked(true);
    vbox->addWidget(Row2Checkbox);


    Row3Checkbox = new QCheckBox("0..9", this);
    vbox->addWidget(Row3Checkbox);

    Row4Checkbox = new QCheckBox("!@#}?", this);
    vbox->addWidget(Row4Checkbox);

    Row5LineEdit = new QLineEdit;
    Row5LineEdit->setReadOnly(true);
    vbox->addWidget(Row5LineEdit);

    setLayout(vbox);

    eventhandler *handler = new eventhandler(this);
    QObject::connect(Row2Checkbox, SIGNAL(toggled(bool)),handler,SLOT(generatePasswordEvent()));
    QObject::connect(Row3Checkbox, SIGNAL(toggled(bool)),handler,SLOT(generatePasswordEvent()));
    QObject::connect(Row4Checkbox, SIGNAL(toggled(bool)),handler,SLOT(generatePasswordEvent()));
    QObject::connect(Row1Slider, SIGNAL(sliderMoved(int)),handler,SLOT(generatePasswordEvent()));


    generatePassword();


}

MyWidget::~MyWidget()
{

}

void MyWidget::generatePassword(){
    qDebug() << "password generation" << endl;

    string possiblevalues = "";
    if(Row2Checkbox->isChecked()){
        possiblevalues.append("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    }
    if(Row3Checkbox->isChecked()){
        possiblevalues.append("0123456789");
    }
    if(Row4Checkbox->isChecked()){
        possiblevalues.append("!@#$?");
    }

    /* initialize random seed: */
    srand (time(NULL));
    int number;
    string finalpassword = "";
    for(int i = 0; i<Row1Slider->value()-1;i++){

          /* generate secret number between 1 and 10: */
          number = rand() % (possiblevalues.length()-1);

          finalpassword += possiblevalues[number];
    }

    Row5LineEdit->setText(QString::fromStdString(finalpassword));


}


