// 反转链表
// 反转一个单链表。

// 示例:

// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL
// 进阶:
// 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(!head)return NULL;
    struct ListNode *list[5000]={NULL},*p=head;
    int i=0;
    for(i=0;p;i++){
        list[i]=p;
        p=p->next;
    }
    p=list[--i];
    for(;i>0;i--){
        list[i]->next=list[i-1];
    }
    list[0]->next=NULL;
    return p;
}
//使用了额外空间

struct ListNode* reverseList(struct ListNode* head){
    typedef struct ListNode * PtrToLNode;
    PtrToLNode new_head, old_head, temp;
	
	old_head=head;		//初始化当前旧表头为head
	new_head=NULL;		//初始化逆转后新表头为空

	while(old_head){	//当旧表头不为空时
		temp=old_head->next;
		old_head->next=new_head;
		new_head=old_head;
		old_head=temp;
	}
	head=new_head;		//更新head
	return head;
}
//不使用额外空间迭代

struct ListNode* reverseList(struct ListNode* head){
    if(!head) return NULL;
    if(!head->next){
        return head;
    }
    struct ListNode* p=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return p;
}
//递归