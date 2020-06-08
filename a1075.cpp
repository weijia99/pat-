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
    int id,total,prefect;
//    ���ֵĴ���
    int grade[5];
    bool flag[5];
    int rank;
    int isShow;
//    0��Ҳ������˵�
//    �Ƿ���ʹ�
}stu[maxn];

bool cmp(node a,node b){
    if (a.total!=b.total){
        return a.total>b.total;
    } else if (a.prefect!=b.prefect){
        return a.prefect>b.prefect;
    } else if (a.id!=b.id){
        return a.id<b.id;
    }
}
//����ȫ��0�������������˵�
int main() {
    int n,k,m;
    cin>>n>>k>>m;
    int question[k+1];
    for (int i = 1; i <=k; ++i) {
        scanf("%d",&question[i]);
    }
    for (int j = 0; j < m; ++j) {
        int id,que,grade;
        cin>>id>>que>>grade;
        stu[id].id=id;
        stu[id].flag[que]= true;
//        �Ѿ����ʹ���


        if (grade>=0){
            stu[id].isShow=1;
//            �Ѿ�չʾ���˵�
        }
        if (grade>stu[id].grade[que]){
//            stu[id].total+=grade;

            stu[id].grade[que]=grade;
        }
//        ���Ǹ���
    }
//    �����ֻܷ���
    for (int k1 = 1; k1 <=n; ++k1) {
        for (int i = 1; i <=k; ++i) {
            if (stu[k1].grade[i]==question[i]){

//            ����
                stu[k1].prefect++;
            }
            stu[k1].total+=stu[k1].grade[i];
        }
    }
    sort(stu+1,stu+n+1,cmp);
    stu[1].rank=1;
    for (int l = 2; l <=n; ++l) {
        if (stu[l].total==stu[l-1].total){
            stu[l].rank=stu[l-1].rank;
        } else{
            stu[l].rank=l;
        }
    }
    for (int i1 = 1; i1 <=n; ++i1) {
        if (stu[i1].isShow!=0) {
            printf("%d %05d %d", stu[i1].rank, stu[i1].id, stu[i1].total);
            for (int i = 1; i <= k; ++i) {
                if (stu[i1].flag[i] == true) {
//                ���Ĺ���
                    printf(" %d", stu[i1].grade[i]);
                } else {
                    printf(" -");

                }
            }
            printf("\n");

        }

    }

    return 0;
}
