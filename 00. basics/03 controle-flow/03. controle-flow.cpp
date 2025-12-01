#include<iostream>
using namespace std;

int main() {

    // if-else simple
    int age; 
    cin >> age;

    if(age >= 18) {
        cout << "You can vote" << endl;
    }
    else {
        cout << "You can't vote" << endl;
    }

    // if - else if - else (Multiple conditions)

    int marks;
    cin >> marks;

    if(marks >= 90) {
        cout << "Grade A" << endl;
    } else if (marks >= 80) {
        cout << "Grade B" << endl;
    } else if (marks >= 70) {
        cout << "Grade C" << endl;
    } else if (marks >= 60) {
        cout << "Grade D" << endl;
    } else {
        cout << "Grade F" << endl;
    } 

    // Nested if-else

    if (age >= 18) {
    if (age < 60)
        cout << "Working age";
    else
        cout << "Senior citizen";
    }
    else {
        cout << "Minor";
    }


}