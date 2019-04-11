//GIVEN CODE
/*
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() {
	// Implement this function
}

LinkedList::~LinkedList() {
	// Implement this function
}

LinkedList::LinkedList(const LinkedList& source) {
	// Implement this function
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
}

void LinkedList::clear() {
	// Implement this function
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
}

string LinkedList::print() const {
	string outputString;
	// Implement this function
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	//Do not modify this function 
	os << ll.print();
	return os;
} */

#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
	// Implement this function
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList() {
	// Implement this function
	clear();
}

LinkedList::LinkedList(const LinkedList& source) {
	// Implement this function
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	static LinkedList temp; // Need fix... temp line
	return temp; // Need fix... temp line
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function

	Node* curr = new Node(location, year, month, temperature);
	Node* temp = head;

	if (head == nullptr && tail == nullptr) {
		head = curr;
		tail = curr;
		return;
	}

	// if less than temp less than curr, insert cu
	else if (curr < temp) {


	}
	
	//insert at head
	else {


	}

	//while lop
	


}	

void LinkedList::clear() {
	// Implement this function
	Node* temp;

	while (head != nullptr) {

		temp = head->next;
		delete head;
		head = temp;

	}

	head = nullptr;
	tail = nullptr;
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return head; 
}

string LinkedList::print() const {
	string outputString;
	// Implement this function
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
