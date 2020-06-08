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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1=NULL,*p2=NULL,*ans=NULL,*p3=NULL,*tail=NULL;
    ans=(struct ListNode*)malloc(sizeof(struct ListNode));
    ans->next=NULL;
    int extra=0,temp1=0,temp2=0;
    for(p1=l1,p2=l2,p3=ans;(p1!=NULL&&p2!=NULL)||extra==1;){
        temp1=0,temp2=0;
        if(p1!=NULL){
            temp1=p1->val;
            p1=p1->next;
        }
        if(p2!=NULL){
            temp2=p2->val;
            p2=p2->next;
        }
        if(extra+temp1+temp2>=10){
            p3->val=extra+temp1+temp2-10;
            extra=1;
        }
        else{
            p3->val=extra+temp1+temp2;
            extra=0;
        }
        if((p1!=NULL&&p2!=NULL)||extra==1){
            p3->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            p3=p3->next;
            p3->next=NULL;
        }
    }
    return ans;
}