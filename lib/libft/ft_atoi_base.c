/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:34:14 by amura             #+#    #+#             */
/*   Updated: 2024/01/21 17:20:25 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_place(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
}

static int	is_valid(char *base, int *bl)
{
	int	str_l;
	int	i;
	int	j;

	str_l = 0;
	while (base[str_l])
		str_l++;
	*bl = str_l;
	if (str_l == 0 || str_l == 1)
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 7 && base[i] <= 13))
			return (0);
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

int	ft_atoi_base(char *nbr, char *base)
{
	long	r;
	int		s;
	int		base_length;

	s = 1;
	r = 0;
	if (!is_valid(base, &base_length))
		return (0);
	while (*nbr == ' ' || (*nbr >= 7 && *nbr <= 13))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			s = -s;
		nbr++;
	}
	while (get_place(*nbr, base) != -1)
	{
		r *= base_length;
		r += get_place(*nbr, base);
		nbr++;
	}
	return ((int)(r * s));
}
