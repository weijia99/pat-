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





using namespace std;
const long int maxn=10010;
const int inf=0x7fffffff;
int n;

int main() {

    cin>>n;
    double sum=0.0;
    for (int i = 1; i <=n; ++i) {
        double temp;
        cin>>temp;
        sum+=(n-i+1)*temp*i;
//        i*(n-i+1)���ܻ������double64λ�����ģ����������һ��double�ų�
    }
    printf("%.2f",sum);
    return 0;
}
