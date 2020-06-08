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
const long int maxn=100100;
const int inf=0x7fffffff;


int main() {
    int n;
    scanf("%d\n",&n);
    string temp;
    for (int i = 0; i < n; ++i) {
        string  string1;
        getline(cin,string1);
        reverse(string1.begin(),string1.end());
        if (i==0){
            temp=string1;
        } else{
            string a;
            for (int j = 0; j < string1.length(); ++j) {
                if (string1[j]==temp[j]){
                    a+=string1[j];
                } else{
                    break;
//                    不相等就滚
                }
            }
            temp=a;
        }
    }
    if (temp.length()==0){
        cout<<"nai";
    } else{
        reverse(temp.begin(),temp.end());
        cout<<temp;
    }

    return 0;
}
