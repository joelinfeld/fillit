/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:23:55 by bchin             #+#    #+#             */
/*   Updated: 2017/02/03 10:43:26 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		count_shapes(char *argv); // counts how many shapes there are based off of a 21 buf size
int		count_length(char *argv); // counts how many characters exist in the file opened
int		piece_cmp(char *big, char *little); //function to compare pieces to see which piece it is and if it is valid (strstr but returns (1) for match)
char	*fill_array(char *argv); //mallocs and copies file to a null terminated character array;

# endif
