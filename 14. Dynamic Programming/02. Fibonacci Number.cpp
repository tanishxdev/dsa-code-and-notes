// OPTIMAL APPROACH (Bottom-Up DP / Space Optimized)

class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }

        int prev2 = 0;
        int prev1 = 1;
        int current;

        for (int i = 2; i <= n; i++)
        {
            current = prev2 + prev1;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};