#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure the size of
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify - Maintains the Max Heap property by swapping nodes as necessary
 * @node: A pointer to the node to start heapifying from
 */
void heapify(binary_tree_t *node)
{
    binary_tree_t *parent, *temp;
    int value;

    while (node && node->parent)
    {
        parent = node->parent;
        if (node->n > parent->n)
        {
            value = node->n;
            node->n = parent->n;
            parent->n = value;
            node = parent;
        }
        else
        {
            break;
        }
    }
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: A double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (root == NULL)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    parent = *root;
    while (parent->left != NULL && parent->right != NULL)
    {
        if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
            parent = parent->left;
        else
            parent = parent->right;
    }

    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;
    heapify(new_node);

    return (new_node);
}
