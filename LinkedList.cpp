#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

//When no parameters are put into our LinkedList constructor
//default constructor initializes empty LinkedList
LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
	// Implement this function
}

//Deconstructor that clears our LinkedList
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

//Inserts Node into linked list in order by id, year, month, then temperature
//Creates first node(head), inserts at front of linked list, in between Nodes, and
//at tail if need be
void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
	Node* curr = new Node(location, year, month, temperature);
	Node* temp = head;
	Node* tempPrev = head;

	if (head == nullptr && tail == nullptr) {
		head = curr;
		tail = curr;
		return;
	} 
	if (*curr < *temp) {
		curr->next = temp;
		head = curr;
		return;
	}
	temp = temp->next;
	while (temp != nullptr) {
		if (*curr < *temp) {
			tempPrev->next = curr;
			curr->next = temp;
			return;
		}
		tempPrev = temp;
		temp = temp->next;
	}
	tail = curr;
	tempPrev->next = curr;
}	

//Traverses Linked List, deletes head, keeps on making next node the head
//and keeps deleting head until nullptr is reached. Then makes sure empty list
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

//Returns head address
Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return head; 
}

//Prints LinkedList in order by printing out head node then traversing through
//linked list and prints data in each node until nullptr is reached
string LinkedList::print() const {
	string outputString = "", curr = "";
	// Implement this function
	Node* temp = head->next;
	
	curr = manip(head);
	outputString = head->data.id + " " + to_string(head->data.year);
	outputString += " " + to_string(head->data.month) + " " + curr + "\n";
	while(temp != nullptr){
	    curr = manip(temp);
		outputString += temp->data.id + " " + to_string(temp->data.year);
		outputString += " " + to_string(temp->data.month) + " " + curr + "\n";
		temp = temp->next;
	}
	return outputString;
}

//Manipulates the printed temperature in print method
string LinkedList::manip(Node* node) const {
	stringstream ss;
    double temp = 0;
    int dtoi = node->data.temperature;
    
    temp = (node->data.temperature) - dtoi;
    if(temp == 0)
        ss << dtoi;
    else
        ss << fixed << setprecision(1) << node->data.temperature;
    return ss.str();
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
