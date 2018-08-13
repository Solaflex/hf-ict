#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include "gamearea.h"

class QSlider;
class QPushButton;
class QLineEdit;
class GameArea;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;

class MainWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel *titleLabel;
    QPushButton *actionButton;
    GameArea *gameArea;

    QSlider *angleSlider;
    QLineEdit *angleInput;
    QLabel *angleLabel;

    QSlider *speedSlider;
    QLineEdit *speedInput;
    QLabel *speedLabel;

    QLabel *shootsLabel;
    QLineEdit *numberOfSchootsInput;

    void createObjects();
    void createLayout();
    void connectObjects();

    bool RepeatDialogOpen;


public:
    explicit MainWidget(QWidget *parent = 0);


public slots:
    void angleSliderMoved(int value);
    void speedSliderMoved(int value);
    void actionButtonClicked();
    void onGameFinished();
};

#endif // MAINWIDGET_H
