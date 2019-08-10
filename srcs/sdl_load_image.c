/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_load_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:05:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/10 09:25:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

SDL_Surface	*sdl_load_image(char const *path, SDL_PixelFormat const *format)
{
	SDL_Surface	*out;
	SDL_Surface	*temp;

	temp = NULL;
	out = NULL;
	NOM_R(IMG_GetError(), temp = IMG_Load(path), NULL);
	NOM_R(SDL_GetError(), out = SDL_ConvertSurface(temp, format, 0), NULL);
	SDL_FreeSurface(temp);
	return (out);
}
