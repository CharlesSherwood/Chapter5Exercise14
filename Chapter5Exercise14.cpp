/*FileName:Chapter5Exercise14.cpp
Programmer Name:Charles Sherwood
Date:4/2025
Requirements:This program should ask the user for the amount 
of students they want to add and which one would be first and 
which one would be last.
*/

#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
bool Repeat();
void Welcome();
int GetStudentCount();
void GetStudentNames(int count, string names[]);
void DisplayFirstAndLast(const string names[], int count);

const int MAX_STUDENTS = 25;

int main()
{
    do {
        Welcome();

        int NumStudents = GetStudentCount();
        string StudentNames[MAX_STUDENTS];

        GetStudentNames(NumStudents, StudentNames);
        DisplayFirstAndLast(StudentNames, NumStudents);

    } while (Repeat());

    cout << "Thank you for using the program!\n";
    return 0;
}

// Displays welcome message
void Welcome() {
    cout << "---------------------------------------------\n";
    cout << "|!! Welcome Let's Get Your Students Names !!|\n";
    cout << "---------------------------------------------\n";
}

// Gets and validates number of students
int GetStudentCount() {
    int count;
    cout << "How Many Students Do You Have In Your Class (1-25)?: ";
    cin >> count;

    while (count < 1 || count > 25) {
        cout << "---------------------------------------------\n";
        cout << "!! Invalid Number. Please Enter 1 to 25 Only !!\n";
        cout << "---------------------------------------------\n";
        cin >> count;
    }

    cin.ignore();
    return count;
}

// Gets student names from user input
void GetStudentNames(int count, string names[]) {
    for (int i = 0; i < count; ++i) {
        cout << "Please Enter The Name Of Student " << (i + 1) << ": ";
        getline(cin, names[i]);
    }
}

// Sorts names manually and displays the first and last alphabetically
void DisplayFirstAndLast(const string names[], int count) {
    if (count == 0) return;

    string sortedNames[MAX_STUDENTS];
    for (int i = 0; i < count; ++i) {
        sortedNames[i] = names[i];
    }

    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (sortedNames[j] > sortedNames[j + 1]) {
                // Swap the names
                string temp = sortedNames[j];
                sortedNames[j] = sortedNames[j + 1];
                sortedNames[j + 1] = temp;
            }
        }
    }

    cout << "\n======================================\n";
    cout << "First in line (Alphabetically): " << sortedNames[0] << endl;
    cout << "Last in line (Alphabetically): " << sortedNames[count - 1] << endl;
    cout << "======================================\n";
}


// Ask if the user wants to repeat the program
bool Repeat() {
    char choice;
    cout << "Would you like to run the program again? (Y/N): ";
    cin >> choice;
    cin.ignore();
    return (choice == 'Y' || choice == 'y');
}
