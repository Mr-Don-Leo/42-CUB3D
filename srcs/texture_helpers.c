/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:19:15 by mbabayan          #+#    #+#             */
/*   Updated: 2025/05/20 15:20:08 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 * Function to count the number of occurrences of a character in a string
 * Returns the count of occurrences
 */
int	count_chars(const char *str, char character)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == character)
			count++;
		str++;
	}
	return (count);
}

/*
 * Function to split a string into an array based on the color identifier
 * Returns a pointer to the array or NULL on error
 */
char	**color_split(char *s)
{
	int	index;
	int	flag;

	index = 0;
	index = 0;
	flag = 0;
	while (s[index] == ' ')
		index++;
	if (s[index] == 'F' || s[index] == 'C')
	{
		index++;
		while (s[index] == ' ' && flag++)
			index++;
	}
	if (flag != 1)
		return (NULL);
	return (ft_split(s + index, ','));
}

/*
 * Function to set colors in the data struct
 * Returns 0 on success or -1 on error
 */
int	use_atoi(t_data *data, char **colors, char texture)
{
	int	color[3];

	color[0] = ft_atoi(colors[0]);
	color[1] = ft_atoi(colors[1]);
	color[2] = ft_atoi(colors[2]);
	if (color[0] < 0 || color[0] > 255 || color[1] < 0 || color[1] > 255
		|| color[2] < 0 || color[2] > 255)
		return (0);
	if (texture == 'F')
		data->textures.floor = color[0] << 16 | color[1] << 8 | color[2];
	else if (texture == 'C')
		data->textures.ceiling = color[0] << 16 | color[1] << 8 | color[2];
	else
		return (0);
	return (1);
}
