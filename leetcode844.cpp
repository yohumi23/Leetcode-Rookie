#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
//比较含退格的字符串
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
    解法2：
    双指针，我们可以维护两个计数器，记录下退格的个数，然后倒序遍历字符串来决定当前字符是否需要跳过，可能有些抽象，请看步骤

    步骤1：我们维护两个计数器 skipS 和 skipT，然后开始倒序遍历字符串
    步骤2：当我们遇到‘#’时，将对应的计数器 + 1；当我们遇到字符时，会有如下的判断：
    如果退格计数器为0，那么该字符无法跳过，此时应该比对当前的字符是否相同
    如果退格计数器 >= 0，那么该字符需要跳过，所以需要让遍历指针往前移一位，同时让计数器 - 1
    步骤3：如果遍历过程中，发现两个位置上的字符并不相同，或者有其中一个字符串已经遍历完，那么直接返回 false，否则继续往前遍历剩下的字符
    最后如果两个字符串都已经遍历完，那么证明它们经过退格的操作后是相等的字符串，返回 true；时间复杂度是 O(N)，空间复杂度是O(1)
    
    */
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {//单个数组内我们只处理两种情况，1.遇到退格，记录下来。2.遇到退格前的字符
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
//        cout << "相同" << endl;
//    }
//    else {
//        cout << "不同" << endl;
//    }
//    return 0;
//}


