#include "binary_trees.h"

binary_tree_t *ancestor_recursion(const binary_tree_t *root, const binary_tree_t *first, const binary_tree_t *second);
int ancestor_recursion_2(const binary_tree_t *root, const binary_tree_t *first, const binary_tree_t *second, int count);

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *root = NULL;

	if (first == NULL || second == NULL)
		return (NULL);

	root = first;
	while (root->parent != NULL)
		root = root->parent;

	return (ancestor_recursion(root, first, second));
}

binary_tree_t *ancestor_recursion(const binary_tree_t *root, const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *ancestor = NULL;

	if (root->left != NULL)
		ancestor = ancestor_recursion(root->left, first, second);
	if (root->right != NULL)
		ancestor = ancestor_recursion(root->right, first, second);

	if (ancestor_recursion_2(root, first, second, 0) == 2 && ancestor == NULL)
		return ((binary_tree_t *)root);

	return (ancestor);
}

int ancestor_recursion_2(const binary_tree_t *root, const binary_tree_t *first, const binary_tree_t *second, int count)
{
	if (root->left != NULL)
		count = ancestor_recursion_2(root->left, first, second, count);
	if (root->right != NULL)
		count = ancestor_recursion_2(root->right, first, second, count);

	if (root == first || root == second)
		count++;

	return (count);
}
