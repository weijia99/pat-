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

int has[maxn];
//恶心题，lld 的范围
int main() {
    int n;
    long long p;
    cin>>n>>p;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int ans=0;
    for (int i = 0; i < n; ++i) {
//        for (int j = n-1; j >=0; --j) {
//            if (arr[j]<=arr[i]*p){
//                if (j-i+1>ans){
//                    ans=j-i+1;
//                    break;
//                }
//            }
//        }
        int j=upper_bound(arr,arr+n,arr[i]*p)-arr-1;
        if (j-i+1>ans){
            ans=j-i+1;
        }
    }
    cout<<ans;
    return 0;
}
