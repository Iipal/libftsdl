/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_load_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:05:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 13:00:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

SDL_Surface	*sdl_load_image(char const *path,
				SDL_PixelFormat const *format,
				SDL_Surface *dst)
{
	SDL_Surface	*temp;

	temp = NULL;
	NOM_R(IMG_GetError(), temp = IMG_Load(path), NULL);
	NOM_R(SDL_GetError(), dst = SDL_ConvertSurface(temp, format, 0), NULL);
	SDL_FreeSurface(temp);
	return (dst);
}
