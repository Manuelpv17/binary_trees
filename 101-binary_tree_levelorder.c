#include "binary_trees.h"

size_t height_recursion(const binary_tree_t *tree, size_t count);
void levelorder_recursion(const binary_tree_t *tree,
						  void (*func)(int), int level, int count);

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0;
	int level;

	if (tree == NULL || func == NULL)
		return;

	height = height_recursion(tree, 0);

	for (level = 0; level <= height; level++)
		levelorder_recursion(tree, func, level, 0);
}

/**
 * levelorder_recursion - aux function for recursion
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * @level: desire level to print
 * @count: couter for current level
 */
void levelorder_recursion(const binary_tree_t *tree,
						  void (*func)(int), int level, int count)
{

	if (count == level)
		func(tree->n);

	if (tree->left != NULL)
		levelorder_recursion(tree->left, func, level, count + 1);

	if (tree->right != NULL)
		levelorder_recursion(tree->right, func, level, count + 1);
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
