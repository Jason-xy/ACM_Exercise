// 93. 复原IP地址
// 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

// 有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

//  

// 示例:

// 输入: "25525511135"
// 输出: ["255.255.11.135", "255.255.111.35"]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/restore-ip-addresses
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** restoreIpAddresses(char* s, int* returnSize) {
    char** ans = (char**)malloc(sizeof(char*) * 100);
    char str[4][4] = { 0 };
    int i[4] = { 0 }, m = 1, n = 1, sum = 0;
    *returnSize = 0;
    for (i[0] = 1; i[0] < 3; i[0]++) {
        for (i[1] = i[0] + m; m < 3; m++) {
            for (i[2] = i[1] + n; n < 3; n++) {
                if (strlen(s + i[2]) <= 3) {
                    for (int q = 3; q >= 1; q--) {
                        sum = 0;
                        for (int p = i[q - 1]; s[p] || s + p < s + i[q]; p++) {
                            str[q][p] = *(s + p);
                            sum += *(s + p) - '0';
                        }
                        if (sum > 255)
                            break;
                    }
                    ans[*returnSize] = (char*)malloc(sizeof(char) * 16);
                    sprintf(ans[*returnSize], "%s.%s.%s.%s", str[0], str[1], str[2], str[3]);
                    (*returnSize)++;
                }
            }
        }
    }
    return ans;
}
