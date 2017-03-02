/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:23:55 by bchin             #+#    #+#             */
/*   Updated: 2017/02/28 21:56:58 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
#include <string.h>

typedef struct	tetromino
{
	char		*bp;
	int			w;
	char		alpha;
	int			use;
} 				tet;
int		count_pieces(char *str); // counts how many shapes there are based off ".\n\n"
int		count_length(char *argv); // counts how many characters exist in the file opened
int		piece_cmp(char *big, char *little); //function to compare pieces to see which piece it is and if it is valid (strstr but returns (1) for match)
char	*fill_array(char *argv); //mallocs and copies file to a null terminated character array;
char	**split_me(char *str); //splits into pieces. Does not verify valid piece or size, just splits by 21 characters
void	write_split(char **split, char *str);
void	write_piece(char *dest, char *from);
char	*find_hash(char *str); //finds first location of a '#' in a string
int		index_score(char *str); //returns sum of index '#' appears in. only 3 pieces have a score of 18, the rest are all different
int		last_index(char *str); //returns the highest index the '#' appears in, the three pieces that have a sum or 18 have different max indexes '#' appears
int		connections(char *str); // returns the sum of connections each block in a tetrimino has should be 6 or 8
tet		maketet(char *str, int i);
void	*ft_memalloc(size_t size);
void 	ft_bzero(void *s, size_t n);
void	fillit(tet *p, int nm, int sz);
void	ft_putstr(char *str);
int		codebreak(char **sq, tet p, char *bp, int x, int y, int sz);
void	pdelete(char **sq, tet p, char *bp, int x, int y);
int		nearestsq(int nb);
int		char_is_newline(char a);
int		char_is_dot(char a);
char	**blanksq(int size);
int		check_count(char *file);
int		check_errors(char **str, int pieces);
int		check_piece_count(char **str);
# endif
