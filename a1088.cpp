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

//这题还是错了



using namespace std;
const long int maxn=100100;
const int inf=0x7fffffff;
typedef long long ll ;
struct fenshu{
    ll up,down;
    //up是分子，down是分母
};
ll  gcd(ll a,ll b){
    if (b==0){
        return a;
    } else{
        return gcd(b,a%b);
    }
    //求最大公约数来约分
}
fenshu simplify(fenshu a){
    //花间分数
    if (a.down<0){
        //如果分母小于《0
//        分母分子符号互换
        a.down=-a.down;
        a.up=-a.up;
    } else if (a.up==0){
        //如果分子为0，分母化为1方便计算
        a.down=1;
    } else{
        ll n=gcd(abs(a.up),abs(a.down));
        a.down/=n;
        a.up/=n;
    }
    return a;


}
fenshu add(fenshu a,fenshu b){
//    分数加法
    fenshu temp;
    temp.up=a.up*b.down+a.down*b.up;
    temp.down=a.down*b.down;
    return simplify(temp);
    //最后返回化简的分数
}
fenshu minu(fenshu a,fenshu b){
    //减法
    fenshu temp;
    temp.up=a.up*b.down-a.down*b.up;
    temp.down=a.down*b.down;
    return simplify(temp);
}
fenshu mul(fenshu a,fenshu b){
//    乘法
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
    //展示结果
    a=simplify(a);
    if (a.up<0){
        printf("(");
    }
    //先化简，有可能之前只是把分子分母换了位置
    if (a.down==1){
        //这是正数
        printf("%lld",a.up);
    } else if (abs(a.up)>abs(a.down)){
        //这是假分数
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
    //分批输出
    //现在是加法
    show(temp1);
    printf(" + ");
    show(temp2);
    printf(" = ");
    show(add(temp1,temp2));
    printf("\n");
    //减法
    show(temp1);
    printf(" - ");
    show(temp2);
    printf(" = ");
    show(minu(temp1,temp2));
    printf("\n");
    //乘法
    show(temp1);
    printf(" * ");
    show(temp2);
    printf(" = ");
    show(mul(temp1,temp2));
    printf("\n");
    //除法
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
