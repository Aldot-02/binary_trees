#include "binary_trees.h"

/**
 * find_node - function to search for a specific node in a tree
 * @root: root of the tree to be searched
 * @node: node to be found
 * Return: 1 if the node exists, 0 if it does not
 */

int find_node(binary_tree_t *root, binary_tree_t *node)
{

	if (root == NULL)
		return (0);
	if (node == root)
		return (1);
	if (node->n < root->n)
		return (find_node(root->left, node));
	if (node->n > root->n)
		return (find_node(root->right, node));
	return (0);
}

/**
 * croos_tree - traverse the tree and check if each node exists correctly
 * @root: root node of the tree
 * @node: current node to be evaluated
 * Return: 1 if it is a binary search tree, 0 if it is not
 */

int croos_tree(binary_tree_t *root, binary_tree_t *node)
{
	if (root && node)
	{
		int aux = 0;

		aux = find_node(root, node);
		if (node->left)
			aux &= croos_tree(root, node->left);
		if (node->right)
			aux &= croos_tree(root, node->right);
		return (aux);
	}
	return (0);
}
/**
 * binary_tree_is_bst - check if the given tree is a valid binary search tree
 * @tree: tree to be checked
 * Return: 1 if it is a binary search tree, 0 if it is not
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (croos_tree((binary_tree_t *)tree, (binary_tree_t *)tree));
}
