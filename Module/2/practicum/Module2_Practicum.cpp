#include <iostream>
using namespace std;

// Program Title: Doubly Linked List Implementation
// This program demonstrates how to insert nodes at the beginning of a doubly linked list
// and traverse the list in both forward (head-to-tail) and backward (tail-to-head) directions.

struct Node 
{
    int data;            // Data for the node
    Node* next;          // Pointer to the next node in the list
    Node* prev;          // Pointer to the previous node in the list
};

int main() 
{
    Node *temp, *head = NULL, *tail = NULL, *newNode;
    int inputData;
    char userChoice;

    cout << "===== Doubly Linked List Insertion and Traversal Program =====\n";

    do 
	{
        // Get user input for the data to insert
        cout << "Enter data: "; 
        cin >> inputData;

        // Create a new node and assign the input data
        newNode = new Node;
        newNode->data = inputData;
        newNode->next = NULL;
        newNode->prev = NULL;

        // If the list is empty, set the new node as both the head and tail
        if (head == NULL) 
		{
            head = newNode;
            tail = newNode;
        }
        else 
		{
            // Add the new node at the beginning of the list
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        // Ask the user if they want to add another node
        cout << "Do you want to add more data? (Press y/Y to continue, any other key to stop): "; 
        cin >> userChoice;
    }
    while (userChoice == 'y' || userChoice == 'Y');

    // Traverse the list from head to tail and print the data
    cout << "Data from head to tail: ";
    temp = head;

    while (temp != NULL) 
	{
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Traverse the list from tail to head and print the data
    cout << "Data from tail to head: ";
    temp = tail;
	
    while (temp != NULL) 
	{
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;

    return 0;
}
