#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on a binary tree.
 * @tree: pointer to the binary_tree_t structure.
 * Return: pointer to the new root node of the tree after the rotation.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *aux, *temp;

	if (tree == NULL)
		return (NULL);
	if (tree->left)
	{
		temp = tree->left->right;
		aux = tree->left;
		aux->parent = tree->parent;
		aux->right = tree;
		tree->parent = aux;
		tree->left = temp;
		if (temp)
			temp->parent = tree;
		return (aux);
	}
	return (NULL);
}
