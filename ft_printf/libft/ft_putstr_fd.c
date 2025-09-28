/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:50:31 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:50:31 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			write(fd, &*s++, 1);
	}
}

/* int main(void)
{
    int fd = open("Hello", O_RDWR | O_CREAT);

	ft_putstr_fd((char*)"42", fd);
	lseek(fd, SEEK_SET, 0);
	char s[10] = {0};
	read(fd, s, 3);
	if (!strcmp(s, "42"))
		printf("CHECK 1 OK\n");
	else
		printf("CHECK 1 KO\n");
	close(fd);
	unlink("./Hello");
    return(0);
} */