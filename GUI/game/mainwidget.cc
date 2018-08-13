#include <QSlider>
#include <QDebug>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "mainwidget.h"
#include <QMessageBox>
#include <QSound>
#include "constants.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    createObjects();
    connectObjects();
    createLayout();

    RepeatDialogOpen = false; // Initialize variable as false
}

void MainWidget::angleSliderMoved(int value)
{
    angleInput->setText(QString::number(value));
}

void MainWidget::speedSliderMoved(int value)
{
    speedInput->setText(QString::number(value));
}

void MainWidget::actionButtonClicked()
{
    QSound::play(Constants::imgFolder  + "sfx_throw.wav");          // prints "QCoreApplication::postEvent: Unexpected null receiver" msg to console
    actionButton->setText("Shoot");
    numberOfSchootsInput->setText(QString::number(
                                      numberOfSchootsInput->text().
                                      toInt() + 1));
    if (gameArea->gameRunning) {
        gameArea->shoot(speedSlider->value(),angleSlider->value());
        qDebug() << "game running: " << gameArea->gameRunning;
        qDebug() << "slider speed: " << speedSlider->value();
        qDebug() << "slider angle: " << angleSlider->value();
    } else {
        gameArea->startGame();
    }


    /*
     *
    if (speedSlider->value() == 60)     // for debugging, to check gameFinished()
    {
        gameArea->gameFinished();
        speedSlider->setValue(1);
    }
    */

}

void MainWidget::onGameFinished()
{
    /*
    //gameObjects.clear();                                     //wiping all the objects inside gameObjects(vector)
    QMessageBox *scoreBox = new QMessageBox();
    scoreBox->setButtonText(QMessageBox::Yes, "Play again!");
    scoreBox->setText("YOUR SCORE: " + numberOfSchootsInput->text());
    scoreBox->setWindowTitle("Finished");
    scoreBox->show();
    */
    if(!RepeatDialogOpen) {
        RepeatDialogOpen = true; // set RepeatDialogOpen to true while the dialog is open to prevent multiple dialogs

        QMessageBox *msgBox = new QMessageBox;
        msgBox->setText("YOUR SCORE: " + numberOfSchootsInput->text());
        msgBox->setInformativeText("Play again! Do it! Do it! ");
        msgBox->setStandardButtons(QMessageBox::Yes);
        msgBox->setDefaultButton(QMessageBox::Yes);
        int ret = msgBox->exec();

        if (ret == QMessageBox::Yes)
        {
            actionButtonClicked();
            gameArea->clearGameObjects();
            gameArea->startGame();
            numberOfSchootsInput->setText(0);

            //connect(score, SIGNAL(finished(int)), this, SLOT(onGameFinished()));       //couldn't bring slot to work
            //onGameFinished();                                                            //might be obsolete or bad design. but works
        } else {
            qDebug() << "Exit";
        }
        RepeatDialogOpen = false; // disable the blocker
    }

}

void MainWidget::createObjects()
{
    titleLabel = new QLabel("<h1>The Gorilla QT Game</h1>");
    actionButton = new QPushButton("Start");

    angleLabel = new QLabel("Angle");
    angleInput = new QLineEdit("0");
    angleInput->setReadOnly(true);
    angleSlider = new QSlider();
    angleSlider->setOrientation(Qt::Horizontal);
    angleSlider->setMinimum(0);
    angleSlider->setMaximum(90);

    speedLabel = new QLabel("Speed");
    speedInput = new QLineEdit("1");
    speedInput->setReadOnly(true);
    speedSlider = new QSlider();
    speedSlider->setOrientation(Qt::Horizontal);
    speedSlider->setMinimum(1);
    speedSlider->setMaximum(100);

    shootsLabel = new QLabel("#Shoots");
    numberOfSchootsInput = new QLineEdit();

    gameArea = new GameArea();
    // initalize gameArea state, otherwise it will always be running
    gameArea->gameRunning = false;
}

void MainWidget::createLayout()
{
    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout();

    hbox->addWidget(actionButton);
    hbox->addWidget(shootsLabel);
    hbox->addWidget(numberOfSchootsInput);
    hbox->addWidget(speedLabel);
    hbox->addWidget(speedSlider);
    hbox->addWidget(speedInput);
    hbox->addWidget(angleLabel);
    hbox->addWidget(angleSlider);
    hbox->addWidget(angleInput);

    vbox->addWidget(titleLabel);
    vbox->addWidget(gameArea, 1);
    vbox->addLayout(hbox);

    setLayout(vbox);
}

void MainWidget::connectObjects()
{
    connect(angleSlider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(angleSliderMoved(int)));

    connect(speedSlider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(speedSliderMoved(int)));

    connect(actionButton,
            SIGNAL(clicked(bool)),
            this,
            SLOT(actionButtonClicked()));
}
