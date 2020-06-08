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
const long int maxn=10010;
const int inf=0x7fffffff;
int count1[maxn]={0};

//自己模拟一遍pre，post travel
bool cmp(string a,string b){
    return a< b;
}
int arr[maxn];
int main() {

    string a,b;
    getline(cin,a);
    getline(cin,b);
    int hash[256];
    for (int i = 0; i < b.length(); ++i) {
        char c=b[i];
        hash[c]=1;
    }
    for (int j = 0; j < a.length(); ++j) {
        if (hash[a[j]]!=1){
            cout<<a[j];
        }
    }
    return 0;
}
