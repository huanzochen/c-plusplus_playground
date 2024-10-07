/**
 * On an infinite number line, we are given instructions [1, x] or [2, x, size]. [1, x] means to put an obstable at location x, and [2, x, size] means return True if there is no obstable between x and x+size-1, inclusive of the endpoints. Return a string of "1" (True) and "0" (False) representing the results of [2, x, size] instructions.



Ex. instructions = [ [1, 2], [1, 5], [2, 3, 2], [2, 3, 3], [2, 1, 1], [2, 1, 2] ]. Correct answer = "1010".



I put the obstacles into a set. Then for every [2, x, size] instruction, I check for every obstacle in the set, whether x <= obstacle <= x+size-1. The runtime is bad for situations where there are a huge number of [1, x] instructions. Any suggestion on the correct solution?


 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//https://oi-wiki.org/ds/seg/
class SegmentTree {
public:
    SegmentTree(int n) : n(n) {
        tree.resize(2 * n, 0);
    }

    void update(int pos, int value) {
        pos += n;
        tree[pos] = value;
        while (pos > 1) {
            pos /= 2;
            tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
        }
    }

    int query(int left, int right) {
        left += n;
        right += n;
        int sum = 0;
        while (left < right) {
            if (left % 2 == 1) {
                sum += tree[left];
                left++;
            }
            if (right % 2 == 1) {
                right--;
                sum += tree[right];
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }

private:
    int n;
    vector<int> tree;
};

string processInstructions(const vector<vector<int>>& instructions) {
    int max_pos = 0;
    for (const auto& instr : instructions) {
        for (size_t i = 1; i < instr.size(); ++i) {
            max_pos = max(max_pos, instr[i]);
        }
    }

    SegmentTree segTree(max_pos + 1);
    string result;

    for (const auto& instr : instructions) {
        if (instr[0] == 1) {
            segTree.update(instr[1], 1);
        } else if (instr[0] == 2) {
            int x = instr[1];
            int size = instr[2];
            if (segTree.query(x, x + size) == 0) {
                result += "1";
            } else {
                result += "0";
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> instructions = { {1, 2}, {1, 5}, {2, 3, 2}, {2, 3, 3}, {2, 1, 1}, {2, 1, 2} };
    string result = processInstructions(instructions);
    cout << result << endl;  // 输出 "1010"
    return 0;
}
