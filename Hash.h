typedef struct hnode{
    int apple;
    struct hnode *next;
}hNode;
unsigned int hash65(char *key);
hNode *list_insert(hNode *ptr,char *str);
void hash_insert(hNode** hashTable,char *str);
void list_find(hNode *ptr,char *str);
void hash_find(hNode** hashTable,char *str);
void hprint(hNode **hashTable);
void Hash();
