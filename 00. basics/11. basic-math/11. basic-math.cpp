#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------
// 1. COUNT DIGITS IN A NUMBER - BRUTE FORCE
// ----------------------------------------------------------
// Problem  : Count total digits in a number
// Approach : Repeatedly divide by 10 until number becomes 0
// TC       : O(log10 N)
// SC       : O(1)
// Important:
// - Handles 0 explicitly because log method fails for 0
// - Negative numbers can be converted using abs(n)

int countDigitsBruteForce(int n)
{
    if(n == 0) return 1;

    int count = 0;
    n = abs(n); // safety for negative numbers

    while(n > 0)
    {
        count++;
        n /= 10;
    }
    return count;
}


// ----------------------------------------------------------
// 2. COUNT DIGITS IN A NUMBER - OPTIMAL (LOG METHOD)
// ----------------------------------------------------------
// TC : O(1)
// SC : O(1)
// Important:
// - Only valid for n > 0
// - Faster but less safe than brute method

int countDigitsOptimal(int n)
{
    if(n == 0) return 1;
    n = abs(n);
    return floor(log10(n) + 1);
}


// ----------------------------------------------------------
// 3. REVERSE DIGITS OF A NUMBER
// ----------------------------------------------------------
// Example: 12345 → 54321
// TC : O(log10 N)
// SC : O(1)
// Important:
// - May overflow for very large numbers
// - Can be used for palindrome checking

int reverseDigits(int n)
{
    int reversed = 0;

    while(n > 0)
    {
        int lastDigit = n % 10;
        reversed = reversed * 10 + lastDigit;
        n /= 10;
    }
    return reversed;
}


// ----------------------------------------------------------
// 4. CHECK IF NUMBER IS PALINDROME
// ----------------------------------------------------------
// Approach: Reverse the number and compare
// TC : O(log10 N)
// SC : O(1)
// Important:
// - Negative numbers are NOT palindrome

bool isPalindrome(int n)
{
    if(n < 0) return false;
    return n == reverseDigits(n);
}


// ----------------------------------------------------------
// 5. GCD - BRUTE FORCE
// ----------------------------------------------------------
// TC : O(min(a,b))
// SC : O(1)
// Important:
// - Inefficient for large numbers
// - Useful for understanding logic

int findGCDBruteForce(int a, int b)
{
    int gcd = 1;
    for(int i = 1; i <= min(a, b); i++)
    {
        if(a % i == 0 && b % i == 0)
            gcd = i;
    }
    return gcd;
}


// ----------------------------------------------------------
// 6. GCD - BETTER (Reverse Loop)
// ----------------------------------------------------------
// TC : O(min(a,b))
// SC : O(1)
// Important:
// - Breaks early when GCD found

int findGCDBetter(int a, int b)
{
    for(int i = min(a, b); i >= 1; i--)
    {
        if(a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}


// ----------------------------------------------------------
// 7. GCD - OPTIMAL (EUCLIDEAN ALGORITHM)
// ----------------------------------------------------------
// TC : O(log(min(a,b)))
// SC : O(1)
// Important:
// - Most used in interviews
// - Based on: gcd(a,b) = gcd(b, a%b)

int findGCDOptimal(int a, int b)
{
    while(b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}


// ----------------------------------------------------------
// 8. CHECK ARMSTRONG NUMBER
// ----------------------------------------------------------
// Armstrong number: sum of digits^number_of_digits = number
// Example: 153 → 1³ + 5³ + 3³ = 153
// TC : O(log10 N)
// SC : O(1)
// Important:
// - Uses pow(), which returns double, but works for small N

bool isArmstrong(int n)
{
    if(n < 0) return false;

    int original = n;
    int digits = countDigitsBruteForce(n);
    int sum = 0;

    while(n > 0)
    {
        int lastDigit = n % 10;
        sum += pow(lastDigit, digits);
        n /= 10;
    }
    return sum == original;
}


// ----------------------------------------------------------
// 9. PRINT DIVISORS - BRUTE FORCE
// ----------------------------------------------------------
// TC : O(N)
// SC : O(number of divisors)
// Important:
// - Always returns sorted order

vector<int> printDivisorsBruteForce(int n)
{
    vector<int> divisors;

    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            divisors.push_back(i);
    }
    return divisors;
}


// ----------------------------------------------------------
// 10. PRINT DIVISORS - OPTIMAL (SORTED)
// ----------------------------------------------------------
// TC : O(√N)
// SC : O(number of divisors)
// Important:
// - Divisors always come in pairs
// - Perfect squares handled carefully

vector<int> printDivisorsOptimal(int n)
{
    vector<int> small, large;

    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            small.push_back(i);
            if(i != n / i)
                large.push_back(n / i);
        }
    }

    reverse(large.begin(), large.end());
    small.insert(small.end(), large.begin(), large.end());

    return small;
}


// ----------------------------------------------------------
// 11. CHECK IF NUMBER IS PRIME
// ----------------------------------------------------------
// TC : O(√N)
// SC : O(1)
// Important:
// - Numbers <= 1 are NOT prime
// - Best method for single checks

bool isPrime(int n)
{
    if(n <= 1) return false;

    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;

    cout << "\n--- COUNT DIGITS ---\n";
    n = 12345;
    cout << countDigitsBruteForce(n) << endl;
    cout << countDigitsOptimal(n) << endl;

    cout << "\n--- REVERSE NUMBER ---\n";
    cout << reverseDigits(n) << endl;

    cout << "\n--- PALINDROME CHECK ---\n";
    n = 123321;
    cout << (isPalindrome(n) ? "Palindrome" : "Not Palindrome") << endl;

    cout << "\n--- GCD METHODS ---\n";
    cout << findGCDBruteForce(12, 18) << endl;
    cout << findGCDBetter(12, 18) << endl;
    cout << findGCDOptimal(12, 18) << endl;

    cout << "\n--- ARMSTRONG CHECK ---\n";
    n = 153;
    cout << (isArmstrong(n) ? "Armstrong" : "Not Armstrong") << endl;

    cout << "\n--- DIVISORS ---\n";
    n = 12;
    vector<int> divisors = printDivisorsOptimal(n);
    for(int d : divisors) cout << d << " ";

    cout << "\n\n--- PRIME CHECK ---\n";
    n = 29;
    cout << (isPrime(n) ? "Prime" : "Not Prime") << endl;

    return 0;
}
