#include "binary_trees.h"

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * the node containing a value equals to value must be removed and freed
 * If the node to be deleted has two children,
 * it must be replaced with its first in-order successor (not predecessor)
 * After deletion of the desired node, the tree must be rebalanced if necessary
 * Return: pointer to the new root node of the tree after removing the desired value,
 * and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	bst_t *remove_me = NULL;
	bst_t *aux = NULL;
	int val;

	remove_me = bst_search(root, value);
	if (remove_me == NULL)
		return (root);

	if (remove_me->left == NULL && remove_me->right == NULL)
	{
		if (remove_me->parent == NULL)
			root = NULL;
		else if (remove_me == remove_me->parent->left)
			remove_me->parent->left = NULL;
		else if (remove_me == remove_me->parent->right)
			remove_me->parent->right = NULL;
		free(remove_me);
	}
	else if (remove_me->left != NULL && remove_me->right == NULL)
	{
		if (remove_me->parent == NULL)
			root = remove_me->left;
		else if (remove_me == remove_me->parent->left)
			remove_me->parent->left = remove_me->left;
		else if (remove_me == remove_me->parent->right)
			remove_me->parent->right = remove_me->left;
		remove_me->left->parent = remove_me->parent;
		free(remove_me);
	}
	else if (remove_me->left == NULL && remove_me->right != NULL)
	{
		if (remove_me->parent == NULL)
			root = remove_me->right;
		else if (remove_me == remove_me->parent->left)
			remove_me->parent->left = remove_me->right;
		else if (remove_me == remove_me->parent->right)
			remove_me->parent->right = remove_me->right;
		remove_me->right->parent = remove_me->parent;
	}
	else if (remove_me->left != NULL && remove_me->right != NULL)
	{
		aux = remove_me->right;
		while (aux->left != NULL)
			aux = aux->left;
		val = aux->n;

		bst_remove(root, val);
		remove_me->n = val;
	}
	return (root);
}
