#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) ((x > y) ? (x) : (y))

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;
heap_t *heapify(heap_t *node);
int isComplete(heap_t *root, int index, int numNodes);
int countNodes(heap_t *root);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
void binary_tree_print(const binary_tree_t *tree);
size_t binaryTreeHeight(heap_t *root);
heap_t *insertCompleteTree(heap_t **root, int value);
heap_t *findParent(heap_t *node, size_t level, size_t height);
#endif /* BINARY_TREES_H */
