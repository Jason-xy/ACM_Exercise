//链表排序插入
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int price;
    struct dish *next
}dish;
dish *head = NULL;

void node_init(void);
void node_insort(dish *pre, dish *after, dish *cur);
dish* add_node(int price);
dish* search_pre(dish *cur);


int main(void)
{
    int n, money, price, sum = 0, pre = 0;
    dish *ptr, *add;
    node_init();
    for(scanf("%d", &n); n != 0; )
    {
        getchar();
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&price);
            add = add_node(price);
            for(ptr = head; ptr; ptr = ptr->next)
            {
                if(add->price < ptr->price)
                node_insort(search_pre(ptr), ptr, add);
                else if(ptr->next == NULL)
                ptr->next = add;
            }
        }
        scanf("%d", &money);
        for(ptr = head; ptr; ptr = ptr->next)
        {
            sum += ptr->price;
            if(money - sum - pre < 5 && money - sum >= 5)
            {
                sum += search_pre(NULL)->price;
            }
            pre = ptr->next;
        }
        printf("%d\n",money - sum);
    }
    return 0;
}

void node_init(void)
{
    head = malloc(sizeof(dish));
    head->next = NULL;
    head->price = 0;
}

void node_insort(dish *pre,dish *after, dish *cur)
{
    pre->next = cur;
    cur->next = after;
}

dish* add_node(int price)
{
    dish *temp;
    temp = malloc(sizeof(dish));
    temp->price = price;
    return temp;
}

dish* search_pre(dish *cur)
{
    dish* temp;
    for(temp = head; temp->next == cur && temp; temp = temp->next);
    return temp;
}