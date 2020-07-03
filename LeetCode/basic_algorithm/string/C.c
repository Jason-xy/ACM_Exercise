// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

 

// 示例：

// s = "leetcode"
// 返回 0

// s = "loveleetcode"
// 返回 2

int firstUniqChar(char * s){
    if(s == NULL || s[0] == '\0' ) {
        return -1;
    }
    int hashtable[26]={0};
    for(int i=0; s[i]!=0; i++){
        hashtable[s[i]-'a']++;
    }
    for(int i=0; s[i]!=0; i++){
        if(hashtable[s[i]-'a']==1)
        return i;
    }
    return -1;
}

//12ms 6.5mb