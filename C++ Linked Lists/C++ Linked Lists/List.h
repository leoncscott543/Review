
#ifndef LIST_H
#define LIST_H
// putting the interface for the class

class List{
private:
// All of the parts that can only be accessed by the functinons that we define later

	typedef struct node{ // this will allow me to type in nodePtr in replace of (node*)
		int data; // this is the value that is stored in the node
		node* next; // this points to the next noe in the list
	}* nodePtr;

	
	

	nodePtr head; // nodePtr means node pointer
	nodePtr curr; // current node pointer
	nodePtr temp; // temperary node pointer 
	
public: // This is where the functions go. Public section will go inside of private section
		// these are where functions prototypes will be

	List(); // this lets the rest of the program know that we are going to set initial values
	void AddNode(int addData); // Adds a new node and puts data in it
	void DeleteNode(int delData); 
	// Deletes a node. Whatever the data we pass into delData the function will look for and deletes the node
	void PrintList(); // this prints the list
};


#endif