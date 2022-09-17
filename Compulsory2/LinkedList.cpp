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

	free(del);
	
}

void LinkedList::insertAt(int dataValue, int index) {
	Node* temp = Head;

	Node* node1 = new Node();
	node1->Data = dataValue;

	Node* NextNode = temp->Next;
	
	// Move temp to correct position
	for (int i = 0; i <= index; i++) {
		temp = temp->Next;
	}

	// Sara gave huge help!
	// Two pointers that point to the nodes that surround the node
	// temp is currently pointing to
	Node* PrevNode = temp->Prev;

	
	//node1->Next = NextNode;
	node1->Next = temp;
	temp->Prev= node1;

	node1->Prev = PrevNode;
	PrevNode->Next = node1;

	//node1 = temp;
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

	std::cout << "Print from Head to Tail" << std::endl;
	
	while (printPtr != nullptr) {
		std::cout << printPtr->Data << std::endl;
		
		printPtr = printPtr->Next;
	}
}

void LinkedList::printTailToHead() {
	Node * printPtr = Tail;

	std::cout << "Print from Tail to Head" << std::endl;
	
	while (printPtr != nullptr) {

		std::cout << printPtr->Data << std::endl;
		printPtr = printPtr->Prev;
	}
}

