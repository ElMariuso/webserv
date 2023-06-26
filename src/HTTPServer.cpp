/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HTTPServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:36:01 by root              #+#    #+#             */
/*   Updated: 2023/06/26 15:16:53 by root             ###   ########.fr       */
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
    if (ret != 0)
        throw (std::runtime_error(this->errorMessage(1, ret)));
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
    if (ret != 0)
        throw (std::runtime_error(this->errorMessage(1, ret)));
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

    Utils::ft_memset((char *)&ret, 0, sizeof(ret));
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
    int                 max_sd;
    int                 rc;
    int                 error;
    fd_set              master_set;
    fd_set              working_set;
    struct sockaddr_in  client_addr;
    socklen_t           addr_len;
    int                 new_socket;
    
    FD_ZERO(&master_set);
    max_sd = this->sockets[0].fd;
    FD_SET(this->sockets[0].fd, &master_set);
    do
    {
        Utils::ft_memcpy(&working_set, &master_set, sizeof(master_set));
        std::cout << "Waiting on select()..." << std::endl;
        rc = select(max_sd + 1, &working_set, NULL, NULL, NULL);
        if (rc < 0)
        {
            error = errno;
            return (error);
        }
        for (int i = 0; i <= max_sd; ++i)
        {
            if (FD_ISSET(i, &working_set))
            {
                if (i == this->sockets[0].fd)
                {
                    addr_len = sizeof(client_addr);
                    new_socket = accept(i, (struct sockaddr *)&client_addr, &addr_len);
                    if (new_socket < 0)
                    {
                        error = errno;
                        return (error);
                    }
                    FD_SET(new_socket, &master_set);
                    if (new_socket > max_sd)
                        max_sd = new_socket;
                    std::cout << "New connexion accepted. Socket FD: " << new_socket << std::endl;
                }
                else
                {
                    char buffer[1024];
                    int bytes_read = read(i, buffer, sizeof(buffer));
                    if (bytes_read > 0)
                    {
                        std::string request(buffer, bytes_read);
                        std::cout << "Received request:" << std::endl << request << std::endl;

                        std::string response = "HTTP/1.1 200 0K\r\n"
                                                "Content-Type: text/plain\r\n"
                                                "\r\n"
                                                "Hello, world!";

                        write(i, response.c_str(), response.size());
                    }
                    close(i);
                    FD_CLR(i, &master_set);
                    std::cout << "Connection closed. Socket FD: " << i << std::endl;
                }
            }
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