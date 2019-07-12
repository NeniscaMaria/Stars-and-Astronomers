#include "QtGuiApplication1.h"
#include <QtWidgets/QApplication>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//to do:
	//show stars on a map
	Repository<Star>* stars=new Repository<Star>{ "stars.txt" };
	Repository<Astronomer>* astronomers=new Repository<Astronomer>{ "astronomers.txt" };
	stars->readFromFile();
	astronomers->readFromFile();
	std::vector<QtGuiApplication1*> windows;
	for (int i= 0; i < astronomers->size(); i++) {
		QtGuiApplication1* window = new QtGuiApplication1{ stars,astronomers,astronomers->getElementFromPosition(i) };
		windows.push_back(window);
		//stars->registerObserver(window);
	}
	for (auto window:windows) {
		window->show();
	}
	//_CrtDumpMemoryLeaks();
	return a.exec();
}
