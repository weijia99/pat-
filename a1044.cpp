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


int main() {

    int n,m;
    cin>>n>>m;
    int sum[n+1];
    sum[0]=0;
    for (int i = 1; i <=n; ++i) {
        int temp;
        cin>>temp;
        sum[i]=sum[i-1]+temp;
    }
    int near=10000;
//    找到最小的值是m还是比m大，这个for的作用
    for (int j = 1; j <=n; ++j) {
        int find=upper_bound(sum+j,sum+n+1,sum[j-1]+m)-sum;
//        之所以是sum【j-1】是选择的和不包当前的值，这样才是完整的一个区间，相减
//          返回的是第一个大于15的值，所以要find-1
        if (sum[find-1]-sum[j-1]==m){
            near=m;
            break;
        } else if (find<=n&&sum[find]-sum[j-1]<near){
//            防止find越界就是没找到，后面这个更新最小值
            near=sum[find]-sum[j-1];

        }

    }
    for (int k = 1; k <=n; ++k) {
        int i=upper_bound(sum+k,sum+n+1,sum[k-1]+near)-sum;
        if (sum[i-1]-sum[k-1]==near){
            printf("%d-%d\n",k,i-1);
        }
    }
    return 0;
}
