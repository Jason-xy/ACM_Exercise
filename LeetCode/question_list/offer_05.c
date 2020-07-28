// 剑指 Offer 05. 替换空格
// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

//  

// 示例 1：

// 输入：s = "We are happy."
// 输出："We%20are%20happy."
//  

// 限制：

// 0 <= s 的长度 <= 10000

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

char* replaceSpace(char* s){
    char *ans = (char*)malloc(sizeof(char)*10001);
    memset(ans, 0, sizeof(char)*10001);
    for(int i = 0, j = 0; s[i]; i++){
        if(s[i] == ' '){
            ans[j++] = '%';
            ans[j++] = '2';
            ans[j++] = '0';
        }
        else
        ans[j++] = s[i];
    }
    return ans;
}