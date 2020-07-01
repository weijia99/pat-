struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
int kthToLast(ListNode* head, int k) {
    ListNode* c=head;
        while(k){
            head=head.next;
            k--;
        }
        while(head){
            c=c.next;
            head=head.next;
        }
        return c.val;

    }
