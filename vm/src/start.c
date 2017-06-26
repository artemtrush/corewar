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

#include "corewar.h"//fonts color
#define FBLACK      "\033[30;"
#define FRED        "\033[31;"
#define FGREEN      "\033[32;"
#define FYELLOW     "\033[33;"
#define FBLUE       "\033[34;"
#define FPURPLE     "\033[35;"
#define D_FGREEN    "\033[6;"
#define FWHITE      "\033[7;"
#define FCYAN       "\033[36;"

//background color
#define BBLACK      "40m"
#define BRED        "41m"
#define BGREEN      "42m"
#define BYELLOW     "43m"
#define BBLUE       "44m"
#define BPURPLE     "45m"
#define BCYAN	    "46m"
#define BWHITE      "47m"

#define BORDER		FWHITE BWHITE
#define GREEN		FGREEN BBLACK
#define RED			FRED BBLACK
#define BLUE		FBLUE BBLACK
#define CYAN		FCYAN BBLACK
#define PCGREEN		FBLACK BGREEN
#define PCRED		FBLACK BRED
#define PCBLUE		FBLACK BBLUE
#define PCCYAN		FBLACK BCYAN

//end color
#define NONE        "\033[0m"

void			print_players(t_data *data)
{
	t_player	*curr;

	curr = data->players;
	while (curr)
	{
		printf("PLAYER[%d]:%s:%s\n", curr->player_id, curr->name, curr->comment);
		curr = curr->next;
	}
}

/****************************
 * 0 0 0 0 1 [0 0 0] <-- RGB
 *         ^ 
 *    PC INDICATOR
 ****************************/

void			print_colored_byte(uchar i, uchar j)
{
	if (i == 1)
		printf(GREEN "%0.2hhx" NONE, j);
	else if (i == 2)
		printf(RED "%0.2hhx" NONE, j);
	else if (i == 3)
		printf(BLUE "%0.2hhx" NONE, j);
	else if (i == 4)
		printf(CYAN "%0.2hhx" NONE, j);
	else if (i == 9)
		printf(PCGREEN "%0.2hhx" NONE, j);
	else if (i == 10)
		printf(PCRED "%0.2hhx" NONE, j);
	else if (i == 11)
		printf(PCBLUE "%0.2hhx" NONE, j);
	else if (i == 12)
		printf(PCCYAN "%0.2hhx" NONE, j);
	else
		printf("%0.2hhx", j);
}

void			print_memory(t_data *data)
{
	size_t		i;

	printf(BORDER "*****************************************************************"
		"********************************************************************" 
		"****************************************************************" NONE "\n" );
	printf(BORDER "*" NONE "                                                                "
		"                                                                    "
		"                                                               " BORDER "*" NONE "\n");
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i == 0)
			printf(BORDER "*" NONE "  ");
		else if (i % 64 == 0)
			printf("  " BORDER "*" NONE "\n" BORDER "*" NONE "  ");
		else
			printf(" "); // ft_
		print_colored_byte(data->color[i], data->map[i]);
		++i;
	}
	printf("  " BORDER "*" NONE "\n" BORDER "*" NONE "                                                                "
	"                                                                    "
	"                                                               " BORDER "*" NONE "\n");
	printf(BORDER "*****************************************************************"
		"********************************************************************" 
		"****************************************************************" NONE "\n" );
}

void			map_init(t_data *data)
{
	t_player	*curr;
	int			i;
	int			j;

	data->map = (uchar *)malloc(sizeof(uchar) * (MEM_SIZE));
	data->color = (uchar *)malloc(sizeof(uchar) * (MEM_SIZE));
	ft_bzero(data->map, MEM_SIZE);
	ft_bzero(data->color, MEM_SIZE);
	curr = data->players;
	i = 0;
	while (curr)
	{
		ft_memcpy(data->map + i, curr->byte_code, curr->prog_size);
		j = i;
		while (j < i + curr->prog_size)
		{
			data->color[j] = i / 1024 + 1;
			j++;
		}
		data->color[i] += 8;
		curr = curr->next;
		i += 1024;
	}
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

void			init_players(t_data *data)
{
	int			i;
	t_player	*curr;	

	data->players = (t_player *)malloc(sizeof(t_player));
	curr = data->players;
	i = 0;
	while (i < 3)
	{
		crunch_init_player(curr);
		curr->player_id -= i;
		curr->next = (t_player *)malloc(sizeof(t_player));
		curr = curr->next;
		i++;
	}
	crunch_init_player(curr);
	curr->player_id -= i;
	curr->next = NULL;
}

void			start(t_data *data)
{
	printf("START\n");
	init_players(data);
	//print_players(data);
	map_init(data);
	print_memory(data);
}
















