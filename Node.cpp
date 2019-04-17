#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node() : next(nullptr) {} // remember to initialize next to nullptr

// Parameterized constructor
//Creates TemperatureData instance with Data Entry and
//equals it to the TemperatureData instance in TemperatureData.h
Node::Node(string id, int year, int month, double temperature) : next(nullptr) {
	TemperatureData td(id, year, month, temperature);
	data = td;
} // remember to initialize next to nullptr

//Called from overloaded operator in LinkedList insert function
//which then calls the overloaded operator method in the TemperatureData class
bool Node::operator<(const Node& b) {
	return this->data < b.data;
}
