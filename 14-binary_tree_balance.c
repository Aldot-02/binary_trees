#include "binary_trees.h"

/**
 * binary_tree_height - computes the height of a binary tree.
 * @tree: pointer to the root node
 * of the tree whose height is to be calculated.
 * Return: 0 if the tree is NULL, otherwise the height of the tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 1, right = 1;

		if (tree->right)
			right +=  binary_tree_height(tree->right);
		if (tree->left)
			left +=  binary_tree_height(tree->left);
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}

/**
 * binary_tree_balance - calculates the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to calculate the balance factor.
 * Return: If tree is NULL, return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left)
		- binary_tree_height(tree->right));
}
