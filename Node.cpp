//Given CODE
/*
#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node() {} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature) {}
// remember to initialize next to nullptr

bool Node::operator<(const Node& b) {
	return this->data < b.data;
} */

#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node() {} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature) {

	TemperatureData td(id, year, month, temperature);
	data = td;
	next = nullptr;

}
// remember to initialize next to nullptr

bool Node::operator<(const Node& b) {
	return this->data < b.data;
}

