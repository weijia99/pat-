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
const long int maxn=10010;
const int inf=0x7fffffff;

int has[maxn];
int main() {
    string a,b;
    cin>>a>>b;
    for (int i = 0; i < b.length(); ++i) {
        char c=toupper(b[i]);
        has[c]=1;
    }
    for (int j = 0; j < a.length(); ++j) {
        char c=toupper(a[j]);
        if (has[c]!=1){
//            �����ظ�����
            has[c]=1;
            cout<<c;
        }
    }
    return 0;
}
