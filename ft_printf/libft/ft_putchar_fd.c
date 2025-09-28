/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:49:46 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:49:46 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int	main(void)
{	//open file to READ, WRITE and CREATE
    int fd = open("Hello", O_RDWR | O_CREAT);
	//put character in file
	ft_putchar_fd('a', fd);
	//put offset on N bytes
	lseek(fd, SEEK_SET, 0);
	char s[10] = {0};
	//read from file 2 bytes to s
	read(fd, s, 2);
	if (!strcmp(s, "a"))
		printf("CHECK 1 OK\n");
	else
		printf("CHECK 1 KO\n");
	close(fd);
	//unlink path
	unlink("./Hello");
    return (0);
} */