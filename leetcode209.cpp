#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    //�����ⷨ
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

    //��������
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
        int result = INT32_MAX; // ���յĽ��
        int sum = 0; // �����е���ֵ֮��
        int subLength = 0; // �����еĳ���
        for (int i = 0; i < nums.size(); i++) { // �������������Ϊi
            sum = 0;
            for (int j = i; j < nums.size(); j++) { // ������������ֹλ��Ϊj
                sum += nums[j];
                if (sum >= s) { // һ�����������кͳ�����s������result
                    subLength = j - i + 1; // ȡ�����еĳ���
                    result = result < subLength ? result : subLength;
                    break; // ��Ϊ�������ҷ���������̵������У�����һ������������break
                }
            }
        }
        // ���resultû�б���ֵ�Ļ����ͷ���0��˵��û�з���������������
        return result == INT32_MAX ? 0 : result;
    }
    int minSubArrayLen4(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // ����������ֵ֮��
        int i = 0; // ����������ʼλ��
        int subLength = 0; // �������ڵĳ���
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // ע������ʹ��while��ÿ�θ��� i����ʼλ�ã��������ϱȽ��������Ƿ��������
            while (sum >= s) {
                subLength = (j - i + 1); // ȡ�����еĳ���
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // �������ֳ��������ڵľ���֮�������ϱ��i�������е���ʼλ�ã�
            }
        }
        // ���resultû�б���ֵ�Ļ����ͷ���0��˵��û�з���������������
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