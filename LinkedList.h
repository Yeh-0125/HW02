typedef struct node{
    int apple;
    struct node *next;
}Node;
void renewline(char *str);
Node *insert(Node *top,char *str);
void print(Node *top);
void LinkedList();
