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


int has[256];
int main() {
    string a,b;
    cin>>a>>b;
    for (int i = 0; i < a.length(); ++i) {
        has[a[i]]++;
    }
    int flag=0;
    int ans=0;
    for (int j = 0; j < b.length(); ++j) {
        has[b[j]]--;
        if (has[b[j]]<0){
            ans++;
            flag=1;
        }
    }
    if (flag==0){
        int temp=a.length()-b.length();
        cout<<"Yes "<<temp;
    } else{
        cout<<"No "<<ans;
    }
    return 0;
}
