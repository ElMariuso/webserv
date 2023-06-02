/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HTTPServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:36:01 by root              #+#    #+#             */
/*   Updated: 2023/06/02 13:37:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HTTPServer.hpp"

/* Constructor */
HTTPServer::HTTPServer() {}

HTTPServer::HTTPServer(std::string path): ConfigParser(path)
{

}

/* Destructor */
HTTPServer::~HTTPServer() {}