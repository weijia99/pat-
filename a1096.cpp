#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <sstream>
typedef  long long ll;


using namespace std;

int main() {
    ll n;
    scanf("%lld",&n);
    int sq=(int)sqrt(n*1.0);
    ll len=0,start=0;
    //从第几位开始，一共多长
    for (int i = 2; i <=sq; ++i) {
        int temp=1,j=i;
        //j是一次次叠乘
        while (1){
            temp*=j;
            if (n%temp!=0){
                break;
                //如果不是直接跳出
            }
            if (j-i+1>len){
                len=j-i+1;
                start=i;
            }
            j++;
        }
    }
    if (len==0){
        printf("1\n%lld",n);
    } else{
        printf("%lld\n",len);
        for (ll i = start; i < start+len; ++i) {
            if (i==start){
                printf("%lld",i);
            } else{
                printf("*%lld",i);

            }

        }
    }
    return 0;
}
