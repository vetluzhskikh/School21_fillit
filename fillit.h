/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:10:45 by gnelson           #+#    #+#             */
/*   Updated: 2019/12/22 15:32:45 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILLIT_H
# define FILLIT_H

#include        "./libft/includes/get_next_line.h"
#include 	    <fcntl.h>

# define __TETRAMINO_SIZE__ 16
# define __MAX_READ__ 442

typedef struct  		s_fillit
{

	struct	s_fillit	*next;
}						t_fillit;

#endif