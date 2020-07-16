// 删除链表的倒数第N个节点
// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

// 示例：

// 给定一个链表: 1->2->3->4->5, 和 n = 2.

// 当删除了倒数第二个节点后，链表变为 1->2->3->5.
// 说明：

// 给定的 n 保证是有效的。

// 进阶：

// 你能尝试使用一趟扫描实现吗？

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *list[1000]={NULL},*p=head;
    int i=0;
    for(i=0; p; i++){
        list[i]=p;
        p=p->next;
    }
    if(list[i-n]==head){
        p=head->next;
        //free(head);
        return p;
    }
    else{
        list[i-n-1]->next=list[i-n]->next;
        //free(list[i-n]);
        return head;
    }
}