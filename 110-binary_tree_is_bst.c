#include "binary_trees.h"

/**
 * is_bst_helper - Helper function to recursively check if a binary tree
 *                 is a valid binary search tree
 * @tree: A pointer to the root node of the tree to check
 * @min: The minimum value a node in the tree can take
 * @max: The maximum value a node in the tree can take
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (is_bst_helper(tree->left, min, tree->n) &&
            is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
