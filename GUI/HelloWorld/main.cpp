#include <QApplication>
#include <QPushButton>
#include <QLCDNumber>
#include <QDial>
#include <QSlider>
#include <QDebug>

int main(int argc, char **argv) {
	QApplication qApplication(argc, argv);
	
	/*
	QPushButton *button = new QPushButton("Push Me");
	button->show();
	*/
	
    /*
	QLCDNumber *LCD = new QLCDNumber(5);
	LCD->display(12345);
	LCD->show();
    */
	
    /*
	QDial *dial = new QDial();
	dial->show();
	*/
	
	/*
	QSlider *slider = new QSlider(Qt::Horizontal);
	slider->show();
	*/
	
	qDebug() << "debug message...";
	qWarning() << "warning message...";
	
	
	return qApplication.exec();
}
