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

//�ص���Ŀ��������
//���ǵ�ǰֵ��һֱpush i
//�Ǿ�pop

int main() {

     int n,m,k;
     cin>>m>>n>>k;

    for (int i = 0; i < k; ++i) {
        vector<int> vector(n+1);
        stack<int> stack;
//

        for (int j = 1; j <=n; ++j) {
            int a;
            cin>>a;
            vector[j]=a;
//
        }
       int current=1;
        for (int l = 1; l <=n; ++l) {
            stack.push(l);
            if (stack.size()>m){
                break;
//                ֱ������

            }
            while (!stack.empty()&&stack.top()==vector[current]){
//                �����ͷ���͵���
                stack.pop();
                current++;
            }
//            ���Ǿ�һֱ��

        }
        if (current==n+1){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
    }
    return 0;
}
