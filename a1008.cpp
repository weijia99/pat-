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
const int maxn=100100;



int main() {
    int n;
    cin>>n ;
    int cost[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&cost[i]);
    }
    int total=cost[0]*6;
    for (int j = 1; j < n; ++j) {
        if (cost[j]<cost[j-1]){
            total+=(cost[j-1]-cost[j])*4;
        } else{
            total+=(cost[j]-cost[j-1])*6;

        }
    }
    total+=n*5;
    cout<<total;
    return 0;
}
