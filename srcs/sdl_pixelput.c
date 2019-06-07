/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pixelput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:02:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/07 19:16:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_pixelput(SDL_Surface *surf, const __v2si p, const Color clr)
{
	if (0 <= X(p) && 0 <= Y(p) && Y(p) < surf->h && X(p) < surf->w)
		((uiarr)(surf->pixels))[Y(p) * surf->w + X(p)] = clr.hex;
}
