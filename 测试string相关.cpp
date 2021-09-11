#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
//将字符串转换成字符数组的方法
int main() {

	/*string s = "geeksforgeeks";
	for (int i = 0; i < s.length(); i++) {
		cout << s[i] << ' ';
	}*/
	/*string b;
	b = b + 'n';
	string c;
	c = c + 'n';
	if (b == c) cout << "good" << endl;
	cout << b << endl;
	string d, e;
	if (d == e) cout << "d == e" << endl;
	string a = "hello";
	cout << a.size() << endl;
	const char* p = a.c_str();*/
	vector<vector<int>> res(4, vector<int>(3, 0));
	res = { {1, 2, 3} ,{4, 5, 6},{7, 8, 9 }, {10, 11, 12} };
	cout << res.size() << endl;

	return 0;
}