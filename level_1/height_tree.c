/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:38:49 by rabduras          #+#    #+#             */
/*   Updated: 2020/02/17 14:04:28 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
    int             value;
    struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
    int i = 0;
    int height;
    int max_height;

    if (!root)
        return (-1);
    if (!root->nodes)
        return (0);
    max_height = height_tree(root->nodes[i]);
    while (root->nodes[++i])
    {
        height = height_tree(root->nodes[i]);
        if (height > max_height)
            max_height = height;   
    }
    return (max_height + 1);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	struct s_node *node94 = malloc(sizeof(struct s_node));
// 	struct s_node *node34 = malloc(sizeof(struct s_node));
// 	struct s_node *node52 = malloc(sizeof(struct s_node));
// 	struct s_node *node1 = malloc(sizeof(struct s_node));
// 	struct s_node *node99 = malloc(sizeof(struct s_node));
// 	struct s_node *node11 = malloc(sizeof(struct s_node));
// 	struct s_node *node13 = malloc(sizeof(struct s_node));

// 	node94->nodes = malloc(sizeof(struct s_node) * 10);
//     node94->value = 94;
// 	node94->nodes[0] = node34;
// 	node94->nodes[1] = node52;
// 	node94->nodes[2] = 0;

// 	node34->nodes = malloc(sizeof(struct s_node) * 10);
//     node34->value = 34;
// 	node34->nodes[0] = node1;
// 	node34->nodes[1] = node99;
// 	node34->nodes[2] = 0;

// 	node52->nodes = malloc(sizeof(struct s_node) * 10);
//     node52->value = 52;
// 	node52->nodes[0] = node11;
// 	node52->nodes[1] = 0;

// 	node1->nodes = malloc(sizeof(struct s_node) * 10);
//     node1->value = 1;
// 	node1->nodes[0] = 0;

// 	node99->nodes = malloc(sizeof(struct s_node) * 10);
//     node99->value = 99;
// 	node99->nodes[0] = 0;

// 	node11->nodes = malloc(sizeof(struct s_node) * 10);
//     node11->value = 11;
//     node11->nodes[0] = node13;
// 	node11->nodes[1] = 0;

// 	node13->nodes = malloc(sizeof(struct s_node) * 10);
//     node13->value = 13;
//     node13->nodes[0] = 0;

// 	printf("%d\n", height_tree(node94));
// }