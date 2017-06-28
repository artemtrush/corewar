/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:27:53 by ochayche          #+#    #+#             */
/*   Updated: 2017/06/05 19:27:54 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*		allowed function:
**		open
**		read
**		lseek
**		write
**		close
**		malloc
**		realloc
**		free
**		perror
**		strerror
**		exit
*/

/* DO LIST:
** init 
**
**
*/

#include <../../inc/libft/inc/libft.h>
#include <../../inc/ft_printf/ft_printf.h>
#include <../../inc/op.h>

#include <fcntl.h>


#include <stdio.h> // dell

#define	USAGE "usage: ./corewar [-v] [-dump nbr_cycles] [[-n number] champion1.cor] ...\n"


typedef unsigned char uchar;
typedef unsigned int uint;


typedef struct	s_proc // to do
{
	uint			id;
	uint			pc;//karetka;
	uint			last_live;//kak budet rabotat`??
	int				cycles_to_exec; //izna4alno -1
	int				reg[REG_NUMBER];
	int				carry;
	struct s_proc	*next;
}				t_proc;
//		last born -> first step


typedef struct	s_player
{
	int				player_id; // -1 -2 -3 -4
	char			alive;
	char 			*name;//[PROG_NAME_LENGTH + 1];
	uint			prog_size;
	char 			*comment;//[COMMENT_LENGTH + 1];
	uint			last_live;
	uint			lives_in_curr;
	uchar			*byte_code;
	struct s_player	*next;
}					t_player;


typedef struct	s_data
{
	int			dump_arg; //		init to -2
	uchar		*map;//[MEM_SIZE + 1];
	uchar		*color; // which player this byte belongs to
	uint		cycle;
	int			cycle_to_die;
	uint		checks;
	uint		num_of_proc;
	// t_asml		asml[16];
	t_player	*players;//4 max
	t_proc		*processes;
	int			visual_flag;
}				t_data;


void			init_data(t_data *data);
void			destruct(t_data *data);
void			read_player(t_data *data, char *av, int n);
void			start(t_data *data);




