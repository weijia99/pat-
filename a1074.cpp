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

//cin�ö��˳���



using namespace std;
const long int maxn=100100;
const int inf=0x7fffffff;

struct node{
    int add,val,next;
}stu[maxn];
int main() {
    int header,n,m;
    cin>>header>>n>>m;
    for (int i = 0; i < n; ++i) {
        int add,next,val;
        cin>>add>>val>>next;
        stu[add].add=add;
        stu[add].val=val;
        stu[add].next=next;
    }
    node temp[n];
    int index=0;
    while (header!=-1){
        node t=stu[header];
        header=t.next;
        temp[index++]=t;

    }
//    ���з���
    int zu=index/m;
    int less=index%m;
    for (int j = 0; j < zu; ++j) {
        for (int i = m-1; i >=0; --i) {
            if (less!=0&&j==zu-1&&i==0){
//                ���һ������һ��
                printf("%05d %d %05d\n",temp[j*m+i].add,temp[j*m+i].val,temp[zu*m].add);
//                cout<<temp[j*m+i].add<<" "<<temp[j*m+i].val<<" "<<temp[zu*m].add<<endl;
                break;
//                ���һ������
            }
            if (less==0&&j==zu-1&&i==0){
                printf("%05d %d -1\n",temp[j*m+i].add,temp[j*m+i].val);

//                cout<<temp[j*m+i].add<<" "<<temp[j*m+i].val<<" "<<"-1"<<endl;
                break;
            }
            if (i==0){
//                ����������һ��
                printf("%05d %d %05d\n",temp[j*m+i].add,temp[j*m+i].val,temp[(j+1)*m+m-1].add);

//                cout<<temp[j*m+i].add<<" "<<temp[j*m+i].val<<" "<<temp[(j+1)*m+m-1].add<<endl;
            } else{
                printf("%05d %d %05d\n",temp[j*m+i].add,temp[j*m+i].val,temp[j*m+i-1].add);

//                cout<<temp[j*m+i].add<<" "<<temp[j*m+i].val<<" "<<temp[j*m+i-1].add<<endl;

            }

        }
    }
    if (less!=0){
        for (int i = 0; i < less; ++i) {
            if (i==less-1){
                printf("%05d %d -1\n",temp[zu*m+i].add,temp[zu*m+i].val);

//                cout<<temp[zu*m+i].add<<" "<<temp[zu*m+i].val<<" "<<"-1"<<endl;

            } else{
                printf("%05d %d %05d\n",temp[zu*m+i].add,temp[zu*m+i].val,temp[zu*m+i+1].add);

//                cout<<temp[zu*m+i].add<<" "<<temp[zu*m+i].val<<" "<<temp[zu*m+i+1].add<<endl;

            }
        }
    }
    return 0;
}
