#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
//���������ƽ��
/*# ˼·

## ��������

��ֱ�۵��෴��Ī���ڣ�ÿ����ƽ��֮���Ÿ��������̣��������£�

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end()); // ��������
        return A;
    }
};
���ʱ�临�Ӷ��� O(n + nlogn)�� ����˵��O(nlogn)��ʱ�临�Ӷȣ���Ϊ�˺�����˫ָ�뷨�㷨ʱ�临�Ӷ��������Աȣ��Ҽ�Ϊ O(n + nlogn)��

## ˫ָ�뷨

������ʵ������ģ� ֻ��������ƽ��֮����ܳ�Ϊ������ˡ�

��ô����ƽ�������ֵ������������ˣ���������߾������ұߣ����������м䡣

��ʱ���Կ���˫ָ�뷨�ˣ�iָ����ʼλ�ã�jָ����ֹλ�á�

����һ��������result����A����һ���Ĵ�С����kָ��result������ֹλ�á�

���A[i] * A[i] < A[j] * A[j] ��ôresult[k--] = A[j] * A[j]; ��

���A[i] * A[i] >= A[j] * A[j] ��ôresult[k--] = A[i] * A[i]; ��


����д�����´��룺

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) { // ע������Ҫi <= j����Ϊ���Ҫ��������Ԫ��
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
��ʱ��ʱ�临�Ӷ�ΪO(n)������ڱ�������ĽⷨO(n + nlogn)�����������ٵġ�

**���ﻹ��˵һ�£���Ҳ���̫����leetcode��ִ����ʱ����ܶ��ٶ����û����������һ����ߣ��ǳ���׼ȷ��**

�����ʱ���Լ��ܷ�������ʱ�临�ӶȾͿ����ˣ�����leetcode��ִ����ʱ����ſ�һ�¾��У�ֻҪ�ﵽ���ŵ�ʱ�临�ӶȾͿ����ˣ�

һ���Ĵ�����ύ���ο��ܾͻ��ܰٷ�֮����.....
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