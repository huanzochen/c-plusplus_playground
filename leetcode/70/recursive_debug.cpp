class Solution {
    int c = 0;

public:
    int climbStairs(int n) {
        // Find n ways to climb to the top when reach step n

        // start from zero
        return climb(0, n);
    }

    // example of n = 3

    // 1 + 1 + 1(this is when i==n)
    // 1 + 2(this is when i==n)
    // 2 + 1

    int climb(int i, int n) {
        // debugger(c++);
        // cout << "i: " << i << endl;

        // base case
        if (i == n) {
            // debugger(c--);
            // cout << "i==n" << endl;
            // means reach the end of this approach
            return 1;
        }
        if (i > n) {
            // debugger(c--);
            // cout << "i>n" << endl;
            // over the limit
            return 0;
        }

        // general case
        int oneStep = climb(i + 1, n);
        int twoStep = climb(i + 2, n);

        // debugger(c--);
        // cout << "oneStep + twoStep: " << (oneStep + twoStep) <<  endl;
        return oneStep + twoStep;
    }

    void debugger(int c) {
        cout << "c: " << c;
        for (int i = 0; i < c; i++) {
            cout << " ";
        }
    }
};