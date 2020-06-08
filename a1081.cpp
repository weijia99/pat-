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


//gcd的经典用法
using namespace std;
const long int maxn=10010;
const int inf=0x7fffffff;

struct node{
    long long fenzi;
    long long fenmu;
}fenshu[maxn],sum;

long long gcd(long long a,long long b){
    if (b!=0){
        return gcd(b,a%b);
    } else{
        return abs(a);
    }
}
//只有*才可以new
void add(node a){
    long long g=gcd(a.fenmu,sum.fenmu);
    long long test=(sum.fenmu/g)*a.fenmu;;
    sum.fenzi=(test/a.fenmu)*a.fenzi+(test/sum.fenmu)*sum.fenzi;
    sum.fenmu=(sum.fenmu/g)*a.fenmu;


}
void amplify(){
    if (abs(sum.fenzi)>abs(sum.fenmu)){
        int t=sum.fenzi/sum.fenmu;
        sum.fenzi=sum.fenzi%sum.fenmu;
        long long g=gcd(sum.fenmu,sum.fenzi);
        if (sum.fenzi!=0){
            printf("%d %d/%d",t,sum.fenzi/g,sum.fenmu/g);

        } else{
            printf("%d",t);

        }
    } else{
        long long g=gcd(sum.fenmu,sum.fenzi);
        if (sum.fenzi!=0){
            printf("%lld/%lld",sum.fenzi/g,sum.fenmu/g);

        } else{
            printf("0");
        }
    }
}
int main() {
    int n;
    cin>>n;
    sum.fenzi=0;
    sum.fenmu=1;
    for (int i = 0; i < n; ++i) {
        scanf("%lld/%lld",&fenshu[i].fenzi,&fenshu[i].fenmu);

    }
    for (int j = 0; j < n; ++j) {
        add(fenshu[j]);
    }
    amplify();
    return 0;
}
