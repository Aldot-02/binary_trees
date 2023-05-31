#include "binary_trees.h"

/**
 * array_to_bst - creates a Binary Search Tree from an array.
 * @array: pointer to the first element of the array to be converted.
 * @size: number of elements in the array.
 * Return: pointer to the root node of the
 * created BST, or NULL if unsuccessful.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t index;

	if (array == NULL)
		return (NULL);
	tree = NULL;
	for (index = 0; index < size; index++)
	{
		bst_insert(&tree, array[index]);
	}
	return (tree);
}
