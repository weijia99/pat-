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
const int maxn=10010;
const int inf=0x7fffffff;
int s1[maxn],s2[maxn];
int main() {
    int n,m;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&s1[i]);
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&s2[i]);
    }
    s1[n]=inf;
    s2[m]=inf;
//    让到达了边界,直接取不同列的值
    int i=0,j=0,count=0;
    int mid=(n+m-1)/2;
//    少进行一次检测
    while (count<mid){
        if (s1[i]<s2[j]){
            i++;
        } else{
            j++;
        }
        count++;
    }
//    这是最后一次的比较,因为上面比较困难会j++
    if (s1[i]<s2[j]){

        printf("%d",s1[i]);
    } else{
        printf("%d",s2[j]);
    }
    return 0;
}
