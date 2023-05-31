#include "binary_trees.h"

/**
 * binary_tree_is_full - determines whether a binary tree is full.
 * @tree: pointer to the root node of the tree to be checked.
 * Return: 0 if tree is NULL, otherwise return 1 if the tree is full.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (0);
}
