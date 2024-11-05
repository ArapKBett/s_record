#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM_SUBJECTS = 3;

struct Student {
    string name;
    int age;
    int marks[NUM_SUBJECTS];
    float averageMarks;
};

void calculateAverageMarks(Student &student) {
    int total = 0;
    for (int i = 0; i < NUM_SUBJECTS; ++i) {
        total += student.marks[i];
    }
    student.averageMarks = static_cast<float>(total) / NUM_SUBJECTS;
}

void addStudent(vector<Student> &students) {
    Student newStudent;
    cout << "Enter name: ";
    cin >> newStudent.name;
    cout << "Enter age: ";
    cin >> newStudent.age;
    cout << "Enter marks for " << NUM_SUBJECTS << " subjects: ";
    for (int i = 0; i < NUM_SUBJECTS; ++i) {
        cin >> newStudent.marks[i];
    }
    calculateAverageMarks(newStudent);
    students.push_back(newStudent);
}

void displayStudents(const vector<Student> &students) {
    for (const auto &student : students) {
        cout << "Name: " << student.name << ", Age: " << student.age << ", Average Marks: " << student.averageMarks << endl;
    }
}

void sortStudentsByAverageMarks(vector<Student> &students) {
    sort(students.begin(), students.end(),  {
        return a.averageMarks > b.averageMarks;
    });
}

void findHighestAndLowestAverage(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No student records available." << endl;
        return;
    }
    auto maxStudent = max_element(students.begin(), students.end(),  {
        return a.averageMarks < b.averageMarks;
    });
    auto minStudent = min_element(students.begin(), students.end(),  {
        return a.averageMarks < b.averageMarks;
    });
    cout << "Highest Average Marks: " << maxStudent->name << " with " << maxStudent->averageMarks << endl;
    cout << "Lowest Average Marks: " << minStudent->name << " with " << minStudent->averageMarks << endl;
}

void calculateClassAverage(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No student records available." << endl;
        return;
    }
    float totalAverage = 0;
    for (const auto &student : students) {
        totalAverage += student.averageMarks;
    }
    cout << "Class Average Marks: " << totalAverage / students.size() << endl;
}

int main() {
    vector<Student> students;
    int choice;
    do {
        cout << "Menu:\n1. Add new student records\n2. Display all student records\n3. Sort students by average marks\n4. Display student with highest and lowest average\n5. Calculate class average\n6. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                sortStudentsByAverageMarks(students);
                break;
            case 4:
                findHighestAndLowestAverage(students);
                break;
            case 5:
                calculateClassAverage(students);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}
