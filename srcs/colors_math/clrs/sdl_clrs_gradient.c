/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_gradient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:04:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 12:04:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

Color	*sdl_clrs_gradient(Color const start, Color const end, size_t const n)
{
	Color	*out;
	FColor	step;
	FColor	diff;
	size_t	i;

	i = ~0UL;
	IFR(1UL > n, NULL);
	NO_R(MALLOC(out, Color, n), NULL);
	if (SDL_CLRS_CMP(start.c, end.c) || 1UL == n)
	{
		while (n > ++i)
			out[i] = start;
		return (out);
	}
	*out = start;
	step = (FColor){start.c.r, start.c.g, start.c.b};
	diff = (FColor){(end.c.r - step.r) / ((float_t)n - 1.0f),
					(end.c.g - step.g) / ((float_t)n - 1.0f),
					(end.c.b - step.b) / ((float_t)n - 1.0f)};
	while (n > ++i)
	{
		step = (FColor){step.r + diff.r, step.g + diff.g, step.b + diff.b};
		out[i].c = (t_clr){INRANGE(step.r), INRANGE(step.g), INRANGE(step.b)};
	}
	return (out);
}
