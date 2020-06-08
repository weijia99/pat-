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

//cin用多了超市

using namespace std;
const long int maxn=1001;
const int inf=0x7fffffff;
struct station{
    double distance;
    double price;
}stu[maxn];
bool cmp(station a,station b){
    if (a.price!=b.distance){
        return a.distance<b.distance;
    }
}
int main() {
    double cmax,distance,per;
    int n;
    cin>>cmax>>distance>>per>>n;
    for (int i = 0; i < n; ++i) {
        double price;
        double d;
        cin>>price>>d;
        stu[i].distance=d;
        stu[i].price=price;
    }
    sort(stu,stu+n,cmp);
//    贪心思想，一次性加满，看能跑到那几个
//加油站，选择价格最低的（比当前的低），那就只加有到这个
//如果比当前的鬼，当前加满，然后到哪里再加满
//    设置重点加油为0
    stu[n].distance=distance;
    stu[n].price=0.0;
    double remain=0;
//    需要加的油
    if (stu[0].distance!=0){
        printf("The maximum travel distance = 0");
        return 0;
    }
    double cur=0;
    double sum=0;
    double cPrice=stu[0].price;
    double maxL=per*cmax;
    while (cur<distance){
//        先找出最小值
        double minPrice=10000.0;
        int p=0;
        int flag=0;
//        看跳出来的是说明原因，是1是找到最小的，是0是多选的
        for (int i = 1; i < n+1; ++i) {
            if (cur<stu[i].distance&&stu[i].distance<=cur+maxL){
//                找到区间

//                如果比当前的价格低，直接走到这个加油站，加正好去这个加油站的油
                if (stu[i].price<cPrice){
//            比当前的小，只加到去这里的油
//          备注，邮箱里还有剩余油
                    sum+=(stu[i].distance-remain*per-cur)*cPrice/per;
//                    不可能是负数，如果是负数，说明上一轮就可以来到这个点
                    cPrice=stu[i].price;
                    remain=0;
                    cur=stu[i].distance;
                    flag=1;
                    break;
//                    已近找到跳出


                }
                if (stu[i].price<minPrice){
                    minPrice=stu[i].price;
                    p=i;
                }
            }else if(stu[i].distance>cur+maxL){
                break;
//
            }

        }
        //            进行贪心
//如果比当前小，那么只加到去这里的油
        if (flag==0&&minPrice!=10000.0){
//            这是多选的
            sum+=(cmax-remain)*cPrice;
//            直接加满

//            到这个加油站时还有多少油
            remain=(cmax-(stu[p].distance-cur)/per);
            cPrice=minPrice;
            cur=stu[p].distance;
//            我走到这里加油

        }
        if (flag==0&&minPrice==inf){
//            没找到
            cur=cmax*per;
            printf("The maximum travel distance = %d",cur);
            return 0;
//            结束
        }
    }
    printf("%.2f",sum);
    return 0;
}
