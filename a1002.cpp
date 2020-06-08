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
    int n,zhishu;
    double xishu;
    double ans[1000];
    fill(ans,ans+1000,0.0);
    int temp[1000];
    int time=0;
    int count=0;
    for (int i = 0; i < 2; ++i) {
        cin>>n;
        for (int j = 0; j <  n; ++j) {
            cin>>zhishu>>xishu;
            if (ans[zhishu]==0.0){
                temp[time]=zhishu;
                time++;
                count++;

            }

            ans[zhishu]+=xishu;
//            如多相加为0
            if (ans[zhishu]==0.0){


                count--;
            }
        }

    }
    cout<<count;
    if (count==0){
        return 0;
    }
    sort(temp,temp+time);
    for (int k = time-1; k >=0 ; --k) {
        if (ans[temp[k]]!=0.0){
            cout<<" "<<temp[k]<<" ";
            printf("%.1lf",ans[temp[k]]);
        }

    }


    return 0;
}
