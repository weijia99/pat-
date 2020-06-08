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
    char ch[3]={'W','T','L'};
    double d1,d2,d3;
    int index=0;
    int hash[3];
    double res=1.0;
    for (int i = 0; i < 3; ++i) {
        cin>>d1>>d2>>d3;
        double t1=max(d1,d2);
        int num=0;
        if (t1==d1){
            num=0;
        } else{
            num=1;
        }


        double t2=max(t1,d3);
        if (t2!=t1){
            num=2;
        }
        hash[index++]=num;
        res*=t2;

    }
    res=(res*0.65-1)*2;
    for (int j = 0; j < index; ++j) {
        cout<<ch[hash[j]]<<" ";
    }
    printf("%0.2f",res);

    return 0;
}
