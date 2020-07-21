#include "binary_trees.h"

size_t leaves_recursion(const binary_tree_t *tree, size_t count);

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: Number of leaves in a binary tree
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a leaf
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (leaves_recursion(tree, 0));
}

/**
 * leaves_recursion - aux function for recursion
 * @tree: pointer to the root node of the tree to count the number of leaves
 * @count: Counter of leaves
 * Return: Number of leaves
 */
size_t leaves_recursion(const binary_tree_t *tree, size_t count)
{
	if (tree->left != NULL)
		count = leaves_recursion(tree->left, count);

	if (tree->right != NULL)
		count = leaves_recursion(tree->right, count);

	if (tree->right == NULL && tree->left == NULL)
		return (count + 1);

	return (count);
}
