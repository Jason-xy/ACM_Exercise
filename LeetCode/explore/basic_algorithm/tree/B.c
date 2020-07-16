//  验证二叉搜索树
// 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

// 假设一个二叉搜索树具有如下特征：

// 节点的左子树只包含小于当前节点的数。
// 节点的右子树只包含大于当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。
// 示例 1:

// 输入:
//     2
//    / \
//   1   3
// 输出: true
// 示例 2:

// 输入:
//     5
//    / \
//   1   4
//      / \
//     3   6
// 输出: false
// 解释: 输入为: [5,1,4,null,null,3,6]。
//      根节点的值为 5 ，但是其右子节点值为 4 。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int num[1000]={0};
bool isValidBST(struct TreeNode* root){
    if(!root)return true;
    int ans=1;
    ans*=isValidBST(root->left);
    num[++num[0]]=root->val;
    if(num[0]!=1&&!(num[num[0]]>num[num[0]-1]))
    return 0;
    ans*=isValidBST(root->right);
    return ans;
}
//不能使用全局变量

bool helper(struct TreeNode *root, long long lower, long long up per) {
    if (root == NULL)
        return true;
    if (root->val <= lower || root->val >= upper)
        return false;
    return helper(root->left, lower, root->val) &&
           helper(root->right, root->val, upper);
}
bool isValidBST(struct TreeNode *root) {
    return helper(root, LONG_MIN, LONG_MAX);
}