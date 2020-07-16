// 合并两个有序链表
// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

// 示例：

// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1)return l2;
    else if(!l2)return l1;
    struct ListNode *head, *tail,*p1,*p2;
    if(l1->val <= l2->val)
    head = l1,p1=l1->next,p2=l2;
    else
    head = l2,p1=l2->next,p2=l1;
    tail=head;
    if(!p1){
        tail->next=p2;
        return head;
    }
    for(;;){
        if(p2->val < p1->val){
            tail->next =p2;
            for(;p2->next&&p1->val>=p2->next->val;p2=p2->next);
            tail = p2;
            if(p2->next)
            p2=p2->next;
            else{
                p2->next=p1;
                return head;
            }
        }
        else{
            tail->next =p1;
            for(;p1->next&&p1->next->val<=p2->val;p1=p1->next);
            tail = p1;
            if(p1->next)
            p1=p1->next;
            else{
                p1->next=p2;
                return head;
            }
        }
    }
    return head;
}
//调整连接次数最少

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode*head=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*tail=head;
    for(;l1&&l2;){
        if(l1->val<=l2->val){
            tail->next=l1;
            tail=l1;
            l1=l1->next;
        }
        else{
            tail->next=l2;
            tail=l2;
            l2=l2->next;
        }
    }
    tail->next=l1?l1:l2;
    return head->next;
}
//思路简单，但是每个节点都要操作