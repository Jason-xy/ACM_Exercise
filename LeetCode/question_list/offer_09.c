// 剑指 Offer 09. 用两个栈实现队列
// 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

//  

// 示例 1：

// 输入：
// ["CQueue","appendTail","deleteHead","deleteHead"]
// [[],[3],[],[]]
// 输出：[null,null,3,-1]
// 示例 2：

// 输入：
// ["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
// [[],[],[5],[2],[],[]]
// 输出：[null,-1,null,null,5,2]
// 提示：

// 1 <= values <= 10000
// 最多会对 appendTail、deleteHead 进行 10000 次调用

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

typedef struct {
    int* in;
    int* out;
    int top_in;
    int top_out;
} CQueue;


CQueue* cQueueCreate() {
    CQueue *obj = (CQueue*)malloc(sizeof(CQueue));
    obj->in = (int*)malloc(sizeof(int)*10000);
    memset(obj->in, 0, sizeof(int)*10000);
    obj->out = (int*)malloc(sizeof(int)*10000);
    memset(obj->out, 0, sizeof(int)*10000);
    obj->top_in = -1;
    obj->top_out = -1;
    return obj;
}

void cQueueAppendTail(CQueue* obj, int value) {
    int i;
    obj->in[++obj->top_in] = value;
    for(i = obj->top_in, obj->top_out = -1; i >= 0; i--) {
        obj->out[++obj->top_out] = obj->in[i];
    }
    return;
}
//O(n)

int cQueueDeleteHead(CQueue* obj) {
    int i;
    if(obj->top_out < 0 || obj->top_in < 0){
        obj->top_out = -1;
        obj->top_in = -1;
        return -1;
    }
    if(obj->top_out == 0){
        obj->top_out = -1;
        obj->top_in = -1;
        return obj->out[0];
    }
    --obj->top_out;
    for(i = obj->top_out, obj->top_in = -1; i >= 0; i--) {
        obj->in[++obj->top_in] = obj->out[i];
    }
    return obj->out[obj->top_out+1];
}
//O(n)

void cQueueFree(CQueue* obj) {
    free(obj->in);
    free(obj->out);
    free(obj);
    return;
}
//垃圾一样的算法

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/