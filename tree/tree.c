#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

node* init_root(const int data)
{
    node* root = (node *) malloc(sizeof(node));
    if (!(int) root)
    {
        perror("Root initialization failed\n");
        exit(EXIT_FAILURE);
    }
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void create_branches(node* root, const int depth)
{
    if (depth <= 0 ||!(int) root)
    {
        return;
    }

    root->left = (node *) malloc(sizeof(node));
    root->right = (node *) malloc(sizeof(node));

    if (!(int) root->left || !(int) root->right)
    {
        perror("Branch creation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter data for left branch (current node data: %d): ", root->data);
    scanf("%d", &(root->left->data));

    printf("Enter data for right branch (current node data: %d): ", root->data);
    scanf("%d", &(root->right->data));

    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = NULL;
    root->right->right = NULL;

    printf("Created branches at depth %d with data %d (left) and %d (right)\n", depth, root->left->data,
           root->right->data);
    create_branches(root->left, depth - 1);
    create_branches(root->right, depth - 1);
}

void free_tree(node* root)
{
    if (!(int) root)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void inorder_traversal(const node* root)
{
    if (!(int) root)
    {
        perror("Root in NULL\n");
        exit(EXIT_FAILURE);
    }
    inorder_traversal(root->left);
    printf("%d ->", root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(const node* root)
{
    if (!(int) root)
    {
        perror("Root in NULL\n");
        exit(EXIT_FAILURE);
    }
    printf("%d ->", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(const node* root)
{
    if (!(int) root)
    {
        perror("Root in NULL\n");
        exit(EXIT_FAILURE);
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ->", root->data);
}

node* __find_first_available_spot__(const node* root)
{
    if (!(int) root)
    {
        return NULL;
    }

    node** queue = malloc(100 * sizeof(node *));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        node* current = queue[front++];
        if (!(int) current->left)
        {
            free(queue);
            return current;
        }
        queue[rear++] = current->left;
        if (!(int) current->right)
        {
            free(queue);
            return current;
        }
        queue[rear++] = current->right;
    }
    free(queue);
    return NULL;
}


__sr__ __find_deepest_and_target_node__(const node* root, const int data)
{
    __sr__ result = {NULL, NULL, NULL};
    if (!(int) root)
    {
        return result;
    }
    node** queue = malloc(100 * sizeof(node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        node* current = queue[front++];
        if (current->data == data)
        {
            result.target = current;
        }

        if (current->left != NULL)
        {
            result.parent_of_deepest = current;
            queue[rear++] = current->left;
        }
        if (current->right != NULL)
        {
            result.parent_of_deepest = current;
            queue[rear++] = current->right;
        }
        result.deepest_node = current;
    }

    free(queue);
    return result;
}

void level_order_traversal(const node* root)
{
    if (!(int) root)
    {
        printf("Tree is empty\n");
        return;
    }
    node** queue = malloc(100 * sizeof(node *));
    int front = 0, rear = 0;
    queue[rear++] = (node *) root;
    while (front < rear)
    {
        const node* current = queue[front++];
        printf("%d -> ", current->data);
        if (current->left)
        {
            queue[rear++] = current->left;
        }
        if (current->right)
        {
            queue[rear++] = current->right;
        }
    }
    free(queue);
}

void add_node(node* root, const int data)
{
    if (!(int) root)
    {
        printf("Tree is empty\n");
        return;
    }

    node** queue = malloc(100 * sizeof(node *));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        node* current = queue[front++];
        if (!(int) current->left)
        {
            current->left = (node *) malloc(sizeof(node));
            current->left->data = data;
            current->left->left = NULL;
            current->left->right = NULL;
            printf("Added node with data %d to the left of node with data %d\n", data, current->data);
            break;
        }
        queue[rear++] = current->left;

        if (!(int) current->right)
        {
            current->right = (node *) malloc(sizeof(node));
            current->right->data = data;
            current->right->left = NULL;
            current->right->right = NULL;
            printf("Added node with data %d to the right of node with data %d\n", data, current->data);
            break;
        }
        queue[rear++] = current->right;
    }

    free(queue);
}


void delete_node(node** root, const int data)
{
    if (!(int) *root)
    {
        printf("Tree is empty\n");
        return;
    }
    const __sr__ result = __find_deepest_and_target_node__(*root, data);
    if (!(int) result.target)
    {
        printf("Node with data %d not found\n", data);
        return;
    }
    result.target->data = result.deepest_node->data;
    if (result.parent_of_deepest)
    {
        if (result.parent_of_deepest->left == result.deepest_node)
        {
            free(result.parent_of_deepest->left);
            result.parent_of_deepest->left = NULL;
        }
        else if (result.parent_of_deepest->right == result.deepest_node)
        {
            free(result.parent_of_deepest->right);
            result.parent_of_deepest->right = NULL;
        }
    }
    else
    {
        free(*root);
        *root = NULL;
    }
    printf("Node with data %d deleted successfully\n", data);
}
