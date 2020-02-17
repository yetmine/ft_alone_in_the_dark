/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:39:07 by rabduras          #+#    #+#             */
/*   Updated: 2020/02/17 13:39:22 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		char c;
		int index;
		int first = 1;
		int hash[26] = {0};

		while (argv[1][i])
		{
			c = argv[1][i];
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			{
				index = (c < 'a') ? c + ' ' : c;
				hash[index - 97]++;
			}
			i++;
		}
		i = 0;
		while (argv[1][i])
		{
			c = argv[1][i];
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			{
				index = (c < 'a') ? c + ' ' : c;
				if (hash[index - 97] > 0)
				{
					if (first)
					{
						printf("%d%c", hash[index - 97], index);
						first = 0;
					}
					else
						printf(", %d%c", hash[index - 97], index);
					hash[index - 97] = 0;
				}
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
