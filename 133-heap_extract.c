#include "binary_trees.h"

/**
 * count_heap_nodes - Calculates the total count of nodes in a tree.
 * @root: Pointer to the root node of the tree.
 *
 * Return: The count of nodes in the tree.
 */

int count_heap_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_heap_nodes(root->left) +
		    count_heap_nodes(root->right));
}

/**
 * bubble_down - Reorganizes the node value to its proper position in the heap.
 * @parent: Pointer to the node in the heap.
 */

void bubble_down(heap_t *parent)
{
	int temp;
	heap_t *max_child = NULL;

	if (!parent)
		return;

	while (parent && parent->left)
	{
		max_child = parent->left;

		if (parent->right && parent->right->n > parent->left->n)
			max_child = parent->right;

		if (max_child->n > parent->n)
		{
			temp = parent->n;
			parent->n = max_child->n;
			max_child->n = temp;
		}

		parent = max_child;
	}
}

/**
 * get_parent - Locates the parent node for a given node
 * @root: Pointer to the node in the heap
 * @index: Index of the current node
 * @pind: Index being searched
 *
 * Return: Pointer to the node in the heap
 */

heap_t *get_parent(heap_t *root, int index, int pind)
{
	heap_t *left = NULL, *right = NULL;

	if (!root || index > pind)
		return (NULL);

	if (index == pind)
		return (root);

	left = get_parent(root->left, index * 2 + 1, pind);
	if (left)
		return (left);

	right = get_parent(root->right, index * 2 + 2, pind);
	if (right)
		return (right);

	return (NULL);
}

/**
 * remove_last_node - Deletes the last node of a heap
 * @root: Double pointer to the root node of the heap
 * @parent: Pointer to the parent node from which the last node is to be removed
 */

void remove_last_node(heap_t **root, heap_t *parent)
{
	if (parent == *root && !parent->left)
	{
		free(*root);
		*root = NULL;

		return;
	}

	if (parent->right)
	{
		(*root)->n = parent->right->n;
		free(parent->right);
		parent->right = NULL;
	}
	else if (parent->left)
	{
		(*root)->n = parent->left->n;
		free(parent->left);
		parent->left = NULL;
	}

	bubble_down(*root);
}

/**
 * heap_extract - Retrieves the maximum value from a heap
 * @root: Double pointer to the root node of the heap
 *
 * Returns: The maximum value of the heap
 */

int heap_extract(heap_t **root)
{
	int nodes, pind = 0, max_val = 0;
	heap_t *parent;

	if (!root || !(*root))
		return (0);

	max_val = (*root)->n;
	nodes = count_heap_nodes(*root);

	pind = (nodes - 2) / 2;
	parent = get_parent(*root, 0, pind);

	remove_last_node(root, parent);

	return (max_val);
}
