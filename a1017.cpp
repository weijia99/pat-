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
struct node{
    int time,wait,work;
}stu[maxn];
bool cmp(node a,node b){
    if (a.time!=b.time){
        return a.time<b.time;
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    int index=0;
    for (int i = 0; i < n; ++i) {
        int hour,minute,second,work;
        scanf("%d:%d:%d %d",&hour,&minute,&second,&work);
        int time=hour*60*60+minute*60+second;
        if (time>61200){
            continue;
        }

        stu[index].time=time;
        stu[index].work=work*60;
        index++;
    }
    sort(stu,stu+index,cmp);
    vector<int> window(m,28800);
//    设置三个窗口
    double total=0.0;
    for (int j = 0; j < index; ++j) {
//        寻找三个窗口里最小的值
        int p=0,min=window[0];
        for (int i = 0; i < m; ++i) {
            if (min>window[i]){
                p=i;
                min=window[i];
            }
        }
//        如果处理结束的时间比他们来早
        if (window[p]<=stu[j].time){
            window[p]=stu[j].time+stu[j].work;
//            无需等待

        } else{
//            来得早,例如在7点50来,就需要等待
            total+=window[p]-stu[j].time;
            window[p]+=stu[j].work;
        }
    }
    if(index == 0)
        printf("0.0");
    else
        printf("%.1f", total / 60.0 / index);



    return 0;
}
