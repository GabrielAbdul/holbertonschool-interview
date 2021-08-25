#include "binary_trees.h"

/**
 * countNode - counts Nodes
 * @root: root of tree
 * Return: num nodes
 */
int countNodes(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + countNodes(root->left) + countNodes(root->right));
}

/**
 * isComplete - checks if bst is complete
 * @root: root
 * @index: index assigned to current node
 * @numNodes: number of nodes
 * Return: int
 */
int isComplete(heap_t *root, int index, int numNodes)
{
	if (root == NULL)
		return (1);

	if (index >= numNodes)
		return (0);

	return (isComplete(root->left, 2 * index + 1, numNodes) && isComplete(root->right, 2 * index + 2, numNodes));
}