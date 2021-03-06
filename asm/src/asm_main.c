/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:14:28 by atrush            #+#    #+#             */
/*   Updated: 2017/05/25 15:14:30 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	open_file(char *filename)
{
	int fd;

	errno = 0;
	fd = open(filename, O_RDONLY);
	if (errno != 0)
	{
		perror(filename);
		exit (-1);
	}
	return (fd);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_body		*body;
	t_header	head;
	t_asml		asml[16];

	if (argc > 1)
	{
		fd = open_file(argv[argc - 1]);
		asml_default(asml);
		head = make_header(fd);
		body = make_body(fd, head.prog_size, asml);
		close(fd);
		
	/*	t_body *tmp; tmp = body;
		while (tmp) {
			ft_printf("label = %s, name = %s, l1 = %s, l2 = %s, l3 = %s, a1 = %lld, a2 = %lld, a3 = %lld\n",
			tmp->label, asml[tmp->cmd].name,tmp->link_1,tmp->link_2,tmp->link_3,tmp->arg1,tmp->arg2,tmp->arg3);
			tmp = tmp->next;}
	*/	
		body_delete(&body);
	}
	else
		ft_printf("Usage: %s%s", argv[0], USAGE);
	return (0);
}
