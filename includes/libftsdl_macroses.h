/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl_macroses.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:20:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/13 09:19:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_MACROSES_H
# define LIBFTSDL_MACROSES_H

# define FPS_FONT "libftsdl/resources/fonts/04B_03__.TTF"
# define FPS_FONT_SIZE 18

# define CONVERT_FROM_CANVAS(x, y, win_x, win_y) (__v2si){x+win_x/2, y+win_y/2}
# define D_FROM_CANVAS(x, y, wx, wy) (__v2df){(x)+((wx)/2),(y)+((wy)/2)}

#endif
