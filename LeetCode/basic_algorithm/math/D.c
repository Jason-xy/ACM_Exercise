// 罗马数字转整数
// 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

// 字符          数值
// I             1              A
// V             5              B
// X             10             C
// L             50             D
// C             100            E
// D             500            F
// M             1000           G
// 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

// 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

// I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
// X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
// C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
// 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

// 示例 1:

// 输入: "III"
// 输出: 3
// 示例 2:

// 输入: "IV"
// 输出: 4
// 示例 3:

// 输入: "IX"
// 输出: 9
// 示例 4:

// 输入: "LVIII"
// 输出: 58
// 解释: L = 50, V= 5, III = 3.
// 示例 5:

// 输入: "MCMXCIV"
// 输出: 1994
// 解释: M = 1000, CM = 900, XC = 90, IV = 4.

void helper(char *s){
    int i=0;
    while(s[i]){
        if(s[i]=='I')s[i]='A';
        else if(s[i]=='V')s[i]='B';
        else if(s[i]=='X')s[i]='C';
        else if(s[i]=='L')s[i]='D';
        else if(s[i]=='C')s[i]='E';
        else if(s[i]=='D')s[i]='F';
        else s[i]='G';
        i++;
    };
}

int romanToInt(char * s){
    helper(s);
    int char2num[7]={1,5,10,50,100,500,1000};
    int len=strlen(s),i=len-1,ans=0;
    for(i=len-1;i>=0; i--){
        if(s[i]<s[i+1])
        ans-=char2num[s[i]-'A'];
        else
        ans+=char2num[s[i]-'A'];
    }
    return ans;
}//8ms 5.5mb
