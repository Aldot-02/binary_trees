#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left rotation
 * operation on a binary tree.
 * @tree: pointer to the binary tree to be rotated.
 * Return: pointer to the new root node of the rotated tree.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *aux, *temp;

	if (tree == NULL)
		return (NULL);
	if (tree->right)
	{
		temp = tree->right->left;
		aux = tree->right;
		aux->parent = tree->parent;
		aux->left = tree;
		tree->parent = aux;
		tree->right = temp;
		if (temp)
			temp->parent = tree;
		return (aux);
	}
	return (NULL);
}
