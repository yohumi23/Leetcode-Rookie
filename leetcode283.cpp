#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
//整体思路，先不管0，最后填0
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != 0) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        while (slowIndex != nums.size()) {
            nums[slowIndex++] = 0;
        }

    }
};
