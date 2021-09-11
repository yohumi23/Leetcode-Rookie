#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
//最小覆盖子串
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        for (auto x : t) ht[x]++;
        string res;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            hs[s[i]]++;
            if (hs[s[i]] <= ht[s[i]]) cnt++;
            while (hs[s[j]] > ht[s[j]] ) hs[s[j++]]--;
            while(hs[s[j]] > ht[s[j]]) hs[s[j++]] --;
            
            if (cnt == t.size()) {
                if (res.empty() || i - j + 1 < res.size()) {
                    res = s.substr(j, i - j + 1);
                }
            }
        }
        return  res;
    }
};
class Instruction {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        for (auto c : t) ht[c] ++;//为t建立一个对应的哈希表
        string res;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            hs[s[i]] ++;
            if (hs[s[i]] <= ht[s[i]]) cnt++;

            while (hs[s[j]] > ht[s[j]]) hs[s[j++]] --;
            if (cnt == t.size()) {
                if (res.empty() || i - j + 1 < res.size())
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};

//int main() {
//    string s = ""
//
//}

