#include <iostream>
using namespace std;

// Program Title: Student Data Management System
// This program manages student data using a linked list, allowing input, search, sort, and display of student information.

struct StudentNode
{
    string name;
    string studentId;
    string department;
    StudentNode* next;
} studentData;

StudentNode *newNode, *newNode1, *firstNode, *firstNode1, *lastNode, *lastNode1, *tempNode, *tempNode1;
StudentNode *left, *right;
string temp;

void createNewNode(string name1, string studentId1, string department1)
{
    newNode = new StudentNode;
    newNode->name = name1;
    newNode->studentId = studentId1;
    newNode->department = department1;
    newNode->next = NULL;
    
    newNode1 = new StudentNode;
    newNode1->name = name1;
    newNode1->studentId = studentId1;
    newNode1->department = department1;
    newNode1->next = NULL;
}

void addToEnd()
{
    if (firstNode == NULL && firstNode1 == NULL)
    {
        firstNode = newNode;
        firstNode1 = newNode1;
    }
    else
    {
        lastNode->next = newNode;
        lastNode1->next = newNode1;
    }
    lastNode = newNode;
    lastNode1 = newNode1;
}

void viewNamesAndDepartments()
{
    tempNode = firstNode;
    while (tempNode != NULL)
    {
        cout << "Name    : " << tempNode->name << endl;
        cout << "Department : " << tempNode->department << endl << endl;
        tempNode = tempNode->next;
    }
}

void viewStudentIds()
{
    tempNode = firstNode1;
    while (tempNode != NULL)
    {
        cout << "Student ID : " << tempNode->studentId << endl;
        tempNode = tempNode->next;
    }
}

void bubbleSort()
{
    right = NULL;
    int swap;
    if (firstNode1 == NULL)
    {
        cout << "No data available." << endl;
    }
    else
    {
        do
        {
            left = firstNode1;
            swap = 0;
            while (left->next != right)
            {
                if (left->studentId > left->next->studentId)
                {
                    temp = left->studentId;
                    left->studentId = left->next->studentId;
                    left->next->studentId = temp;
                    swap = 1;
                }
                left = left->next;
            }
            right = left;
        } while (swap);
    }
}

void linearSearch()
{
    string searchName;
    int position = 1, found;
    cin.ignore();
    cout << "Enter student name to search: ";
    getline(cin, searchName);
    tempNode1 = firstNode;
    while (tempNode1 != NULL)
    {
        if (tempNode1->name != searchName)
        {
            tempNode1 = tempNode1->next; 
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
        cout << "Name      : " << tempNode1->name << endl;
        cout << "Student ID: " << tempNode1->studentId << endl;
        cout << "Department: " << tempNode1->department << endl << endl;
    }
    else
    {
        cout << "Node not found." << endl;
    }
}

void displaySortedStudentIds()
{
    int counter = 1;
    tempNode = firstNode1;
    while (tempNode != NULL)
    {
        cout << counter << ". Sorted Student ID : " << tempNode->studentId << endl;
        tempNode = tempNode->next;
        counter++;
    }
}

int main()
{
    cout << "===== Student Data Management System =====" << endl;

    int choice, repeat;
    do
    {
        system("cls");
        cout << "1. Input student data" << endl;
        cout << "2. Search student data" << endl;
        cout << "3. Sort student data" << endl;
        cout << "4. Display Names and Departments" << endl;
        cout << "5. Display Student IDs" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cin.ignore();
            cout << endl;
            cout << "Enter student name: ";
            getline(cin, studentData.name);
            cout << "Enter student ID: ";
            getline(cin, studentData.studentId);
            cout << "Enter department: ";
            getline(cin, studentData.department);
            createNewNode(studentData.name, studentData.studentId, studentData.department);
            addToEnd();
        }
        if (choice == 2)
        {
            linearSearch();
        }
        if (choice == 3)
        {
            bubbleSort();
            displaySortedStudentIds();
        }
        if (choice == 4)
        {
            viewNamesAndDepartments();
        }
        if (choice == 5)
        {
            viewStudentIds();
        }

        cout << endl;
        cout << "Press 1 to continue: ";
        cin >> repeat;
    }
    while (repeat == 1);

    return 0;
}
