/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 10:39:50 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/08 16:21:23 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_printf
{
	char		*format;
	char		*f_tmp;
	char		*output;
	char		*o_tmp;
	va_list		ap;
	int			rv;
	int			rv_tmp;
	int			flag_align_left;
	int			flag_zero;
	int			field;
	int			precision;
	char		conversion;
}				t_printf;

/*
**ft_printf.c
*/
int				ft_printf(const char *format, ...);
int				read_format(t_printf *p_t);
int				parse_format(t_printf *p_t);
int				set_tmp(t_printf *p_t);
/*
**parse.c
*/
int				parse_flag(t_printf *p_t);
int				parse_flag_exception (t_printf *p_t);
int				parse_field_width(t_printf *p_t);
int				parse_precision(t_printf *p_t);
int				parse_conversion(t_printf *p_t);
/*
**utils_init.c
*/
void			init_t_printf(t_printf *p_t);
void			init_flags(t_printf *p_t);
/*
**utils_toa.c
*/
int				a_base_len(unsigned int num, unsigned int base);
char			*utoa_base_low(unsigned int num, unsigned int base);
char			*utoa_base_up(unsigned int num, unsigned int base);
/*
**utils_padding.c
*/
int				pad_letter(int start, int end, char c, t_printf *p_t);
int				pad_str(int start, int end, char *str, t_printf *p_t);
int				pad_u_c(int start, int end, unsigned char c, t_printf *p_t);
/*
**utils_free.c
*/
int				free_t_printf(t_printf *p_t, int rv);
char			*free_strjoin(char *str1, char *str2);
char			*free_join_output(t_printf *p_t);
/*
**output_c.c
*/
int				set_c(unsigned char c, t_printf *p_t);
int				set_len_c(t_printf *p_t);
int				set_c_inside(unsigned char c, int len, t_printf *p_t);
/*
**output_s.c
*/
int				set_s(char *s, t_printf *p_t);
int				set_len_s(int s_len, t_printf *p_t);
int				set_s_inside(char *s, int s_len, int len, t_printf *p_t);
/*
**output_per.c
*/
int				set_per(t_printf *p_t);
/*
**output_p.c
*/
int				set_p(void *p, t_printf *p_t);
int				set_len_p(int p_len, t_printf *p_t);
int				set_p_inside(char *str_p, int p_len, int len, t_printf *p_t);
/*
**output_d.c
*/
int				set_d(int d, t_printf *p_t);
int				set_str_d(int d, char **p_str_d, t_printf *p_t);
int				set_len_d(int d, int d_len, t_printf *p_t);
int				set_d_inside_plus(char *str_d, int d_len,
									int len, t_printf *p_t);
int				set_d_inside_minus(char *str_d, int d_len,
									int len, t_printf *p_t);
/*
**output_uxX.c
*/
int				set_u(unsigned int u, char cs, t_printf *p_t);
int				set_str_u(unsigned int u, char cs, char **p_str_u, t_printf *p_t);
int				set_len_u(int u_len, t_printf *p_t);
int				set_u_inside(char *str_u, int u_len, int len, t_printf *p_t);

#endif
