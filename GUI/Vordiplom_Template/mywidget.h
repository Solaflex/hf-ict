#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>

class MyWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel *titleLabel;
    QLineEdit *LineEdit;
    QPushButton *AddButton;
    QPushButton *ClearButton;
    QListWidget *List;
    QPushButton *SortButton;
public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void OnButtonAddClicked();
    void OnButtonClearClicked();
    void OnButtonSortClicked();
};

#endif // MYWIDGET_H
