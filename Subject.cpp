#include "Subject.h"
#include "Observer.h"
void Subject::registerObserver(Observer* o)
{
	this->observers.push_back(o);
}


void Subject::notify()
{
	for (auto obs : observers)
	{
		obs->update();
	}
}
