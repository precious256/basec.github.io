struct ListNode*hascycle(struct ListNode*head)
 {
     if(head==NULL)
     {
         return;
     }
     struct ListNode*fast=head;
     struct ListNode*slow=head;
     while(fast&&fast->next)
     {
         slow=slow->next;
         fast=fast->next->next;
         if(slow==fast)
         {
             return slow;
         }
     }
     return NULL;
 }
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode*ph=hascycle(head);
    if(head==NULL||ph==NULL)
    {
        return NULL;
    }
    struct ListNode*slow=head;
    while(ph!=slow)
    {
        ph=ph->next;
        slow=slow->next;
    }
    return ph;
    
}