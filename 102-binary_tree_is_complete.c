#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    /* Check for presence of NULL pointers */
    if (binary_tree_is_complete(tree->left) && binary_tree_is_complete(tree->right))
        return (1);

    /* Check if left child is NULL and right child is not NULL */
    if (tree->left == NULL && tree->right != NULL)
        return (0);

    /* If right child is NULL, check if all its left children are NULL */
    if (tree->right == NULL)
    {
        if (tree->left == NULL)
            return (1);
        else
            return (0);
    }

    /* Recursively check subtrees */
    return (binary_tree_is_complete(tree->left) && binary_tree_is_complete(tree->right));
}
