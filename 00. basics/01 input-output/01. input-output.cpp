#include <iostream>
using namespace std;

int main() {
    int age;
    string name;

    // cout << "Enter your name: ";
    getline(cin, name);

    // cout << "Enter your age: ";
    cin >> age;

    cout << "Name: " << name << endl;
    cout << "Age: " << age;

    return 0;
}
