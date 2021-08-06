#include "binary_trees.h"

/**
 * binary_tree_node - creates a new binary tree node
 * @parent: parent node
 * @value: value of node
 * Return: new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	return ((node) ? node : NULL);
}
