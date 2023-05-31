#include "binary_trees.h"

/**
 * binary_tree_height - calculates the height of a binary tree.
 * @tree: pointer to the root node of the tree to be measured.
 * Return: If the tree is NULL, the function returns 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0, right = 0;

		if (tree->right)
			right = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}
/**
 * binary_tree_size - calculates the size of a binary tree.
 * @tree: pointer to the root node of the tree to calculate the size.
 * Return: If tree is NULL, it returns 0.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	{
		size_t n_left, n_right;

		n_left = binary_tree_size(tree->left);
		n_right = binary_tree_size(tree->right);
		return (1 + n_left + n_right);
	}
}

/**
 * binary_tree_is_perfect - determines whether a binary tree is perfect.
 * @tree: pointer to the root node of the tree to be checked.
 * Return: 0 if the tree is NULL, otherwise return 1 if the tree is perfect.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h = 0, perfect_size = 0;

	if (tree == NULL)
		return (0);
	h = binary_tree_height(tree);
	perfect_size = (1 << (h + 1)) - 1;
	if (perfect_size == binary_tree_size(tree))
		return (1);
	else
		return (0);
}
