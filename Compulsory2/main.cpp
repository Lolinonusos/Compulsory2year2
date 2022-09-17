#include <iostream>
#include <ctime> 

#include "LinkedList.h"

/*
Task 2: 
In this task you need to create a doubly linked list with the following instructions and functionalities.
You create a Static array and populate the array with 40 random numbers.

You need to add a new value into the middle of the array. In order to do that you will need to transfer 
the values to a linked list, instead of an array which we have done in compulsory 1.

After adding the new value to the array and transferring data to a linked list, you will need to sort the 
linked list and remove duplicate numbers in the list.

Then print the entire linked list from the head to 
tail and once more from tail to head. 

Add at the end of list - completed
Remove
Insert at - completed
Sort
Print/ return number of elements in list
Print from head to tail - completed
Print from tail to head

-Optional-
Pop function (which every time this function is called one item from the end of the list is 
removed) 
Add to head (add to the beginning of the list) 
*/

static int arrey[40];

int main() {

	LinkedList Blendre;
	
	int size = sizeof(arrey)/sizeof(arrey[0]);

	std::srand(time(0));
	
	for (int i = 0; i < size; i++) {
		Blendre.addAtEnd(arrey[i] = rand() % 101);
		//std::cout << arrey[i] << std::endl;
	}
	//std::cout << std::endl;
	std::cout << "Found " << Blendre.amountOfElements() << " elements" << std::endl;

	Blendre.insertAt(666, 13);

	Blendre.printHeadToTail();

}