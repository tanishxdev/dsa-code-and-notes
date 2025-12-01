#include <bits/stdc++.h>
using namespace std;

/*
    PURPOSE: operations on SEQUENCE CONTAINERS.
*/

// ================= VECTOR OPERATIONS =================

void vectorDemo()
{
    cout << "----- VECTOR DEMONSTRATION -----\n";

    vector<int> v;

    // 1. INSERTION
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 2. DISPLAY
    cout << "Elements in vector: ";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    // 3. ACCESSING ELEMENTS
    cout << "\nFront element: " << v.front();
    cout << "\nLast element: " << v.back();
    cout << "\nSize: " << v.size();

    // 4. DELETE LAST ELEMENT
    cout << "\nDeleting last element: " << v.back();
    v.pop_back();

    cout << "\nVector after pop_back(): ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    // 5. INSERT AT BEGINNING
    cout << "\nInserting 5 at beginning";
    v.insert(v.begin(), 5);

    cout << "\nVector after insertion: ";
    for (int x : v)
        cout << x << " ";

    // 6. ERASE FIRST ELEMENT
    cout << "\nErasing first element";
    v.erase(v.begin());

    cout << "\nVector after erase: ";
    for (int x : v)
        cout << x << " ";

    // 7. EMPTY CHECK
    if (v.empty())
        cout << "\nVector is empty";
    else
        cout << "\nVector is not empty";

    // 8. CLEAR VECTOR
    v.clear();
    cout << "\nSize after clear(): " << v.size() << endl;
}

// ================= DEQUE OPERATIONS =================
void printDeque(deque<int> &dq)
{
    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void dequeDemo()
{
    cout << "\n========== DEQUE DEMO ==========\n";

    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_front(40);
    dq.push_front(50);

    cout << "Elements in deque: ";
    printDeque(dq);

    cout << "Size: " << dq.size() << endl;
    cout << "Front element: " << dq.front() << endl;

    cout << "Deleting first element" << endl;
    dq.pop_front();
    printDeque(dq);

    cout << "Last element: " << dq.back() << endl;
    cout << "Deleting last element" << endl;
    dq.pop_back();
    printDeque(dq);
}
// ================= LIST OPERATIONS =================

void printlist(list<int> li)
{
    list<int>::iterator it;
    for (it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void listDemo()
{
    cout << "\n========== LIST DEMO ==========\n";

    list<int> li;

    // 1. INSERT
    li.push_back(10);
    li.push_back(20);
    li.push_front(30);
    li.push_front(40);
    li.push_front(50);

    cout<<"The elements in the list are: ";
    printlist(li);
    
    cout<<"Reversing the list: ";
    li.reverse();
    printlist(li);
    
    cout<<"Sorting the list: ";
    li.sort();
    printlist(li);
    
    cout<<"The size of the list is: "<<li.size()<<endl;
    
    cout<<"The first element in the list: "<<li.front()<<endl;
    
    cout<<"Deleting the first element"<<endl;
    li.pop_front();
    printlist(li);
    
    cout<<"The last element of the list: "<<li.back()<<endl;
    
    cout<<"Deleting the last element"<<endl;
    li.pop_back();
    printlist(li);

}
// ================= MAIN FUNCTION =================

int main()
{
    vectorDemo();
    dequeDemo();
    listDemo();
    return 0;
}
