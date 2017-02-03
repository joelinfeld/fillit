/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:23:55 by bchin             #+#    #+#             */
/*   Updated: 2017/02/03 12:16:42 by bchin            ###   ########.fr       */
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

int		count_pieces(char *str); // counts how many shapes there are based off ".\n\n"
int		count_length(char *argv); // counts how many characters exist in the file opened
int		piece_cmp(char *big, char *little); //function to compare pieces to see which piece it is and if it is valid (strstr but returns (1) for match)
char	*fill_array(char *argv); //mallocs and copies file to a null terminated character array;
char	**split_me(char *str); //splits into pieces. Does not verify valid piece or size, just splits by 21 characters
void	write_split(char **split, char *str);
void	write_piece(char *dest, char *from);


# endif
