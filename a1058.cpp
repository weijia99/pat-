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
int count1[maxn]={0};

int main() {
    long long g1,g2,s1,s2,k1,k2;
    scanf("%lld.%lld.%lld %lld.%lld.%lld",&g1,&s1,&k1,&g2,&s2,&k2);
    long long ans=(g1+g2)*29*17+(s1+s2)*29+(k1+k2);
    long long k3=ans%29;
    long long s3=ans%(29*17)/29;
    long long g3=ans/(29*17);
    printf("%lld.%lld.%lld",g3,s3,k3);
    return 0;
}
