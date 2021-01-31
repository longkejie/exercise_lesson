/*************************************************************************
	> File Name: oj369_dp.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sun 31 Jan 2021 06:09:04 PM CST
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
#define max_num 50000000666LL
typedef long long ll;
ll dp[20][2][2], pos[20];

ll dfs(int i, int f1, int f2, int limit) {
    if (i == 0) return 1;
    if (!limit && dp[i][f1][f2]) return dp[i][f1][f2];
    ll up = limit ? pos[i] : 9;
    ll ret = 0;
    for (int num = 0; num <= up; ++num) {
        if (num == 6 && f1 && f2) continue;
        ret += dfs(i - 1, num == 6, f1, limit && num == up);
    }
    if (limit == 0) dp[i][f1][f2] = ret; 
    return ret;
}

ll getNum(ll n) {
    memset(dp, 0, sizeof(dp));
    ll cnt = 0, temp = n;
    while (n) {
        pos[++cnt] = n % 10;
        n /= 10;
    }
    return temp - dfs(cnt, 0, 0, 1) + 1;
}

ll bs(long long l, long long r, ll x) {
    if (l == r) return l;
    long long mid = (l + r) >> 1;
    if (getNum(mid) < x) return bs(mid + 1, r, x);
    return bs(l, mid, x);
}

void solve() {
    int n;
    cin >> n;
    cout << bs(1, max_num, n) << endl;
    return ;
}


int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
