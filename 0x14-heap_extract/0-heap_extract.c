#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a max binary heap
 * @root: double pointer to root node
 * Return: new max data
 */
int heap_extract(heap_t **root)
{
	heap_t  *last;
	int n;

	if (root == NULL)
		return (0);

	n = (*root)->n;
	last = retrieveLastNode(*root);

	if ((*root) == last)
	{
		free(*root);
		*root = NULL;
		return (n);
	}

	if (last->parent->right)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;

	(*root)->n = last->n;
	heapify(*root);
	free(last);
	return (n);
}

/**
 * heapify - heapifies max heap
 * @root: binary heap
 */
void heapify(heap_t *root)
{
	heap_t *max = NULL;
	int temp;

	if (!root)
		return;

	if (root->right)
	{
		if (root->right->n > root->left->n)
			max = root->right;
		else
			max = root->left;
	}
	else if (root->left)
		max = root->left;

	if (max)
	{
		if (max->n)
		{
			temp = max->n;
			max->n = root->n;
			root->n = temp;
			heapify(max);
		}
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree, returns 0 if tree is NULL
 */

size_t binary_tree_height(heap_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left) + 1;
	right = binary_tree_height(tree->right) + 1;

	if (left >= right)
		return (left);

	return (right);
}

/**
 * binary_tree_size - retreives the size of a binary tree
 * @tree: root node of the tree
 * Return: binary tree size
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * retrieveLastNode - gets the last node in tree
 * @root: root node
 * Return: node most recently inserted
 */
heap_t *retrieveLastNode(heap_t *root)
{
	if (!root)
		return (NULL);

	if (!root->left && !root->right)
		return (root);

	if (binary_tree_height(root->left) > binary_tree_height(root->right))
		return (retrieveLastNode(root->left));

	if (binary_tree_size(root->left) > binary_tree_size(root->right))
		return (retrieveLastNode(root->right));

	return (retrieveLastNode(root->right));
}
