#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
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
	Node* tempPrev = nullptr;

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

	tempPrev = temp;
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
	Node* temp = head->next;
	string curr;
	
	curr = manip(head);
	
	outputString = head->data.id + " " + to_string(head->data.year) + " " + to_string(head->data.month) + " " + curr + "\n";
	while(temp != nullptr){
		
	    curr = manip(temp);

		outputString += temp->data.id + " " + to_string(temp->data.year) + " " + to_string(temp->data.month) + " " + curr + "\n";
		temp = temp->next;

	}

	return outputString;
}

string LinkedList::manip(Node* node) const {

	stringstream ss;
	string curr;
	int numTemp = 0;

	ss << fixed << setprecision(1) << node->data.temperature;
	curr = ss.str();

	for(int i = 0; i < curr.length(); i++) {
        if(curr[i] == '.'){
            if(curr[i + 1] == '0'){
                numTemp = stoi(curr);
                ss.str("");
                ss.clear();
                ss << numTemp;
            }
            else
                break;
            
        }
    }

    return ss.str();

}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
