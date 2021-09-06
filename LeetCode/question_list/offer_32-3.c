// 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void reverse(int *array, int len){
    int i, temp;
    for(i = 0; i < len / 2; i++){
        temp = array[i];
        array[i] = array[len - 1 - i];
        array[len - 1 - i] = temp;
    }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **val_queue = (int **)malloc(1000 * sizeof(int*));
    returnColumnSizes[0] = (int *)malloc(1000 * sizeof(int));
    struct TreeNode* addr_queue[1100] = {0};
    int idx_val = 0, idx_addr = 0, idx_level = 0, node_num = 0, child_num = 0, i = 0;

    struct TreeNode* p;
    if(root == NULL){
        *returnSize = 0;
        returnColumnSizes[0][0] = 0;
        return val_queue;
    }
    node_num = 1;
    val_queue[0] = (int *)malloc(node_num * sizeof(int));
    addr_queue[0] = root;
    val_queue[0][0] = root->val;
    returnColumnSizes[0][0] = 1;
    
    idx_level = 1;
    for(i = 0; !(p->left == NULL && p->right == NULL && i > idx_addr); idx_level++){
        val_queue[idx_level] = (int *)malloc(2 * node_num * sizeof(int));
        idx_val = 0;
        for(int j = 0; j < node_num; j++, i++){
            p = addr_queue[i];
            if(p->left != NULL){
                addr_queue[++idx_addr] = p->left;
                val_queue[idx_level][idx_val++] = p->left->val;
            }
            if(p->right != NULL){
                addr_queue[++idx_addr] = p->right;
                val_queue[idx_level][idx_val++] = p->right->val;
            }
        }
        returnColumnSizes[0][idx_level] = idx_val;
        node_num = idx_val;
        if(idx_level % 2)
            reverse(val_queue[idx_level], idx_val);
    }
    *returnSize = idx_level - 1;
    return val_queue;
}