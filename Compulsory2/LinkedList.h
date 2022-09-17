#pragma once
#include <iterator>

class Node {
public:
	int Data;
	Node* Next;
	Node* Prev;
	
	Node() {
		Data = 0;
		Next = nullptr;
		Prev = nullptr;
	}
	
	
};
	
class LinkedList{
public:
	Node* Head;
	Node* Tail;
	friend Node; // Gives full access to named class

	LinkedList() {
		Head = nullptr;
		Tail = nullptr;
		Head = Tail;
	}
	void addAtEnd(int value);
	
	void findDuplicate();

	void remove(int index);

	void insertAt(int dataValue, int index);

	int amountOfElements();

	void printHeadToTail();

	void printTailToHead();
};



