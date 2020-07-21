#include "binary_trees.h"

size_t height_recursion(const binary_tree_t *tree, size_t count);
size_t leaves_recursion(const binary_tree_t *tree, size_t count);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * A perfect binary tree is one that all internal nodes have two children
 * and all leaves are at same level
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise
 * If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0;
	size_t leaves = 0;
	size_t expected_leaves = 1;
	size_t count;

	if (tree == NULL)
		return (0);

	height = height_recursion(tree, 0);
	leaves = leaves_recursion(tree, 0);

	for (count = 0; count < height; count++)
		expected_leaves = expected_leaves * 2;

	if (expected_leaves == leaves)
		return (1);

	return (0);
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

/**
 * height_recursion - aux function for recursion
 * @tree: pointer to tree
 * @count: counter of height
 * Return: height
 */
size_t height_recursion(const binary_tree_t *tree, size_t count)
{
	size_t count_r = 0;
	size_t count_l = 0;

	if (tree->left != NULL)
		count_l = height_recursion(tree->left, count + 1);

	if (tree->right != NULL)
		count_r = height_recursion(tree->right, count + 1);

	if (tree->left == NULL && tree->right == NULL)
		return (count);

	if (count_r > count_l)
		return (count_r);
	else
		return (count_l);
}
