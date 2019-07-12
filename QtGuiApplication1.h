#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"
#include "Repository.h"
#include "Astronomer.h"
#include "Observer.h"
#include "Drawing.h"
#include <qscrollarea.h>
#include <qcombobox.h>
class QtGuiApplication1 : public QMainWindow,public Observer
{
	Q_OBJECT

public:
	std::vector<Star> constellations;
	Astronomer astronomer;
	Repository<Star>* stars;
	Repository<Astronomer>* astronomers;
	QtGuiApplication1(Repository<Star>* starsFromUser, Repository<Astronomer>* astronomersFromUser, Astronomer astronomerFromUser,QWidget *parent = Q_NULLPTR);
	Drawing* starsDrawing;
	QWidget* drawingWindow;
	QLabel* descriptionLabel;
	QVBoxLayout* mainLayout;
	//view constellation meniu
	QWidget* constellationsWindow;
	QVBoxLayout* layout;
	QComboBox* comboBox;
	QLabel* imageLabel;
private:
	Ui::QtGuiApplication1Class ui;
	void displayData();
	void exitProgram();
	void viewConstellations();
	void addStar();
	void showFilteredStars();
	void viewStar();
	void update() {
		displayData();
	}
};
