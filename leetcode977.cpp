#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
//有序数组的平方
/*# 思路

## 暴力排序

最直观的相反，莫过于：每个数平方之后，排个序，美滋滋，代码如下：

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end()); // 快速排序
        return A;
    }
};
这个时间复杂度是 O(n + nlogn)， 可以说是O(nlogn)的时间复杂度，但为了和下面双指针法算法时间复杂度有鲜明对比，我记为 O(n + nlogn)。

## 双指针法

数组其实是有序的， 只不过负数平方之后可能成为最大数了。

那么数组平方的最大值就在数组的两端，不是最左边就是最右边，不可能是中间。

此时可以考虑双指针法了，i指向起始位置，j指向终止位置。

定义一个新数组result，和A数组一样的大小，让k指向result数组终止位置。

如果A[i] * A[i] < A[j] * A[j] 那么result[k--] = A[j] * A[j]; 。

如果A[i] * A[i] >= A[j] * A[j] 那么result[k--] = A[i] * A[i]; 。


不难写出如下代码：

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j])  {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};
此时的时间复杂度为O(n)，相对于暴力排序的解法O(n + nlogn)还是提升不少的。

**这里还是说一下，大家不必太在意leetcode上执行用时，打败多少多少用户，这个就是一个玩具，非常不准确。**

做题的时候自己能分析出来时间复杂度就可以了，至于leetcode上执行用时，大概看一下就行，只要达到最优的时间复杂度就可以了，

一样的代码多提交几次可能就击败百分之百了.....
* 
* 
* 
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int k = nums.size() - 1;
        int length = nums.size();
        vector<int> sorted(nums.size(), 0);
        while (left <= right) {
            if (pow(nums[left], 2) < pow(nums[right], 2)) {
                sorted[k--] = pow(nums[right], 2);
                right--;
            }
            else {
                sorted[k--] = pow(nums[left], 2);
                left++;
            }
        }
        return sorted;
    }
};
//int main() {
//    int nums[] = { -4, - 1, 0, 3, 10 };
//    vector<int> arr(nums, nums +  sizeof(nums) / sizeof(int));
//    Solution solution;
//    arr = solution.sortedSquares(arr);
//    for (int i = 0; i < arr.size(); i++) {
//        cout << arr[i];
//        cout << ' ';
//    }
//    return 0;
//}