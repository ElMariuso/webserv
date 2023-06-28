/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:44:23 by root              #+#    #+#             */
/*   Updated: 2023/06/21 12:52:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

/* Includes ***************************************************************** */

# include <cstddef>

/* Class ******************************************************************** */

class Utils
{
    /* Member functions ********************************************************* */
    public:
        static void ft_memset(void *ptr, int value, size_t num);
        static void ft_memcpy(void *dest, const void *src, size_t num);
};

#endif