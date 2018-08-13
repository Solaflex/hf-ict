#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class MyWidget : public QWidget
{
    Q_OBJECT

private:
    QPushButton *CheckButton;
    QLineEdit *LineEdit;
    QLabel *titleLabel;
public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void CheckPrime();
};

#endif // MYWIDGET_H
