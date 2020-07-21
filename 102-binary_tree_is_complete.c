#include "binary_trees.h"

size_t height_recursion(const binary_tree_t *tree, size_t count);
int level_check_recursion(const binary_tree_t *tree, int level, int count, int flag);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if is complete, 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height;
	int full = 1, semi = 1;

	if (tree == NULL)
		return (0);

	height = height_recursion(tree, 0);

	if (height > 1)
		full = level_check_recursion(tree, height - 2, 0, 1);
	if (height > 0)
		semi = level_check_recursion(tree, height - 1, 0, 1);

	if (full != 0 && semi != 0)
		return (1);
	return (0);
}

/**
 * levelorder_recursion - aux function for recursion
 * @tree: pointer to the root node of the tree to traverse
 * @level: desire level to print
 * @count: counter for current level
 * @leaves: Number of leaves in level
 */
int level_check_recursion(const binary_tree_t *tree, int level, int count, int flag)
{

	if (tree->left != NULL)
		flag = level_check_recursion(tree->left, level, count + 1, flag);

	if (tree->right != NULL)
		flag = level_check_recursion(tree->right, level, count + 1, flag);

	if (count == level && flag == 1 && tree->left == NULL)
		flag = 2;
	else if (count == level && flag == 2 && tree->left != NULL)
		flag = 0;

	if (count == level && flag == 1 && tree->right == NULL)
		flag = 2;
	else if (count == level && flag == 2 && tree->right != NULL)
		flag = 0;

	return (flag);
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
