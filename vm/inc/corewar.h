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

#define	USAGE "usage: ./corewar [-dump nbr_cycles] [-n number] champion1.cor] ...\n"


typedef unsigned char uchar;
typedef unsigned int uint;


typedef struct	s_proc //to do
{
	short		player;


	
	struct s_proc *next;
}				t_proc;

//		last burn -> first steap


typedef struct	s_player
{
	int			player; 	// -1 -2 -3 -4
	char 		*name;
	uint  		size;
	char 		*comment;
	char 		*byte_code;
	int 		koretka;	// init to 0;
}				t_player;




typedef struct	s_data
{
	int			dump_arg; //		init to -2
	uchar		map[MEM_SIZE + 1];
	uint		processes; //placeholder
	uint		cycle;
	uint		cycle_to_die;
	uint		checks;
	t_player	**players;
}				t_data;





void			init_data(t_data *data);
void			destruct(t_data *data);
void			read_player(t_data *data, char *av, int n);


