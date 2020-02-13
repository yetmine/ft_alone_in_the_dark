/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:06:09 by rabduras          #+#    #+#             */
/*   Updated: 2020/02/12 14:18:31 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_2s(int n)
{
	int sum = 0;

	while (n)
	{
		if (n % 10 == 2)
			sum++;
		n /= 10;
	}
	return (sum);
}

int		count_of_2(int n)
{
	int i = 1;
	int sum = 0;

	while (++i <= n)
		sum += count_2s(i);
	return (sum);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%d\n", count_of_2(25));
// 	return (0);
// }
