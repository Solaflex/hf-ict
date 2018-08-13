#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include <QPaintEvent>
#include <map>


class Widget : public QWidget
{
    Q_OBJECT
private:
    QLabel *titleLabel;
    QPushButton *ResetButton;
    QPushButton *PaintButton;


public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void PaintPoints();
    void ResetPoints();

    bool AllowPoints;
    bool AllowLines;

    std::map<int,int> MapOfClicks;
};

#endif // WIDGET_H
