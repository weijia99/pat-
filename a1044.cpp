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
int count1[maxn]={0};

//�Լ�ģ��һ��pre��post travel


int main() {

    int n,m;
    cin>>n>>m;
    int sum[n+1];
    sum[0]=0;
    for (int i = 1; i <=n; ++i) {
        int temp;
        cin>>temp;
        sum[i]=sum[i-1]+temp;
    }
    int near=10000;
//    �ҵ���С��ֵ��m���Ǳ�m�����for������
    for (int j = 1; j <=n; ++j) {
        int find=upper_bound(sum+j,sum+n+1,sum[j-1]+m)-sum;
//        ֮������sum��j-1����ѡ��ĺͲ�����ǰ��ֵ����������������һ�����䣬���
//          ���ص��ǵ�һ������15��ֵ������Ҫfind-1
        if (sum[find-1]-sum[j-1]==m){
            near=m;
            break;
        } else if (find<=n&&sum[find]-sum[j-1]<near){
//            ��ֹfindԽ�����û�ҵ����������������Сֵ
            near=sum[find]-sum[j-1];

        }

    }
    for (int k = 1; k <=n; ++k) {
        int i=upper_bound(sum+k,sum+n+1,sum[k-1]+near)-sum;
        if (sum[i-1]-sum[k-1]==near){
            printf("%d-%d\n",k,i-1);
        }
    }
    return 0;
}
