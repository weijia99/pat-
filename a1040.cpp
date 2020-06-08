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


int main() {
   string name;
   getline(cin,name);
//   ����dp����
    int len=name.length();
    int dp[len][len];
    int ans=1;
    for (int i = 0; i <len ; ++i) {
        dp[i][i]=1;
//        ���Լ�����һ���ѳ�
//        dp��ʼ��
        if (i<len-1){
            if(name[i]==name[i+1]){
                dp[i][i+1]=1;
                ans=2;
            }
        }
    }
//    ����Ѱ��l�ĳ���,��3��ʼ
    for (int j = 3; j <=len; ++j) {
//
        for (int i = 0; i +j-1<len ; ++i) {
//            i+j-1���Ҷ˵�
            int p=i+j-1;
            if (name[i]==name[p]&&dp[i+1][p-1]==1){
//                ���������������
                dp[i][p]=1;
                ans=j;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
