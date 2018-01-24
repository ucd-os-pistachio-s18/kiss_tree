#include <stdio.h>
#include <stdlib.h>
#include "kiss_tree.h"


KissNode* new_KissNode(int key)
{
    // ALLOCATE MEMORY
    KissNode* node_ptr;
    node_ptr = (KissNode*)malloc(sizeof(struct KissNode));

    // INIT DATA
    node_ptr->left_ptr = NULL;
    node_ptr->right_ptr = NULL;
    node_ptr->data = key;

    printf("DEBUG:  Created new node with key:  %d \n\n", key);

    return node_ptr;
}


void destroy_KissNode(KissNode *node_ptr)
{

    if (node_ptr->left_ptr != NULL || node_ptr->right_ptr != NULL)
    {
        printf("ERROR:  NODE HAS ACTIVE CHILDREN\n");
    }
    else
        printf("DEBUG:  Destroying node with key:  %d \n", node_ptr->data);

    // DESTROY DATA
    node_ptr->data = 0;

    // DEALLOCATE NODE
    free(node_ptr);

    printf("DEBUG:  DESTROYED NODE.\n\n");
}


KissNode* insert_kiss_node(KissNode* root_ptr, int key)
{
    if (root_ptr == NULL)
    {
        // CASE: NO NODE EXISTS AT ROOT; MAKE A NEW NODE WITH KEY
        printf("DEBUG:  Unable to find key:  %d\n", key);
        root_ptr = new_KissNode(key);

        // RECURSION IS COMPLETE.  RETURN NODE ADDRESS
    }
    else
    {
        // CASE: TREE EXISTS
        if (key == root_ptr->data)
        {
            // CASE: KEY FOUND IN THE ROOT NODE

            /* DO STUFF HERE */
            printf("DEBUG:  Found key in tree:  %d \n\n", key);

            // RECURSION IS COMPLETE.  RETURN NODE ADDRESS
        }
        else if (key < root_ptr->data)
        {
            // CASE: KEY IS LESS THAN THE ROOT NODE DATA
            printf("DEBUG:  Searching left branch of node:  %d  for key:  %d \n", root_ptr->data, key);

            // RECURSIVELY SEARCH THE LEFT BRANCH
            root_ptr->left_ptr = insert_kiss_node(root_ptr->left_ptr, key);
        }
        else if (key > root_ptr->data)
        {
            // CASE: INPUT DATA IS GREATER THAN THE ROOT NODE DATA
            printf("DEBUG:  Searching right  branch of node:  %d  for key:  %d \n", root_ptr->data, key);

            // RECURSIVELY SEARCH THE RIGHT BRANCH
            root_ptr->right_ptr = insert_kiss_node(root_ptr->right_ptr, key);
        }
    }

    // RETURN THE POINTER TO THE NODE WHERE THE DATA WAS FOUND OR INSERTED
    return root_ptr;
}


void destroy_kiss_tree(KissNode* node_ptr, KissNode* parent_ptr)
{
    printf("DEBUG:  Attempting to destroy node with key:  %d \n", node_ptr->data);

    if (node_ptr->left_ptr != NULL)
    {
        printf("DEBUG:  Going left of node with key:  %d \n", node_ptr->data);
        destroy_kiss_tree(node_ptr->left_ptr, node_ptr);
    }

    if (node_ptr->right_ptr != NULL)
    {
        printf("DEBUG:  Going right of node with key:  %d \n", node_ptr->data);
        destroy_kiss_tree(node_ptr->right_ptr, node_ptr);
    }

    if (parent_ptr != NULL)
    {
        if (parent_ptr->left_ptr != NULL)
            parent_ptr->left_ptr = NULL;
        else if (parent_ptr->right_ptr != NULL)
            parent_ptr->right_ptr = NULL;
        else
            printf("ERROR:  UNABLE TO SET CHILDREN NULL IN PARENT\n");

    }

    // BOTH CHILDREN NOW NULL; DELETE NODE
    printf("\nDEBUG:  Initiating destruction of node with key:  %d \n", node_ptr->data);
    destroy_KissNode(node_ptr);
    node_ptr = NULL;
}


void kiss_tree_test_driver()
{
    KissNode* root;
    int newKey;

//    int intArray[] = {3, 1, 2, 7, 6, 9, 8, 11};
//    int intArray[] = {50, 10, 20, 15, 18, 16, 17};
    int intArray[] = {4,2,1,3,6,5,7};
//    int intArray[] = {4,2,1,3};

    root = new_KissNode(intArray[0]);

    int max = (sizeof(intArray)/ sizeof(newKey));
    for (int index = 1; index < max; ++index)
    {
        newKey =  intArray[index];
        printf("DEBUG:  Inserting key:  %d \n", newKey);
        insert_kiss_node(root, newKey);
    }

    printf("\nDEBUG:  Destroying tree...\n\n");
    destroy_kiss_tree(root, NULL);
}