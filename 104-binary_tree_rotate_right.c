#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *parent = NULL;
	binary_tree_t *aux = NULL;

	if (tree == NULL)
		return (NULL);

	parent = tree->parent;
	aux = tree->left;

	tree->left = aux->right;
	if (aux->right != NULL)
		aux->right->parent = tree;

	aux->right = tree;
	tree->parent = aux;
	aux->parent = parent;

	if (parent != NULL)
	{
		if (parent->left == tree)
			parent->left = aux;
		else
			parent->right = aux;
	}

	return (aux);
}
