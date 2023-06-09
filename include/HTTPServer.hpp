/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HTTPServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:47:13 by root              #+#    #+#             */
/*   Updated: 2023/06/26 15:15:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPSERVER_HPP
# define HTTPSERVER_HPP

/* Includes ***************************************************************** */

# include <iostream>
# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <cstring>
# include <unistd.h>

/* Includes.hpp ************************************************************* */

# include "ConfigParser.hpp"
# include "Utils.hpp"

/* Structure **************************************************************** */

typedef struct s_socket
{
    int                 fd;
    struct sockaddr_in  addr;
}   t_socket;

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

        /* Utils */
        int                     setup(int index);
        struct sockaddr_in      setDefaultAddr(int index);
        int                     process();

        /* Error */
        std::string             errorMessage(int error, int errnoValue);

        /* Getters */
        std::vector<t_socket>   getSockets();

    /* Attributes *************************************************************** */
    private:
        std::vector<t_socket>   sockets;
};

#endif