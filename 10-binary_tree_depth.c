#include "binary_trees.h"

/**
* binary_tree_depth - calculates the depth of a node within a binary tree.
* @tree: pointer to the node whose depth is to be measured.
* Return: If tree is NULL, the function should return 0.
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
