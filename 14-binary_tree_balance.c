#include "binary_trees.h"

/**
 * binary_tree_height_b - Function that measures the height of a binary tree
 * @tree: tree to go through
 * Return: the height
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
	right_height = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: tree to go through
 * Return: The balance
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree)
	{
		left_height = binary_tree_height_b(tree->left);
		right_height = binary_tree_height_b(tree->right);
	}
	return (left_height - right_height);
}
