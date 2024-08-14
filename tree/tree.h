
#ifndef TREE_H
#define TREE_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;

typedef struct SearchResult {
    node* target;
    node* deepest_node;
    node* parent_of_deepest;
} __sr__;


node* init_root(const int data);

void create_branches(node* root, const int depth);

void free_tree(node* root);

void inorder_traversal(const node* root);

void preorder_traversal(const node* root);

void postorder_traversal(const node* root);

__sr__ __find_deepest_and_target_node__(const node* root, const int data);

node* __find_first_available_spot__(const node* root);

void add_node(node* root, const int data);

void delete_node(node** root, const int data);


#endif
