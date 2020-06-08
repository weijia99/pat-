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

int main() {
    int n;
    cin>>n;
    long long a,b,c;
    for (int i = 0; i < n; ++i) {
        cin>>a>>b>>c;
        printf("Case #%d: ",i+1);
        if (a>0&&b>0&&a+b<0){
            printf("true\n");
        } else if (a<0&&b<0&&a+b>=0){
            printf("false\n");

        } else if (a+b>c){
            printf("true\n");

        } else{
            printf("false\n");

        }

    }
    return 0;
}
