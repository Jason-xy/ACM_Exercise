// 剑指 Offer 06. 从尾到头打印链表
// 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

//  

// 示例 1：

// 输入：head = [1,3,2]
// 输出：[2,3,1]
//  

// 限制：

// 0 <= 链表长度 <= 10000

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* reversePrint(struct ListNode* head, int* returnSize){
    struct ListNode* temp;
    int length = 0;
    for(temp = head; temp; temp = temp->next, length++);
    returnSize[0] = length;
    int *ans=(int*)malloc(sizeof(int)*length);
    length--;
    for(temp = head; temp; temp = temp->next)
        ans[length--] = temp->val;
    return ans;
}//遍历


int* reversePrint(struct ListNode* head, int* returnSize){
    if(head == NULL){
        *returnSize = 0;
        return malloc(sizeof(int) * 10000);
    }
    int *ans = reversePrint(head->next, returnSize);
    ans[(*returnSize)++] = head->val;
    return ans;
}//递归