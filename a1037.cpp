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
    int n;
    cin>>n;
    int arr1[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr1[i]);
    }
    int m;
    cin>>m;
    int arr2[m];
    for (int j = 0; j < m; ++j) {
        scanf("%d",&arr2[j]);
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    int p=-1;
//    ���ǵ���������ʱ��
    for (int k = 0; k < n; ++k) {
        if (arr1[k]>=0){
            p=k;
            break;
        }
    }
    int q=-1;
    for (int l = 0; l < m; ++l) {
        if (arr2[l]>=0){
            q=l;
            break;
        }
    }
    if (p==-1&&q==0){
//        ȫ�Ǹ���������
        printf("0");
        return 0;
    }
    if (q==-1&&p==0){
        printf("0");
        return 0;
    }
//    ȫ�Ǹ���
    int a;
    int p1,q1,b;
    if (p==-1&&q==-1){
        a=min(n,m);
    } else {


//    �ҳ���С�ĸ������
        a = min(p, q);
    }
        int sum = 0;
        for (int i1 = 0; i1 < a; ++i1) {
            sum += arr1[i1] * arr2[i1];
        }
//        ȫ�Ǹ����Ļ���p1��q1=0��
        if (p==-1&&q==-1){
            b=0;
        } else{
            p1 = n - p;
            q1 = m - q;
            b = min(p1, q1);
        }

//    �����ķ�Χ��ȡ��󼸸�
        for (int k1 = 0; k1 < b; ++k1) {
            sum += arr1[n - 1 - k1] * arr2[m - 1 - k1];
        }
        printf("%d", sum);


    return 0;
}
