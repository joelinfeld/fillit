/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:23:55 by bchin             #+#    #+#             */
/*   Updated: 2017/03/16 13:32:46 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"

typedef struct	s_tetromino
{
	char		*bp;
	char		alpha;
	int			use;
}				t_tet;
typedef struct	s_numlist
{
	int			x;
	int			y;
	int			sz;
}				t_num;
int				count_pieces(char *str);
int				count_length(char *argv);
char			*fill_array(char *argv);
char			**split_me(char *str);
void			write_split(char **split, char *str);
void			write_piece(char *dest, char *from);
char			*find_hash(char *str);
int				index_score(char *str);
int				last_index(char *str);
int				connections(char *str);
t_tet			maketet(char *str, int i);
t_num			makenum(int x, int y, int sz);
void			fillit(t_tet *p, int nm, int sz);
int				codebreak(char **sq, t_tet p, char *bp, t_num nums);
void			pdelete(char **sq, t_tet p, char *bp, t_num nums);
int				nearestsq(int nb);
int				char_is_newline(char a);
int				char_is_dot(char a);
char			**blanksq(int size);
int				check_count(char *file);
int				check_errors(char **str, int pieces);
void			arrdel(char **sq);
void			pdel(t_tet **p);

#endif
