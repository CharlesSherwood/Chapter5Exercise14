/*FileName:Chapter5Exercise14.cpp
Programmer Name:Charles Sherwood
Date:4/2025
Requirements:This program should ask the user for the amount 
of students they want to put inti 
alphabetical order.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 25;
const string pathName = R"(C:\Users\CHARLIE BOI\Downloads\)"; // Constant path to LineUp.txt

// Function Prototypes
void Welcome();
int LoadStudentNames(string names[]);
void DisplayFirstAndLast(const string names[], int count);

int main() {
    Welcome();

    string StudentNames[MAX_STUDENTS];
    int NumStudents = LoadStudentNames(StudentNames);

    if (NumStudents == 0) {
        cout << "No names were found in LineUp.txt.\n";
    }
    else {
        DisplayFirstAndLast(StudentNames, NumStudents);
    }

    cout << "\nThank you for using the program!\n";
    return 0;
}

// Displays welcome message
void Welcome() {
    cout << "----------------------------------------------------------\n";
    cout << "|!! Welcome! Reading Student Line-Up From a File !!      |\n";
    cout << "----------------------------------------------------------\n";
}

// Loads student names from the LineUp.txt file
int LoadStudentNames(string names[]) {
    string fullPath = pathName + "LineUp.txt";
    ifstream inputFile(fullPath.c_str()); // safer for compatibility

    int count = 0;

    if (!inputFile) {
        cerr << "Error: Could not open file at path: " << fullPath << "\n";
        return 0;
    }

    while (count < MAX_STUDENTS && getline(inputFile, names[count])) {
        if (!names[count].empty()) {
            ++count;
        }
    }

    inputFile.close();
    return count;
}

// Sorts names manually and displays the first and last alphabetically
void DisplayFirstAndLast(const string names[], int count) {
    if (count == 0) return;

    string sortedNames[MAX_STUDENTS];
    for (int i = 0; i < count; ++i) {
        sortedNames[i] = names[i];
    }

    // Bubble sort
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (sortedNames[j] > sortedNames[j + 1]) {
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
