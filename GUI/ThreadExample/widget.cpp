#include "widget.h"
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

}
