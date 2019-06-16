
#include <stdio.h>
#include <stdlib.h>


struct Data
{
    void** ppData;
    int size;
};

struct Node
{
    int id;
    struct Node* parent;
    struct Node** children;
    int childCount;
    struct Data* data;   
};

void initNode(struct Node*);

void dropNode(struct Node*);

void attachChildren(struct Node* nodParent, struct Node** nodChildren, int nHowMany);

struct Node* getParent(struct Node*);

struct Node* getRoot(struct Node*);

void printChildTree(struct Node*);
