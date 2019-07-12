#pragma once
#include <vector>
class Observer;
class Subject {
public:
	std::vector<Observer*> observers;
public:
	Subject() {};
	~Subject() {};
	void registerObserver(Observer*);
	void notify();
};