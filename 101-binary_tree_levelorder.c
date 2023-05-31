#include "binary_trees.h"

/**
 * binary_tree_height - calculates the height of a binary tree.
 * @tree: pointer to the root node of the tree to calculate the height.
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
 * print_at_level - print a specific node at a given level.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node.
 * @level: the level at which the node should be printed.
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_at_level(tree->left, func, level - 1);
			print_at_level(tree->right, func, level - 1);
		}
	}

}

/**
 * binary_tree_levelorder - performs a level-order traversal on a binary tree.
 * @tree: pointer to the root node of the tree to be traversed.
 * @func: pointer to a function to be invoked for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h = 0, i = 1;

	if (tree && func)
	{
		h = binary_tree_height(tree);
		while (i <= h + 1)
		{
			print_at_level(tree, func, i);
			i++;
		}
	}

}
