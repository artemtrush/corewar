/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 20:31:11 by ochayche          #+#    #+#             */
/*   Updated: 2017/06/14 20:31:12 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	open_error(char *av)
{
	ft_printf("Can't read source file %s\n", av);
	exit(1);
}


void	read_player(t_data *data, char *av, int n)
{
	int fd;

	if ((fd = open(av, O_RDONLY)) == -1)
	{
		open_error(av);
	}














	if (close(fd) == -1)
		perror("");
}
