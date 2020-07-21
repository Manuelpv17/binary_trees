#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 * If tree is NULL, do nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *aux = tree;
	int flag = 1;

	if (tree == NULL)
		return;

	while (flag)
	{
		aux = tree;
		while (1)
		{
			if (aux->right != NULL)
				aux = aux->right;
			else if (aux->left != NULL)
				aux = aux->left;
			else
			{
				if (aux->parent == NULL)
					flag = 0;
				else if (aux->parent->right != NULL)
					aux->parent->right = NULL;
				else
					aux->parent->left = NULL;
				free(aux);
				break;
			}
		}
	}
}
