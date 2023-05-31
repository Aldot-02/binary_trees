#include "binary_trees.h"

/*
 * binary_tree_node - Function that generates a node for a binary tree.
 * @parent: A pointer to the parent node of the node to be created.
 * @value: The value to be assigned to the new node.
 *
 * Return: The function should return a pointer
 * to the newly created node, or NULL if unsuccessful.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
