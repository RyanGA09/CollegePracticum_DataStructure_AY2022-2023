#include <iostream>
using namespace std;

// Define the structure for a doubly linked list node
struct Node 
{
    int data;            // Data of the node
    Node* next;          // Pointer to the next node
    Node* prev;          // Pointer to the previous node
};

int main() 
{
    Node* temp, *head = NULL, *tail = NULL, *newNode;
    int inputData;
    char userChoice;

	cout << "===== Doubly Linked List Insertion and Traversal Program =====\n";

    do 
	{
        // Input data for the new node
        cout << "Enter data: "; 
        cin >> inputData;

        // Allocate memory for the new node
        newNode = new Node;
        newNode->data = inputData;
        newNode->next = NULL;
        newNode->prev = NULL;

        // If the list is empty, the new node is both head and tail
        if (head == NULL) 
		{
            head = newNode;
            tail = newNode;
        }
        else 
		{
            // Insert the new node at the beginning of the list
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        // Ask if the user wants to continue adding data
        cout << "Do you want to add more data? (Press y/Y to continue, any other key to stop): "; 
        cin >> userChoice;
    }
    while (userChoice == 'y' || userChoice == 'Y');

    // Traverse and print the list from head to tail
    cout << "Data from head to tail: ";
    temp = head;
    while (temp != NULL) 
	{
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Traverse and print the list from tail to head
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
