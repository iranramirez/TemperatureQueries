//GIVEN CODE
/*
#include "TemperatureData.h"
using namespace std;

TemperatureData::TemperatureData() {} //initialize everything

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature) {} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	// Implement this
} */

#include "TemperatureData.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TemperatureData::TemperatureData() {} //initialize everything

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature) {
	this->id = id;
	this->year = year;
	this->month = month;
	this->temperature = temperature;

} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	// Implement this
	return true;
}


