#include <bits/stdc++.h>
using namespace std;

/*
Backtracking function

current → current row string
idx     → index in current row
above   → row being built above
mp      → allowed transitions map
memo    → memoization map
*/
bool solve(string &current,
           int idx,
           string &above,
           unordered_map<string, vector<char>> &mp,
           unordered_map<string, bool> &memo)
{

    // BASE CASE 1:
    // If current row length is 1, pyramid is complete
    if (current.length() == 1)
    {
        return true;
    }

    // Create a unique memoization key
    string key = current + "|" + to_string(idx) + "|" + above;
    if (memo.count(key))
    {
        return memo[key];
    }

    // BASE CASE 2:
    // Finished processing current row, move to next row
    if (idx == current.length() - 1)
    {
        string nextRow = above;
        string empty = "";
        bool result = solve(nextRow, 0, empty, mp, memo);
        return memo[key] = result;
    }

    // Form pair of adjacent characters
    string pair = current.substr(idx, 2);

    // If no allowed transition exists → dead end
    if (!mp.count(pair))
    {
        return memo[key] = false;
    }

    // Try all possible top blocks
    for (char ch : mp[pair])
    {
        // DO
        above.push_back(ch);

        // EXPLORE
        if (solve(current, idx + 1, above, mp, memo))
        {
            return memo[key] = true;
        }

        // UNDO
        above.pop_back();
    }

    // If no valid option works
    return memo[key] = false;
}

/*
MAIN FUNCTION
*/
class Solution
{
public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {

        // STEP 1: Build transition map
        unordered_map<string, vector<char>> mp;

        for (string &pattern : allowed)
        {
            string base = pattern.substr(0, 2);
            char top = pattern[2];
            mp[base].push_back(top);
        }

        // STEP 2: Memoization map
        unordered_map<string, bool> memo;

        // STEP 3: Start backtracking
        string above = "";
        return solve(bottom, 0, above, mp, memo);
    }
};

int main()
{
    Solution sol;

    // Example test
    string bottom = "BCD";
    vector<string> allowed = {"BCC", "CDE", "CEA", "FFF"};

    cout << (sol.pyramidTransition(bottom, allowed) ? "true" : "false") << endl;

    return 0;
}