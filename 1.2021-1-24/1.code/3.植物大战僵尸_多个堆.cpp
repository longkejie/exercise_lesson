/*************************************************************************
	> File Name: 3.植物大战僵尸_多个堆.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sun 24 Jan 2021 03:47:42 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define MAX_N 50000
#define swap(a, b) {\
    __typeof(a) _temp = a;\
    a = b, b = _temp;\
}

typedef struct Data {
    int n, f, s;
}Data;

Data heap[101][MAX_N + 5];

void insert(Data *h, Data val){
    h[0].n +=1;
    h[h[0].n] = val;
    int ind = h[0].n;
    while (ind >> 1 && h[ind].f > h[ind >> 1].f) {
        swap(h[ind], h[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

Data top(Data *h) {return h[1];}

void pop(int *h) {
    swap(h[1], h[h[0].n]);
    h[0].n -= 1;
    int ind = 1, temp;
    while (ind << 1 <= h[0].n) {
        int temp = ind;
        if (h[ind << 1].f > h[temp].f) temp = ind << 1;
        if (ind << 1 | 1 <= h[0].n && h[ind << 1 | 1].f <= h[temp].f) temp = ind << 1 | 1;
        if (temp == ind) break;
    }
}
int empty(Data *h) {return h[0].n == 0;}


void clear(Data *h) {
    h[0].n = 0;
}

void init_heap() {
    for (int i = 0; i <= 100 ;++i) clear(heap[i]);
    return;
}

void solve() {
    init_heap();
    int n, f, s;
    scanf("%d",&n);
    for (int i = 0 ; i < n ; ++i ) {
        scanf("%d%d",&f,&s) ;
        push(h[s],{i , f, s});
    }
    for (int i = 1; i <= n; ++i ){
        int ind = 0, pos;
        for (int j = 1; j <= 100; ++j) {
            if (empty(heap[j])) continue;
            int cur_pos = (i - 1) * j +_top(heap[j]).f;
            if (ind == 0 || (ind && pos < cur_pos)) {
                ind = j, pos = cur_pos;
            }
        }
        if (i - 1) printf(" ");
    }
}

int main () {
    int tcase, n = 0;
    scanf("%d",&tcase);
    while ((n++) < tcase) {
        printf("")
    }


    return 0;
}
