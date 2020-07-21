#include "binary_trees.h"

size_t nodes_recursion(const binary_tree_t *tree, size_t count);

/**
 * binary_tree_nodes - ounts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: Number of nodes with at least 1 child in a binary tree
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (nodes_recursion(tree, 0));
}

/**
 * nodes_recursion - aux function for recursion
 * @tree: pointer to the root node of the tree to count the number of nodes
 * @count: Counter for numbert of Nodes
 * Return: Number of Nodes
 */
size_t nodes_recursion(const binary_tree_t *tree, size_t count)
{
	if (tree->left != NULL)
		count = nodes_recursion(tree->left, count);

	if (tree->right != NULL)
		count = nodes_recursion(tree->right, count);

	if (tree->left != NULL || tree->right != NULL)
		return (count + 1);
	return (count);
}
