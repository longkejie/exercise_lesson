/*************************************************************************
	> File Name: 2.根据三元组建立二叉链表.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sun 24 Jan 2021 03:05:07 PM CST
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
typedef struct Node {
    char ch;
    struct Node *lchild, *rchild;
}Node; 

Node *arr[26];

Node *getNewNode(char ch) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->lchild = p->rchild = NULL;
    return p;
}
char str[10];

void output(Node *root) {
    if (root == NULL) return;
    printf("%c",root->ch);
    if (root->lchild == NULL && root->rchild == NULL) return;
    printf("(");
    output(root->lchild);
    if (root->rchild) printf(",");
    output(root->rchild);
    printf(")");
}

int main () {
    Node *root = NULL;
    while (scanf("%s",str)) {
        if (str[0] == '^' && str[1] == '^') break;
        Node *p = getNewNode(str[1]);
        arr[str[1] - 'A'] = p;
        if (str[0] == '^') {
            root = p;
            continue;
        }
        switch(str[2]) {
            case 'L' : arr[str[0] - 'A'] -> lchild = p;break;
            case 'R' : arr[str[0] - 'A'] -> rchild = p;break;
        }
    }

    output(root);
    printf("\n");
    return 0;
}
