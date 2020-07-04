// 验证回文字符串
// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

// 说明：本题中，我们将空字符串定义为有效的回文串。

// 示例 1:

// 输入: "A man, a plan, a canal: Panama"
// 输出: true
// 示例 2:

// 输入: "race a car"
// 输出: false

bool isPalindrome(char * s){
    if(s==NULL||s[0]==0)
    return true;
    int i=0,j=0;
    char* str=(char*)malloc(sizeof(char)*strlen(s));
    for(i=0;s[i]!=0;i++){
        if(s[i]>=48&&s[i]<=57)
        str[j++]=s[i];
        else if(s[i]>=65&&s[i]<=90)
        str[j++]=s[i]+32;
        else if(s[i]>=97&&s[i]<=122)
        str[j++]=s[i];
    }
    for(i=0;i<j/2;i++){
        if(str[i]!=str[j-i-1])
        return false;
    }
    return true;
}