#include "binary_trees.h"
#include "_1-heap_insert.c"

/**
 * heap_insert - inserts node into max heap
 * Return: node we added
 */
heap_t *heap_insert(heap_t **root, int value)
{
    if (!(*root))
    {
        (*root) = binary_tree_node(NULL, value);
        return (*root);
    }
    return (insertCompleteTree(root, value));
}

/**
 * insertCompleteTree - inserts into a complete tree
 * @root: root node
 * @value: value
 * Return: heap node
 */
heap_t *insertCompleteTree(heap_t **root, int value)
{
    int numNodes = countNodes(*root);
    heap_t *parent, *tmp, *node;
    size_t height = binaryTreeHeight(*root);

    if (isComplete(*root, 0, numNodes))
    {
        tmp = *root;
        node = binary_tree_node(NULL, value);
        while (tmp && tmp->left)
            tmp = tmp->left;
        node->parent = tmp;
        tmp->left = node;
        heapify(node);
        return (node);
    }
    parent = findParent(*root, height - 1, height);
    if (!parent)
    {
        for (tmp = (*root); tmp->left; tmp = tmp->left)
            ;
        parent = tmp;
    }
    node = binary_tree_node(parent, value);
    if (!parent->left)
        parent->left = node;
    else
        parent->right = node;
    heapify(node);
    return (node);
}

/**
 * binaryTreeHeight - finds height of tree
 * @root: root of tree
 * Return: height
 */
size_t binaryTreeHeight(heap_t *root)
{
    size_t left, right;

    if (!root)
        return (0);
    left = (root->left) ? 1 + binaryTreeHeight(root->left) : 0;
    right = (root->right) ? 1 + binaryTreeHeight(root->right) : 0;
    return (MAX(left, right));
}
/**
 * findParent - finds parent of node
 * @node: node to find parent of
 * @height: height of tree
 * Return: parent
 */
heap_t *findParent(heap_t *node, size_t level, size_t height)
{
    heap_t *left, *right;

    if (node->left && node->right && node->parent == NULL)
    {
        if (node->left->left == NULL)
            return (node->left);
        else if (node->right->right == NULL)
            return (node->right);
    }
    if (level == height - 1)
        return (!node->left || !node->right) ? node : node->left;

    left = findParent(node->left, level, height - 1);
    right = findParent(node->right, level, height - 1);

    if (!left && !right)
        return (NULL);
    else if (left && !right)
        return (left);
    else
        return (right);
}

/**
 * heapify - fix a heap after insertion
 * @root: root node
 * @node: node
 * Return: node
 */
heap_t *heapify(heap_t *node)
{
	int n;

	if (node->parent)
	{
		if (node->parent->n < node->n)
		{
			n = node->parent->n;
			node->parent->n = node->n;
			node->n = n;
			return (heapify(node->parent));
		}
	}
	return (node);
}