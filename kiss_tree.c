#include <stdio.h>
#include <stdlib.h>
#include "kiss_tree.h"


KissNode* new_KissNode()
{
    KissNode* node_ptr;
    node_ptr = (KissNode*)malloc(sizeof(struct KissNode));

    printf("DEBUG:  Created new node\n");
}


void destroy_KissNode(KissNode *node_ptr)
{
    free(node_ptr);

    printf("DEBUG:  Destroyed node\n");
}



void kiss_tree_test_driver()
{
    KissNode* root;

    root = new_KissNode();


    destroy_KissNode(root);
}