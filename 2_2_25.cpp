struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
void reorderList(ListNode* head) {
        ListNode* p=head,*q=head,*r,*s=head;
        if(!head)            //headΪ�գ���ֱ���˳�
            return ;
        while(q->next){      //Ѱ���м���
            q=q->next;       //p��һ��
            p=p->next;
            if(q->next)
              q=q->next;     //q������
        }
        q=p->next;           //p��ָ���Ϊ�м��㣬qΪ����������׽��
        p->next=nullptr;
        while(q){            //�������������
            r=q->next;
            q->next=p->next;
            p->next=q;
            q=r;
        }
        q=p->next;            //qָ����εĵ�һ�����ݽ��
        p->next=nullptr;      //��������������γɻ���һֱ����
        while(q){             //��������εĽ����뵽ָ��λ��
            r=q->next;        //rָ����ε���һ�����
            q->next=s->next;  //��q��ָ�����뵽s��ָ��㣨head��㣩֮��
            s->next=q;
            s=q->next;        //sָ��ǰ��ε���һ�������
            q=r;
        }
    }
