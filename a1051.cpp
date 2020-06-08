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
int count1[maxn]={0};

//重点题目，又忘了
//不是当前值就一直push i
//是就pop

int main() {

     int n,m,k;
     cin>>m>>n>>k;

    for (int i = 0; i < k; ++i) {
        vector<int> vector(n+1);
        stack<int> stack;
//

        for (int j = 1; j <=n; ++j) {
            int a;
            cin>>a;
            vector[j]=a;
//
        }
       int current=1;
        for (int l = 1; l <=n; ++l) {
            stack.push(l);
            if (stack.size()>m){
                break;
//                直接跳出

            }
            while (!stack.empty()&&stack.top()==vector[current]){
//                如果是头部就弹出
                stack.pop();
                current++;
            }
//            不是就一直加

        }
        if (current==n+1){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
    }
    return 0;
}
