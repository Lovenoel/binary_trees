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
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 * @heap: A pointer to the root node of the heap to convert
 * @size: An address to store the size of the array
 * Return: A pointer to the sorted array of integers in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    if (heap == NULL)
    {
        *size = 0;
        return (NULL);
    }

    size_t height = get_tree_height(heap);
    size_t array_size = (size_t)(1 << height) - 1; // 2^height - 1
    int *sorted_array = malloc(array_size * sizeof(int));

    if (sorted_array == NULL)
    {
        *size = 0;
        return (NULL);
    }

    int *current = sorted_array;

    while (heap != NULL)
    {
        *current = heap->n;
        current++;
        heap->n = get_last_node(heap, height)->n;
        heapify_down(heap);
    }

    *size = array_size;
    return (sorted_array);
}
