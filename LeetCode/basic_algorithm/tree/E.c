// 将有序数组转换为二叉搜索树
// 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

// 示例:

// 给定有序数组: [-10,-3,0,5,9],

// 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

//       0
//      / \
//    -3   9
//    /   /
//  -10  5

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void array2bst(struct TreeNode* root,int* array,int max_index,int min_index){
    if(max_index==min_index){
        root->val=array[max_index];
        root->left=NULL;
        root->right=NULL;
    }
    else{
        int mid=min_index+ceil((max_index-min_index)/(float)2);
        root->val=array[mid];
        root->left=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        array2bst(root->left,array,mid-1,min_index);
        if(mid==max_index)
        root->right=NULL;
        else{
            root->right=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            array2bst(root->right,array,max_index,mid+1);
        }
    }
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize==0||!nums)return NULL;
    struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    array2bst(root,nums,numsSize-1,0);
    return root;
}
//8ms 17.3mb