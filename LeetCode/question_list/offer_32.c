// 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* levelOrder(struct TreeNode* root, int* returnSize){
    int *val_queue = malloc(1100 * sizeof(int));
    struct TreeNode* addr_queue[1100] = {0};
    int idx_val = 0, idx_addr = 0, i = 0;
    struct TreeNode* p;
    if(root == NULL){
        *returnSize = 0;
        return val_queue;
    }
    addr_queue[0] = root;
    val_queue[0] = root->val;
    
    for(i = 0; !(p->left == NULL && p->right == NULL && i > idx_addr); i++){
        p = addr_queue[i];
        if(p->left != NULL){
            addr_queue[++idx_addr] = p->left;
            val_queue[++idx_val] = p->left->val;
        }
        if(p->right != NULL){
            addr_queue[++idx_addr] = p->right;
            val_queue[++idx_val] = p->right->val;
        }
    }
    *returnSize = idx_val + 1;
    return val_queue;
}

