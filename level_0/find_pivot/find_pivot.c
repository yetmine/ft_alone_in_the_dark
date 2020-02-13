/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:19:04 by rabduras          #+#    #+#             */
/*   Updated: 2020/02/12 14:40:27 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		getSum(int *arr, int n)
{
	int i = 0;
	int sum = 0;

	while (i < n)
	{
		sum += arr[i++];
	}
	return (sum);
}

int		find_pivot(int *arr, int n)
{
	int i = 0;
	int left = 0;
	int right = getSum(arr + 1, n - 1);

	while (i < n)
	{
		if (left == right)
			return (i);
		left += arr[i];
		right -= arr[i + 1];
		i++;
	}
	return (-1);
}

// #include <stdio.h>

// int main(void)
// {
// 	int arr[] = {1 , 2 };

// 	printf("%d\n", find_pivot(arr, 2));
// 	return (0);
// }
