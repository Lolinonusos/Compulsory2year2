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
	
	// Index is less than zero
	if (index < 0) {
		std::cout << "Indexes below 0 does not exist." << std::endl;
		return;
	}

	// Index 0 is the head
	// Delete Head node
	if (index == 0) {
		Head = del->Next;
		Head->Prev = nullptr;
		
		free(del);
		return;
	}
	else {
		// Find node to remove
		for (int i = 0; i <= index - 1; i++) {
			del = del->Next;
			if (del->Next == nullptr) {
				std::cout << "Index is out of bounds." << std::endl;
				return;
			}
		}

		// Create two pointers that point to the nodes surrounding the
		// node del is currently pointing to
		Node* NextNode = del->Next;
		Node* PrevNode = del->Prev;

		// Connect surrounding nodes
		NextNode->Prev = PrevNode;
		PrevNode->Next = NextNode;

		// Removes the node del points to and frees up the memory
		free(del);
		return;
	}
}


void LinkedList::insertAt(int dataValue, int index) {
	Node* temp = Head;

	Node* node1 = new Node();
	node1->Data = dataValue;
	
	// Move temp to correct position
	for (int i = 0; i <= index; i++) {
		temp = temp->Next;
	}

	// Sara gave huge help!
	// A pointer that points to the node which is previous to the one
	// temp points to
	Node* PrevNode = temp->Prev;

	// Connects new node with the node temp points to
	node1->Next = temp;
	temp->Prev= node1;

	// Connects the new node with the node PrevNode points to
	node1->Prev = PrevNode;
	PrevNode->Next = node1;
	
}


void LinkedList::sortedInsert(Node* HeadRef, Node* newNode) {

	Node* current;

	if (HeadRef == nullptr) {
		HeadRef = newNode;
	}
	
	else if (HeadRef->Data >= newNode->Data) {
		newNode->Next = HeadRef;
		newNode->Next->Prev = newNode;
		HeadRef = newNode;
	}

	else {
		current = HeadRef;
		while(current->Next != nullptr && current->Next->Data < newNode->Data) {
			current = current->Next;
		}
	}

	newNode->Next = current->Next;

	if (current->Next != nullptr) {
		newNode->Next->Prev = newNode;
	}
	current->Next = newNode;
	newNode->Prev = current;
	
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
