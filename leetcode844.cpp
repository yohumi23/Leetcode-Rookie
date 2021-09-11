#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
//�ȽϺ��˸���ַ���
class Solution {
public:
    bool backspaceCompare2(string s, string t) {
        stack<char> stS;
        stack<char> stT;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                stS.push(s[i]);
            }
            else if (s[i] == '#' && !stS.empty()) {
                stS.pop();
            }
        }
        for (int i = 0; i < t.length(); i++) {
            if (t[i] != '#') {
                stT.push(t[i]);
            }
            else if (t[i] == '#' && !stT.empty()) {
                stT.pop();
            }
        }
        if (stS.size() != stT.size()) {
            return false;
        }
        while (!stS.empty() && !stT.empty()) {
            if (stS.top() != stT.top()) {
                return false;
            }
            stS.pop();
            stT.pop();
        }
        return true;
    }
    /*
    �ⷨ2��
    ˫ָ�룬���ǿ���ά����������������¼���˸�ĸ�����Ȼ��������ַ�����������ǰ�ַ��Ƿ���Ҫ������������Щ�����뿴����

    ����1������ά������������ skipS �� skipT��Ȼ��ʼ��������ַ���
    ����2��������������#��ʱ������Ӧ�ļ����� + 1�������������ַ�ʱ���������µ��жϣ�
    ����˸������Ϊ0����ô���ַ��޷���������ʱӦ�ñȶԵ�ǰ���ַ��Ƿ���ͬ
    ����˸������ >= 0����ô���ַ���Ҫ������������Ҫ�ñ���ָ����ǰ��һλ��ͬʱ�ü����� - 1
    ����3��������������У���������λ���ϵ��ַ�������ͬ������������һ���ַ����Ѿ������꣬��ôֱ�ӷ��� false�����������ǰ����ʣ�µ��ַ�
    �����������ַ������Ѿ������꣬��ô֤�����Ǿ����˸�Ĳ���������ȵ��ַ��������� true��ʱ�临�Ӷ��� O(N)���ռ临�Ӷ���O(1)
    
    */
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {//��������������ֻ�������������1.�����˸񣬼�¼������2.�����˸�ǰ���ַ�
                if (S[i] == '#') {
                    skipS++, i--;
                }
                else if (skipS > 0) {
                    skipS--, i--;
                }
                else {
                    break;
                }
            }
            while (j >= 0) {
                if (T[j] == '#') {
                    skipT++, j--;
                }
                else if (skipT > 0) {
                    skipT--, j--;
                }
                else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (S[i] != T[j]) {
                    return false;
                }
            }
            else {
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }
            i--, j--;
        }
        return true;
    }
};

//int main() {
//    string s = "bbbextm";
//    string t = "bbb#extm";
//    Solution solution;
//    bool flag = solution.backspaceCompare2(s, t);
//    if (flag) {
//        cout << "��ͬ" << endl;
//    }
//    else {
//        cout << "��ͬ" << endl;
//    }
//    return 0;
//}


