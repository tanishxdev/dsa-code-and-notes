#include <iostream>
using namespace std;

int main() {
    int arr[5];
    string name;

    cout << "Enter 5 numbers: ";
    for(int i = 0; i < 5; i++)
        cin >> arr[i];

    cout << "Enter your name: ";
    cin >> name;

    cout << "Array: ";
    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    cout << endl;
    cout << "Name: " << name;
    return 0;
}
