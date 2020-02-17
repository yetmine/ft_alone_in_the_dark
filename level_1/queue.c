/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:05:55 by rabduras          #+#    #+#             */
/*   Updated: 2020/02/17 14:41:42 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
    void *content;
    struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

int isEmpty(struct s_queue *queue);

struct s_queue *init(void)
{
    struct s_queue *queue;

    queue = (struct s_queue*)malloc(sizeof(struct s_queue));
    if (queue != NULL)
    {
        queue->first = NULL;
        queue->last = NULL;
        return (queue);
    }
    return (NULL);
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

void enqueue(struct s_queue *queue, void *content)
{
    struct s_node *node;

    node = create(content);
    if (node == NULL)
        return;
    if (isEmpty(queue))
        queue->first = node;
    else
        queue->last->next = node;
    queue->last = node;
}

void *dequeue(struct s_queue *queue)
{
    struct s_node *temp;
    void *content;

    if (isEmpty(queue))
        return (NULL);
    temp = queue->first->next;
    content = queue->first->content;
    free(queue->first);
    queue->first = temp;
    return (content);
}

void *peek(struct s_queue *queue)
{
    if (isEmpty(queue))
        return (NULL);
    return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
    if (!queue || !queue->first || !queue->last)
        return (1);
    return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char a[] = "First"; (void)a;
// 	char b[] = "Second"; (void)b;
// 	char c[] = "Third"; (void)c;
// 	char d[] = "Fourth"; (void)d;

// 	struct s_queue *queue = init();
// 	printf("isEmpty A: %d\n", isEmpty(queue));
// 	enqueue(queue, a);
// 	printf("isEmpty B: %d\n", isEmpty(queue));
// 	enqueue(queue, b);
// 	enqueue(queue, c);
// 	enqueue(queue, d);

// 	printf("Peek: %s\n", peek(queue));
// 	printf("Pop: %s\n", dequeue(queue));
// 	printf("Pop: %s\n", dequeue(queue));
// 	printf("Pop: %s\n", dequeue(queue));
// 	printf("Pop: %s\n", dequeue(queue));
// 	printf("Pop: %s\n", dequeue(queue));
// 	printf("Peek: %s\n", peek(queue));
// 	printf("isEmpty C: %d\n", isEmpty(queue));
// 	return (0);
// }