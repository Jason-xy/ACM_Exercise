// 回文链表
// 请判断一个链表是否为回文链表。

// 示例 1:

// 输入: 1->2
// 输出: false
// 示例 2:

// 输入: 1->2->2->1
// 输出: true
// 进阶：
// 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    if(!head||!head->next)return true;
    int len=0;
    struct ListNode* p=head;
    for(len=0;p;p=p->next,len++);
    int *list=(int*)malloc(sizeof(int)*len);
    for(p=head,len=0;p;p=p->next,len++){
        list[len]=p->val;
    }
    for(int i=0;i<len/2;i++){
        if(list[i]!=list[len-1-i])
        return false;
    }
    return true;
}
//16ms 9.6mb

bool isPalindrome(struct ListNode* head){
    if(!head||!head->next)return true;
    int len=0;
    struct ListNode* p=head;
    int list[10000]={0};
    for(p=head,len=0;p;p=p->next,len++){
        list[len]=p->val;
    }
    for(int i=0;i<len/2;i++){
        if(list[i]!=list[len-1-i])
        return false;
    }
    return true;
}
//16ms 9.5mb

//TODO反转链表比较