#include "QtGuiApplication1.h"
#include <qerrormessage.h>
#include <qpixmap.h>
QtGuiApplication1::QtGuiApplication1(Repository<Star>* starsFromUser, Repository<Astronomer>* astronomersFromUser, Astronomer astronomerFromUser, QWidget *parent)
	: QMainWindow(parent)
{
	astronomer = astronomerFromUser;
	stars = starsFromUser;
	astronomers = astronomersFromUser;
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(astronomer.getName()));
	displayData();
	stars->registerObserver(this);
	ui.nameLine->setPlaceholderText("Name of star...");
	ui.RALine->setPlaceholderText("Right ascension of star...");
	ui.declinationLine->setPlaceholderText("Declination of star...");
	ui.diameterLine->setPlaceholderText("Diameter of star...");
	ui.searchLine->setPlaceholderText("Search for a star here...");
	ui.imageLine->setPlaceholderText("Image location...");
	comboBox = new QComboBox{};
	QLabel* imageLabel = new QLabel();
	connect(ui.checkBox, &QCheckBox::stateChanged, this, &QtGuiApplication1::displayData);
	connect(ui.pushButton, &QPushButton::clicked, this, &QtGuiApplication1::addStar);
	connect(ui.searchLine, &QLineEdit::textChanged, this, &QtGuiApplication1::showFilteredStars);
	connect(ui.viewButton, &QPushButton::clicked, this, &QtGuiApplication1::viewStar);
	connect(ui.actionExit, &QAction::triggered, this, &QtGuiApplication1::exitProgram);
	connect(ui.viewConstellation, &QAction::triggered, this, &QtGuiApplication1::viewConstellations);
	connect(comboBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
		[=](const QString &text) { for (auto constellation : constellations) {
		if (constellation.getConstellation() == text.toStdString()) {
			QPixmap pm(QString::fromStdString(constellation.getImage()));
			imageLabel->setPixmap(pm.scaled(pm.width() / 2, pm.height() / 2));
			layout->addWidget(imageLabel);
		}
	} });
}

void QtGuiApplication1::viewConstellations() {
	constellationsWindow = new QWidget();
	constellationsWindow->setWindowTitle("Constellations");
	layout = new QVBoxLayout();
	constellationsWindow->setLayout(layout);
	for (int i = 0; i < stars->size(); i++) {
		std::string constellation = stars->getElementFromPosition(i).getConstellation();
		bool ok = true;
		for (auto s : constellations) {
			if (s.getConstellation() == constellation)
				ok = false;
		}
		if (ok == true) {
			constellations.push_back(stars->getElementFromPosition(i));
			comboBox->addItem(QString::fromStdString(constellation));
		}
	}
	QLabel* label = new QLabel{ "Choose a constellation to view:" };
	layout->addWidget(label);
	layout->addWidget(comboBox);
	constellationsWindow->show();
	
}
void QtGuiApplication1::exitProgram() {
	exit(0);
}
void QtGuiApplication1::viewStar() {
	std::string starDescription = ui.starList->selectedItems()[0]->text().toStdString();
	std::size_t first = starDescription.find(",");
	first = starDescription.find(",");
	std::string name = starDescription.substr(0,first);
	std::size_t second = starDescription.find(",",first+1);
	std::string constellation = starDescription.substr(first+1, second-first-1);
	std::vector<Star> starsToDisplay;//here we have all the stars from the same constellation as the one selected. We need to represent these stars.
	Star myStar;
	for (int i = 0; i < stars->size(); i++) {
		if (stars->getElementFromPosition(i).getConstellation() == constellation)
			starsToDisplay.push_back(stars->getElementFromPosition(i));
		if (stars->getElementFromPosition(i).getName() == name)
			myStar = stars->getElementFromPosition(i);
	}
	starsDrawing = new Drawing{ starsToDisplay,myStar };
	drawingWindow = new QWidget();
	descriptionLabel = new QLabel{ QString::fromStdString("You are seeing the star " + myStar.getName() + " from the constellation " + myStar.getConstellation()) };
	mainLayout = new QVBoxLayout{};
	drawingWindow->setLayout(mainLayout);
	mainLayout->addWidget(descriptionLabel);
	mainLayout->addWidget(starsDrawing);
	drawingWindow->show();
}
void QtGuiApplication1::showFilteredStars() {
	std::string matchText = ui.searchLine->text().toStdString();
	if (matchText == "") {
		ui.listWidget->clear();
		return;
	}
	std::vector<Star> starsToPrint;
	for (int i = 0; i < stars->size(); i++) {
		Star star = stars->getElementFromPosition(i);
		std::size_t found = star.getName().find(matchText);
		if (found != std::string::npos)
			starsToPrint.push_back(stars->getElementFromPosition(i));
		found = star.getRighAscension().find(matchText);
		if (found != std::string::npos)
			starsToPrint.push_back(stars->getElementFromPosition(i));
		found = star.getDeclination().find(matchText);
		if (found != std::string::npos)
			starsToPrint.push_back(stars->getElementFromPosition(i));
		found = std::to_string(star.getDiameter()).find(matchText);
		if (found != std::string::npos)
			starsToPrint.push_back(stars->getElementFromPosition(i));
	}
	ui.listWidget->clear();
	for (auto star : starsToPrint)
		ui.listWidget->addItem(QString::fromStdString(star.toStr()));
}
void QtGuiApplication1::addStar() {
	try {
		std::string name = ui.nameLine->text().toStdString();
		if (name == "")
			throw std::exception("No name!");
		std::string RA = ui.RALine->text().toStdString();
		if (RA == "")
			throw std::exception("No right ascension!");
		std::string declination = ui.declinationLine->text().toStdString();
		if (declination == "")
			throw std::exception("No declination!");
		if (ui.diameterLine->text().toStdString() == "")
			throw std::exception("No diameter!");
		double diameter = atof(ui.diameterLine->text().toStdString().c_str());
		if (diameter == 0)
			throw std::exception("Diameter is not a number!");
		std::string location = ui.imageLine->text().toStdString();
		if (location == "")
			throw std::exception("No location!");
		Star* starToAdd = new Star(name, astronomer.getConstellation(), RA, declination, diameter,location);
		stars->add(*starToAdd);
		stars->notify();
		ui.nameLine->clear();
		ui.RALine->clear();
		ui.declinationLine->clear();
		ui.diameterLine->clear();
		delete starToAdd;
	}
	catch (std::exception& e) {
		QErrorMessage* box = new QErrorMessage{};
		box->showMessage(e.what());
	}
}
void QtGuiApplication1::displayData() {
	ui.starList->clear(); if (ui.checkBox->isChecked()) {
		ui.starList->clear();
		std::vector<Star> starsToDisplay;
		for (int i = 0; i < stars->size(); i++)
			if (stars->getElementFromPosition(i).getConstellation() == astronomer.getConstellation())
				starsToDisplay.push_back(stars->getElementFromPosition(i));
		for (auto starToDisplay : starsToDisplay)
			ui.starList->addItem(QString::fromStdString(starToDisplay.toStr()));
	}
	else
		for (int i = 0; i < stars->size(); i++) {
			Star starToDisplay = stars->getElementFromPosition(i);
			ui.starList->addItem(QString::fromStdString(starToDisplay.toStr()));
		}
}
