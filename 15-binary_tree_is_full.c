#include "binary_trees.h"

/**
 * binary_tree_is_full - full binary tree in which all nodes
 * have either zero or two child nodes.
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if full, 0 otherwise
 * If tree is NULL, your function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int right = 1;
	int left = 1;

	if (tree == NULL)
		return (0);

	if ((tree->left == NULL && tree->right != NULL) ||
		(tree->left != NULL && tree->right == NULL))
		return (0);

	if (tree->left != NULL)
		left = binary_tree_is_full(tree->left);

	if (tree->right != NULL)
		right = binary_tree_is_full(tree->right);

	if (right == 0 || left == 0)
		return (0);

	return (1);
}
