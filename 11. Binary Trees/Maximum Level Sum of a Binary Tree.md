## Concept (Soch ka tareeqa)

Binary Tree ko **levels** me dekho:

- Level 0 → root
- Level 1 → root ke children
- Level 2 → grandchildren
- …

Har level par:

- us level ke **saare nodes ka sum**
- phir next level

Iska best tool hai **Queue + BFS (Level Order Traversal)**.

---

## Example Tree (Samajhne ke liye)

![Image](https://favtutor.com/resources/images/uploads/Fig%202.jpg)

![Image](https://media.geeksforgeeks.org/wp-content/uploads/Tree_level.png)

```
        1
      /   \
     2     3
    / \     \
   4   5     6
```

Level-wise nodes:

- Level 0 → [1] → sum = 1
- Level 1 → [2, 3] → sum = 5
- Level 2 → [4, 5, 6] → sum = 15

Output: **[1, 5, 15]**

---

## Algorithm (Step-by-step)

1. Agar root null → return empty
2. Queue me root daalo
3. Jab tak queue empty na ho:

   - current level ka `size = queue.size()`
   - `levelSum = 0`
   - `size` times loop chalao:

     - node nikalo
     - `levelSum += node->val`
     - left/right child ho to queue me daalo

   - `levelSum` ko answer me store karo

---

## C++ Code (Detailed comments)

```cpp
// Binary Tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

#include <queue>
#include <vector>
using namespace std;

vector<int> levelSum(TreeNode* root) {
    vector<int> result;

    // Edge case: empty tree
    if (root == NULL) return result;

    queue<TreeNode*> q;
    q.push(root);

    // Level Order Traversal
    while (!q.empty()) {

        int levelSize = q.size();  // nodes count in current level
        int sum = 0;

        // Process current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* curr = q.front();
            q.pop();

            sum += curr->val;  // add node value

            // push children for next level
            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }

        // store sum of this level
        result.push_back(sum);
    }

    return result;
}
```

---

## Dry Run (Queue ka flow)

Initial:

```
Queue: [1]
```

Iteration 1:

```
levelSize = 1
sum = 1
Queue -> [2, 3]
result = [1]
```

Iteration 2:

```
levelSize = 2
sum = 2 + 3 = 5
Queue -> [4, 5, 6]
result = [1, 5]
```

Iteration 3:

```
levelSize = 3
sum = 4 + 5 + 6 = 15
Queue -> []
result = [1, 5, 15]
```

---

## Time & Space Complexity

- **Time:** `O(N)`
  (Har node ek baar visit hota hai)

- **Space:** `O(N)`
  (Queue me worst case ek full level aa sakta hai)

---

## Interview Notes

- Ye problem **Level Order Traversal ka direct extension** hai
- Follow-up aa sakta hai:

  - maximum level sum
  - minimum level sum
  - deepest level sum

- DFS se bhi ho sakta hai (map + level), par BFS zyada clean hai

---

follow-up hai.

👉 **Goal:**

> **Maximum level sum** nikalna hai **aur agar tie ho (same max sum)**
> to **sabse chhota level index (smallest level)** return karna hai.

(Level numbering usually **1-based** hoti hai in interviews unless specified.)

---

## Concept (Soch ka model)

Hum already **level order traversal** kar rahe hain.
Bas humein extra cheeze track karni hain:

### Track these:

1. `level` → current level number
2. `maxSum` → ab tak ka maximum level sum
3. `answerLevel` → jis level ka sum max hai

### Rule:

- Agar `currentSum > maxSum`
  → update both `maxSum` & `answerLevel`
- Agar `currentSum == maxSum`
  → **ignore** (kyunki pehla / smallest level already stored hai)

Isliye BFS naturally kaam karta hai.

---

## Example

![Image](https://favtutor.com/resources/images/uploads/Fig%202.jpg)

![Image](https://media.geeksforgeeks.org/wp-content/uploads/Tree_level.png)

```
        1
      /   \
     2     3
    / \     \
   4   5     6
```

Level sums:

- Level 1 → 1
- Level 2 → 2+3 = 5
- Level 3 → 4+5+6 = 15 ← max

👉 Output: **3**

Agar do levels ka sum same hota:

```
Level 2 = 10
Level 4 = 10
```

👉 Return **2** (smallest level)

---

## Algorithm (Step-by-step)

1. Queue me root daalo
2. `level = 1`
3. For each level:

   - calculate `levelSum`
   - compare with `maxSum`
   - update only if strictly greater

4. `level++`

---

## C++ Code (Detailed comments)

```cpp
#include <queue>
using namespace std;

// Tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

int smallestLevelWithMaxSum(TreeNode* root) {

    if (root == NULL) return 0;

    queue<TreeNode*> q;
    q.push(root);

    int level = 1;
    int answerLevel = 1;
    int maxSum = INT_MIN;

    while (!q.empty()) {

        int levelSize = q.size();
        int sum = 0;

        // calculate sum of current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* curr = q.front();
            q.pop();

            sum += curr->val;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        // update only if strictly greater
        if (sum > maxSum) {
            maxSum = sum;
            answerLevel = level;
        }

        level++;
    }

    return answerLevel;
}
```

---

## Dry Run (Important part)

Initial:

```
level = 1, maxSum = -inf
```

Level 1:

```
sum = 1 > maxSum
maxSum = 1, answerLevel = 1
```

Level 2:

```
sum = 5 > maxSum
maxSum = 5, answerLevel = 2
```

Level 3:

```
sum = 15 > maxSum
maxSum = 15, answerLevel = 3
```

Return **3**

---

## Time & Space Complexity

- **Time:** `O(N)`
- **Space:** `O(N)` (queue)

---

## Interview Follow-ups (Very common)

1. **Return max sum instead of level**
2. **Return both (level, sum)**
3. **0-based vs 1-based level**
4. **Negative values in tree**
5. **DFS solution using map**

---

## Interview One-liner

> “I used level-order traversal and tracked the maximum sum while preserving the earliest level by updating only on strictly greater sums.”

---
