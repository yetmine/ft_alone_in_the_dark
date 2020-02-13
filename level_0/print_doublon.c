/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:01:44 by rabduras          #+#    #+#             */
/*   Updated: 2020/02/12 16:30:36 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int i = 0;
	int j = 0;
	int first = 1;

	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (first)
			{
				printf("%d", a[i]);
				first = 0;
			}
			else
				printf(" %d", a[i]);
			i++;
			j++;
		}
		else if (a[i] > b[j])
			j++;
		else if (a[i] < b[j])
			i++;
	}
	printf("\n");
}

// int		main(void)
// {
// 	int a[] = {-5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
// 	int b[] = {2,  4,  5,  6,  7, 10,  40,  70};

// 	print_doublon(a, 11, b, 8);
// }
