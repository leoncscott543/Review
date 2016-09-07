#include <cstdlib>
#include <stdafx.h>
#include <iostream> // need input and outputs

#include "List.h" // we need to reference the header file we created

using namespace std; // we need standard namespace

List::List(){
	// we define our List() constructor
	// we set all private pointers to NULL by default
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void List::AddNode(int addData){
	// define AddNode function

	nodePtr n = new node; // we create a node pointer called (n)
	n->next = NULL; // we set this up to be the last node in the list
	// find the node that n is pointing to, acess its next element, and make that point to Nothing
	n->data = addData;
	// add data to n

	if (head != NULL){ // if the head isnt equal to NULL (aka if its not the end)
		curr = head;
		// make the current pointer point to the same thing the header is pointed to

		while (curr->next != NULL) {
			// while we're not at the end of the list
			curr = curr->next; // it will keep advancing the loopd
		}
		curr->next = n; // the next element points to the new element we created above
	}
	else
	{
		head = n; // if we dont have a list, we'll just make n = to the front
	}

}

void List::DeleteNode(int delData){
	nodePtr delPtr = NULL;
	// nodePtr is the same thing as node*

	temp = head; // set temperary pointer to the head
	curr = head; // set the current pointer to the head
	// we'll have the temperary pointer one step behind the current pointer just in case

	while (curr != NULL && curr->data != delData){
		// end loop if we passed through entire list or until we found the node that has the data we want to delete
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL){
	// when the while loop ends, if the curr still equals NULL, we haven not found the data to delete
		cout << delData << "was not in the list\n";
	}
	
	else{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if (delPtr == head)
			// if deletion pointer is pointing to the front of the list
		{
			head = head->next;
			temp = NULL;
		}
		delete delPtr; // this deletes the node
		cout << "The value " << delData << " was deleted\n";
	}
}

void List::PrintList(){
	curr = head;
	while (curr != NULL)
	// as long as we are not at the last node,
	// print out each node and keep advancing it
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
}