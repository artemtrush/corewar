/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:33:07 by ochayche          #+#    #+#             */
/*   Updated: 2017/06/07 11:33:08 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			print_memory(t_data *data)
{
	size_t		i;

	printf("*****************************************************************"
		"********************************************************************"
		"****************************************************************\n");
	printf("*                                                                "
		"                                                                    "
		"                                                               *\n");
	i = 0;
	printf("\033[32m");
	while (i < MEM_SIZE)
	{
		if (i == 0)
			printf("*  %0.2hhx", data->map[i]);
		else if (i % 64 == 0)
			printf("  *\n*  %0.2hhx", data->map[i]);
		else
			printf(" %0.2hhx", data->map[i]); // ft_
		++i;
		if (i == data->players->prog_size)
			printf("\033[0m");
	}
	printf("  *\n*                                                                "
		"                                                                    "
		"                                                               *\n");
	printf("*****************************************************************"
		"********************************************************************"
		"****************************************************************\n");
}

void			map_init(t_data *data)
{
	data->map = (uchar *)malloc(sizeof(uchar) * (MEM_SIZE));
	ft_bzero(data->map, MEM_SIZE + 1);
	ft_memcpy(data->map, data->players->byte_code, data->players->prog_size);
}

int				hex_to_int(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	if ('a' <= c && c <= 'f')
		return (c - 'a' + 10);
	printf("hex_to_int error\n");
	exit(0);
}

void			crunch_init_player(t_player *p)
{
	char		*code = "0b6801000f00010664010000000001010000000109fffb";

	p->player_id = -1;
	p->alive = 1;
	p->name = ft_strdup("zork");
	p->prog_size = 23;
	p->comment = ft_strdup("IAM ALIVE");
	p->last_live = 0;
	p->lives_in_curr = 0;
	p->byte_code = malloc(23);

	int			i;
	int			j;
	int			n;
	i = 0;
	j = 0;
	while (i < 46)
	{
		n = hex_to_int(code[i]) * 16 + hex_to_int(code[i + 1]);
		p->byte_code[j++] = n;
		i += 2;
	}
	
}

void			start(t_data *data)
{
	t_player	p;

	printf("START\n");
	crunch_init_player(&p);
	data->players = &p;
	map_init(data);
	print_memory(data);
}
