#include <bits/stdc++.h>
using namespace std;
void stringsBasics()
{
    // Declaring a string and initializing
    string str1 = "Hello";
    string str2 = "World";
    string str3(5, 'A');

    // Priting the strings
    cout << "\n⭐ Priting the strings\n";
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    cout << "String 3: " << str3 << endl;
    
    // Length and size
    cout << "\n⭐ Length and size\n";
    cout << "Length of string 1: " << str1.length() << endl;
    cout << "Size of string 1: " << str1.size() << endl;
    cout << "Size of string 3: " << str3.size() << endl;
    
    // Cancatentations
    cout << "\n⭐ Cancatentations\n";
    string result = str1 + " " + str2;
    cout << "Concatenated string: " << result << endl;
    
    cout << "\n⭐ Append\n";
    result += "!"; // Append '!'
    cout << "After += " << result << endl;
    
    // Accessing characters
    cout << "\n⭐ Accessing characters\n";
    cout << "First char of str1: " << str1[0] << endl;
    cout << "Second char of str1(using at): " << str1.at(1) << endl;
    cout << "Last char of str1: " << str1[str1.length() - 1] << endl;
    
    // Substring
    cout << "\n⭐ Substring\n";
    cout << "Substring of result (pos 6, len 5): "<< result.substr(6, 5) << endl; // Output: World, Because start index is 6 and length is 5
    
    cout << "\n⭐ Find\n";
    // Find - Returns the position of the first occurrence of the substring
    size_t pos = result.find("World");
    if (pos != string::npos) {
        cout << "Found 'World' at position " << pos << endl;
    }
    
    cout << "\n⭐ Replace\n";
    // Replace - Replaces the first occurrence of the substring with the new substring
    string newStr = result.replace(6, 5, "Coder"); // Replace "World" with "Coder"
    cout << "Replaced string: " << newStr << endl;
    
    // Comparison 
    cout << "\n⭐ Comparison\n";
    if(str1 == "Hello") cout << "Strings are equal" << endl;
    else cout << "Strings are not equal" << endl;
    
    // Input and Output
    cout << "\n⭐ Input and Output\n";
    string str4;
    // cout << "Enter a string: ";
    // cin.ignore(); // Ignore the newline character
    getline(cin, str4); // Read the entire line
    cout << "You entered: " << str4 << endl;

}
int main()
{
    stringsBasics();
    return 0;
}