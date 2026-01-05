#include <bits/stdc++.h>
using namespace std;

/*
    Solution class
    LeetCode expects this structure.
*/
class Solution
{
public:
    /*
        Function: numMagicSquaresInside

        Input:
        - grid: 2D matrix of integers

        Output:
        - Number of 3x3 magic square subgrids
    */
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        /*
            Number of rows in the grid
            grid.size() returns how many row-vectors exist
        */
        int rows = grid.size();

        /*
            Number of columns in the grid
            grid[0] is the first row
            grid[0].size() is number of elements in that row
        */
        int cols = grid[0].size();

        /*
            Counter to store number of valid magic squares
        */
        int count = 0;

        /*
            We iterate only till rows-3 and cols-3
            because we need a full 3x3 window.
        */
        for (int i = 0; i <= rows - 3; i++)
        {
            for (int j = 0; j <= cols - 3; j++)
            {

                /*
                    STEP 1: Center must be 5

                    In any 3x3 magic square using numbers 1..9,
                    the center element is always 5.

                    Center of current 3x3 subgrid is:
                    (i+1, j+1)
                */
                if (grid[i + 1][j + 1] != 5)
                    continue; // reject early

                /*
                    STEP 2: Range + distinct check

                    used[] array keeps track of which numbers
                    from 1..9 have already appeared.
                */
                bool used[10] = {false}; // index 1 to 9 used
                bool valid = true;

                /*
                    Traverse all 9 cells of the 3x3 subgrid
                */
                for (int r = i; r < i + 3 && valid; r++)
                {
                    for (int c = j; c < j + 3; c++)
                    {
                        int val = grid[r][c];

                        /*
                            Range check:
                            value must be between 1 and 9

                            Distinct check:
                            value must not repeat
                        */
                        if (val < 1 || val > 9 || used[val])
                        {
                            valid = false;
                            break;
                        }

                        // Mark this value as seen
                        used[val] = true;
                    }
                }

                // If range/distinct failed, skip this window
                if (!valid)
                    continue;

                /*
                    STEP 3: Check row sums

                    Each row in magic square must sum to 15
                */
                for (int r = i; r < i + 3; r++)
                {
                    int sum = 0;

                    for (int c = j; c < j + 3; c++)
                        sum += grid[r][c];

                    if (sum != 15)
                    {
                        valid = false;
                        break;
                    }
                }

                if (!valid)
                    continue;

                /*
                    STEP 4: Check column sums

                    Each column must also sum to 15
                */
                for (int c = j; c < j + 3; c++)
                {
                    int sum = 0;

                    for (int r = i; r < i + 3; r++)
                        sum += grid[r][c];

                    if (sum != 15)
                    {
                        valid = false;
                        break;
                    }
                }

                if (!valid)
                    continue;

                /*
                    STEP 5: Check diagonals

                    Main diagonal:
                    (i,j) -> (i+1,j+1) -> (i+2,j+2)

                    Anti diagonal:
                    (i,j+2) -> (i+1,j+1) -> (i+2,j)
                */
                int d1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];

                int d2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

                /*
                    If both diagonals sum to 15,
                    this is a valid magic square
                */
                if (d1 == 15 && d2 == 15)
                {
                    count++;
                }
            }
        }

        return count;
    }
};

/*
    MAIN FUNCTION
    Used for local testing only.
*/
int main()
{
    /*
        Sample grid for testing

        Note:
        - Grid values can go from 0 to 15
        - Only 1..9 are valid inside magic square
    */
    vector<vector<int>> grid = {
        {4, 3, 8, 4},
        {9, 5, 1, 9},
        {2, 7, 6, 2},
    };

    /*
        Create Solution object
    */
    Solution obj;

    /*
        Call function and print result
    */
    cout << obj.numMagicSquaresInside(grid) << endl;

    return 0;
}
