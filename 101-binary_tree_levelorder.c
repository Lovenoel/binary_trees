#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Level order traversal of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;

    /* Create a queue to store tree nodes */
    binary_tree_t *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        binary_tree_t *temp = queue[front++];

        /* Print the front of queue */
        func(temp->n);

        /* Enqueue left child */
        if (temp->left)
            queue[rear++] = temp->left;

        /* Enqueue right child */
        if (temp->right)
            queue[rear++] = temp->right;
    }
}
