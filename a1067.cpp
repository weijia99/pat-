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

//这题超时了，还是用柳大神的方法吧

using namespace std;
const long int maxn=100100;
const int inf=0x7fffffff;

int main() {
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    bool flag= false;
//    统计几个不在位置上的
    for (int i = 0; i < n; ++i) {
        int m;
        cin>>m;
        arr[m]=i;
//        可以获取0所在的下表好交换
        if (i!=m){
            flag=false;
        }
    }

    int ans=0;
    while (!flag){
        if(arr[0]!=0){
//            不是这个下表
//            就交换这个下表的值
            swap(arr[0],arr[arr[0]]);

            ans++;
        } else{
//            如果为0，就交换不在自己位置的值
                int p=0;
            for (int i = 1; i <n; ++i) {
                if (arr[i]!=i){
                    p=i;

                    break;
                }
            }
            if (p!=0){
                flag= false;
                swap(arr[0],arr[p]);
                ans++;
            } else{
                flag= true;
            }

        }
    }
    printf("%d",ans);

    return 0;
}
