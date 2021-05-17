struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL||headB==NULL)
    {
        return NULL;
    }
    //首先统计两个链表的位数
    struct ListNode*list1=headA;
    struct ListNode*list2=headB;
    int count1=0;
    int count2=0;
    while(list1)
    {
        count1++;
        list1=list1->next;
    }
    while(list2)
    {
        count2++;
        list2=list2->next;
    }
    list1=headA;
    list2=headB;
    int num=count1-count2;
    if(num>0)
    {
        while(num--)
        {
           
           
                list1=list1->next;
            
        }
    }
    else if(num<0)
    {
        while(num++)
        {
            list2=list2->next;
        }
    }
   
    while(list1!=NULL&&list2!=NULL)
    {
        if(list1==list2)
        {
            return list1;
        }
        list1=list1->next;
        list2=list2->next;
    }
    return NULL;
    
}