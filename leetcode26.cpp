#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
//ɾ���������ظ�Ԫ��
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
        if (nums.empty()) return 0; // �����ǿ�������ж�
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < (nums.size() - 1); fastIndex++) {
            if (nums[fastIndex] != nums[fastIndex + 1]) { // ���ֺͺ�һ������ͬ
                nums[++slowIndex] = nums[fastIndex + 1]; //slowIndex = 0 ������һ���ǲ��ظ��ģ�����ֱ�� ++slowIndex
            }//��ô��⣿�����ǰ������ĵ�һ�����ظ��ķ��������У�����Ĭ��nums[0]���ǲ��ظ���
        }
        return slowIndex + 1; //������slowIndex�Ǵ�0��ʼ�ģ����Է���slowIndex + 1
    }
};

