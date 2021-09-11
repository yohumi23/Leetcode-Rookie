#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
//长度最小的子数组
class Solution {
public:
    //暴力解法
    int minSubArrayLen1(int target, vector<int>& nums) {
        int length, minLength = INT32_MAX;
        int sum;
        int i, j;
        for (i = 0; i < nums.size(); i++) {
            sum = 0;
            for (j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= target) {
                    length = j - i + 1;
                    minLength = length < minLength ? length : minLength;
                    break;
                }

            }
        }
        return (minLength == INT32_MAX ? 0 : minLength);
    }

    //滑动窗口
    int minSubArrayLen2(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sublength = 0, sum = 0;
        int start = 0;
        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];
            while (sum >= target) {
                sublength = end - start + 1;
                result = result < sublength ? result : sublength;
                sum -= nums[start++];
            }
        }
        result = (result == INT32_MAX ? 0 : result);
        return result;

    }

};
class Instruction {
public:
    int minSubArrayLen3(int s, vector<int>& nums) {
        int result = INT32_MAX; // 最终的结果
        int sum = 0; // 子序列的数值之和
        int subLength = 0; // 子序列的长度
        for (int i = 0; i < nums.size(); i++) { // 设置子序列起点为i
            sum = 0;
            for (int j = i; j < nums.size(); j++) { // 设置子序列终止位置为j
                sum += nums[j];
                if (sum >= s) { // 一旦发现子序列和超过了s，更新result
                    subLength = j - i + 1; // 取子序列的长度
                    result = result < subLength ? result : subLength;
                    break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
                }
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
    int minSubArrayLen4(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};

//int main() {
//    int nums[] = { 2,3,1,2,4,3 };
//    vector<int> arr(nums, nums +  sizeof(nums) / sizeof(int));
//    Solution solution;
//    cout << solution.minSubArrayLen2(7, arr);
//    return 0;
//}
