#ifndef KISS_TREE_KISS_TREE_H
#define KISS_TREE_KISS_TREE_H

typedef struct KissNode KissNode;

struct KissNode {

    struct KissNode* left_ptr;
    struct KissNode* right_ptr;

    int data;
};


KissNode* new_KissNode(int key);
void destroy_KissNode(KissNode*);

KissNode* insert_kiss_node(KissNode*, int);
void destroy_kiss_tree(KissNode*, KissNode*);



void kiss_tree_test_driver();



#endif //KISS_TREE_KISS_TREE_H
