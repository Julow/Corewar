/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:04:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/11 17:08:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** Reverse the bytes of a 32 bits value
*/
#define B16_REV(B)	((((B)&0xFF) << 8) | (((B)>> 8) & 0xFF))
#define B32_REV(B)	(_B32_REV_L(B) | _B32_REV_R(B))

/*
** -
*/

#define _B32_REV_L(B)	((((B)&0xFF) << 24) | (((B)&0xFF00) << 8))
#define _B32_REV_R(B)	((((B)>>8) & 0xFF00) | (((B)>> 24) & 0xFF))

#endif
