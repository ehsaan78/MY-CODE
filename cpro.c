Good, `g++` is available. Let me create a beginner-friendly **Student Management System** that demonstrates objects in action, with file I/O.
Action: file_editor create /app/cpp_project/student_management.cpp --file-text "/*
============================================================
   STUDENT MANAGEMENT SYSTEM (Beginner OOP Demo - C++)
============================================================
   Demonstrates OBJECTS in action:
     - A Student class (blueprint)
     - Multiple Student objects (instances)
     - Each object has its OWN state (data members)
     - Shared behavior (member functions)
     - File I/O to save & load student records
============================================================
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// -----------------------------
// CLASS: blueprint for a Student
// -----------------------------
class Student {
private:
    // ---- STATE (data members) ----
    int    rollNo;
    string name;
    float  marks;

public:
    // ---- CONSTRUCTOR ----
    // Runs automatically when an object is created
    Student() {
        rollNo = 0;
        name   = \"Unknown\";
        marks  = 0.0f;
    }

    // ---- BEHAVIOR (member functions) ----

    // Take input from user for this object
    void inputData() {
        cout << \"  Enter Roll No : \";
        cin  >> rollNo;
        cin.ignore();                       // flush newline before getline
        cout << \"  Enter Name    : \";
        getline(cin, name);
        cout << \"  Enter Marks   : \";
        cin  >> marks;
    }

    // Show this object's data
    void display() const {
        cout << \"  Roll: \" << rollNo
             << \" | Name: \" << name
             << \" | Marks: \" << marks
             << \" | Grade: \" << calculateGrade() << endl;
    }

    // Compute grade based on marks
    char calculateGrade() const {
        if (marks >= 90) return 'A';
        if (marks >= 75) return 'B';
        if (marks >= 60) return 'C';
        if (marks >= 40) return 'D';
        return 'F';
    }

    // Getter — needed when writing to file
    int  getRollNo() const { return rollNo; }

    // Write this object's data to an output file stream
    void writeToFile(ofstream &out) const {
        // Use '|' as separator; name may contain spaces
        out << rollNo << \"|\" << name << \"|\" << marks << \"\n\";
    }

    // Read one student record from an input file stream
    // Returns true if a record was read successfully
    bool readFromFile(ifstream &in) {
        string line;
        if (!getline(in, line)) return false;
        if (line.empty()) return false;

        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        if (p1 == string::npos || p2 == string::npos) return false;

        rollNo = stoi(line.substr(0, p1));
        name   = line.substr(p1 + 1, p2 - p1 - 1);
        marks  = stof(line.substr(p2 + 1));
        return true;
    }
};

// -----------------------------
// Helper: save an array of objects to a file
// -----------------------------
void saveAllToFile(Student students[], int count, const string &filename) {
    ofstream out(filename);
    if (!out) {
        cout << \"  [!] Could not open file for writing.\n\";
        return;
    }
    for (int i = 0; i < count; i++) {
        students[i].writeToFile(out);
    }
    out.close();
    cout << \"  [OK] Saved \" << count << \" student(s) to '\" << filename << \"'\n\";
}

// -----------------------------
// Helper: load objects from a file
// -----------------------------
int loadAllFromFile(Student students[], int maxSize, const string &filename) {
    ifstream in(filename);
    if (!in) {
        cout << \"  [i] No existing file found. Starting fresh.\n\";
        return 0;
    }
    int count = 0;
    while (count < maxSize) {
        Student s;
        if (!s.readFromFile(in)) break;
        students[count++] = s;
    }
    in.close();
    if (count > 0)
        cout << \"  [OK] Loaded \" << count << \" student(s) from '\" << filename << \"'\n\";
    return count;
}

// -----------------------------
// MAIN — demonstrates objects in action
// -----------------------------
int main() {
    const int MAX = 50;
    Student students[MAX];          // <-- ARRAY OF OBJECTS
    int count = 0;
    const string FILENAME = \"students.txt\";

    // Try to load existing data on start-up
    count = loadAllFromFile(students, MAX, FILENAME);

    int choice;
    do {
        cout << \"\n========= STUDENT MANAGEMENT SYSTEM =========\n\";
        cout << \" 1. Add Student\n\";
        cout << \" 2. Display All Students\n\";
        cout << \" 3. Save to File\n\";
        cout << \" 4. Reload from File\n\";
        cout << \" 5. Exit\n\";
        cout << \"=============================================\n\";
        cout << \" Enter choice: \";
        cin  >> choice;

        switch (choice) {
            case 1:
                if (count >= MAX) {
                    cout << \"  [!] Storage full.\n\";
                } else {
                    cout << \"\n-- Adding Student #\" << (count + 1) << \" --\n\";
                    students[count].inputData();   // call on a specific object
                    count++;
                    cout << \"  [OK] Student added.\n\";
                }
                break;

            case 2:
                cout << \"\n-- All Students (\" << count << \") --\n\";
                if (count == 0) {
                    cout << \"  (no records)\n\";
                } else {
                    for (int i = 0; i < count; i++) {
                        students[i].display();    // each object shows its own data
                    }
                }
                break;

            case 3:
                saveAllToFile(students, count, FILENAME);
                break;

            case 4:
                count = loadAllFromFile(students, MAX, FILENAME);
                break;

            case 5:
                // Auto-save before exit
                saveAllToFile(students, count, FILENAME);
                cout << \"  Goodbye!\n\";
                break;

            default:
                cout << \"  [!] Invalid choice. Try again.\n\";
        }
    } while (choice != 5);

    return 0;
}
"
Observation: Create successful: /app/cpp_project/student_management.cpp

