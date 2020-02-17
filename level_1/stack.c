/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:28:41 by rabduras          #+#    #+#             */
/*   Updated: 2020/02/17 14:44:51 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
    void          *content;
    struct s_node *next;
};

struct s_stack {
    struct s_node *top;
};

int isEmpty(struct s_stack *stack);

struct s_stack *init(void)
{
    struct s_stack *stack;

    stack = (struct s_stack*)malloc(sizeof(struct s_stack));
    if (stack != NULL)
    {
        stack->top = NULL;
        return (stack);
    }
    return (NULL);
}

void *pop(struct s_stack *stack)
{
    void *content;
    struct s_node *temp;

    if (isEmpty(stack))
        return (NULL);
    temp = stack->top->next;
    content = stack->top->content;
    free(stack->top);
    stack->top = temp;
    return (content);
}

static struct s_node *create(void *content)
{
    struct s_node *node;

    node = (struct s_node*)malloc(sizeof(struct s_node));
    if (node != NULL)
    {
        node->content = content;
        node->next = NULL;
        return (node);
    }
    return (NULL);
}

void push(struct s_stack *stack, void *content)
{
    struct s_node *node;

    if (stack == NULL)
        return;
    node = create(content);
    if (node == NULL)
        return;
    node->next = stack->top;
    stack->top = node;
}

void *peek(struct s_stack *stack)
{
    if (isEmpty(stack))
        return (NULL);
    return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
    if (!stack || !stack->top)
        return (1);
    return (0);
}

#include <stdio.h>
int 	main(void)
{
	char a[] = "aaaaa";			(void)a;
	char b[] = "bbbbb";			(void)b;
	char c[] = "ccccc";			(void)c;
	char d[] = "ddddd";		    (void)d;
	struct s_stack *stack;

	stack = init(); 			(void)stack;
	printf("isEmpty: %d\n", isEmpty(stack));
	printf("peek: %s\n", peek(stack));
	printf("pop: %s\n", pop(stack));
	push(stack, a); push(stack, b); push(stack, c); push(stack, d);
	printf("isEmpty: %d\n", isEmpty(stack));
	printf("peek: %s\n", peek(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("isEmpty: %d\n", isEmpty(stack));

	return (0);
}