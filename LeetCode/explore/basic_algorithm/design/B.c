// 最小栈
// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

// push(x) —— 将元素 x 推入栈中。
// pop() —— 删除栈顶的元素。
// top() —— 获取栈顶元素。
// getMin() —— 检索栈中的最小元素。
 

// 示例:

// 输入：
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// 输出：
// [null,null,null,null,-3,null,0,-2]

// 解释：
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.getMin();   --> 返回 -2.
 

// 提示：

// pop、top 和 getMin 操作总是在 非空栈 上调用。
int getMin(int *array,int size){
    int min=INT_MAX;
    for(int i = 0; i < size; i++)
    min=min<array[i]?min:array[i];
    return min;
}

typedef struct {
    int elem[10000];
    int top;
    int min;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate() {
    MinStack* obj=(MinStack*)malloc(sizeof(MinStack));
    memset(obj,0,10000*sizeof(int));
    obj->top=0;
    obj->min=INT_MAX;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    obj->elem[obj->top++]=x;
    obj->min=getMin(obj->elem,obj->top);
}

void minStackPop(MinStack* obj) {
    if(obj->top>0)
    obj->top--;
    obj->min=getMin(obj->elem,obj->top);
}

int minStackTop(MinStack* obj){
    if(obj->top>0)
    return obj->elem[obj->top-1];
    else
    return;
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
//每次pop或者push都重新查找min 效率太低
//124ms 12.9mb;


typedef struct {
    int elem[10000];
    int top;
    int min[10000];
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate() {
    MinStack* obj=(MinStack*)malloc(sizeof(MinStack));
    memset(obj->elem,0,1000*sizeof(int));
    memset(obj->min,INT_MAX,1000*sizeof(int));
    obj->top=0;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->top>0)
    obj->min[obj->top]=obj->min[obj->top-1]<x?obj->min[obj->top-1]:x;
    else
    obj->min[obj->top]=x;
    obj->elem[obj->top++]=x;
}

void minStackPop(MinStack* obj) {
    if(obj->top>0)
    obj->top--;
}

int minStackTop(MinStack* obj){
    if(obj->top>0)
    return obj->elem[obj->top-1];
    else
    return;
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->top-1];
}

void minStackFree(MinStack* obj) {
    free(obj);
}
//28ms 1.7mb
//维护一个最小值数组对应不同的top位置