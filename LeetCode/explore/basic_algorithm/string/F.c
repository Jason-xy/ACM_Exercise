// 字符串转换整数 (atoi)
// 请你来实现一个 atoi 函数，使其能将字符串转换成整数。

// 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

// 如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
// 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
// 该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
// 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。

// 在任何情况下，若函数不能进行有效的转换时，请返回 0 。

// 提示：

// 本题中的空白字符只包括空格字符 ' ' 。
// 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。
 

// 示例 1:

// 输入: "42"
// 输出: 42
// 示例 2:

// 输入: "   -42"
// 输出: -42
// 解释: 第一个非空白字符为 '-', 它是一个负号。
//      我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
// 示例 3:

// 输入: "4193 with words"
// 输出: 4193
// 解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
// 示例 4:

// 输入: "words and 987"
// 输出: 0
// 解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
//      因此无法执行有效的转换。
// 示例 5:

// 输入: "-91283472332"
// 输出: -2147483648
// 解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
//      因此返回 INT_MIN (−231) 。

int myAtoi(char* str) {
    if (!str)
        return 0;
    char* s = (char*)malloc(sizeof(char) * strlen(str) + 1);
    int i = 0, j = 0;
    for (i = 0; str[i] != 0; i++) {
        if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
            s[j++] = str[i];
        if (j == 0 && (str[i] != ' ' && str[i] != '+' && str[i] != '-'))//ab213
            return 0;
        if (j == 1 && !((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' || str[i] == '+'))) {//-+123
            if (s[0] == '+' || s[0] == '-')
                return 0;
            else
                break;
        }
        if (j == 2 && (str[i] == '-' || str[i] == '+'))
            return 0;
        if (j >= 2 && !(str[i] >= '0' && str[i] <= '9')) {
            if(str[i]=='+'||str[i]=='-')
            j--;
            break;
        }
        if (j >= 1 && str[i] == '.')//3.14
            break;
    }
    s[j] = 0;
    if (j == 0 || (j == 1 && (s[0] == '-' || s[0] == '+')))
        return 0;
    long ans = 0;
    if (s[0] == '-' || s[0] == '+') {
        for (i = 1; i <= j - 1; i++) {
            ans = ans * 10 + (s[i] - '0');
            if (ans > (int)ans) {
                if (s[0] == '+')
                    return 2147483647;
                else
                    return -2147483648;
            }
        }
        if (s[0] == '+')
            return (int)ans;
        else
            return -(int)ans;
    }
    else {
        for (i = 0; i < j; i++) {
            ans = ans * 10 + (s[i] - '0');
            if (ans > (int)ans)
                return 2147483647;
        }
        return (int)ans;
    }
}
//Rubbish


int myAtoi(char* str) {
    char* s = (char*)malloc(sizeof(char) * strlen(str));
    int i = 0, j = 0;
    if (!str)return 0; //空字符情况
    for (i = 0; str[i] != 0; i++) {
        if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
            s[j++] = str[i]; //如果为有效整数字符则拷贝
        if (j == 0 && str[i] != ' ')return 0; //如果第一个非空格字符不是有效整数字符
        if (s[0] == '+' || s[0] == '-') {//有符号的情况
            if (j == 1 && !((str[i] >= '0' && str[i] <= '9')||str[i]=='-'||str[i]=='+'))return 0; //在符号后面出现非数字的情况
            if (j >= 2 && !(str[i] >= '0' && str[i] <= '9')) {
                if (j == 2 && (str[i] == '-' || str[i] == '+'))
                    return 0;//连续出现两次符号
                else
                    if (str[i] == '-' || str[i] == '+')
                        j--;//由于出现符号而截断
                    break; //数字后出现非整数字符，提前截断 
            }
        }
        else if (s[0] >= '0' && s[0] <= '9') {
            if (j >= 1 && !(str[i] >= '0' && str[i] <= '9')){
                if (str[i] == '-' || str[i] == '+')
                        j--;//由于出现符号而截断
                break; //数字后出现非整数字符，提前截断 
            }
        }
    }
    if (j == 0 || (j == 1 && (s[0] == '-' || s[0] == '+')))
        return 0; //空字符或者没有出现数字
    long ans = 0;
    if (s[0] == '-' || s[0] == '+') {
        for (i = 1; i <= j - 1; i++) {
            ans = ans * 10 + (s[i] - '0');
            if (ans > (int)ans) {
                if (s[0] == '+')
                    return 2147483647;
                else
                    return -2147483648;
            }
        }
        if (s[0] == '+')
            return (int)ans;
        else
            return -(int)ans;
    }
    else {
        for (i = 0; i < j; i++) {
            ans = ans * 10 + (s[i] - '0');
            if (ans > (int)ans)
                return 2147483647;
        }
        return (int)ans;
    }
}
//辣鸡重构

int myAtoi(char *str){
    long i = 0;
    int ret = sscanf(str, "%ld", &i); // 注意：读取的是%ld，不是%1d
    if (ret) {
        if (i > (int)i)
            i = 2147483647;
        else if (i < (int)i)
            i = -2147483647;
    }
    return (int)i;
}
//涨姿势了