#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 * If parent already has a left-child, the new node must take its place,
 * and the old left-child must be set as the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;
	binary_tree_t *aux = NULL;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->left = NULL;
	new->right = NULL;
	new->n = value;
	new->parent = parent;

	if (parent->left != NULL)
	{
		new->left = parent->left;
		aux = parent->left;
		parent->left = new;
		aux->parent = new;
	}
	else
		parent->left = new;

	return (new);
}
