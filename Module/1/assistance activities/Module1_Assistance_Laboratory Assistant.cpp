#include <iostream>
using namespace std;

// Structure to store book details
struct Book 
{
    string title;
    string author;
    int publicationYear;
};

// Structure to store the loan date
struct Date 
{
    int day;
    int month;
    int year;
};

// Structure to store details of the borrowed books
struct Loan 
{
    Book book;
    Date loanDate;
    char borrowerName[100];
} borrowedBooks[100];

int main() 
{
    Book books[10][10];  // Array for storing book details
    int numberOfBooks, numberOfLoans, repeatProgram;

    do 
	{
        system("cls");  // Clear the screen (Windows-specific)
        cout << "=====BOOK LOAN PROGRAM=====\n";
        cout << "Enter the number of books to input: "; 
        cin >> numberOfBooks;

        // Input details for each book
        for (int row = 1; row <= numberOfBooks; row++) 
		{
            cout << "Book " << row << endl;
            for (int col = 1; col <= numberOfBooks; col++) 
			{
                cin.ignore();  // Clear the input buffer before reading strings
                cout << "________________________________________________________________________________________________________\n";
                cout << "Book Title\t\t\t\t: "; 
                getline(cin, books[row][col].title);
                cout << "Author Name\t\t\t\t: "; 
                getline(cin, books[row][col].author);
                cout << "Publication Year\t\t\t: "; 
                cin >> books[row][col].publicationYear;
                cout << "________________________________________________________________________________________________________\n";
            }
        }

        cin.ignore();  // Clear any leftover newline character

        cout << "=========================================\n";
        cout << "Borrower's Name\t\t\t\t: "; 
        cin.getline(borrowedBooks[100].borrowerName, 100);  // Input borrower's name
        cout << "Loan Date (e.g., 19 02 1998)\t\t: "; 
        cin >> borrowedBooks[100].loanDate.day >> borrowedBooks[100].loanDate.month >> borrowedBooks[100].loanDate.year;
        cout << "Number of Books Borrowed\t\t: "; 
        cin >> numberOfLoans;

        // Input details for each borrowed book
        for (int row = 1; row <= numberOfLoans; row++) 
		{
            cin.ignore();  // To clear the input buffer
            cout << "-----------------------------------------\n";
            cout << "Book Title\t\t: "; 
            getline(cin, borrowedBooks[row].book.title);
            cout << "Author Name\t\t: "; 
            getline(cin, borrowedBooks[row].book.author);
            cout << "Publication Year\t\t: "; 
            cin >> borrowedBooks[row].book.publicationYear;
            cout << "-----------------------------------------\n";
        }

        cout << "=========================================\n"; 
        cout << endl;
        
        // Ask if the user wants to repeat the program
        cout << "Repeat Program (Press 1 to continue)\t: "; 
        cin >> repeatProgram;
    } 
	while (repeatProgram == 1);

    system("cls");
    cout << "==========PROGRAM ENDED==========\n";
    
    return 0;
}
