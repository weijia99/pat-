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


int main() {

    int n,d;
    cin>>n>>d;
    int c1=n;
    int arr[maxn];
    int index=0;

    do{
        arr[index++]=n%d;
        n/=d;
    }while (n!=0);
    int sum=0;
    for (int i = 0; i < index; ++i) {
        sum=sum*d+arr[i];
    }
    if (sum==c1){
        printf("Yes\n");
        for (int i = 0; i < index; ++i) {
            if (i==0){
                printf("%d",arr[i]);
            } else{
                printf(" %d",arr[i]);

            }
        }

    } else{
        printf("No\n");
        for (int i = index-1; i >=0; --i) {
            if (i==index-1){
                printf("%d",arr[i]);
            } else{
                printf(" %d",arr[i]);

            }
        }
    }
    return 0;
}
