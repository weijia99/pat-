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

//���ⳬʱ�ˣ�������������ķ�����

using namespace std;
const long int maxn=100100;
const int inf=0x7fffffff;

int main() {
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    bool flag= false;
//    ͳ�Ƽ�������λ���ϵ�
    for (int i = 0; i < n; ++i) {
        int m;
        cin>>m;
        arr[m]=i;
//        ���Ի�ȡ0���ڵ��±�ý���
        if (i!=m){
            flag=false;
        }
    }

    int ans=0;
    while (!flag){
        if(arr[0]!=0){
//            ��������±�
//            �ͽ�������±��ֵ
            swap(arr[0],arr[arr[0]]);

            ans++;
        } else{
//            ���Ϊ0���ͽ��������Լ�λ�õ�ֵ
                int p=0;
            for (int i = 1; i <n; ++i) {
                if (arr[i]!=i){
                    p=i;

                    break;
                }
            }
            if (p!=0){
                flag= false;
                swap(arr[0],arr[p]);
                ans++;
            } else{
                flag= true;
            }

        }
    }
    printf("%d",ans);

    return 0;
}
