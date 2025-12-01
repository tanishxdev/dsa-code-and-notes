#include <iostream>
using namespace std;
int main()
{
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "You choose 1" << endl;
        break;
    case 2:
        cout << "You choose 2" << endl;
        break;
    case 3:
        cout << "You choose 3" << endl;
        break;
    case 4:
        cout << "You choose 4" << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}