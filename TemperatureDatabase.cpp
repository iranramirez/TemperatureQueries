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

/*Loads data from file using filestream, stringstream, and getline
  Does all error checking for file and each data type
  After error checking creates a LinkedList called records*/
void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	string id = "", line = "";
	int year = 0, month = 0;
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
		
		stream >> id >> year >> month >> temperature;
		if (stream.fail()) {
			cout << "Error: Other invalid input" << endl;
			continue;
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

/*Loads queries from file using filestream, stringstream, and getline
  Does all error checking for file and each data type
  After error checking does either Average or Mode Calculation for City and Year Range
  Calculations are then written into an output file*/
void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
	string id = "", calc = "", line = "";
	int year = 0, yearTwo = 0, mode = 0;
	double avg = 0;
	ifstream dataFile;
	ofstream outputFile;
	
	dataFile.open(filename);
	outputFile.open("result.dat");

	if (!dataFile.is_open()) {
		cout << "Unable to open " << filename << ".dat" << endl;
		exit(1);
	}
	while (getline(dataFile,line)) {
		//Read everything as string and convert each one to specified data type
		stringstream stream(line);
		
		stream >> id >> calc >> year >> yearTwo;
		if (stream.fail())
			cout << "Error: Other invalid query" << endl;

		else if (calc != "AVG" && calc != "MODE") 
			cout << "Error: Unsupported query " << calc << endl;

		else if (year > 2018 || year < 1800) 
			cout << "Error: Invalid range " << year << "-" << yearTwo << endl;

		else if (yearTwo > 2018 || yearTwo < 1800) 
			cout << "Error: Invalid range " << year << "-" << yearTwo << endl;

		else if (year > yearTwo) 
			cout << "Error: Invalid range " << year << "-" << yearTwo << endl;
		//Don't forget to add the unknown condition... you deleted try and catch
		else {
				if (calc == "AVG") {
					avg = records.average(id, year, yearTwo);
					if (avg == -99.99) {
						outputFile << id << " " << year << " " << yearTwo << " " << calc << " ";
						outputFile << "unknown" << endl;
					}
					else {
						outputFile << id << " " << year << " " << yearTwo << " " << calc << " ";
						outputFile << avg << endl;
					}
				}
				else {
					mode = records.mode(id, year, yearTwo);
					if (mode == -99) {
						outputFile << id << " " << year << " " << yearTwo << " " << calc << " ";
						outputFile << "unknown" << endl;
					}
					else {
						outputFile << id << " " << year << " " << yearTwo << " " << calc << " ";
						outputFile << mode << endl;
					}
				}
		}	
	}
}
