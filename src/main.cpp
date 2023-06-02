/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:08:11 by root              #+#    #+#             */
/*   Updated: 2023/06/02 12:38:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HTTPServer.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    try
    {
        if (argc < 2)
            throw (std::runtime_error("Not enough arguments."));
        else if (argc > 2)
            throw (std::runtime_error("Too many arguments."));
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}