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
int ma[500000]={0};
int isPrime(int num){
    int sq=int(sqrt(1.0*num));
    if (num<=1){
        return 0;
    }
    for (int i = 2; i < sq; ++i) {
        if (num%i==0){
            return 0;
        }
    }
    return 1;
}
int main() {
    for (int i = 1; i < 500000; ++i) {
        ma[i]=isPrime(i);
    }
    long int n;
    cin>>n;
    int index=0;
    if (n==1){
        //特殊情况
        printf("1=1");
        return 0;
    }
    cout<<n<<"=";
        for (int i = 2; i < 500000; ++i) {
            if (n==0){
                break;
            }
            if (ma[i] == 1) {
                int xi = 0;
                while (n % i == 0&&n!=0) {
                    xi++;
                    n /= i;
                }
                if (xi == 1) {
                    if (index == 0) {
                        printf("%d", i);

                    } else {

                        printf("*%d", i);

                    }
                    index++;
                }
                if (xi >= 2) {
                    if (index == 0) {
                        printf("%d^%d", i, xi);

                    } else {

                        printf("*%d^%d", i, xi);
                    }
                    index++;
                }

            }
        }

    return 0;
}
