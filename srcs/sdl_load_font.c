/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_load_font.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:15:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/17 15:37:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

SDL_Surface	*sdl_load_font(Sdl const *const sdl,
				char const *text,
				SDL_Color const text_color)
{
	SDL_Surface	*temp = TTF_RenderGlyph_Solid(sdl->font, *text, text_color);
	SDL_Surface	*out;

	out = NULL;
	if (!temp)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s\n", TTF_GetError());
		return out;
	}
	out = SDL_ConvertSurface(temp, sdl->wsurf->format, 0);
	if (!out)
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s\n", SDL_GetError());
	SDL_FreeSurface(temp);
	return (out);
}
