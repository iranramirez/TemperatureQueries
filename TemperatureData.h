//GIVEN CODE
/*
#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA

struct TemperatureData {
	// Put data members here
	TemperatureData();
	TemperatureData(std::string id, int year, int month, double temperature);
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b);
};

#endif /* TEMPERATUREDATA */

#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA
#include <string>

struct TemperatureData {
	std::string id;
	int year, month;
	double temperature;

	// Put data members here
	TemperatureData();
	TemperatureData(std::string id, int year, int month, double temperature);
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b);
};

#endif /* TEMPERATUREDATA */
