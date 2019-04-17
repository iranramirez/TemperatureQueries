#include "TemperatureDatabase.h"
#include "TemperatureData.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

int TemperatureDatabase::countEntries(std::string entry) {
	int count = 0;

	for(int i = 0; i < entry.length(); i++){
		if(entry[i] == ' ') {
			count++;
		}
	}
	return count;
}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	
	string id = "";
	string line = "";
	int year = 0;
	int month = 0;;
	double temperature = 0;


	ifstream dataFile;
	dataFile.open(filename);

	if (!dataFile.is_open()) {
		cout << "Unable to open " << filename << ".dat" << endl;
		exit(1);
	}

	while (getline(dataFile,line)) {
		//Read everything as string and convert each one to specified data type
		stringstream stream(line);
		int count = 0;
	
		count = countEntries(line);

		if (count != 3) {
			cout << "Error: Other invalid input" << endl;
			cout << "Hey entry" << endl;
			continue;
		}

		stream >> id;
		stream >> year;
		if (stream.fail()) {
			cout << "Error: Other invalid input" << endl;
			exit(1);
		}

		 stream >> month;
		 if (stream.fail()) {
			cout << "Error: Other invalid input" << endl;
			cout << "Hey month" << endl;
			exit(1);
		}

		 stream >> temperature;
		 if (stream.fail()) {
			cout << "Error: Other invalid input" << endl;
			exit(1);
		}


		if(temperature == -99.99)
			continue;

		if (temperature < -50 || temperature > 50) {
			cout << "Error: Invalid temperature " << temperature << endl;
			continue;
		}


		if (year > 2018 || year < 1800) {
			cout << "Error: Invalid year " << year << endl;
			continue;
		}


		if (month <= 0 || month > 12) {
			cout << "Error: Invalid month " << month << endl;
			continue;
		}


		records.insert(id, year, month, temperature);
	}


}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
}
