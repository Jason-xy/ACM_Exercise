// 剑指 Offer 13. 机器人的运动范围
// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

//  

// 示例 1：

// 输入：m = 2, n = 3, k = 1
// 输出：3
// 示例 2：

// 输入：m = 3, n = 1, k = 0
// 输出：1
// 提示：

// 1 <= n,m <= 100
// 0 <= k <= 20

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//BFS 
typedef struct point{
    int x;
    int y;
}Point;

typedef struct queue{
    Point point[10000];
    int head;
    int tail;
    int length;
}Queue;

void push(Queue* queue, Point point){
    queue->point[queue->tail].x = point.x;
    queue->point[queue->tail].y = point.y;
    queue->tail = (queue->tail + 1) % 10000;
    queue->length++;
}

void pop(Queue* queue, Point* point){
    point->x = queue->point[queue->head].x;
    point->y = queue->point[queue->head].y;
    queue->head = (queue->head + 1) % 10000;
    queue->length--;
}

int add(int x, int y){
    return x % 10 + (x - (x % 10)) / 10 + y % 10 + (y - (y % 10)) / 10;
}

int movingCount(int m, int n, int k){
    if(m == 0 || n == 0)
    return 0;

    Point point, temp;
    point.x = 0, point.y = 0;

    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->head = 0;
    queue->tail = 0;
    queue->length = 0;
    push(queue, point);

    int path[100][100]={1};
    int ans = 1;

    for(;queue->length;){
        pop(queue, &point);
        if(point.x - 1 >= 0 && path[point.x - 1][point.y] == 0){
            if(add(point.x - 1, point.y) <= k){
                path[point.x - 1][point.y] = 1;
                temp.x = point.x - 1, temp.y = point.y;
                push(queue, temp);
                ans++;
            }
        }
        if(point.x + 1 < n && path[point.x + 1][point.y] == 0){
            if(add(point.x + 1, point.y) <= k){
                path[point.x + 1][point.y] = 1;
                temp.x = point.x + 1, temp.y = point.y;
                push(queue, temp);
                ans++;
            }
        }
        if(point.y - 1 >=0 && path[point.x][point.y - 1] == 0){
            if(add(point.x, point.y - 1) <= k){
                path[point.x][point.y - 1] = 1;
                temp.x = point.x, temp.y = point.y - 1;
                push(queue, temp);
                ans++;
            }
        }
        if(point.y + 1 < m && path[point.x][point.y + 1] == 0){
            if(add(point.x, point.y + 1) <= k){
                path[point.x][point.y + 1] = 1;
                temp.x = point.x, temp.y = point.y + 1;
                push(queue, temp);
                ans++;
            }
        }
    }
    return ans;
}