#include "main.h"

/**
 * addrvarnode - variable at the end
 * of a r_var list.
 * @head: head
 * @lvar: length
 * @val: value
 * @lval: length
 * Return: head.
 */
r_var *addrvarnode(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *temp;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar, new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * freervarlist - frees
 * @head: head
 * Return: no.
 */
void freervarlist(r_var **head)
{
	r_var *temp;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
			curr = curr->next, free(temp);
		*head = NULL;
	}
}
