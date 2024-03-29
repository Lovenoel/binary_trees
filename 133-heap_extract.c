#include "binary_trees.h"

/**
 * get_tree_height - Gets the height of a binary tree
 * @tree: A pointer to the root node of the binary tree
 * Return: The height of the binary tree
 */
size_t get_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t left_height = get_tree_height(tree->left);
    size_t right_height = get_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * get_last_node - Gets the last node of the binary tree in level order
 * @root: A pointer to the root node of the binary tree
 * @height: The height of the binary tree
 * Return: A pointer to the last node of the binary tree in level order
 */
binary_tree_t *get_last_node(binary_tree_t *root, size_t height)
{
    if (root == NULL)
        return (NULL);

    if (height == 1)
        return (root);

    binary_tree_t *left = get_last_node(root->left, height - 1);
    binary_tree_t *right = get_last_node(root->right, height - 1);

    return (right != NULL ? right : left);
}

/**
 * heapify_down - Adjusts the heap rooted at a given node
 * @root: A pointer to the root node of the binary heap
 */
void heapify_down(binary_tree_t *root)
{
    binary_tree_t *max = root;
    binary_tree_t *left = root->left;
    binary_tree_t *right = root->right;

    if (left != NULL && left->n > max->n)
        max = left;
    if (right != NULL && right->n > max->n)
        max = right;

    if (max != root)
    {
        int temp = root->n;
        root->n = max->n;
        max->n = temp;
        heapify_down(max);
    }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: A double pointer to the root node of the heap
 * Return: The value stored in the root node, or 0 if the function fails
 */
int heap_extract(heap_t **root)
{
    if (root == NULL || *root == NULL)
        return (0);

    int extracted_value = (*root)->n;
    size_t height = get_tree_height(*root);
    binary_tree_t *last_node = get_last_node(*root, height);

    if (*root == last_node)
    {
        /* The root is the only node in the heap */
        free(*root);
        *root = NULL;
        return (extracted_value);
    }

    (*root)->n = last_node->n;

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    free(last_node);
    heapify_down(*root);

    return (extracted_value);
}
