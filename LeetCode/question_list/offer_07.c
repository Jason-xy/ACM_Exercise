// 剑指 Offer 07. 重建二叉树
// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

//  

// 例如，给出

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7
//  

// 限制：

// 0 <= 节点个数 <= 5000

//  

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//Definition for a binary tree node.
#define NULL 0

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


// void build(struct TreeNode *root, int* preorder, int preorderSize, int* pos, int* inorder, int min, int max){
//     if(min > max || (*pos) == preorderSize)return;
//     int aim = 0;
//     for(aim = min; aim <= max; aim++){
//         if(inorder[aim] == preorder[*pos]){
//             root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//             root->left = NULL;
//             root->right = NULL;
//             root->val = preorder[*pos];
//             pos[0]++;
//             build(root->left, preorder, preorderSize, pos, inorder, min, aim - 1);
//             build(root->right, preorder, preorderSize, pos, inorder, aim + 1, max);
//             break;
//         }
//     }
// }

// struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
//     struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//     root->left = NULL;
//     root->right = NULL;
//     root->val = 0;
//     int pos[1] = {0};
//     build(root, preorder, preorderSize, pos, inorder, 0, inorderSize - 1);
//     return root;
// }
// 无法修改参数里面内容。

struct TreeNode* build(struct TreeNode* root, int* preorder, int preorderSize, int* pos, int* inorder, int min, int max) {
    if (min > max || (*pos) == preorderSize)return NULL;
    int aim = 0;
    for (aim = min; aim <= max; aim++) {
        if (inorder[aim] == preorder[*pos]) {
            root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            root->left = NULL;
            root->right = NULL;
            root->val = preorder[*pos];
            pos[0]++;
            root->left = build(root->left, preorder, preorderSize, pos, inorder, min, aim - 1);
            root->right = build(root->right, preorder, preorderSize, pos, inorder, aim + 1, max);
            break;
        }
    }
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    struct TreeNode* root;
    int pos[1] = { 0 };
    return build(root, preorder, preorderSize, pos, inorder, 0, inorderSize - 1);
}
//分治法、递归