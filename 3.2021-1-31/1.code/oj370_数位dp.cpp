/*************************************************************************
	> File Name: oj370_数位dp.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sun 31 Jan 2021 08:12:35 PM CST
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

int dp[11][90][90][90];
int f[11][90];
int base[90][11], pos[15];


void init_dp() {

    for (int i = 1; i < 90; ++i) {
        base[i][0] = 1;
        for (int j = 1; j < 11; ++j) {
            base[i][j] = base[j][j - 1] * 10 % i;
        }
    }
    for (int n = 0; n < 10; n++){ 
        for (int k = 1; k < 90; ++k) {
            dp[1][n][k][n % k] += 1;
        }
    }
    for (int n = 2; n <= 10; ++n) {
        for (int i = 0; i < 100; ++i) {
            for (int k = 1; k < 100; ++k) {
                for (int j = 0; j < k; ++j) {
                    dp[n][i][k][j] = 0;
                    for (int p = 0; p <= 9; ++p) {
                        dp[n][i][k][j] += dp[n - 1][i - p][k][(j + k - (p *base[k][n - 1]) % k) % k];
                    }
                }
            } 
        }
    }

    for (int i = 1; i < 11; ++i) {
        for (int j = 0; j < 90; ++j) {
            f[i][j] = 0;
            for (int k = 0;k < 90; ++k) {
                f[i][j] += dp[i][k][k][j];
            }
        }
    }
    return ;
}

int dfs(int i, int j, int limit) {
    if (i == 0) return j == 0;
    if (!limit) return f[i][j];
    int up = limit ? pos[i] : 9;
    int ret = 0;
    for (int num = 0; num <= up; ++num) {
        ret += dfs()
    }
}

int getNum(int n) {
    int cnt = 0;
    while (n) {
        pos[++cnt] = n % 10;
        n /= 10;
    }
    return dfs(cnt, 0, 1);
}

int main () {
    init_dp();
    int l, r;
    while (cin >> l >> r) {
        cout << getNum(r) - getNum(l - 1) << endl;
    }

    return 0;
}
