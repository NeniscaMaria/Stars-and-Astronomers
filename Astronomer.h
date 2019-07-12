#pragma once
#include <vector>
class Astronomer {
private:
	std::string name;
	std::string constellationStudied;
public:
	std::string getName() {
		return name;
	}
	std::string getConstellation() {
		return constellationStudied;
	}
	Astronomer() {};
	Astronomer(std::string nameFromUser, std::string constellationFromUser) {
		name = nameFromUser;
		constellationStudied = constellationFromUser;
	}
	~Astronomer() {};
	friend std::ostream& operator<<(std::ostream& os, Astronomer astronomer) {
		os <<astronomer.name<<","<<astronomer.constellationStudied<< "\n";
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Astronomer* astronomer) {
		std::string line;
		getline(is, line);
		char array[512];
		strcpy(array, line.c_str());
		std::vector<char*> tokens;
		char* token = strtok(array, ",");
		while (token != NULL) {
			tokens.push_back(token);
			token = strtok(NULL, ",");
		}
		if (tokens.size() != 2)
			return is;
		std::string nameFromFile = tokens[0];
		astronomer->name = nameFromFile;
		std::string constFromFile = tokens[1];
		astronomer->constellationStudied = constFromFile;
		return is;
	}
};