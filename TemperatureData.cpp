#include "TemperatureData.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TemperatureData::TemperatureData() {
	id = "";
	year = 1800;
	month = 1;
	temperature = 0;

} //initialize everything

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature) {
	this->id = id;
	this->year = year;
	this->month = month;
	this->temperature = temperature;

} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	// Implement this

	if (this->id != b.id)
		return this->id < b.id;

	if (this->year != b.year)
		return this->year < b.year;
	
	if (this->month != b.month)
		return this->month < b.month;

	return this->temperature < b.temperature;

}

