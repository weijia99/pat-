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
const int maxn=100100;



int main() {
    string string1;
    cin>>string1;
    int ans=0;
    for (int i = 0; i < string1.length(); ++i) {
        ans+=string1[i]-'0';
    }
    string string2=to_string(ans);
    string out[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    for (int j = 0; j < string2.length(); ++j) {
        if (j==0){
            cout<<out[string2[j]-'0'];
        } else{
            cout<<" "<<out[string2[j]-'0'];

        }
    }
    return 0;
}
