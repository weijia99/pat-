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

//������cctype
//isalnum���ֱ���ĸ������


using namespace std;
const long int maxn=100100;
const int inf=0x7fffffff;

//�Լ���װ�ַ������޷��ո��и�
int main() {
    string a;
    getline(cin,a);
    map<string ,int> map;
    string temp="";
    for (int i = 0; i < a.length(); ++i) {
        if (((!isalpha(a[i]))&&(!isdigit(a[i])))||i==a.length()-1){
//            a[i]=' ';
//            ����ַ�����ȡ���
//            ���һ��ǿ�ƽ���
            if (temp.length()!=0){
                map[temp]++;
//                ��Ϊ�ղż��롣
            }

            temp="";
        } else{
            a[i]=tolower(a[i]);
//            ȫ��Сд
            temp+=a[i];
        }
//        ���ɿո�
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
