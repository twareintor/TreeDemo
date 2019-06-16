#include <stdio.h>
#include <stdlib.h>

#include "version.h"
#include "tree.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
	printVersion();
	
    const int nScenes = 1;
    const int nTrees = 7;
    const int nAnimals = 3;
   
    /** prepare the scene **/
    struct Node* nodWorld = (struct Node*)malloc(sizeof(struct Node));
    initNode(nodWorld);
    nodWorld->id = 0;
    struct Node* nodScene = (struct Node*)malloc(sizeof(struct Node));
    initNode(nodScene);
    attachChildren(nodWorld, (struct Node**)&nodScene, nScenes);
    nodScene->id = 10;
    struct Node** nodTrees = (struct Node**)malloc(sizeof(struct Node*)*nTrees);
    int i;
    for(i = 0; i<nTrees; i++)
    {
        nodTrees[i] = (struct Node*)malloc(sizeof(struct Node));
        initNode(nodTrees[i]);
        nodTrees[i]->id = 300+1;
    }
    struct Node** nodAnimals = (struct Node**)malloc(sizeof(struct Node*)*nAnimals);
    for(i = 0; i<nAnimals; i++)
    {
        nodAnimals[i] = (struct Node*)malloc(sizeof(struct Node));
        initNode(nodAnimals[i]);
        nodAnimals[i]->id = 100+i;
    }
    attachChildren(nodScene, nodAnimals, nAnimals);
    attachChildren(nodScene, nodTrees, nTrees);
   
    /** do whatever..... **/
    printChildTree(nodWorld);
   
    /** free resources **/
    for(i = 0; i<nTrees; i++)
    {
        dropNode(nodTrees[i]);
        /* free(nodTrees[i]); */
    }
    free(nodTrees);
    for(i = 0; i<nAnimals; i++)
    {
        dropNode(nodAnimals[i]);
        /* free(nodAnimals[i]); */
    }
    free(nodAnimals);
    dropNode(nodScene);
    free(nodScene);
    dropNode(nodWorld);
    free(nodWorld);
    printf("Game Over!\n");
    return 0;
}


