/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:50:17 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:50:17 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				r;

	nb = n;
	if (n < 0)
	{
		nb = n * -1;
		write(fd, "-", 1);
	}
	if (nb <= 9)
	{
		nb += 48;
		write(fd, &nb, 1);
	}
	else
	{
		r = nb % 10;
		nb = nb - r;
		r += 48;
		ft_putnbr_fd(nb / 10, fd);
		write(fd, &r, 1);
	}
}

/* int main(void)
{
    int fd = open("Hello", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(0, fd);
	lseek(fd, SEEK_SET, 0);
	char s[42] = {0};
	read(fd, s, 2);
	if (!strcmp(s, "0"))
		printf("CHECK 1 OK\n");
	else
		printf("CHECK 1 KO\n");
	close(fd);
	unlink("./Hello");
 	fd = open("Hello", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(10, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 3);
	if (!strcmp(s, "10"))
		printf("CHECK 2 OK\n");
	else
		printf("CHECK 2 KO\n");
	close(fd);
	unlink("./Hello");
	fd = open("Hello", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(2147483647, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 11);
	if (!strcmp(s, "2147483647"))
		printf("CHECK 3 OK\n");
	else
		printf("CHECK 3 KO\n");
	close(fd);
	unlink("./Hello");
	fd = open("Hello", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(-2147483648, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 12);
	if (!strcmp(s, "-2147483648"))
		printf("CHECK 4 OK\n");
	else
		printf("CHECK 4 KO\n");
	close(fd);
	unlink("./Hello");
    return(0);
} */