#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //��������
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> buckets;
        int slow = 0;
        int result = 0;
        for (int fast = 0; fast < fruits.size(); fast++) {
            buckets[fruits[fast]]++;//fast����һֱ�������������ͽ�����Ӧkey-value��
            while (buckets.size() > 2) {//�ı䴰����ʼλ��
                buckets[fruits[slow]]--;
                if (buckets[fruits[slow]] == 0) {
                    buckets.erase(fruits[slow]);
                }
                //result = result > fast - slow ? result : fast - slow;���ܷŽ�ȥ���������û�г��ֵ�����ˮ������ô���Ƿ���0������Ȼ�ǲ���ȷ��
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
        unordered_map<int, int> buckets;//unordered_map�Զ�������ֵ�ԡ�
        int result = 0;
        for (int fast = 0; fast < fruits.size(); fast++) {
            buckets[fruits[fast]]++;
            while (buckets.size() > 2) {
                buckets[fruits[slow]]--;//���ոս����ļ�ֵ�Ե�value��һ
                if (buckets[fruits[slow]] == 0) {
                    buckets.erase(fruits[slow]);//ɾ�������ֵ��
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

