#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that checks an ancestor
 * @first: First node
 * @second: Second node
 * Return: the node of the ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	binary_tree_t *fp, *sp;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	fp = first->parent;
	sp = second->parent;
	if (!fp || first == sp || (!fp->parent && sp))
		return (binary_trees_ancestor(first, sp));

	else if (!sp || second == fp || (!sp->parent && fp))
		return (binary_trees_ancestor(fp, second));

	return (binary_trees_ancestor(fp, sp));
}
