#include "binary_trees.h"

/**
 * binary_tree_nodes - calculates the number
 * of nodes in a binary tree that have at least one child.
 * @tree: pointer to the root node of the tree to count the number of nodes.
 * Return: If the tree is NULL, the function will return 0.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->right != NULL || tree->left != NULL)
		return  (1 + binary_tree_nodes(tree->right) +
			 binary_tree_nodes(tree->left));
	return (0);
}
