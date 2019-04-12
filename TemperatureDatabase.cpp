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

		//Read everything as string and convert each one to specified data type
		dataFile >> id;
		dataFile >> year;
		if (dataFile.fail()) {
			cout << "Error: Other invalid input" << endl;
			dataFile.clear();
			exit(1);
		}
	
		dataFile >> month;
		if (dataFile.fail()) {
			cout << "Error: Other invalid input" << endl;
			dataFile.clear();
			exit(1);
		}

		dataFile >> temperature;
		if (dataFile.fail()) {
			cout << "Error: Other invalid input" << endl;
			dataFile.clear();
			exit(1);
		}

		if (temperature < -50 || temperature > 50) {
			cout << "Error: Invalid temperature " << temperature << endl;
		}


		if (year > 2018 || year < 1800) {
			cout << "Error: Invalid year " << year << endl;
		}


		if (month <= 0 || month > 12) {
			cout << "Error: Invalid month " << month << endl;
		}


		records.insert(id, year, month, temperature);
	}


}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
}
