//  最长公共前缀
// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

// 示例 1:

// 输入: ["flower","flow","flight"]
// 输出: "fl"
// 示例 2:

// 输入: ["dog","racecar","car"]
// 输出: ""
// 解释: 输入不存在公共前缀。
// 说明:

// 所有输入只包含小写字母 a-z 。

char * longestCommonPrefix(char ** strs, int strsSize){
    char* same= (char*)malloc(sizeof(char) *1000);
    same[0]=0;
    if(!strsSize||!strs)return same;
    strcpy(same,strs[0]);
    int len=strlen(same),i=0,j=0;
    for(i=0;i<strsSize;i++){
        for(j=0;j<len;j++){
            if(strs[i][j]!=same[j]){
                len=j;
                same[j]=0;
                break;
            }
        }
    }
    return same;
}
//0ms 5.7mb