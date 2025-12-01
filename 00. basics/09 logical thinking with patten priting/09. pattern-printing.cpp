#include <iostream>
using namespace std;

int main() {
    int n = 5;

    // ==================================================
    // Pattern 1: Solid Square
    // *****
    // *****
    // *****
    // *****
    // *****
    // ==================================================
    cout << "Pattern 1: Solid Square\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

    // ==================================================
    // Pattern 2: Right Triangle
    // *
    // **
    // ***
    // ****
    // *****
    // ==================================================
    cout << "Pattern 2: Right Triangle\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

    // ==================================================
    // Pattern 3: Inverted Right Triangle
    // *****
    // ****
    // ***
    // **
    // *
    // ==================================================
    cout << "Pattern 3: Inverted Right Triangle\n";
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

    // ==================================================
    // Pattern 4: Number Triangle
    // 1
    // 12
    // 123
    // 1234
    // 12345
    // ==================================================
    cout << "Pattern 4: Number Triangle\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }

    cout << endl;

    // ==================================================
    // Pattern 5: Repeated Number Triangle
    // 1
    // 22
    // 333
    // 4444
    // 55555
    // ==================================================
    cout << "Pattern 5: Repeated Number Triangle\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }

    cout << endl;

    // ==================================================
    // Pattern 6: Pyramid
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    // ==================================================
    cout << "Pattern 6: Pyramid\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for(int j = 1; j <= 2*i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

    // ==================================================
    // Pattern 7: Inverted Pyramid
    // *********
    //  *******
    //   *****
    //    ***
    //     *
    // ==================================================
    cout << "Pattern 7: Inverted Pyramid\n";
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for(int j = 1; j <= 2*i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

    // ==================================================
    // Pattern 8: Diamond
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    //  *******
    //   *****
    //    ***
    //     *
    // ==================================================
    cout << "Pattern 8: Diamond\n";
    // Upper Half
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for(int j = 1; j <= 2*i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    // Lower Half
    for(int i = n - 1; i >= 1; i--) {
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for(int j = 1; j <= 2*i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

    // ==================================================
    // Pattern 9: Binary Pattern
    // 1
    // 01
    // 101
    // 0101
    // 10101
    // ==================================================
    cout << "Pattern 9: Binary Pattern\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if((i + j) % 2 == 0)
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }

    cout << endl;

    // ==================================================
    // Pattern 10: Hollow Square
    // *****
    // *   *
    // *   *
    // *   *
    // *****
    // ==================================================
    cout << "Pattern 10: Hollow Square\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 || i == n || j == 1 || j == n)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
