#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <set>
#include <stack>
#include <queue>

//cin用多了超市

using namespace std;
const int maxn=10010;


int main() {
    int a,b;
    cin>>a>>b;
    int c=a+b;
    string  d=to_string(c);
    int count=0;
    string  temp="";
    if (c<0){
        cout<<"-";
        for (int i = d.length()-1; i >=1; --i) {
            count++;
            temp=d[i]+temp;
            if (count%3==0&&i!=d.length()-1&&i!=1){
//                cout<<',';
                temp=','+temp;
            }
        }
    } else{
        for (int i = d.length()-1; i >=0; --i) {
            count++;
            temp=d[i]+temp;
            if (count%3==0&&i!=d.length()-1&&i!=0){
                temp=','+temp;
            }
        }
    }
    cout<<temp;


    return 0;
}
