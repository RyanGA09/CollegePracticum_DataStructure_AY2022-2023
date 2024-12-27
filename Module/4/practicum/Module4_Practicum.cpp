#include <iostream>
using namespace std;

// Program Title: Student Data Management System (Linked List Version)
// This program allows you to input, search, sort, and display student data using a linked list.

struct Node
{
    string name, npm, department;
    Node *next;
} studentData;

Node *newNode, *newNode1, *start, *start1, *end, *end1, *helper, *helper1;
Node *left, *right;
string temp;

void createNewNode(string name1, string npm1, string department1)
{
    newNode = new Node;
    newNode->name = name1;
    newNode->npm = npm1;
    newNode->department = department1;
    newNode->next = NULL;
    
    newNode1 = new Node;
    newNode1->name = name1;
    newNode1->npm = npm1;
    newNode1->department = department1;
    newNode1->next = NULL;
}

void addToEnd()
{
    if (start == NULL && start1 == NULL)
    {
        start = newNode;
        start1 = newNode1;
    }
    else
    {
        end->next = newNode;
        end1->next = newNode1;
    }
    end = newNode;
    end1 = newNode1;
}

void displayNamesAndDepartments()
{
    helper = start;
    while (helper != NULL)
    {
        cout << "Name    : " << helper->name << endl;
        cout << "Department : " << helper->department << endl << endl;
        helper = helper->next;
    }
}

void displayNPM()
{
    helper = start1;
    while (helper != NULL)
    {
        cout << "NPM     : " << helper->npm << endl;
        helper = helper->next;
    }
}

void bubbleSort()
{
    right = NULL;
    int swapped;
    if (start1 == NULL)
    {
        cout << "No data available" << endl;
    }
    else
    {
        do
        {
            left = start1;
            swapped = 0;
            while (left->next != right)
            {
                if (left->npm > left->next->npm)
                {
                    temp = left->npm;
                    left->npm = left->next->npm;
                    left->next->npm = temp;
                    swapped = 1;
                }
                left = left->next;
            }
            right = left;
        } while (swapped);
    }
}

void linearSearch()
{
    string searchName;
    int position = 1, found;
    cin.ignore();
    cout << "Enter the name of the student to search for: ";
    getline(cin, searchName);
    helper1 = start;
    while (helper1 != NULL)
    {
        if (helper1->name != searchName)
        {
            helper1 = helper1->next;
            position++;
        }
        else
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        cout << "Node found at position: " << position << endl;
        cout << "Name    : " << helper1->name << endl;
        cout << "NPM     : " << helper1->npm << endl;
        cout << "Department : " << helper1->department << endl << endl;
    }
    else
    {
        cout << "Node not found" << endl;
    }
}

void displaySortedData()
{
    int count = 1;
    helper = start1;
    while (helper != NULL)
    {
        cout << count << ". NPM after sorting: " << helper->npm << endl;
        helper = helper->next;
        count++;
    }
}

int main()
{
    cout << "===== Student Data Management System (Linked List Version) =====" << endl;

    int choice, repeat;
    do
    {
        system("cls");
        cout << "1. Input Data" << endl;
        cout << "2. Search Data" << endl;
        cout << "3. Sort Data" << endl;
        cout << "4. Display Names and Departments" << endl;
        cout << "5. Display NPM" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cin.ignore();
            cout << endl;
            cout << "Enter name    : ";
            getline(cin, studentData.name);
            cout << "Enter NPM     : ";
            getline(cin, studentData.npm);
            cout << "Enter department : ";
            getline(cin, studentData.department);
            createNewNode(studentData.name, studentData.npm, studentData.department);
            addToEnd();
        }
        if (choice == 2)
        {
            linearSearch();
        }
        if (choice == 3)
        {
            bubbleSort();
            displaySortedData();
        }
        if (choice == 4)
        {
            displayNamesAndDepartments();
        }
        if (choice == 5)
        {
            displayNPM();
        }

        cout << endl;
        cout << "Press 1 to continue: ";
        cin >> repeat;
    }
    while (repeat == 1);

    return 0;
}
