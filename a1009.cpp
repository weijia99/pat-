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
    double  a[maxn],b[maxn];
    fill(a,a+maxn,0.0);
    fill(b,b+maxn,0.0);
    int temp[maxn];
    int count=0;
//    统计一共有多少个
    int a_index=0;
    int hash[maxn];
    int total=0;
    for (int i = 0; i < 2; ++i) {
        int n,zhishu;
        double xishu;
        cin>>n;
        for (int j = 0; j < n; ++j) {
            cin>>zhishu>>xishu;
            if (i==0){
                a[zhishu]=xishu;
                temp[a_index++]=zhishu;
            } else{
                for (int k = 0; k < a_index; ++k) {

                    int weizhi=zhishu+temp[k];
                    if (b[weizhi]==0.0){
                        hash[count]=weizhi;
                        count++;
//                        系数增加
                        total++;
                    }
                    b[weizhi]+=xishu*a[temp[k]];
                    if (b[weizhi]==0.0){
                        total--;
                    }
                }
            }
        }
    }
    cout<<total;
    sort(hash,hash+count);

    for (int l = count-1; l >=0 ; --l) {
        if (b[hash[l]]!=0.0)
        printf(" %d %0.1lf",hash[l],b[hash[l]]);

    }
    return 0;
}
