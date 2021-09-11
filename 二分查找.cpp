#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] > target) {
                high = mid - 1;
            }
            else if (target > nums[mid]) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};
//int main() {
//    int a[] = { 11, 22, 33, 44, 55, 66 };
//    vector<int> arr(a, a + sizeof(a) / sizeof(int));
//    Solution solution;
//    cout << solution.search(arr, 66) << endl;
//    
//}