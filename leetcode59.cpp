#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
//过程模拟
//class Solution {
//public:
//    vector<vector<int>> generateMatrix(int n) {
//        vector<vector<int> > res(n, vector<int>(n, 0));
//        int startx = 0, starty = 0;
//        int loop = n / 2;
//        int mid = n / 2;
//        int count = 1;//用来给矩阵中每一个空格赋值
//        int offset = 1;//每一圈循环需要控制每一条边遍历的长度
//        int i, j;
//        while (loop--) {
//            i = startx;
//            j = starty;
//            for(j = starty; j < )
//        }
//    }
//};

class Instruction {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int starty = 0, startx = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2; // (n为奇数专用)矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1; // 用来给矩阵中每一个空格赋值
        int offset = 1; // 每一圈循环，需要控制每一条边遍历的长度
        int i, j;
        while (loop--) {
            i = starty;
            j = startx;

            // 下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右(左闭右开)
            for (j = startx; j < startx + n - offset; j++) {
                res[starty][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = starty; i < starty + n - offset; i++) {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > startx; j--) {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > starty; i--) {
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            starty++;
            startx++;

            // offset 控制每一圈里每一条边遍历的长度
            offset += 2;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};