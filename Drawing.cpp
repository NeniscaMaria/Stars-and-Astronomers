#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include "Drawing.h"
Drawing::Drawing(std::vector<Star> starsFromUser, Star starFromUser, QWidget *parent) : QWidget{ parent } {
	starsToPaint = starsFromUser;
	myStar = starFromUser;
	this->whatToPaint = Paint::ManyThings;
	this->setWindowTitle(QString::fromStdString(myStar.getConstellation()));
	
}
Drawing::~Drawing() {}
QSize Drawing::sizeHint() const {
	return QSize{ 600, 400 };
}

void Drawing::paintStars() {
	int distance = 5;
	QPainter painter{ this };
	painter.eraseRect(0, 0, 600, 400);
	for (auto star : starsToPaint) {
		std::string RA = star.getRighAscension();
		std::string declination = star.getDeclination();
		double diameter = star.getDiameter();
		//now we parse the right acsension to get the coordinates on the x-axis
		//here is why: the right ascension is comparable with the longitude and the declination is comparable with the latitude
		//https://en.wikipedia.org/wiki/Right_ascension#/media/File:Ra_and_dec_on_celestial_sphere.png
		//sample of right ascension: 11h 50m 41.71824s
		std::size_t position = RA.find("h");
		int hours = atoi(RA.substr(0, position).c_str());
		//now we parse the declination to get the coordinates on the y-axis
		//declination sample 3d 23' 50.8932''
		position = declination.find("d");
		int degrees = atoi(declination.substr(0, position).c_str());
		if (hours < 0)
			painter.translate(hours*(-1) * 5, 0);
		if (degrees < 0)
			painter.translate(0, degrees*(-1) * 5);
		if (star.getName() == myStar.getName()) {
			QPen pen2{ Qt::red, 1, Qt::SolidLine, Qt::RoundCap };
			painter.setPen(pen2);
			QBrush brush{ Qt::red, Qt::SolidPattern };
			painter.setBrush(brush);
			painter.drawEllipse(hours*distance,degrees*distance,diameter,diameter);
		}
		else {
			QPen pen2{ Qt::black, 1, Qt::SolidLine, Qt::RoundCap };
			painter.setPen(pen2);
			QBrush brush{ Qt::black, Qt::SolidPattern };
			painter.setBrush(brush);
			painter.drawEllipse(hours*distance, degrees*distance, diameter, diameter);
		}
	}
}

void Drawing::paintEvent(QPaintEvent *event) {
	switch (this->whatToPaint)
	{
	case Paint::ManyThings:
		this->paintStars();
		break;
	
	default:
		break;
	}
}