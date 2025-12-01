#include <iostream>
using namespace std;

// Function with return & parameters
int add(int a, int b)
{
    return a + b;
}

// Function without return
void greet() {
    cout << "Hello World" << endl;
}
// PASS BY VALUE 
void change(int x) {
    x = 20;
}

// PASS BY REFERENCE
void change(int *x) {
    *x = 20;
}
int main()
{
    // Function with return & parameters
    int a = 5;
    int b = 10;
    
    cout << "Sum = " << add(a, b) << endl;
    
    // Function without return
    greet();

    // PASS BY VALUE
    int x = 10;
    change(x);
    cout << x << endl;

    // PASS BY REFERENCE
    int y = 10;
    change(&y);
    cout << y << endl;

    return 0;
}

