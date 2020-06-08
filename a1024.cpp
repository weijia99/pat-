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

bool isPa(string a){
    int mid=a.length()/2;
    for (int i = 0; i < mid; ++i) {
        if (a[i]!=a[a.length()-1-i]){
            return false;
        }
    }
    return true;
}
int main() {
    string a;
    int b;
    cin>>a>>b;
    for (int i = 0; i < b; ++i) {
        if (isPa(a)){
            cout<<a<<endl;
            cout<<i<<endl;
            return 0;
        }
        string temp=a;
        reverse(a.begin(),a.end());
        string s;
        int carry=0;
        for (int j = a.length()-1; j >=0 ; --j) {
            int p=(a[j]-'0')+(temp[j]-'0')+carry;
            if (p>=10){
                s=to_string(p-10)+s;
                carry=1;
            } else{
                s=to_string(p)+s;
                carry=0;
            }
        }
        if (carry==1){
//            还有进位加一
            s="1"+s;
        }
        a=s;
    }
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}
