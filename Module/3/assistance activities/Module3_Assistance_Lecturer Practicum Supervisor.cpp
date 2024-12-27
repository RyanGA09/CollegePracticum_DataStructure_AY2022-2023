#include <iostream>
#include <string>
using namespace std;

// Program Title: Queue System for Counters
// This program simulates a queue system where customers are assigned to counters.

struct QueueNode
{
    string customerName;
    int queueNumber, counterNumber;
    QueueNode *next;
    QueueNode *prev;
};

QueueNode customer;
QueueNode *firstQueue = NULL, *lastQueue = NULL, *newNode, *tempNode;
int addQueue, queueCompleted, continueQueue;

int main()
{
    cout << "===== Queue System for Counters =====\n";

    do
    {
        cout << "Available Counters (Counter 1 and 2)\n";
        cout << "Customer Name: "; getline(cin, customer.customerName);
        cout << "Queue Number: "; cin >> customer.queueNumber;
        cout << "Counter Number: "; cin >> customer.counterNumber;

        // Displaying message based on counter number
        switch (customer.counterNumber)
        {
        case 1:
            cout << "Queue Number " << customer.queueNumber << " Please proceed to Counter 1\n";
            break;
        case 2:
            cout << "Queue Number " << customer.queueNumber << " Please proceed to Counter 2\n";
            break;
        }

        // Add the customer to the queue
        newNode = new QueueNode;
        newNode->customerName = customer.customerName;
        newNode->queueNumber = customer.queueNumber;
        newNode->counterNumber = customer.counterNumber;
        newNode->next = NULL;
        newNode->prev = NULL;

        // If the queue is empty, the new node becomes both the first and last node
        if (lastQueue == NULL)
        {
            firstQueue = newNode;
            lastQueue = newNode;
        }
        else
        {
            // Add the new node at the end of the queue
            newNode->prev = lastQueue;
            lastQueue->next = newNode;
            lastQueue = newNode;
        }

        cout << "Add another customer to the queue (press 1): "; cin >> addQueue;
        cin.ignore();
    }
    while (addQueue == 1);

    // Display the entire queue
    tempNode = firstQueue;
    while (tempNode != NULL)
    {
        cout << "Customer Name: " << tempNode->customerName << endl;
        cout << "Queue Number: " << tempNode->queueNumber << endl;
        cout << "Counter Number: " << tempNode->counterNumber << endl;
        tempNode = tempNode->next;
    }

    cout << "\n";
    cout << "Queue completed\n";
    cout << "Has the customer been served? (Press 1): "; cin >> queueCompleted;

    if (queueCompleted == 1)
    {
        do
        {
            system("cls");

            // If there's only one customer left in the queue, reset the queue
            if (firstQueue == lastQueue)
            {
                cout << "Queue is empty\n";
                firstQueue = NULL;
                lastQueue = NULL;
            }
            else
            {
                // Remove the first customer from the queue
                tempNode = firstQueue->next;
                tempNode->prev = NULL;
                firstQueue = tempNode;
            }

            // Display the remaining queue
            tempNode = firstQueue;
            while (tempNode != NULL)
            {
                cout << "Customer Name: " << tempNode->customerName << endl;
                cout << "Queue Number: " << tempNode->queueNumber << endl;
                cout << "Counter Number: " << tempNode->counterNumber << endl;
                tempNode = tempNode->next;
            }

            cout << "Proceed with the next customer in the queue (press 1): "; cin >> continueQueue;
        } 
		while (continueQueue == 1);

        cout << "\n";
        system("cls");

        cout << "Program Finished\n";
    }

    return 0;
}
