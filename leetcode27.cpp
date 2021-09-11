#include <iostream>
#include <vector>

using namespace std;
//删除数组中的指定元素
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            if (nums[i] == val) {
                for (int j = i+1; j < length; j++) {
                    nums[j - 1] = nums[j];
                }
                i--;
                length--;                  
            }
        }
        return length;
    }
    //快慢指针法
    //时间复杂度O(N)
    int removeElement2(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};
//int main() {
//    int a[] = { 0,1,2,2,3,0,4,2 };
//    vector<int>  arr(a, a + sizeof(a) / sizeof(int));
//    Solution solution;
//    cout << solution.removeElement(arr, 2);
//
//
//}