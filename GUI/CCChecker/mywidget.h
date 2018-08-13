#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class QLabel;
class QPushButton;
class QLineEdit;

class MyWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel *titleLabel;
    QLabel *textLabel;
    QPushButton *okButton;
    QLineEdit *inputLineEdit;
public:
    void DisplayTextbox();
    MyWidget();


};

#endif // MYWIDGET_H
