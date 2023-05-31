#include "binary_trees.h"

/**
 * binary_tree_postorder - performs a post-order traversal of a binary tree.
 * @tree: pointer to the root node of the tree to be traversed.
 * @func: pointer to a function to be executed for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
