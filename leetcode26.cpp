#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
//删除有序数组中的重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < (nums.size() - 1); fastIndex++) {
            if (nums[fastIndex] != nums[fastIndex + 1]) {
                nums[++slowIndex] = nums[fastIndex + 1];
            }
        }
        return slowIndex + 1;
    }
};
class DALAO{
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // 别忘记空数组的判断
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < (nums.size() - 1); fastIndex++) {
            if (nums[fastIndex] != nums[fastIndex + 1]) { // 发现和后一个不相同
                nums[++slowIndex] = nums[fastIndex + 1]; //slowIndex = 0 的数据一定是不重复的，所以直接 ++slowIndex
            }//怎么理解？？就是把遇到的第一个不重复的放在数组中，这里默认nums[0]就是不重复的
        }
        return slowIndex + 1; //别忘了slowIndex是从0开始的，所以返回slowIndex + 1
    }
};

