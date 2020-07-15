// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

// 示例 1:

// 输入: "()"
// 输出: true
// 示例 2:

// 输入: "()[]{}"
// 输出: true
// 示例 3:

// 输入: "(]"
// 输出: false
// 示例 4:

// 输入: "([)]"
// 输出: false
// 示例 5:

// 输入: "{[]}"
// 输出: true

typedef struct{
    char* elem;
    int top;
}Stack;

Stack* Stack_Init(){
    Stack* obj = (Stack*)malloc(sizeof(Stack));
    obj->elem = (char*)malloc(sizeof(char)*10000);
    memset(obj->elem, 0, sizeof(char)*10000);
    obj->top = 0;
    return obj;
}

void push(Stack* obj,char a){
    obj->elem[obj->top++]=a;
}

void pop(Stack* obj){
    obj->top--;
}

bool isValid(char * s){
    int i=0;
    Stack* obj=Stack_Init();
    for(i=0;s[i];i++){
        push(obj,s[i]);
        if(obj->top>1){
            if((obj->elem[obj->top-1]==')'&&obj->elem[obj->top-2]=='(')|| \
               (obj->elem[obj->top-1]==']'&&obj->elem[obj->top-2]=='[')|| \
               (obj->elem[obj->top-1]=='}'&&obj->elem[obj->top-2]=='{'))
            obj->top-=2;
        }
    }
    if(obj->top)
    return false;
    else
    return true;
}//0ms 6.3mb