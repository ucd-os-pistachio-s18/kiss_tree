#ifndef KISS_TREE_KISS_TREE_H
#define KISS_TREE_KISS_TREE_H

typedef struct KissNode KissNode;

struct KissNode {

    struct KissNode* left_ptr;
    struct KissNode* right_ptr;

    int count;
};


KissNode* new_KissNode();
void destroy_KissNode(KissNode *);


void kiss_tree_test_driver();



#endif //KISS_TREE_KISS_TREE_H
