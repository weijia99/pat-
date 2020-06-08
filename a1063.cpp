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
const long int maxn=100100;
const int inf=0x7fffffff;

int main() {
    int n;
    cin>>n;
    set<int> set[n];
    for (int i = 0; i < n; ++i) {
        int m;
        cin>>m;
        for (int j = 0; j < m; ++j) {
            int a;
            cin>> a;
            set[i].insert(a);
        }
    }
    int m;
    cin>>m;
    for (int k = 0; k < m; ++k) {
        int a,b;
        cin>>a>> b;
        int count=0;
        int sum=set[b-1].size();
        for(auto item=set[a-1].begin();item!=set[a-1].end();item++){
            if (set[b-1].find(*item)!=set[b-1].end()){
                count++;
            } else{
                sum++;
            }
        }
        double ans=(double)count/sum*100;
        printf("%.1f%%\n",ans);
    }
    return 0;
}
