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
    cin>>n;
    int cost[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&cost[i]);
    }

//    首先检查睡吧睡吧全是负数
    int flag=0;
    for (int j = 0; j < n; ++j) {
        if (cost[j]>0){
            flag= 1;
        }
    }
    if (flag==0){
//
        printf("0 %d %d",cost[0],cost[n-1]);
        return 0;
    }
    //构建转移方程
//    首先是初始化d【0】=a【0】
//    然后是d【i】=a【i】或者是d【i】=d【i-1】+a【i】
    int d[n];
    d[0]=cost[0];
    int s[n];
//    这是起点
    for (int k = 1; k < n; ++k) {
        if (d[k-1]+cost[k]>cost[k]){
//
            d[k]=d[k-1]+cost[k];
            s[k]=s[k-1];
        } else{
            d[k]=cost[k];
//            更新起点
            s[k]=k;

        }
    }
    int p=0;
    for (int l = 0; l <n ; ++l) {
        if (d[l]>d[p]){
            p=l;
        }
    }
    cout<<d[p]<<" "<<cost[s[p]]<<" "<<cost[p];
    return 0;
}
