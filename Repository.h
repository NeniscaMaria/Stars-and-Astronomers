#pragma once
#include <vector>
#include <fstream>
#include "Subject.h"
template <typename Type>
class Repository : public Subject{
private:
	std::vector<Type> elements;
	std::string fileName;
public:
	Repository(std::string fileNameFromUser) {
		fileName = fileNameFromUser;
	}
	int size() {
		return elements.size();
	}
	Type getElementFromPosition(int position) {
		if (position >= elements.size())
			throw std::exception("Invalid position");
		return elements[position];
	}
	void add(Type a) {
		elements.push_back(a);
		std::ofstream file;
		file.open(fileName);
		if (!file.is_open())
			return;
		for (auto el : elements)
			file << el;
		file.close();
	}
	void readFromFile() {
		std::ifstream file;
		file.open(fileName);
		if (!file.is_open())
			return;
		Type* element = new Type{};
		while (file >> element) {
			elements.push_back(*element);
		}
		file.close();
		delete element;
	}
};