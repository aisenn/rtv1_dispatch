/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecnorm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:30:18 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/08 15:30:19 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

void		ft_vecnorm(t_vec *vec)
{
	double	n;

	n = 1.0 / ft_veclength(*vec);
	vec->x *= n;
	vec->y *= n;
	vec->z *= n;
}
