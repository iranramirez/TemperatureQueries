// CODE GIVEN
/*#include "TemperatureDatabase.h"

#include <fstream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
} */

#include "TemperatureDatabase.h"
#include "TemperatureData.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	
	string id;
	int year, month;
	double temperature;

	ifstream dataFile;
	dataFile.open(filename);

	if (!dataFile.is_open()) {
		cout << "Unable to open " << filename << ".dat" << endl;
		exit(1);
	}

	while (!dataFile.eof()) {

		dataFile >> id;
		dataFile >> year;
		if (!dataFile.good()) {
			cout << "Error: Other invalid input" << endl;
			exit(1);
		}
		dataFile >> month;
		if (!dataFile.good()) {
			cout << "Error: Other invalid input" << endl;
			exit(1);
		}
		dataFile >> temperature;
		if (!dataFile.good()) {
			cout << "Error: Other invalid input" << endl;
			exit(1);
		}

		if (temperature < -50 && temperature > 50) {
			cout << "Invalid temperature " << temperature << endl;
			exit(1);
		}

		if (year > 2019) {
			cout << "Invalid year " << year << endl;
			exit(1);
		}

		if (month <= 0) {
			cout << "Invalid month " << month < endl;
			exit(1);
		}

		records.insert(id, year, month, temperature);
	}


}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
}
