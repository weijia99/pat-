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
    int n,m;
    scanf("%d %d",&n,&m);
    map<int ,int> map;
    int mid=(n*m)/2;
    for (int i = 0; i <m ; ++i) {
        for (int j = 0; j < n; ++j) {
            int temp;
           scanf("%d",&temp);
            map[temp]++;
            if (map[temp]>mid){
                printf("%d",temp);
                return 0;
            }
        }
    }

    return 0;
}
