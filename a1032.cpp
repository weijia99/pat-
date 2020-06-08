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
const long int maxn=1001000;
const int inf=0x7fffffff;
struct node{
    int add;
    string  data;
    int next;
}stu[maxn];
int main() {
    int header1,header2,n;
    cin>>header1>>header2>>n;
    int ch1=header1,ch2=header2;
    for (int i = 0; i < n; ++i) {
        int add,next;
        string name;
        cin>>add>>name>>next;
        stu[add].add=add;
        stu[add].next=next;
        stu[add].data=name;

    }
//    进行区分两条链

    node link1[n];
    node link2[n];
    int index1=0,index2=0;
    while (header1!=-1){
        node cur=stu[header1];
        header1=cur.next;
        link1[index1++]=cur;

    }
    while (header2!=-1){
        node cur=stu[header2];
        header2=cur.next;
        link2[index2++]=cur;

    }
//    找到两条链的长度差距

    if (index1>index2){
        int num=index1-index2;
        for (int i = 0; i < index2; ++i) {
            if (link2[i].add==link1[i+num].add){
//                如果地址相同

                printf("%05d",link2[i].add);
                return 0;
            }
        }


    } else{
        int num=index2-index1;
        for (int i = 0; i < index1; ++i) {
            if (link2[i+num].add==link1[i].add){
//                如果地址相同

                printf("%05d",link1[i].add);
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}
