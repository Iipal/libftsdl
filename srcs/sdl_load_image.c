/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_load_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:05:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/23 22:32:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

SDL_Surface	*sdl_load_image(char const *path, SDL_PixelFormat const *format)
{
	SDL_Surface	*temp = IMG_Load(path);
	SDL_Surface	*out;

	out = NULL;
	if (!temp)
	{
		SDL_Log("%s\n", TTF_GetError());
		return out;
	}
	out = SDL_ConvertSurface(temp, format, 0);
	if (!out)
		SDL_Log("%s\n", SDL_GetError());
	SDL_FreeSurface(temp);
	return (out);
}
