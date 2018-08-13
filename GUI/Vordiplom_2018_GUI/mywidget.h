#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include <QSlider>
#include <QCheckBox>

class MyWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel *titel;
    QLabel *Row1Text;
    QSlider *Row1Slider;
    QCheckBox *Row2Checkbox;
    QCheckBox *Row3Checkbox;
    QCheckBox *Row4Checkbox;
    QLineEdit *Row5LineEdit;
public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void generatePassword();
};

#endif // MYWIDGET_H
