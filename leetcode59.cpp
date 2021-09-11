#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
//����ģ��
//class Solution {
//public:
//    vector<vector<int>> generateMatrix(int n) {
//        vector<vector<int> > res(n, vector<int>(n, 0));
//        int startx = 0, starty = 0;
//        int loop = n / 2;
//        int mid = n / 2;
//        int count = 1;//������������ÿһ���ո�ֵ
//        int offset = 1;//ÿһȦѭ����Ҫ����ÿһ���߱����ĳ���
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
        vector<vector<int>> res(n, vector<int>(n, 0)); // ʹ��vector����һ����ά����
        int starty = 0, startx = 0; // ����ÿѭ��һ��Ȧ����ʼλ��
        int loop = n / 2; // ÿ��Ȧѭ�����Σ�����nΪ����3����ôloop = 1 ֻ��ѭ��һȦ�������м��ֵ��Ҫ��������
        int mid = n / 2; // (nΪ����ר��)�����м��λ�ã����磺nΪ3�� �м��λ�þ���(1��1)��nΪ5���м�λ��Ϊ(2, 2)
        int count = 1; // ������������ÿһ���ո�ֵ
        int offset = 1; // ÿһȦѭ������Ҫ����ÿһ���߱����ĳ���
        int i, j;
        while (loop--) {
            i = starty;
            j = startx;

            // ���濪ʼ���ĸ�for����ģ��ת��һȦ
            // ģ��������д�����(����ҿ�)
            for (j = startx; j < startx + n - offset; j++) {
                res[starty][j] = count++;
            }
            // ģ��������д��ϵ���(����ҿ�)
            for (i = starty; i < starty + n - offset; i++) {
                res[i][j] = count++;
            }
            // ģ��������д��ҵ���(����ҿ�)
            for (; j > startx; j--) {
                res[i][j] = count++;
            }
            // ģ��������д��µ���(����ҿ�)
            for (; i > starty; i--) {
                res[i][j] = count++;
            }

            // �ڶ�Ȧ��ʼ��ʱ����ʼλ��Ҫ���Լ�1�� ���磺��һȦ��ʼλ����(0, 0)���ڶ�Ȧ��ʼλ����(1, 1)
            starty++;
            startx++;

            // offset ����ÿһȦ��ÿһ���߱����ĳ���
            offset += 2;
        }

        // ���nΪ�����Ļ�����Ҫ�������������м��λ�ø�ֵ
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};