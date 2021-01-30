/*************************************************************************
	> File Name: 3.oj224_复合线段树.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sat 30 Jan 2021 07:23:01 PM CST
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
#define MAX_N 100000
long long p;
struct Node {
    long long sum, t1, t2;
}tree[MAX_N << 2 ];

void update(long long ind) {
    tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
    tree[ind].sum %= p;
    return;
}

void mul_tag(long long ind, long long x) {
    tree[ind].sum *= x;
    tree[ind].sum %= p;
    tree[ind].t1 *= x;
    tree[ind].t1 %= p;
    tree[ind].t2 *= x;
    tree[ind].t2 %= p;
    return;
}

void add_tag(long long ind, long long x, long long n) {
    tree[ind].sum += x * n;
    tree[ind].sum %= p;
    tree[ind].t2 += x;
    tree[ind].t2 %= p;
    return;
}

long long a[MAX_N + 5];
void build(long long ind, long long l, long long r) {
    tree[ind].t1 = 1; tree[ind].t2 = 0;
    if (l == r) {
        tree[ind].sum = a[l];
        return;
    }
    long long mid = (l + r) >> 1;
    build(ind << 1, l, mid);
    build(ind << 1 | 1, mid + 1, r);
    update(ind);
    return;
}
void down(long long ind, long long l, long long r) {
    long long mid = (l + r) >> 1;
    if (tree[ind].t1 - 1 || tree[ind].t2) {
        long long a = tree[ind].t1, b = tree[ind].t2;
        mul_tag(ind << 1, a);
        mul_tag(ind << 1 | 1, a);
        add_tag(ind << 1, b, mid - l +  1);
        add_tag(ind << 1 | 1, b, r - mid);
        tree[ind].t1 = 1;
        tree[ind].t2 = 0;
    }
    return ;
}

void modify(long long ind, long long flag, long long x, long long y,long long val,long long l, long long r) {

    if (x <= l && r <= y) {
        if (flag == 0) {
            mul_tag(ind, val);
        }else {
            add_tag(ind, val, r - l + 1);
        }
        return;
    }
    down(ind, l, r);
    long long mid = (l + r) >> 1;
    if (x <= mid) modify(ind << 1, flag, x, y, val, l, mid);
    if (y > mid) modify(ind << 1 | 1, flag, x, y, val, mid + 1, r);
    update(ind);
    return ;
}

long long query(long long ind, long long x, long long y, long long l, long long r) {
    if (x <= l && r <= y) {
        return tree[ind].sum;
    }
    down(ind, l , r);
    long long mid = (l + r) >> 1;
    long long ans = 0;
    if (x <= mid) ans += query(ind << 1, x, y, l ,mid);
    ans %= p;
    if (y > mid) ans += query(ind << 1 | 1, x, y, mid + 1, r);
    ans %= p;
    update(ind);
    return ans;
}

int main () {
    long long n, m;
    cin >> n >> m >> p;
    for (long long i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    long long op, x, y, k; 
    for (long long i = 0; i < m; ++i) {
        cin >> op >> x >> y;
        switch(op) {
            case 1:
            case 2:{
                cin >> k;
                modify(1, op - 1, x, y, k, 1, n);
            }break;
            case 3:{
                cout << query(1, x, y, 1, n) << endl;
            }break;
        }
    }

    return 0;
}
