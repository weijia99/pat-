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

double toTen(string num,int rad){
    double ans=0;
    for (int i = 0; i < num.length(); ++i) {
        if (isalpha(num[i])){
//            如果是字母
            ans+=(num[i]-'a'+10)*pow(rad,(num.length()-1-i));

        } else{
            ans+=(num[i]-'0')*pow(rad,(num.length()-1-i));
        }
    }
    return ans;
}

double getRadix(double ans,string num){
    int max=0;
    for (int i = 0; i < num.length(); ++i) {
        if (isalpha(num[i])){
//            如果是字母
            if (num[i]-'a'+10>max){
                max=num[i]-'a'+10;
            }

        } else{
            if (num[i]-'0'>max){
                max=num[i]-'0';
            }
        }
    }
    int rad=max+1;
    double temp=toTen(num,rad);
    int flag=0;
    while (ans>=temp){
        if (ans==temp){
            flag=1;
//            找到答案
            break;
        }
        rad++;
        temp=toTen(num,rad);
    }
    if (flag==1){
        return rad;
    } else{
        return -1;
    }
}

int main() {
    string string1,string2;
    int n1,n2;
    cin>>string1>>string2>>n1>>n2;
    double ans,res;
    if (n1==1){
        ans=toTen(string1,n2);
        res=getRadix(ans,string2);
    } else{
        ans=toTen(string2,n2);
        res=getRadix(ans,string1);
    }
    int r=(int)res;
    if (r==-1){
        printf("Impossible");
    } else{
        printf("%d",r);
    }

    return 0;
}
