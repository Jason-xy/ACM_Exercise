// 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

//交叉比较
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p = l1, *q = l2, *pp, *qp, *ans;
    if(l1 == NULL && l2 == NULL) return NULL;
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    if(l1->val <= l2->val) ans = l1;
    else ans = l2;

    for(p = l1, q = l2; p != NULL && q != NULL;){
        if(q->val < p->val){
           for(;q != NULL && q->val < p->val; q = q->next){
               qp = q;
           }
           qp->next = p;
        }else if(q->val >= p->val){
            for(;p != NULL && q->val >= p->val; p = p->next){
                pp = p;
            }
            pp->next = q;
        }
    }
    return ans;
}