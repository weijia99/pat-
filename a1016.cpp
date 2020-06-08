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
int rate[25];
struct node{
    string name;
    int month,day ,hour,minute;
    int type,time;
//    判断是哪个off还是on
} stu[maxn];

bool cmp(node a,node b){
    if (a.name!= b.name){
        return a.name<b.name;
    } else if (a.time!=b.time){
        return a.time<b.time;
    }
}
//通过与0.0.0.时区来计算现在的价钱
double getBill(node a){
    double total=0.0;
    total+=a.day*60*rate[24];
//    这是24小时时区的合计价钱,*60相当于一个小时
    for (int i = 0; i < a.hour; ++i) {
        total+=60*rate[i];
    }
    total+=rate[a.hour]*a.minute;
    return total/100.0;


}

int main() {

    for (int i = 0; i < 24; ++i) {
        scanf("%d",&rate[i]);
        rate[24]+=rate[i];
    }
    int n;
    cin>>n ;
    for (int j = 0; j < n; ++j) {
        string name,ty;
        cin>>name;
        int month,day,hour,minute,type;
        scanf("%d:%d:%d:%d",&month,&day,&hour,&minute);
        cin>>ty;
        if (ty=="on-line"){
            type=0;
        } else{
            type=1;
        }
        int time=day*24*60+hour*60+minute;
        stu[j].time=time;
        stu[j].type=type;
        stu[j].month=month;
        stu[j].day=day;
        stu[j].hour=hour;
        stu[j].minute=minute;
        stu[j].name=name;



    }
    sort(stu,stu+n,cmp);
    map<string ,vector<node>> m1;
    for (int k = 1; k < n; ++k) {
        if (stu[k].name==stu[k-1].name&&stu[k-1].type==0&&stu[k].type==1){
            m1[stu[k].name].push_back(stu[k-1]);
            m1[stu[k].name].push_back(stu[k]);

        }
    }

    for(auto item:m1){
        string  name=item.first;
        vector<node> vector=item.second;
        cout<<name;
        int month=vector[0].month;
        printf(" %02d\n",month);
        double total=0.0;
        for (int i = 0; i < vector.size(); i+=2) {
            double toll=getBill(vector[i+1])-getBill(vector[i]);
            total+=toll;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                   vector[i].day,vector[i].hour,vector[i].minute,
                   vector[i+1].day,vector[i+1].hour,vector[i+1].minute,
                   vector[i+1].time-vector[i].time,
                   toll);
        }
        printf("Total amount: $%.2f\n",total);
    }

    return 0;
}
