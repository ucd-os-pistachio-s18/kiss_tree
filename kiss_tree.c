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
    printf("DEBUG:  Destroying node\n");
    free(node_ptr);
//    printf("DEBUG:  Destroyed node\n");
}


KissNode* insert_kiss_node(KissNode* root_ptr, int key)
{

    if (root_ptr == NULL)
    {
        // CASE: NO NODE EXISTS AT ROOT; MAKE A NEW NODE WITH KEY
        printf("DEBUG:  Unable to find key:  %d\n", key);

        KissNode* newNode_ptr;
        newNode_ptr = new_KissNode(key);


        // RECURSION IS COMPLETE.  RETURN NODE ADDRESS
    }
    else
    {
        // CASE: TREE EXISTS
        if (key == root_ptr->data)
        {
            // CASE: KEY FOUND IN THE ROOT NODE

            /* DO STUFF HERE */
            printf("DEBUG:  Found key in tree:  %d \n", key);

            // RECURSION IS COMPLETE.  RETURN NODE ADDRESS
        }
        else if (key < root_ptr->data)
        {
            // CASE: KEY IS LESS THAN THE ROOT NODE DATA
            printf("DEBUG:  Searching left branch for key:  %d \n", key);

            // RECURSIVELY SEARCH THE LEFT BRANCH
            root_ptr->left_ptr = insert_kiss_node(root_ptr->left_ptr, key);
        }
        else if (key > root_ptr->data)
        {
            // CASE: INPUT DATA IS GREATER THAN THE ROOT NODE DATA
            printf("DEBUG:  Searching right branch for key:  %d \n", key);

            // RECURSIVELY SEARCH THE RIGHT BRANCH
            root_ptr->right_ptr = insert_kiss_node(root_ptr->left_ptr, key);
        }
    }

    // RETURN THE POINTER TO THE NODE WHERE THE DATA WAS FOUND OR INSERTED
    return root_ptr;
}




void kiss_tree_test_driver()
{
    KissNode* root;
    int newKey;

    newKey = 5;
    root = new_KissNode(newKey);

    int intArray[] = {3, 1, 2, 7, 6, 9, 8, 11};
    for (int index = 0; newKey < (sizeof(intArray)/ sizeof(int)); ++index)
    {
        newKey =  intArray[index];
        printf("DEBUG:  Inserting key:  %d  into root with key:  %d \n", newKey, root->data);
        insert_kiss_node(root, newKey);
    }

    printf("\nDEBUG:  Destroying tree...\n\n");
    destroy_KissNode(root);
}