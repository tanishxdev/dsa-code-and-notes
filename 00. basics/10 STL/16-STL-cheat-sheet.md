# C++ STL Cheat Sheet

## 📚 **Containers**

### Sequence Containers
```cpp
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>

// Vector - Dynamic array
vector<int> v = {1, 2, 3};
v.push_back(4);           // O(1) amortized
v.pop_back();             // O(1)
v.insert(v.begin(), 0);   // O(n)
v.erase(v.begin());       // O(n)
v.size();                 // O(1)
v.empty();                // O(1)

// Deque - Double-ended queue
deque<int> dq = {1, 2, 3};
dq.push_front(0);         // O(1)
dq.push_back(4);          // O(1)
dq.pop_front();           // O(1)
dq.pop_back();            // O(1)

// List - Doubly linked list
list<int> lst = {1, 2, 3};
lst.push_front(0);        // O(1)
lst.push_back(4);         // O(1)
lst.insert(++lst.begin(), 5); // O(1)
lst.remove(2);            // O(n)
lst.sort();               // O(n log n)
lst.unique();             // O(n)

// Array - Fixed size array
array<int, 3> arr = {1, 2, 3};
arr.size();               // O(1)
arr.fill(0);              // O(n)
```

### Associative Containers
```cpp
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// Set (ordered, unique)
set<int> s = {3, 1, 2};           // {1, 2, 3}
s.insert(4);                     // O(log n)
s.erase(2);                      // O(log n)
s.find(3);                       // O(log n), returns iterator
s.count(3);                      // O(log n), returns 0/1
s.lower_bound(2);                // O(log n)
s.upper_bound(2);                // O(log n)

// Multiset (ordered, allows duplicates)
multiset<int> ms = {1, 1, 2};

// Map (ordered key-value)
map<string, int> m = {{"a", 1}, {"b", 2}};
m["c"] = 3;                     // O(log n) insertion
m.insert({"d", 4});             // O(log n)
m.find("a");                    // O(log n)
m.erase("b");                   // O(log n)

// Unordered Set (hash table)
unordered_set<int> us = {1, 2, 3};
us.insert(4);                   // O(1) average, O(n) worst
us.erase(2);                    // O(1) average
us.find(3);                     // O(1) average

// Unordered Map (hash table)
unordered_map<string, int> um;
um["key"] = 10;                 // O(1) average
um.insert({"key2", 20});        // O(1) average
```

### Container Adapters
```cpp
#include <stack>
#include <queue>
#include <priority_queue>

// Stack - LIFO
stack<int> stk;
stk.push(1);                    // O(1)
stk.pop();                      // O(1)
stk.top();                      // O(1)
stk.empty();                    // O(1)

// Queue - FIFO
queue<int> q;
q.push(1);                      // O(1)
q.pop();                        // O(1)
q.front();                      // O(1)
q.back();                       // O(1)

// Priority Queue - Max heap by default
priority_queue<int> pq;         // Max heap
pq.push(3);                     // O(log n)
pq.push(1);
pq.push(2);
pq.top();                       // O(1) - returns 3
pq.pop();                       // O(log n)

// Min heap
priority_queue<int, vector<int>, greater<int>> min_pq;
```

## 🔧 **Algorithms** (`<algorithm>`)
```cpp
#include <algorithm>
#include <numeric>

vector<int> v = {3, 1, 4, 1, 5, 9};

// Sorting
sort(v.begin(), v.end());                 // O(n log n)
sort(v.begin(), v.end(), greater<int>()); // Descending
stable_sort(v.begin(), v.end());          // Preserves order of equals

// Searching
auto it = find(v.begin(), v.end(), 4);    // O(n)
bool found = binary_search(v.begin(), v.end(), 5); // O(log n)

// Min/Max
int mx = *max_element(v.begin(), v.end()); // O(n)
int mn = *min_element(v.begin(), v.end()); // O(n)

// Count
int cnt = count(v.begin(), v.end(), 1);   // O(n)

// Accumulate/Sum
int sum = accumulate(v.begin(), v.end(), 0); // O(n)
int product = accumulate(v.begin(), v.end(), 1, multiplies<int>());

// Transform
vector<int> squared;
transform(v.begin(), v.end(), back_inserter(squared),
          [](int x) { return x * x; });   // O(n)

// Remove duplicates
sort(v.begin(), v.end());
auto last = unique(v.begin(), v.end());   // O(n)
v.erase(last, v.end());

// Reverse
reverse(v.begin(), v.end());              // O(n)

// Rotate
rotate(v.begin(), v.begin() + 2, v.end()); // O(n)

// Partition
auto pivot = partition(v.begin(), v.end(), 
                      [](int x) { return x % 2 == 0; }); // O(n)

// Next permutation
next_permutation(v.begin(), v.end());     // O(n)
prev_permutation(v.begin(), v.end());

// Fill
fill(v.begin(), v.end(), 0);              // O(n)

// Generate
generate(v.begin(), v.end(), 
         []() { return rand() % 100; });  // O(n)
```

## 🔢 **Numeric** (`<numeric>`)
```cpp
#include <numeric>
#include <cmath>

vector<int> v = {1, 2, 3, 4, 5};

// Accumulate
int sum = accumulate(v.begin(), v.end(), 0);
int product = accumulate(v.begin(), v.end(), 1, multiplies<int>());

// Inner product (dot product)
vector<int> a = {1, 2, 3};
vector<int> b = {4, 5, 6};
int dot = inner_product(a.begin(), a.end(), b.begin(), 0);

// Partial sum (prefix sum)
vector<int> prefix;
partial_sum(v.begin(), v.end(), back_inserter(prefix));

// Adjacent difference
vector<int> diff;
adjacent_difference(v.begin(), v.end(), back_inserter(diff));

// GCD/LCM (C++17)
int g = gcd(12, 18);  // 6
int l = lcm(4, 6);    // 12
```

## 🔤 **Strings** (`<string>`)
```cpp
#include <string>
#include <sstream>
#include <regex>

// String operations
string s = "Hello";
s += " World";                   // Append
s.substr(6, 5);                  // "World"
s.find("World");                 // Returns position
s.replace(0, 5, "Hi");           // "Hi World"
s.erase(2, 3);                   // Remove characters

// String stream
stringstream ss("1 2 3");
int a, b, c;
ss >> a >> b >> c;

// to_string / stoi
string num = to_string(42);      // "42"
int n = stoi("123");             // 123
double d = stod("3.14");         // 3.14

// Regex
regex pattern(R"(\d+)");
string text = "123 abc 456";
smatch matches;
while (regex_search(text, matches, pattern)) {
    cout << matches[0] << " ";
    text = matches.suffix();
}
```

## ⏰ **Time** (`<chrono>`)
```cpp
#include <chrono>
#include <ctime>
using namespace std::chrono;

// Current time
auto now = system_clock::now();
auto now_c = system_clock::to_time_t(now);
cout << ctime(&now_c);                    // Formatted time

// Duration
auto start = high_resolution_clock::now();
// Code to measure
auto end = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(end - start);
cout << duration.count() << "ms\n";

// Sleep
this_thread::sleep_for(seconds(1));
```

## 🧵 **Threading** (`<thread>`, `<mutex>`, `<atomic>`)
```cpp
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
#include <condition_variable>

// Thread creation
void task(int x) { cout << x; }
thread t1(task, 42);             // Start thread
t1.join();                       // Wait for completion
// t1.detach();                  // Detach thread

// Mutex
mutex mtx;
{
    lock_guard<mutex> lock(mtx); // RAII lock
    // Critical section
}

// Unique lock (more flexible)
unique_lock<mutex> ulock(mtx, defer_lock);
ulock.lock();
ulock.unlock();

// Atomic operations
atomic<int> counter{0};
counter.fetch_add(1);            // Thread-safe increment
counter.load();                  // Thread-safe read

// Condition variable
condition_variable cv;
mutex cv_mtx;
bool ready = false;

// Thread 1
unique_lock<mutex> lock(cv_mtx);
cv.wait(lock, []{ return ready; });

// Thread 2
{
    lock_guard<mutex> lock(cv_mtx);
    ready = true;
}
cv.notify_one();

// Async operations
auto future = async(launch::async, []() {
    return 42;
});
int result = future.get();       // Waits for result

// Promise/Future
promise<int> p;
future<int> f = p.get_future();
// In thread:
p.set_value(42);
// In main:
int val = f.get();
```

## 📁 **Filesystem** (C++17, `<filesystem>`)
```cpp
#include <filesystem>
namespace fs = std::filesystem;

// Path manipulation
fs::path p = "/home/user/file.txt";
p.filename();                    // "file.txt"
p.extension();                   // ".txt"
p.parent_path();                 // "/home/user"

// File operations
fs::exists(p);                   // Check if exists
fs::file_size(p);                // Get file size
fs::last_write_time(p);          // Get modification time

// Directory operations
for (auto& entry : fs::directory_iterator(".")) {
    cout << entry.path() << endl;
}

// Create/Remove
fs::create_directory("new_dir");
fs::remove("file.txt");
fs::remove_all("directory");     // Recursive remove

// Copy/Rename
fs::copy("src.txt", "dst.txt");
fs::rename("old.txt", "new.txt");
```

## 🎯 **Smart Pointers**
```cpp
#include <memory>

// Unique pointer (exclusive ownership)
unique_ptr<int> p1 = make_unique<int>(42);
// auto p2 = p1;                  // Error! Can't copy
auto p2 = move(p1);              // OK, transfers ownership

// Shared pointer (shared ownership)
shared_ptr<int> sp1 = make_shared<int>(42);
shared_ptr<int> sp2 = sp1;        // Reference count: 2
sp1.use_count();                  // Returns 2

// Weak pointer (non-owning reference)
weak_ptr<int> wp = sp1;
if (auto sp = wp.lock()) {        // Convert to shared_ptr
    // Use sp
}

// Arrays
unique_ptr<int[]> arr = make_unique<int[]>(10);
arr[0] = 1;

// Custom deleter
unique_ptr<FILE, decltype(&fclose)> 
    file(fopen("test.txt", "r"), fclose);
```

## 🎭 **Functional** (`<functional>`)
```cpp
#include <functional>

// Function wrapper
function<int(int, int)> add = [](int a, int b) { return a + b; };
cout << add(2, 3);                // 5

// Bind
auto add_five = bind(add, placeholders::_1, 5);
cout << add_five(10);             // 15

// Placeholders
using namespace placeholders;
function<int(int, int, int)> sum3 = 
    [](int a, int b, int c) { return a + b + c; };
auto sum_with_10 = bind(sum3, _1, _2, 10);
cout << sum_with_10(1, 2);       // 13

// Hash
hash<string> hasher;
size_t h = hasher("hello");
```

## 🗂️ **Utility** (`<utility>`)
```cpp
#include <utility>
#include <tuple>

// Pair
pair<int, string> p = {1, "one"};
p.first;                         // 1
p.second;                        // "one"
auto p2 = make_pair(2, "two");

// Tuple
tuple<int, string, double> t = {1, "pi", 3.14};
get<0>(t);                       // 1
get<1>(t);                       // "pi"
auto t2 = make_tuple(2, "e", 2.71);

// Tie (unpack tuple)
int x; string y; double z;
tie(x, y, z) = t;

// Structured bindings (C++17)
auto [id, name, value] = t;

// Move semantics
vector<int> v1 = {1, 2, 3};
vector<int> v2 = move(v1);       // v1 is now empty

// Forward (perfect forwarding)
template<typename T>
void wrapper(T&& arg) {
    process(forward<T>(arg));
}
```

## 📊 **Iterators**
```cpp
// Iterator categories:
// - Input: Read once, forward only
// - Output: Write once, forward only  
// - Forward: Multiple passes, forward only
// - Bidirectional: Forward + backward
// - Random Access: Direct access, arithmetic

// Iterator operations
vector<int> v = {1, 2, 3, 4, 5};
auto it = v.begin();

advance(it, 2);                  // Move iterator
auto dist = distance(v.begin(), it); // Distance between iterators
auto prev_it = prev(it);         // Previous iterator
auto next_it = next(it);         // Next iterator

// Reverse iterators
for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
    cout << *rit;                // Reverse traversal
}

// Insert iterators
back_insert_iterator<vector<int>> back_it(v);
*back_it = 6;                    // v.push_back(6)

front_insert_iterator<list<int>> front_it(lst);
*front_it = 0;                   // lst.push_front(0)

insert_iterator<vector<int>> ins_it(v, v.begin() + 2);
*ins_it = 99;                    // v.insert(v.begin()+2, 99)
```

## 🎨 **Type Traits** (`<type_traits>`)
```cpp
#include <type_traits>

// Type queries
is_integral<int>::value;         // true
is_floating_point<double>::value;// true
is_pointer<int*>::value;         // true
is_reference<int&>::value;       // true
is_const<const int>::value;      // true
is_same<int, int>::value;        // true

// Type transformations
remove_const<const int>::type;   // int
add_const<int>::type;            // const int
remove_pointer<int*>::type;      // int
add_pointer<int>::type;          // int*
decay<int[5]>::type;             // int*

// Enable if (SFINAE)
template<typename T>
typename enable_if<is_integral<T>::value, T>::type
foo(T x) { return x; }
```

## 🔍 **Search Algorithms**
```cpp
vector<int> v = {1, 2, 3, 4, 5, 5, 6};

// Binary search (requires sorted)
bool found = binary_search(v.begin(), v.end(), 3);

// Lower/Upper bound
auto lb = lower_bound(v.begin(), v.end(), 5);  // First ≥ 5
auto ub = upper_bound(v.begin(), v.end(), 5);  // First > 5

// Equal range
auto range = equal_range(v.begin(), v.end(), 5);
// Returns pair of iterators [lb, ub)

// Find if
auto it = find_if(v.begin(), v.end(), 
                  [](int x) { return x > 3; });

// Adjacent find
auto adj = adjacent_find(v.begin(), v.end());
```

## 📈 **Heap Operations**
```cpp
vector<int> v = {3, 1, 4, 1, 5, 9};

// Make heap
make_heap(v.begin(), v.end());   // Max heap: {9, 5, 4, 1, 1, 3}

// Push heap
v.push_back(6);
push_heap(v.begin(), v.end());

// Pop heap
pop_heap(v.begin(), v.end());
v.pop_back();                    // Largest element removed

// Sort heap
sort_heap(v.begin(), v.end());   // Sorts in ascending order

// Is heap
bool is_heap = is_heap(v.begin(), v.end());
```

## 📝 **I/O Manipulators** (`<iomanip>`)
```cpp
#include <iomanip>

// Formatting
cout << setw(10) << "Hello";     // Field width
cout << setfill('*') << setw(10) << "Hi"; // "*******Hi"
cout << fixed << setprecision(2) << 3.14159; // "3.14"
cout << scientific << 0.001;     // "1.00e-03"
cout << boolalpha << true;       // "true" instead of "1"
cout << hex << 255;              // "ff"
cout << oct << 64;               // "100"
cout << dec << 100;              // "100"

// Input
string s;
getline(cin, s);                 // Read line
cin >> ws;                       // Skip whitespace
```

## 🔗 **Useful Macros & Constants**
```cpp
#include <climits>
#include <cfloat>
#include <limits>

// Limits
INT_MAX, INT_MIN                 // int limits
LONG_MAX, LONG_MIN               // long limits
FLT_MAX, FLT_MIN                 // float limits
DBL_MAX, DBL_MIN                 // double limits

// C++ limits
numeric_limits<int>::max()
numeric_limits<double>::epsilon()

// Constants
#include <numbers>               // C++20
double pi = numbers::pi;
double e = numbers::e;

// Type sizes
sizeof(int);                     // Size in bytes
alignof(double);                 // Alignment requirement
```

## 🏗️ **Common Patterns**
```cpp
// Lambda expressions
auto lambda = [](int x) -> int { return x * x; };
auto capture = [&x, y](int z) { return x + y + z; };
auto generic = [](auto a, auto b) { return a + b; };

// Range-based for loop
for (const auto& item : container) {
    // Use item
}

// Structured bindings with map
unordered_map<string, int> m;
for (const auto& [key, value] : m) {
    cout << key << ": " << value;
}

// Auto type deduction
auto x = 42;                     // int
auto& ref = x;                   // int&
const auto& cref = x;            // const int&
auto* ptr = &x;                  // int*
auto&& uref = x;                 // int& (lvalue)

// decltype
decltype(x) y = x;               // Same type as x
```

## ⚡ **Performance Tips**
1. **Use `reserve()`** for vectors when size is known
2. **Emplace operations** instead of insert/push when possible
3. **Move semantics** for large objects
4. **`unordered_map`** over `map` when order not needed
5. **Algorithm over raw loops** when possible
6. **Prefer `make_shared/make_unique`** over direct constructors
7. **Use `const` references** for function parameters
8. **Reserve strings** when building from many pieces

## 🚨 **Common Pitfalls**
1. **Iterator invalidation** after container modification
2. **Dangling references/pointers** to local variables
3. **Memory leaks** from raw pointers
4. **Undefined behavior** with uninitialized variables
5. **Integer overflow** in calculations
6. **Floating point comparison** with `==`
7. **Race conditions** in multi-threaded code
8. **Exception safety** in resource management

---

**Quick Reference Legend:**
- **O(1)**: Constant time
- **O(log n)**: Logarithmic time  
- **O(n)**: Linear time
- **O(n log n)**: Linearithmic time
- **O(n²)**: Quadratic time

This cheat sheet covers the essential STL components. Bookmark it for quick reference during coding sessions!