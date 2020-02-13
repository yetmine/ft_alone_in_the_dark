/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:13:40 by rabduras          #+#    #+#             */
/*   Updated: 2020/02/12 14:18:27 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	equation(int n)
{
	int a, b, c;

	a = 0;
	while (a <= 9)
	{
		b = 0;
		while (b <= 9)
		{
			c = 0;
			while (c <= 9)
			{
				if ((a * 10 + b) + (c * 10 + a) == n)
					printf("A = %d, B = %d, C = %d\n", a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}

// int main(void)
// {
// 	equation(0);
// 	return (0);
// }
