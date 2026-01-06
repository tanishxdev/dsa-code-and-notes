#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// Tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        queue<TreeNode *> q;
        q.push(root);

        int level = 1;
        int answerLevel = 1;
        int maxSum = INT_MIN;

        while (!q.empty())
        {

            int levelSize = q.size();
            int sum = 0;

            // calculate sum of current level
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                sum += curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            // update only if strictly greater
            if (sum > maxSum)
            {
                maxSum = sum;
                answerLevel = level;
            }

            level++;
        }

        return answerLevel;
    }
};

int main()
{
}