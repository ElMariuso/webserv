/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HTTPServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:36:01 by root              #+#    #+#             */
/*   Updated: 2023/06/08 00:56:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HTTPServer.hpp"

/* Constructor */
HTTPServer::HTTPServer(): ConfigParser()
{
    int         ret;
    std::string error_message;

    for (std::size_t i = 0; i != this->port.size(); ++i)
    {
        ret = this->setup(i);
        if (ret != 0)
            throw (std::runtime_error(this->errorMessage(1, ret)));
    }
    ret = this->process();
}

HTTPServer::HTTPServer(std::string path): ConfigParser(path)
{
    int         ret;
    std::string error_message;

    ret = 0;
    for (std::size_t i = 0; i != this->port.size(); ++i)
    {
        ret = this->setup(i);
        if (ret != 0)
            throw (std::runtime_error(this->errorMessage(1, ret)));
    }
    ret = this->process();
}

/* Destructor */
HTTPServer::~HTTPServer() {}

/* Utils */
int HTTPServer::setup(int index)
{
    t_socket    new_elem;
    int         error;

    new_elem.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (new_elem.fd < 0)
    {
        error = errno;
        return (error);
    }
    new_elem.addr = this->setDefaultAddr(index);
    if (bind(new_elem.fd, (struct sockaddr *)&new_elem.addr, sizeof(new_elem.addr)) < 0)
    {
        error = errno;
        return (error);
    }
    if (listen(new_elem.fd, SOMAXCONN) < 0)
    {
        error = errno;
        return (error);
    }
    this->sockets.push_back(new_elem);
    return (0);
}

struct sockaddr_in HTTPServer::setDefaultAddr(int index)
{
    struct sockaddr_in  ret;

    memset((char *)&ret, 0, sizeof(ret));
    ret.sin_family = AF_INET;
    ret.sin_port = htons(this->port[index]);
    if (this->host == "localhost")
       ret.sin_addr.s_addr = INADDR_ANY;
    // else
    //     ret.sin_addr.s_addr = NULL; 
    return (ret);
}

int HTTPServer::process()
{
    int     max_sd;
    int     rc;
    int     error;
    fd_set  master_set;
    fd_set  working_set;
    
    FD_ZERO(&master_set);
    max_sd = this->sockets[0].fd;
    FD_SET(this->sockets[0].fd, &master_set);
    do
    {
        memcpy(&working_set, &master_set, sizeof(master_set));
        std::cout << "Waiting on select()..." << std::endl;
        rc = select(max_sd + 1, &working_set, NULL, NULL, NULL);
        if (rc < 0)
        {
            error = errno;
            return (error);
        }
    }
    while (true);
    return (0);   
}

/* Error */
std::string HTTPServer::errorMessage(int error, int errnoValue)
{
    if (error == 1)
        return ("During setting up server: " + std::string(strerror(errnoValue)));
    return ("");
}

/* Getters */
std::vector<t_socket> HTTPServer::getSockets() { return (this->sockets); }