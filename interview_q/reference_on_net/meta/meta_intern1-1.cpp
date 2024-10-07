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

class SegmentTree{
    int n;
    vector<int> tree;
public:
    SegmentTree(int n) : n(n){
        tree.resize(2*n, 0);
    }

    void update(int pos, int value){
        pos+= n;
        tree[pos] = value;
        while(pos > 1) {
            pos /=2;
            tree[pos] = tree[2*pos] + tree[2*pos +1];
        }
    }

    int query(int left, int right){
        left+=n;
        right+=n;
        int sum = 0;
        while(left < right){
            if(left%2 ==1){
                sum+= tree[left];
                left++;
            }
            if(right %2 == 1){
                right--;
                sum+= tree[right];
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

string processInstructions(vector<vector<int>> &instructions) {
    int maxPos = 0;
    for(vector<int> &instr: instructions){
        int n = instr.size();
        for(int i = 1; i < n;i++){
            // 找出區間內最大的邊界在哪裡
            maxPos = max(maxPos, instr[1]);
        }
    }

    // 線段樹實現
    SegmentTree segTree(maxPos + 1);
    string result;

    for(const auto & instr: instructions){
        if(instr[0] == 1){
            segTree.update(instr[1], 1);
        } else if(instr[0] == 2){
            int x = instr[1];
            int sz = instr[2];

            if(segTree.query(x, x + sz) == 0){
                result += "1";
            } else {
                result +="0";
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> instructions = { {1, 2}, {1, 5}, {2, 3, 2}, {2, 3, 3}, {2, 1, 1}, {2, 1, 2} };
    string result = processInstructions(instructions);
    cout << result << endl;  // 输出 "1010"
    vector<std::vector<int>> instructions2 = {
    {1, 10}, {1, 20}, {2, 5, 5}, {2, 15, 5}, {2, 10, 1}, {2, 20, 1}
};
    string result2 = processInstructions(instructions2);
    cout << result2 << endl; // Expected output: "1100"
    return 0;
}
