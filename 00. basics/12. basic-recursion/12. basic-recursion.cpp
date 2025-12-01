#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------
// 1. PRINT "HELLO" N TIMES
// ------------------------------------------------------
// Problem : Print "Hello" exactly n times using recursion
// Concept : Tail Recursion
// Approach: Print once, then reduce n
// TC: O(n)
// SC: O(n) -> Recursive stack

void printHello(int n)
{
    if(n == 0) return;              // base case
    cout << "Hello" << endl;        // work
    printHello(n - 1);              // recursive call
}


// ------------------------------------------------------
// 2. PRINT NAME N TIMES
// ------------------------------------------------------
// Problem : Print "tanishxdev" n times
// TC: O(n)
// SC: O(n)

void printName(int n)
{
    if(n == 0) return;
    cout << "tanishxdev" << endl;
    printName(n - 1);
}


// ------------------------------------------------------
// 3. PRINT 1 TO N USING RECURSION
// ------------------------------------------------------
// Concept : Backtracking recursion
// Approach: Go till 1, then print while returning
// TC: O(n)
// SC: O(n)

void print1toN(int n)
{
    if(n == 0) return;
    print1toN(n - 1);     // first recursive call
    cout << n << " ";     // then print
}


// ------------------------------------------------------
// 4. PRINT N TO 1 USING RECURSION
// ------------------------------------------------------
// Concept : Forward recursion
// TC: O(n)
// SC: O(n)

void printNto1(int n)
{
    if(n == 0) return;
    cout << n << " ";
    printNto1(n - 1);
}


// ------------------------------------------------------
// 5. SUM OF FIRST N NUMBERS
// ------------------------------------------------------
// Formula: n + sum(n-1)
// Base: sum(0) = 0
// TC: O(n)
// SC: O(n)

int sumN(int n)
{
    if(n == 0) return 0;
    return n + sumN(n - 1);
}


// ------------------------------------------------------
// 6. FACTORIAL OF N
// ------------------------------------------------------
// Formula: n! = n * (n-1)!
// Base: 0! = 1 , 1! = 1
// TC: O(n)
// SC: O(n)

int factorial(int n)
{
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}


// ------------------------------------------------------
// 7. REVERSE ARRAY USING RECURSION
// ------------------------------------------------------
// Concept : Two pointers + recursive swapping
// TC: O(n)
// SC: O(n)

void reverseArray(int arr[], int start, int end)
{
    if(start >= end) return;
    swap(arr[start], arr[end]);
    reverseArray(arr, start + 1, end - 1);
}


// ------------------------------------------------------
// 8. CHECK PALINDROME USING RECURSION
// ------------------------------------------------------
// Concept : Compare outer characters
// TC: O(n)
// SC: O(n)

bool isPalindromeRec(string &s, int l, int r)
{
    if(l >= r) return true;
    if(s[l] != s[r]) return false;
    return isPalindromeRec(s, l + 1, r - 1);
}


// ------------------------------------------------------
// 9. FIBONACCI USING RECURSION
// ------------------------------------------------------
// Formula: fib(n) = fib(n-1) + fib(n-2)
// TC: O(2^n) -> very slow
// SC: O(n)

int fibonacci(int n)
{
    if(n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


// ======================================================
// MAIN DRIVER
// ======================================================

int main()
{
    cout << "---- PRINT HELLO ----" << endl;
    printHello(3);

    cout << "\n---- PRINT NAME ----" << endl;
    printName(2);

    cout << "\n---- PRINT 1 TO N ----" << endl;
    print1toN(5);

    cout << "\n\n---- PRINT N TO 1 ----" << endl;
    printNto1(5);

    cout << "\n\n---- SUM OF N ----" << endl;
    cout << sumN(5) << endl;

    cout << "\n---- FACTORIAL ----" << endl;
    cout << factorial(5) << endl;

    cout << "\n---- REVERSE ARRAY ----" << endl;
    int arr[] = {1,2,3,4,5};
    reverseArray(arr, 0, 4);
    for(int x : arr) cout << x << " ";

    cout << "\n\n---- PALINDROME CHECK ----" << endl;
    string s = "madam";
    cout << isPalindromeRec(s, 0, s.size() - 1);

    cout << "\n\n---- FIBONACCI ----" << endl;
    cout << fibonacci(6);

    return 0;
}
