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


int main() {
    int n,m;
    cin>>n>>m;
    map<string,vector<int>> map;
    for (int i = 0; i < m; ++i) {
        int id,num;
        cin>>id>>num;
        string name;
        for (int j = 0; j < num; ++j) {
            cin>>name;
            map[name].push_back(id);
        }
    }
    for (int k = 0; k < n; ++k) {
        string name;
        cin>>name;
        cout<<name<<" "<<map[name].size();
        sort(map[name].begin(),map[name].end());
        for (int i = 0; i < map[name].size(); ++i) {
            cout<<" "<<map[name][i];
        }
        printf("\n");
    }
    return 0;
}
