/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:17:09 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/11 17:13:15 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_it(int n, int fd)
{
	char c;
	if (n == 0)
		return ;
	print_it(n / 10, fd);
	c = ('0' + (n % 10));
	write(fd,&c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if(n == 0)
	{
		write(fd,"0",1);
		return;
	}
	print_it(n, fd);
}

// #include "libft.h"
// #include <fcntl.h>  // for open
// #include <stdio.h>  // for printf

// int main(void)
// {

//     // Test writing to standard output
//     ft_putnbr_fd(0, 1);
//     write(1, "\n", 1);

//     ft_putnbr_fd(42, 1);
//     write(1, "\n", 1);

//     ft_putnbr_fd(-42, 1);
//     write(1, "\n", 1);

//     ft_putnbr_fd(2147483647, 1); // INT_MAX
//     write(1, "\n", 1);

//     ft_putnbr_fd(-2147483648, 1); // INT_MIN
//     write(1, "\n", 1);

//     // Test writing to a file
//     printf("Check numbers.txt for output.\n");
//     return 0;
// }
