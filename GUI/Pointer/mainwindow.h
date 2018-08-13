#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPaintEvent;

class MainWindow : public QMainWindow {
	Q_OBJECT

	public:
		MainWindow(QWidget *parent = 0);
		void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
