/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HTTPServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:47:13 by root              #+#    #+#             */
/*   Updated: 2023/06/02 13:35:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPSERVER_HPP
# define HTTPSERVER_HPP

/* Includes ***************************************************************** */

# include <iostream>

/* Includes.hpp ************************************************************* */

# include "ConfigParser.hpp"

/* Class ******************************************************************** */

class HTTPServer: public ConfigParser
{
    /* Member functions ********************************************************* */
    public:
        /* Constructor */
        HTTPServer();
        HTTPServer(std::string path);

        /* Destructor */
        ~HTTPServer();

    /* Attributes *************************************************************** */
    private:
};

#endif