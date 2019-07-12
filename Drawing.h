#pragma once
#include <QtWidgets/QMainWindow>
#include <QPen>
#include "Star.h"
#include <vector>
#include <QLabel>
#include <QHBoxLayout>
class Drawing : public QWidget
{
	Q_OBJECT

private:
	enum Paint
	{
		ManyThings,
		Ellipse,
		EllipseUp,
		EllipseDown
	};
	Paint whatToPaint;
	std::vector<Star> starsToPaint;
	Star myStar;
public:
	Drawing(std::vector<Star> starsFromUser,Star starFromUser,QWidget *parent = 0);
	~Drawing();
	QSize sizeHint() const Q_DECL_OVERRIDE; // this must be redefined (the default implementation returns an invalid size, if there is no layout)
	void paintStars();

protected:
	void paintEvent(QPaintEvent *event) override;		// will draw shapes on the widget
	//void mousePressEvent(QMouseEvent * event) Q_DECL_OVERRIDE;	// is invoked when a key on the mouse is pressed
};
