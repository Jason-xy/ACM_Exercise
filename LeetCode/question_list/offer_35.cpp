/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        Node *(map[2000]) = {NULL};
        Node *temp = NULL;
        int i = 0, count = 0;
        for(Node *p = head, *q = NULL; p; p = p->next, q = q->next, i = i + 2){
            temp = (Node*)malloc(sizeof(Node));
            temp->val = p->val;
            q = temp;
            map[i] = p,
            map[i+1] = q;
        }
        count = i;
        for(i = 0; i < count; i += 2){
            if(i < count - 2){
                map[i + 1]->next = map[i + 3];
            }
            else{
                map[i + 1]->next = NULL;
            }

            if(map[i]->random == NULL) map[i + 1]->random = NULL;
            else{
                map[i + 1]->random = NULL;
                for(int j = 0; j < count; j += 2){
                    if(map[j] == map[i]->random){
                        map[i + 1]->random = map[j + 1];
                        break;
                    }
                }
            }
        }
        return map[1];
    }
};