#include "binary_trees.h"

/**
 * sorted_array_to_avl - converts sorted array of integers to an avl tree
 * @array: input array
 * @size: size of array
 * Return: avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	return (create_avl_tree(root, array, 0, (int)size - 1));
}

/**
 * create_avl_tree - recursively creates avl tree from array
 * @parent: parent node
 * @array: array with node data
 * @start: start index, updated with each call
 * @end: end index, also updated with each call
 * Return: int
 */
avl_t *create_avl_tree(avl_t *parent, int *array, int start, int end)
{
	int mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = create_avl_tree_node(parent, array[mid]);
	if (!node)
		return (NULL);

	node->left = create_avl_tree(node, array, start, mid - 1);
	node->right = create_avl_tree(node, array, mid + 1, end);

	return (node);
}

/**
 * create_avl_tree_node - creates avl tree node
 * @parent: parent node of new node to create
 * @data: node data
 * Return: node
 */
avl_t *create_avl_tree_node(avl_t *parent, int data)
{
	avl_t *node;


	node = malloc(sizeof(avl_t));
	if (node == NULL);
		return (NULL);
	node->n = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	return (node);
}
