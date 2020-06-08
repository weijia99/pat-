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
//    ̰��˼�룬һ���Լ����������ܵ��Ǽ���
//����վ��ѡ��۸���͵ģ��ȵ�ǰ�ĵͣ����Ǿ�ֻ���е����
//����ȵ�ǰ�Ĺ���ǰ������Ȼ�������ټ���
//    �����ص����Ϊ0
    stu[n].distance=distance;
    stu[n].price=0.0;
    double remain=0;
//    ��Ҫ�ӵ���
    if (stu[0].distance!=0){
        printf("The maximum travel distance = 0");
        return 0;
    }
    double cur=0;
    double sum=0;
    double cPrice=stu[0].price;
    double maxL=per*cmax;
    while (cur<distance){
//        ���ҳ���Сֵ
        double minPrice=10000.0;
        int p=0;
        int flag=0;
//        ������������˵��ԭ����1���ҵ���С�ģ���0�Ƕ�ѡ��
        for (int i = 1; i < n+1; ++i) {
            if (cur<stu[i].distance&&stu[i].distance<=cur+maxL){
//                �ҵ�����

//                ����ȵ�ǰ�ļ۸�ͣ�ֱ���ߵ��������վ��������ȥ�������վ����
                if (stu[i].price<cPrice){
//            �ȵ�ǰ��С��ֻ�ӵ�ȥ�������
//          ��ע�������ﻹ��ʣ����
                    sum+=(stu[i].distance-remain*per-cur)*cPrice/per;
//                    �������Ǹ���������Ǹ�����˵����һ�־Ϳ������������
                    cPrice=stu[i].price;
                    remain=0;
                    cur=stu[i].distance;
                    flag=1;
                    break;
//                    �ѽ��ҵ�����


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
        //            ����̰��
//����ȵ�ǰС����ôֻ�ӵ�ȥ�������
        if (flag==0&&minPrice!=10000.0){
//            ���Ƕ�ѡ��
            sum+=(cmax-remain)*cPrice;
//            ֱ�Ӽ���

//            ���������վʱ���ж�����
            remain=(cmax-(stu[p].distance-cur)/per);
            cPrice=minPrice;
            cur=stu[p].distance;
//            ���ߵ��������

        }
        if (flag==0&&minPrice==inf){
//            û�ҵ�
            cur=cmax*per;
            printf("The maximum travel distance = %d",cur);
            return 0;
//            ����
        }
    }
    printf("%.2f",sum);
    return 0;
}
