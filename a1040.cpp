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
   string name;
   getline(cin,name);
//   构建dp方程
    int len=name.length();
    int dp[len][len];
    int ans=1;
    for (int i = 0; i <len ; ++i) {
        dp[i][i]=1;
//        与自己就是一个堆成
//        dp初始化
        if (i<len-1){
            if(name[i]==name[i+1]){
                dp[i][i+1]=1;
                ans=2;
            }
        }
    }
//    进行寻找l的长度,从3开始
    for (int j = 3; j <=len; ++j) {
//
        for (int i = 0; i +j-1<len ; ++i) {
//            i+j-1是右端点
            int p=i+j-1;
            if (name[i]==name[p]&&dp[i+1][p-1]==1){
//                设置这两点是相等
                dp[i][p]=1;
                ans=j;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
