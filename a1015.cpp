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
const int maxn=10010;

bool isPrime(int n){
    if (n<=1){
        return false;
    }
    int p=(int)sqrtf(n*1.0);
    for (int i = 2; i <=p; ++i) {
        if (n%i==0){
            return false;
        }
    }
    return true;
}


int main() {
    int n;
    while (scanf("%d",&n)!=EOF){
        if (n<0){
            break;
        }
        int d;
        scanf("%d",&d);
        if (!isPrime(n)){
            printf("No\n");

        } else {


//        ת��Ϊn������ʽ
            int stack[maxn];
            int cnt = 0;
            do {
                int q = n % d;
                stack[cnt] = q;
                n = n / d;
                cnt++;
            } while (n != 0);
            int sum = 0;
            for (int i = 0; i < cnt; ++i) {
                sum = sum * d + stack[i];
//            �ݹ��γ�ʮ����
            }
            if (isPrime(sum)) {
                printf("Yes\n");

            } else{
                printf("No\n");

            }
        }
    }

//    ����ʮ����

    return 0;
}
