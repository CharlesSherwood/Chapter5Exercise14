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
#include <vector>
#include <algorithm>
using namespace std;

// Function Prototypes
bool Repeat();
void Welcome();
int GetStudentCount();
void GetStudentNames(int count, vector<string>& names);
void SaveNamesToFile(const vector<string>& names);
void DisplayFirstAndLast(const vector<string>& names);

int main()
{
    do {
        Welcome();

        int NumStudents = GetStudentCount();
        vector<string> StudentNames;

        GetStudentNames(NumStudents, StudentNames);
        SaveNamesToFile(StudentNames);
        DisplayFirstAndLast(StudentNames);

    } while (Repeat());

    cout << "Thank you for using the program!\n";
    return 0;
}

// Displays welcome message
void Welcome() {
    cout << "----------------------------------------------------------\n";
    cout << "|!! Welcome! Let's Alphabetize Your Students' Names !!   |\n";
    cout << "----------------------------------------------------------\n";
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
void GetStudentNames(int count, vector<string>& names) {
    string name;
    for (int i = 0; i < count; ++i) {
        cout << "Please Enter The Name Of Student " << (i + 1) << ": ";
        getline(cin, name);
        names.push_back(name);
    }
}

// Saves names to a file
void SaveNamesToFile(const vector<string>& names) {
    ofstream outFile("StudentNames.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto& name : names) {
        outFile << name << endl;
    }

    outFile.close();
}

// Sorts names and displays the first and last alphabetically
void DisplayFirstAndLast(const vector<string>& names) {
    if (names.empty()) return;

    vector<string> sortedNames = names;
    sort(sortedNames.begin(), sortedNames.end());

    cout << "\n======================================\n";
    cout << "First in line (Alphabetically): " << sortedNames.front() << endl;
    cout << "Last in line (Alphabetically): " << sortedNames.back() << endl;
    cout << "======================================\n";
}

// Ask if the user wants to repeat the program
bool Repeat() {
    char choice;
    cout << "Would you like to run the program again? (Y/N): ";
    cin >> choice;
    cin.ignore(); // Clear buffer
    return (choice == 'Y' || choice == 'y');
}
