#include "binary_trees.h"

/**
 * bst_insert - inserts a value into a Binary Search Tree.
 * @tree: double pointer to the root node of
 * the BST where the value is to be inserted.
 * @value: value to be inserted into the tree.
 * Return: Always 0 (Success).
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *aux = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	aux = *tree;
	if (value < aux->n)
	{
		if (aux->left == NULL)
		{
			aux->left = binary_tree_node(aux, value);
			return (aux->left);
		}
		return (bst_insert(&(aux->left), value));
	}
	if (value > aux->n)
	{
		if (aux->right == NULL)
		{
			aux->right = binary_tree_node(aux, value);
			return (aux->right);
		}
		return (bst_insert(&(aux->right), value));
	}
	return (NULL);
}
