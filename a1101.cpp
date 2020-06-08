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

//高频错误题目



using namespace std;
const long int maxn=10010;
const int inf=0x7fffffff;

int main() {
    int n;
    cin>>n;
    int arr1[n],arr2[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr1[i]);
        arr2[i]=arr1[i];
    }
    sort(arr1,arr1+n);
//    思路，位置与排好的对应，而且排好的比左边i-1个大，因为是拍好的
    int max=-1;
    vector<int> vector;
    for (int j = 0; j < n; ++j) {
        if (arr1[j]==arr2[j]&&arr2[j]>max){
            vector.push_back(arr2[j]);
        }
        if (arr2[j]>max){
            max=arr2[j];
//            前j-1里面最大的元素
        }
    }
    cout<<vector.size()<<endl;
    for (int k = 0; k < vector.size(); ++k) {
        if (k==0){
            cout<<vector[k];
        } else{
            cout<<" "<<vector[k];
        }
    }
    printf("\n");
    return 0;
}
