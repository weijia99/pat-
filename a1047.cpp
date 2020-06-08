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

int main() {

    int n,m;
    cin>>n>>m;
    vector<string> vector[m+1];
    for (int i = 0; i < n; ++i) {
        string name;
        int num;
        cin>>name>>num;
        for (int j = 0; j < num; ++j) {
            int temp;
            cin>>temp;
            vector[temp].push_back(name);
        }
    }

    for (int k = 1; k <=m ; ++k) {
        sort(vector[k].begin(),vector[k].end(),cmp);
        cout<<k<<" "<<vector[k].size()<<endl;
        for (int i = 0; i < vector[k].size(); ++i) {
            cout<<vector[k][i]<<endl;
        }

    }
    return 0;
}
