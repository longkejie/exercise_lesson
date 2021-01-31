/*************************************************************************
	> File Name: 1.找没有出现四次的数.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sun 31 Jan 2021 03:57:56 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<vector>
#include<cmath>
using namespace std;
#define MAX_N 100
int num[MAX_N + 5];
int n;
int main () {
    
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> num[i];
    int a = 0, b = 0, c;
    for (int i = 0; i < n; ++i) {
        c = num[i];
        a = (a  & ~c) | (a & ~b & c) | (~a & b & c);
        b = (~b & c);
    }

    cout << b << endl;


}
