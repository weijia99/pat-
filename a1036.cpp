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
const long int maxn=10010;
const int inf=0x7fffffff;

struct node{
    string  name,id;
}stu[maxn];
int main() {
    int n;
    cin>>n;
    int num=0;
    int rec[n];
    for (int i = 0; i < n; ++i) {
        string a,b;
        cin>>a>>b;
        stu[i].name=a;
        int flag=0;
        for (int j = 0; j < b.length(); ++j) {
            if (b[j]=='1'){
                flag++;
                b[j]='@';
            }
            if (b[j]=='0'){
                flag++;
                b[j]='%';
            }
            if (b[j]=='l'){
                flag++;
                b[j]='L';
            }
            if (b[j]=='O'){
                flag++;
                b[j]='o';
            }
        }
        if (flag>0){
            rec[num++]=i;
        }
        stu[i].id=b;
    }
    if (n==1&&num==0){
        printf("There is 1 account and no account is modified\n");
    }
    if (n>1){
        if (num!=0){
            printf("%d\n",num);
            for (int i = 0; i < num; ++i) {
                cout<<stu[rec[i]].name<<" "<<stu[rec[i]].id<<endl;
            }
        } else{
            printf("There are %d accounts and no account is modified",n);
        }
    }

    return 0;
}
