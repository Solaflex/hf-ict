#include "widget.h"
#include "eventhandler.h"

#include<QPushButton>
#include<QLabel>

#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QDebug>

#include <QPainter>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(500,500);
    titleLabel = new QLabel("<h1>Polygon Plotter</h1>");
    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout();

    ResetButton = new QPushButton("Reset");
    PaintButton = new QPushButton("Paint");

    hbox->addWidget(ResetButton);
    hbox->addWidget(PaintButton);

    vbox->addWidget(titleLabel);
    vbox->addLayout(hbox);


    //setLayout(vbox);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(titleLabel,0,0);
    layout->addWidget(ResetButton, 1,0);
    layout->addWidget(PaintButton,1,1);

    setLayout(layout);

    AllowLines = false;
    AllowPoints = true;

    EventHandler *handler = new EventHandler(this);
    QObject::connect(PaintButton,SIGNAL(clicked()),handler,SLOT(onButtonClicked()));

    QObject::connect(ResetButton, SIGNAL(clicked()),handler,SLOT(onResetButtonClicked()));


}

Widget::~Widget()
{
}

void Widget::ResetPoints(){
    qDebug() << "Reset button clicked" << endl;
    MapOfClicks.clear();
    AllowPoints = true;
    AllowLines = false;

    // Somehow we should remove all paintings here but I have no clue how to do it :)
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    int firstx;
    int firsty;

    int previousx = NULL;
    int previousy = NULL;




    for (std::map<int,int>::const_iterator it = MapOfClicks.begin(); it != MapOfClicks.end(); ++it)
    {
        if(it==MapOfClicks.begin()){
            firstx = it->first;
            firsty = it->second;
        }
        painter.drawPoint(it->first, it->second);

        if(AllowLines) {
            // Start to draw lines
            if(previousx == NULL && previousy == NULL) {
                painter.drawLine(it->first, it->second, it->first, it->second);
            } else if(it==MapOfClicks.end()){
                // Combine the last point with the first point
                painter.drawLine(it->first,it->second,firstx,firsty);
                painter.drawLine(50,100,150,200);
            } else {
                // Combine the current point with the previous one
                painter.drawLine(it->first, it->second, previousx, previousy);
            }
            previousx = it->first;
            previousy = it->second;

            /*
             * Something is not working as it should.
             * The drawing don't get paintent :(
             * */


        }

    }
    if(AllowLines){
        AllowLines = false;
    }
    update();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "x:" << event->x() << " y:" << event->y();

    int x = event->x();
    int y = event->y();

    MapOfClicks.insert(std::make_pair(x,y));
    update();
}

void Widget::PaintPoints(){
    qDebug() << "Button Paint pressed, amount of points: " << MapOfClicks.size() << endl;
    AllowLines = true;

}
