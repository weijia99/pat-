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

//可以用cctype
//isalnum来分辨字母和数组


using namespace std;
const long int maxn=100100;
const int inf=0x7fffffff;

//自己组装字符串，无法空格切割
int main() {
    string a;
    getline(cin,a);
    map<string ,int> map;
    string temp="";
    for (int i = 0; i < a.length(); ++i) {
        if (((!isalpha(a[i]))&&(!isdigit(a[i])))||i==a.length()-1){
//            a[i]=' ';
//            这个字符串读取完成
//            最后一个强制结束
            if (temp.length()!=0){
                map[temp]++;
//                不为空才加入。
            }

            temp="";
        } else{
            a[i]=tolower(a[i]);
//            全部小写
            temp+=a[i];
        }
//        换成空格
    }
    int max=0;

    for(auto item=map.begin();item!=map.end();item++){
        if (item->second>max){
            max=item->second;
            temp=item->first;
        }
        if (item->second==max){
            if (item->first<temp){
                temp=item->first;
            }
        }
    }
    cout<<temp<<" "<<max;



    return 0;
}
