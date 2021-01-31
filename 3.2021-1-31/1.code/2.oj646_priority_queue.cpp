/*************************************************************************
	> File Name: 2.oj646_priority_queue.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sun 31 Jan 2021 04:12:17 PM CST
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
struct Data {
    string name;
    int sex, age, ind;
    bool operator <(const Data &a) const {
        if (name.find("wang")  == 0  && a.name.find("wang") != 0) return false; 
        if (name.find("wang") != 0 && a.name.find("wang") == 0) return true;
        if (sex - a.sex) return sex != 0;
        if (age - a.age) return age < a.age;
        if (name != a.name) return name > a.name;
        return ind > a.ind;
    }
};

int main () {
    priority_queue<Data> s;
    int n, op;
    cin >> n;
    string name;
    int sex;
    int age;
    for (int i = 0; i < n; ++i){
        cin >> op;
        switch(op) {
            case 1:{
                cin >> name >> sex >> age;
                s.push(Data{name,sex, age, i});
            }break;
            case 2:{
                if (s.size() == 0) cout << "empty" << endl;
                else cout << s.top().name << endl;
            }break;
            case 3:{
                if (s.size() == 0) break;
                s.pop();
            }break;
        }
    }


    return 0;
}
