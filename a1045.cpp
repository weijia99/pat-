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

    int n;
    cin>>n;
    int arr[n+1];
    int sum=0;
    for (int i = 1; i <=n; ++i) {
        int temp;
        cin>>temp;
        arr[i]=temp;
        sum+=temp;
    }
    int m;
    cin>>m;
    for (int j = 0; j < m; ++j) {
        int a,b;
        cin>>a>>b;
        if (a>b){
            int temp=a;
            a=b;
            b=temp;
        }
        int ans=0;
        for (int i = a; i <b ; ++i) {
            ans+=arr[i];
        }
        int ans2=sum-ans;
        if (ans2<ans){
            ans=ans2;
        }
        printf("%d\n",ans);
    }

    return 0;
}
