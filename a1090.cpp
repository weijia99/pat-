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

//傻逼题，这尼玛烦



using namespace std;
const long int maxn=10010;
const int inf=0x7fffffff;
int n;
double price,rate;
vector<int > arr[maxn];
//dfs算法求
int maxDepth=0;
int num=0;
void dfs(int v,int depth){
    if (arr[v].size()==0) {


        if (depth > maxDepth) {
            maxDepth = depth;
            num = 1;
        } else if (depth == maxDepth) {
            num++;
        }
        return;
//        为0返回
    }
    for (int i = 0; i < arr[v].size(); ++i) {
        dfs(arr[v][i],depth+1);
    }
}
int main() {

    cin>>n>>price>>rate;
    rate/=100;
    int father;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin>>temp;
        if (temp!=-1){
            arr[temp].push_back(i);
        } else{
            father=i;
        }
    }
    dfs(father,0);
    printf("%.2f %d\n",price*pow(1+rate,maxDepth),num);
    return 0;
}
