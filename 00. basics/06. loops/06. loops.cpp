#include<iostream>
using namespace std;

int main(){

    // For Loop with Array
    
    cout << "For Loop: " << endl;
    int arr[5] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++){
        cout << arr[i] << endl;
    }

    // Reverse Loop
    
    cout << "Reverse Loop: " << endl;
    for(int i = 4; i >= 0; i--){
        cout << arr[i] << endl;
    }

    // While Loop

    cout << "While Loop: " << endl;
    int i = 0;
    while(i < 5){
        cout << arr[i] << endl;
        i++;
    }

    // Do-While Loop

    cout << "Do-While Loop: " << endl;
    int j = 0;
    do{
        cout << arr[j] << endl;
        j++;
    }while(j < 5);
    return 0;
}