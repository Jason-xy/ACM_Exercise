//在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

char firstUniqChar(char* s){
    unsigned char map[26] = {0};
    for(char *p = s; *p; p++)
        map[*p - 'a']++;
    for(char *p = s; *p; p++){
        if(map[*p - 'a'] == 1) return *p;
    }
    return ' ';
}