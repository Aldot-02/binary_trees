#include "binary_trees.h"

/**
 * binary_tree_is_leaf - a function that determines
 * whether a given node is a leaf or not.
 * @node: a pointer to the node being checked.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);
	else
		return (0);
}
