#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <cstdlib>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget( *parent))
	: QMainWindow(parent) {
}

void MainWindow::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	QPointF p, m;

	// draw first three points
	QPointF a(30, 30);
	QPointF b(300, 130);
	QPointF c(90, 300);
	painter.drawPoint(a);
	painter.drawPoint(b);
	painter.drawPoint(c);

	// set first point
	qreal x = a.rx();
	qreal y = a.ry();


	// init random number
	int random(0);
	srand(0); 

	for (int i=0; i<20000; i++) {
		// set p randomly
		random = rand() % 3;
		switch(random) {
			case 0:
				p = a;
				break;
			case 1:
				p = b;
				break;
			case 2:
				p = c;
				break;
		}

		//qDebug() << "x: " << x;
		//qDebug() << "px: " << p.rx();
		//qDebug() << "mx: " << (x + p.rx()) / 2;


		//qDebug() << "y: " << y;
		//qDebug() << "py: " << p.ry();
		//qDebug() << "my: " << (y + p.ry()) / 2;
		//qDebug() << endl;

		// set m in between the previous and next point
		m.setX((x + p.rx()) / 2);
		m.setY((y + p.ry()) / 2);

		// draw new point m and reset x/y
		painter.drawPoint(m);
		x = m.rx();
		y = m.ry();
	}
}
