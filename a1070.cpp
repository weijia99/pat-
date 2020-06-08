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

//这题超时了，还是用柳大神的方法吧

using namespace std;
const long int maxn=100100;
const int inf=0x7fffffff;
struct node{
    double price;
    double toll;
}stu[maxn];
bool cmp(node a,node b){
    return a.price/a.toll>b.price/b.toll;
}
int main() {
    int n;
    double m;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {

        scanf("%lf",&stu[i].toll);
    }
    for (int i = 0; i < n; ++i) {

        scanf("%lf",&stu[i].price);
    }
    sort(stu,stu+n,cmp);
    double sum=0.0;
    for (int j = 0; j < n; ++j) {
        if (m==0){
            break;
        }
        if (m>stu[j].toll){
            m-=stu[j].toll;
            sum+=stu[j].price;
        } else {
            sum+=stu[j].price*(m*1.0/stu[j].toll);
            m=0;
        }

    }
    printf("%.2f",sum);




    return 0;
}
