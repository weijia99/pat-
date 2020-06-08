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
bool isPrime(int n){
    if (n<2){
        return false;
    }
    int sqr=(int)sqrt(n*1.0);
    for (int i = 2; i <=sqr; ++i) {
        if (n%i==0){
            return false;
        }
    }
    return true;
}

int main() {
    int n,m;
    cin>>n>>m;
    while (!isPrime(n)){
        n++;
    }
    int arr[n];
    fill(arr,arr+n,0);
    for (int i = 0; i < m; ++i) {
        int a;
        scanf("%d",&a);
        int temp=a%n;
        int flag=0;
        if (arr[temp]==0){
            arr[temp]=1;
            flag=1;
        } else{
            for (int j = 1; j < n; ++j) {
                temp=(a+j*j)%n;
                if (arr[temp]==0){
                    arr[temp]=1;
                    flag=1;
                    break;
                }
            }
        }
        if (flag==0){
            if (i==0){
                printf("-");
            } else{
                printf(" -");

            }
        } else{
            if (i==0){
                printf("%d",temp);
            } else{
                printf(" %d",temp);

            }
        }
    }
    return 0;
}
