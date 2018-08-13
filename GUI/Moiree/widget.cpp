#include "widget.h"
#include "QPainter"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{    
    QPainter *myPainter = new QPainter(this);

    int h = height();
    int w = width();

    int AmountOfTopLines = 20;
    int AmountOfSideLines = 20;

    int TopSpaceBetweenLines = h/AmountOfTopLines;
    int SideSpaceBetweenLines = w/AmountOfSideLines;

    myPainter->drawLine(10,10,10,10);
    for(int i = 0;i<AmountOfTopLines;i++){
        myPainter->drawLine(0,(1*i)+(TopSpaceBetweenLines*i),h,0);
    }


    delete myPainter;
}
