#include "binary_trees.h"

/**
 * binary_tree_insert_left - This function is used to insert a new
 * node as the left-child of a given node in a binary tree.
 *
 * @parent: A pointer to the node where the left-child should be inserted.
 * @value: The value to be stored in the new node.
 *
 * Return: A pointer to the newly created node if successful,
 * or NULL if there is a failure or if the parent node is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	if (parent->left == NULL)
		parent->left = node;
	else
	{
		node->left = parent->left;
		parent->left = node;
		node->left->parent = node;
	}
	return (node);
}
