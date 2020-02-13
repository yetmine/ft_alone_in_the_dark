/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:41:27 by rabduras          #+#    #+#             */
/*   Updated: 2020/02/12 15:01:22 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_anagram(char *a, char *b)
{
	int i = 0;
	int hash[94] = {0};

	while (*a)
	{
		hash[*a - 32]++;
		a++;
	}
	while (*b)
	{
		hash[*b - 32]--;
		b++;
	}
	while (i < 94)
		if (hash[i++] != 0)
			return (0);
	return (1);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", is_anagram("abcdef", "fabcde"));
// 	printf("%d\n", is_anagram(".123?.", "?321.."));
// 	printf("%d\n", is_anagram("abca", "bcab"));
// }
