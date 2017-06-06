/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:22:14 by ochayche          #+#    #+#             */
/*   Updated: 2017/06/05 19:22:15 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_destruct(t_data *data)
{
	ft_memdel((void **)&data);
}

static void	ft_usage(void)
{
	ft_printf("usage:\n./corewar [-dump nbr_cycles] \
	[[-n number] champion1.cor] ...");
}

int			main(int ar, char **av)
{
	t_data data;

	if (ar > 2)
	{
		read_flags(av);
		;
	}
	else
		ft_usage();
	return (0);
}
