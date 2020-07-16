// 有效的字母异位词
// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 示例 1:

// 输入: s = "anagram", t = "nagaram"
// 输出: true
// 示例 2:

// 输入: s = "rat", t = "car"
// 输出: false
// 说明:
// 你可以假设字符串只包含小写字母。

// 进阶:
// 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

bool isAnagram(char * s, char * t){
    int hashtable[26]={0},i;
    for(i=0;s[i]!=0&&t[i]!=0;i++){
        hashtable[s[i]-'a']++;
        hashtable[t[i]-'a']--;
    }
    if(s[i]!=0||t[i]!=0)
    return false;
    for(i=0;s[i]!=0;i++){
        if(hashtable[s[i]-'a']!=0)
        return false;
    }
    return true;
}
//0ms 5.7mb