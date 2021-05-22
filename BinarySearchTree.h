typedef struct leaf{
    int apple;
    struct leaf *right;
    struct leaf *left;
}Leaf;
Leaf * Rinsert(Leaf *root,char *str);
void BSTsearch(Leaf *ptr,char *str);
void BinarySearchTree();
