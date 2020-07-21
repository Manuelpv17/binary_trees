#include "binary_trees.h"

size_t size_recursion(const binary_tree_t *tree, size_t count);

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: the size of a binary tree
 * If tree is NULL, the function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (size_recursion(tree, 0) + 1);
}

/**
 * size_recursion - aux function for recursion
 * @tree: pointer to the root node of the tree to measure the size
 * @count: counter of size
 * Return: size
 */
size_t size_recursion(const binary_tree_t *tree, size_t count)
{
	if (tree->left != NULL)
		count = size_recursion(tree->left, count + 1);

	if (tree->right != NULL)
		count = size_recursion(tree->right, count + 1);

	return (count);
}
