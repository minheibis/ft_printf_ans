#include "ft_printf.h"

int		set_others(t_printf *p_t)
{
	if(!(p_t->o_tmp = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	p_t->o_tmp[1] = '\0';
	p_t->o_tmp[0] = p_t->conversion;
	p_t->rv_tmp = 1;
	return (0);
}
