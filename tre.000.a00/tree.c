
#include "tree.h"

void initNode(struct Node* nod)
{
    nod->parent = 0;
    nod->childCount = 0;
    nod->children = 0;

}

void dropNode(struct Node* nod)
{
    if(nod->children) free(nod->children);
}

struct Node* getParent(struct Node* nod)
{
    return nod->parent;
}

struct Node* getRoot(struct Node* nod)
{
    struct Node* nodOut = nod;
    while(nodOut->parent)
    {
        nodOut = nodOut->parent;
    }
    return nodOut;
}

void attachChildren(struct Node* nod, struct Node** nodChildren, int nHowMany)
{
    /*************
    if(!nod->children)
    {
        if(!(nod->children = (struct Node**)malloc(nHowMany*sizeof(struct Node*)))) return;       
    }
    else
    {
        if(!(realloc(nod->children, (nod->childCount+nHowMany)*sizeof(struct Node*)))) return;       
    }
    *************/
    nod->children = (struct Node**)realloc(nod->children, (nod->childCount+nHowMany)*sizeof(struct Node*));
    int i;
    for(i = 0; i<nHowMany; i++)
    {
        nod->children[nod->childCount+i] = nodChildren[i];
        /* nod->children[nod->childCount+i]->parent = nod; */
    }
    nod->childCount+=nHowMany;
    for(i = 0; i<nod->childCount; i++)
    {
        nod->children[i]->parent = nod;
    }
}

void printChildTree(struct Node* nod)
{
    if(nod)
    {
        printf("%d\t", nod->id);
        if(nod->parent) printf("parent = %d\t", nod->parent->id); else printf("no parent \t");
        if(getRoot(nod)) printf("root = %d", getRoot(nod)->id);
        printf("\n");
        if(nod->childCount)
        {
            int i;
            for(i = 0; i<nod->childCount; i++)
            {
                printChildTree(nod->children[i]);
            }
        }
    }
}



