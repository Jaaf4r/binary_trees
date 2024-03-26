#include "binary_trees.h"

/**
 * tree_is_perfect - checks if a binary tree is perfect
 * @tree: tree to go through
 * Return: 1 if perfect, 0 if not
*/
int tree_is_perfect(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree->left && tree->right)
	{
		l = 1 + tree_is_perfect(tree->left);
		r = 1 + tree_is_perfect(tree->right);
		if (l == r && r != 0 && l != 0)
			return (l);
		return (0);
	}
	else if (!tree->left && !tree->right)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: tree to go through
 * Return: 0 if tree is not perfect or NULL
 *         1 if tree is perfect
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (!tree)
		return (0);

	result = tree_is_perfect(tree);
	if (result)
		return (1);
	return (0);
}
