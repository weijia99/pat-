#include <iostream>
#include<string>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
       ListNode *p=node.next,*q=p.next;
       //pre是断链后端头插法节点

       ListNode *pre;
       //进行断链
       p.next=NULL;
       //进行替换
       p=r;
       while(p!=NULL){
        r=p.next;
        pre=node;
        while(pre.next!=null&&pre.next.val<p.val){
            pre=pre.next;
        }
        p.next=pre.next;
        pre.next=p;
        p=r;
        //进行下一轮
       }


    }
 void reorderList(ListNode* head) {
        ListNode* p=head,*q=head,*r,*s=head;
        if(!head)            //head为空，则直接退出
            return ;
        while(q->next){      //寻找中间结点
            q=q->next;       //p走一步
            p=p->next;
            if(q->next)
              q=q->next;     //q走两步
        }
        q=p->next;           //p所指结点为中间结点，q为后半段链表的首结点
        p->next=nullptr;
        while(q){            //将链表后半段逆置
            r=q->next;
            q->next=p->next;
            p->next=q;
            q=r;
        }
        q=p->next;            //q指向后半段的第一个数据结点
        p->next=nullptr;
        while(q){             //将链表后半段的结点插入到指定位置
            r=q->next;        //r指向后半段的下一个结点
            q->next=s->next;  //将q所指结点插入到s所指结点（head结点）之后
            s->next=q;
            s=q->next;        //s指向前半段的下一个插入点
            q=r;
        }
    }


{
    int a,b;
    cin>>a>>b;
    int c=a+b;

    if(c<0){
        for(int i=1;i<)
    }
    return 0;
}
