#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	const binary_tree_t *aux_first = first;
	const binary_tree_t *aux_second = second;

	if (first == NULL || second == NULL)
		return (NULL);

	while (aux_first != NULL)
	{
		aux_second = second;
		while (aux_second != NULL)
		{
			if (aux_first == aux_second)
				return ((binary_tree_t *)aux_first);
			aux_second = aux_second->parent;
		}
		aux_first = aux_first->parent;
	}
	return (NULL);
}
