#include "binary_trees.h"

/**
 * count_h_nodes - Calculates the total number of nodes in a tree
 * @root: Pointer to the root node of the tree
 *
 * Returns: The count of nodes in the tree
 */

int count_h_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_h_nodes(root->left) +
		    count_h_nodes(root->right));
}

/**
 * heap_to_sorted_array - Generates a sorted array from a maximum heap
 * @heap: Pointer to the heap's starting node
 * @size: Pointer to the size of the resulting array
 *
 * Returns: Pointer to the array of integers in sorted order
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, nodes, *arr = NULL;

	*size = 0;
	if (!heap)
		return (NULL);

	nodes = count_h_nodes(heap);
	arr = malloc(sizeof(*arr) * nodes);
	if (!arr)
		return (NULL);

	*size = nodes;
	for (i = 0; i < nodes; i++)
		arr[i] = heap_extract(&heap);

	return (arr);
}
