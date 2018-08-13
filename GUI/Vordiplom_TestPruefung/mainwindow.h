#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>

class MainWindow : public QWidget
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
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void OnAddButtonClicked();
};

#endif // MAINWINDOW_H
