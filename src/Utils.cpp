/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:45:49 by root              #+#    #+#             */
/*   Updated: 2023/06/21 12:54:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

void Utils::ft_memset(void  *ptr, int value, size_t num)
{
    unsigned char* byte_ptr = static_cast<unsigned char*>(ptr);

    for (std::size_t i = 0; i < num; ++i)
    {
        byte_ptr[i] = static_cast<unsigned char>(value);
    }
}

void Utils::ft_memcpy(void *dest, const void *src, size_t num)
{
    const char *src_ptr = static_cast<const char*>(src);
    char *dest_ptr = static_cast<char*>(dest);

    for (std::size_t i = 0; i < num; ++i)
    {
        dest_ptr[i] = src_ptr[i];
    }
}