#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addStudent()
{
    ofstream file("students.txt", ios::app);

    int rollNo, age;
    string name, course;

    cout << "Enter Roll Number: ";
    cin >> rollNo;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, course);

    file << rollNo << "|" << name << "|" << age << "|" << course << endl;

    file.close();

    cout << "Student added successfully!\n";
}

void displayStudents()
{
    ifstream file("students.txt");

    string line;

    cout << "\n----- Student Records -----\n";

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void updateStudent()
{
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    int rollNo, newAge, searchRoll;
    string name, course;
    string line;
    bool found = false;

    cout << "Enter Roll Number to update: ";
    cin >> searchRoll;
    cin.ignore();

    while(getline(file, line))
    {
        int pos1 = line.find("|");
        int pos2 = line.find("|", pos1 + 1);
        int pos3 = line.find("|", pos2 + 1);

        int currentRoll = stoi(line.substr(0, pos1));

        if(currentRoll == searchRoll)
        {
            found = true;

            cout << "Enter New Name: ";
            getline(cin, name);

            cout << "Enter New Age: ";
            cin >> newAge;
            cin.ignore();

            cout << "Enter New Course: ";
            getline(cin, course);

            temp << searchRoll << "|" << name << "|" << newAge << "|" << course << endl;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if(found)
        cout << "Record updated successfully!\n";
    else
        cout << "Student not found!\n";
}

void deleteStudent()
{
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    int searchRoll;
    string line;
    bool found = false;

    cout << "Enter Roll Number to delete: ";
    cin >> searchRoll;

    while(getline(file, line))
    {
        int pos = line.find("|");
        int currentRoll = stoi(line.substr(0, pos));

        if(currentRoll == searchRoll)
        {
            found = true;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if(found)
        cout << "Student deleted successfully!\n";
    else
        cout << "Student not found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}
