#include "LinkedList.h"
#include <iostream>

void LinkedList::addAtEnd(int value) {
	
	Node* node1 = new Node();
	node1->Data = value;

	node1->Next = nullptr;
	node1->Prev = nullptr;
	
	if (Head == nullptr) {
		Head = node1;
		Tail = Head;
	}
	else {
		node1->Prev = Tail;
		Tail->Next = node1;
		Tail = node1;
	}
}

void LinkedList::findDuplicate() {
}

void LinkedList::remove(int index) {

	Node* del = Head;
	
	for (int i = 0; i <= index; i++) {

		del = del->Next;
	}

	
	
}

void LinkedList::insertAt(int dataValue, int index) {
	Node* temp = Head;

	for (int i = 0; i <= index; i++) {
		temp = temp->Next;
	}
	
	temp->Data = dataValue;
}

int LinkedList::amountOfElements() {
	Node* temp = Head;

	int count = 0;
	
	while (temp != nullptr) {
		temp = temp->Next;
		count += 1;
	}
	return count;
}


void LinkedList::printHeadToTail() {
	Node* printPtr = Head;

	while (printPtr != nullptr) {
		std::cout << printPtr->Data << std::endl;
		
		printPtr = printPtr->Next;
	}
}

void LinkedList::printTailToHead() {
	for (int i = 0; i < 10; i++) {
		std::cout << std::endl;
	}
}

