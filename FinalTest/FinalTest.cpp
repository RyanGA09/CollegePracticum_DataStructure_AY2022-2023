#include <iostream>
using namespace std;

struct Node {
    string name, toy, date;
    int price;
    Node* next;
    Node* prev;
};

Node data;
Node* head = NULL, * tail = NULL, * newNode, * helper, * helper1;
int addMore, repeatProcess, deleteMore, choice;

void swap(Node* first, Node* second) {
    string temp = first->name;
    first->name = second->name;
    second->name = temp;
}

void insertionSort() {
    Node* current = head;
    Node* temp = NULL;
    while (current != NULL) {
        temp = current->next;
        while (temp != NULL && temp->prev != NULL && temp->name < temp->prev->name) {
            swap(temp, temp->prev);
            temp = temp->prev;
        }
        current = current->next;
    }
}

void displaySorted() {
    int count = 1;
    helper = head;
    while (helper != NULL) {
        cout << count << ". Name after sorting: " << helper->name << endl;
        helper = helper->next;
        count++;
    }
}

void linearSearch() {
    string searchName;
    int position = 1, found = 0;
    cout << "Enter the buyer's name to search: ";
    getline(cin, searchName);
    helper1 = head;
    while (helper1 != NULL) {
        if (helper1->name != searchName) {
            helper1 = helper1->next;
            position++;
        } else {
            found = 1;
            break;
        }
    }
    if (found == 1) {
        cout << "Buyer found at node " << position << endl;
        cout << "Name: " << helper1->name << endl;
        cout << "Transaction Date: " << helper1->date << endl;
        cout << "Toy: " << helper1->toy << endl;
        cout << "Toy Price: Rp." << helper1->price << endl;
    } else {
        cout << "Buyer not found!" << endl;
    }
}

int main() {
    cout << "==============================\n";
    cout << "    Toy Purchase Management System\n";
    cout << "==============================\n";

    do {
        cout << "Menu\n1. Add Data\n2. Sort Data\n3. Search Data\n4. Delete Data\n";
        cout << "Enter your choice: "; cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                do {
                    cout << "Buyer's Name: "; getline(cin, data.name);
                    cout << "Transaction Date: "; getline(cin, data.date);
                    cout << "Toy Name: "; getline(cin, data.toy);
                    cout << "Toy Price: Rp."; cin >> data.price;
                    cin.ignore();

                    newNode = new Node;
                    newNode->name = data.name;
                    newNode->date = data.date;
                    newNode->toy = data.toy;
                    newNode->price = data.price;
                    newNode->next = NULL;
                    newNode->prev = NULL;

                    if (tail == NULL) {
                        head = newNode;
                        tail = newNode;
                    } else {
                        newNode->prev = tail;
                        tail->next = newNode;
                        tail = newNode;
                    }

                    cout << "Add more data? (Press 1): "; cin >> addMore;
                    cin.ignore();
                } while (addMore == 1);

                helper = head;
                while (helper != NULL) {
                    cout << "Buyer's Name: " << helper->name << endl;
                    cout << "Transaction Date: " << helper->date << endl;
                    cout << "Toy: " << helper->toy << endl;
                    cout << "Toy Price: Rp." << helper->price << endl;
                    helper = helper->next;
                }
                break;

            case 2:
                cout << "\nSorting Data\n";
                insertionSort();
                displaySorted();
                break;

            case 3:
                cout << "\nSearch Data\n";
                linearSearch();
                break;

            case 4:
                do {
                    if (head == NULL) {
                        cout << "Sorry, the list is empty.";
                    } else if (head == tail) {
                        head = NULL;
                        tail = NULL;
                    } else {
                        helper = head->next;
                        helper->prev = NULL;
                        head = helper;
                    }
                    cout << "Delete again? (Press 1): "; cin >> deleteMore;
                } while (deleteMore == 1);

                helper = head;
                while (helper != NULL) {
                    cout << "Buyer's Name: " << helper->name << endl;
                    cout << "Transaction Date: " << helper->date << endl;
                    cout << "Toy: " << helper->toy << endl;
                    cout << "Toy Price: Rp." << helper->price << endl;
                    helper = helper->next;
                }
                break;

            default:
                cout << "Option not available!";
        }

        cout << "Repeat the process? (Press 1): "; cin >> repeatProcess;
    } while (repeatProcess == 1);

    return 0;
}
