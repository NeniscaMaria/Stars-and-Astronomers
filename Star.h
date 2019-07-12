#pragma once
#include <vector>
class Star {
private:
	std::string name;
	std::string constellation;
	std::string rightAscension;
	std::string declination;
	double diameter;
	std::string image;
public:
	std::string getName() {
		return name;
	}
	std::string getConstellation() {
		return constellation;
	}
	std::string getRighAscension() {
		return rightAscension;
	}
	std::string getDeclination() {
		return declination;
	}
	double getDiameter() {
		return diameter;
	}
	std::string getImage() {
		return image;
	}
	std::string toStr() {
		std::string result = name + "," + constellation + "," + rightAscension + "," + declination + "," + std::to_string(diameter);
		return result;
	}
	Star() {}
	Star(std::string nameFromUser, std::string constellationFromUser, std::string RAFromUser, std::string deFromUSer, double diameterFromUser,std::string locationFromUSer) {
		name = nameFromUser;
		constellation = constellationFromUser;
		rightAscension = RAFromUser;
		declination = deFromUSer;
		diameter = diameterFromUser;
		image = locationFromUSer;
	}
	~Star() {};
	friend std::ostream& operator<<(std::ostream& os, Star star) {
		os << star.name << "," << star.constellation << "," << star.rightAscension << "," << star.declination << "," << star.diameter << "," << star.image << "\n";
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Star* star) {
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
		if (tokens.size() != 6)
			return is;
		std::string nameFromFile = tokens[0];
		star->name = nameFromFile;
		std::string constFromFile = tokens[1];
		star->constellation = constFromFile;
		std::string RA = tokens[2];
		star->rightAscension = RA;
		std::string decFromFile = tokens[3];
		star->declination = decFromFile;
		double diameterFromFile = atof(tokens[4]);
		star->diameter = diameterFromFile;
		std::string image = tokens[5];
		star->image = image;
		return is;
	}
};