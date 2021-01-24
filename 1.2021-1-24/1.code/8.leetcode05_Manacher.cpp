/*************************************************************************
	> File Name: 8.leetcode05_Manacher.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sun 24 Jan 2021 09:58:21 PM CST
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

class Solution {
public:
    string get_new_string(string &s) {
        string ns = "#";
        for (int i = 0; s[i]; ++i) {
            (ns += s[i]) += "#";
        }
        return ns;
    }
    string longestPalindrome(string s) {
        string ns = get_new_string(s);
        int *r = new int[ns.size()];
        int c;
        r[0] = 1, c = 0;
        for (int i = 1; i < ns.size(); ++i) {
            if (i >= c + r[c]) {
                r[i] = 1;
            }else {
                r[i] = min(c + r[c] - i, r[2 * c - i]);    
            }
            while (i - r[i] >= 0 && ns[i - r[i]] == ns[i + r[i]]) r[i] += 1;
            if (i + r[i] > c + r[c]) c = i;
        }
        string ret = "";
        int ans = 0;
        for (int i = 0; ns[i]; ++i) {
            if (r[i] < ans) continue;
            ret = "";
            ans = r[i];
            for (int j = i - r[i] + 1; j < i + r[i]; j++) {
                if (ns[j] == '#')continue;
                ret += ns[j];
            }
        }
        return ret;
    }
};

int main () {
	string str;
	cin >> str;
	Solution solution;
	cout << solution.longestPalindrome(str) << endl;
} 
