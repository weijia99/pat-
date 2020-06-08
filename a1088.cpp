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

//���⻹�Ǵ���



using namespace std;
const long int maxn=100100;
const int inf=0x7fffffff;
typedef long long ll ;
struct fenshu{
    ll up,down;
    //up�Ƿ��ӣ�down�Ƿ�ĸ
};
ll  gcd(ll a,ll b){
    if (b==0){
        return a;
    } else{
        return gcd(b,a%b);
    }
    //�����Լ����Լ��
}
fenshu simplify(fenshu a){
    //�������
    if (a.down<0){
        //�����ĸС�ڡ�0
//        ��ĸ���ӷ��Ż���
        a.down=-a.down;
        a.up=-a.up;
    } else if (a.up==0){
        //�������Ϊ0����ĸ��Ϊ1�������
        a.down=1;
    } else{
        ll n=gcd(abs(a.up),abs(a.down));
        a.down/=n;
        a.up/=n;
    }
    return a;


}
fenshu add(fenshu a,fenshu b){
//    �����ӷ�
    fenshu temp;
    temp.up=a.up*b.down+a.down*b.up;
    temp.down=a.down*b.down;
    return simplify(temp);
    //��󷵻ػ���ķ���
}
fenshu minu(fenshu a,fenshu b){
    //����
    fenshu temp;
    temp.up=a.up*b.down-a.down*b.up;
    temp.down=a.down*b.down;
    return simplify(temp);
}
fenshu mul(fenshu a,fenshu b){
//    �˷�
    fenshu temp;
    temp.up=a.up*b.up;
    temp.down=a.down*b.down;
    return simplify(temp);
}
fenshu div(fenshu a,fenshu b){
    fenshu temp;
    temp.up=a.up*b.down;
    temp.down=a.down*b.up;
    return simplify(temp);
}
void show(fenshu a){
    //չʾ���
    a=simplify(a);
    if (a.up<0){
        printf("(");
    }
    //�Ȼ����п���֮ǰֻ�ǰѷ��ӷ�ĸ����λ��
    if (a.down==1){
        //��������
        printf("%lld",a.up);
    } else if (abs(a.up)>abs(a.down)){
        //���Ǽٷ���
        printf("%lld %lld/%lld",a.up/a.down,abs(a.up)%a.down,a.down);
    } else{
        printf("%lld/%lld",a.up,a.down);

    }
    if (a.up<0){
        printf(")");
    }
}
int main() {
    fenshu temp1,temp2;
    scanf("%lld/%lld %lld/%lld",&temp1.up,&temp1.down,&temp2.up,&temp2.down);
    //�������
    //�����Ǽӷ�
    show(temp1);
    printf(" + ");
    show(temp2);
    printf(" = ");
    show(add(temp1,temp2));
    printf("\n");
    //����
    show(temp1);
    printf(" - ");
    show(temp2);
    printf(" = ");
    show(minu(temp1,temp2));
    printf("\n");
    //�˷�
    show(temp1);
    printf(" * ");
    show(temp2);
    printf(" = ");
    show(mul(temp1,temp2));
    printf("\n");
    //����
    show(temp1);
    printf(" / ");
    show(temp2);
    printf(" = ");
    if (temp2.up==0){
        printf("Inf");
    } else{
        show(div(temp1,temp2));

    }
    printf("\n");
    return 0;
}
