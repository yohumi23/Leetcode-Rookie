#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //滑动窗口
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> buckets;
        int slow = 0;
        int result = 0;
        for (int fast = 0; fast < fruits.size(); fast++) {
            buckets[fruits[fast]]++;//fast用来一直遍历，遍历到就建立对应key-value对
            while (buckets.size() > 2) {//改变窗口起始位置
                buckets[fruits[slow]]--;
                if (buckets[fruits[slow]] == 0) {
                    buckets.erase(fruits[slow]);
                }
                //result = result > fast - slow ? result : fast - slow;不能放进去，如果从来没有出现第三种水果，那么岂不是返回0？这显然是不正确的
                slow++;
            }
            result = result > fast - slow ? result : fast - slow;
        }
        return result;
    }
};

class Instruction {
public:
    int totalFruit2(vector<int>& fruits) {
        int slow = 0;
        unordered_map<int, int> buckets;//unordered_map自动建立键值对。
        int result = 0;
        for (int fast = 0; fast < fruits.size(); fast++) {
            buckets[fruits[fast]]++;
            while (buckets.size() > 2) {
                buckets[fruits[slow]]--;//将刚刚建立的键值对的value减一
                if (buckets[fruits[slow]] == 0) {
                    buckets.erase(fruits[slow]);//删除这个键值对
                }
                slow++;
            }
            result = result < fast - slow + 1 ? fast - slow + 1 : result;
        }

        return result;
    }
};
//int main() {
//    int nums[] = { 0, 1, 2, 2 };
//    vector<int> arr(nums, nums + sizeof(nums) / sizeof(int));
//    Solution solution;
//    cout << solution.totalFruit(arr);
//    return 0;
//}

