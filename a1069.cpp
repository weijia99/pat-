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

//a。insert的运发

using namespace std;
const long int maxn=100100;
const int inf=0x7fffffff;

int main() {
   string string1;
   cin>>string1;
   string1.insert(0,4-string1.length(),'0');
//   人心险恶啊，你输入的是个位数。。
   sort(string1.begin(),string1.end());
   string string2=string1;
   reverse(string1.begin(),string1.end());
   if (string1==string2){

       cout<<string1<<" - "<<string2<<" = 0000"<<endl;
       return 0;
   }
    int a=stoi(string1);
    int b=stoi(string2);
    int ans=a-b;
    printf("%04d - %04d = %04d\n",a,b,ans);

    while (ans!=6174){
        string tem=to_string(ans);
        int len=tem.length();
        int add=4-len;
//        有可能缺0
        for (int i = 0; i < add; ++i) {
            ans*=10;
        }
        string1=to_string(ans);
        sort(string1.begin(),string1.end());
        string2=string1;
        reverse(string1.begin(),string1.end());
        a=stoi(string1);
        b=stoi(string2);
        ans=a-b;

        printf("%04d - %04d = %04d\n",a,b,ans);


    }


    return 0;
}
