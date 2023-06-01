/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:49:55 by root              #+#    #+#             */
/*   Updated: 2023/06/01 18:09:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ConfigParser.hpp"

 /* Constructor */
ConfigParser::ConfigParser() {}

/* Destructor */
ConfigParser::~ConfigParser() {}

/* Getters */
std::string ConfigParser::getConfigFile() { return (this->configFile); }
int ConfigParser::getPort() { return (this->port); }
std::string ConfigParser::getHost() { return (this->host); }
std::vector<std::string> ConfigParser::getServerNames() { return (this->serverNames); }
std::string ConfigParser::getDefaultServer() { return (this->defaultServer); }
std::string ConfigParser::getErrorPage() { return (this->errorPage); }
int ConfigParser::getMaxRequestBodySize() { return (this->maxRequestBodySize); }
std::vector<std::string> ConfigParser::getAllowedMethods() { return (this->allowedMethods); }
std::string ConfigParser::getRedirection() { return (this->redirection); }
std::string ConfigParser::getRootDirectory() { return (this->rootDirectory); }
bool ConfigParser::getEnableDirectoryListing() { return (this->enableDirectoryListing); }
std::string ConfigParser::getDefaultFile() { return (this->defaultFile); }
std::string ConfigParser::getCgiExtension() { return (this->cgiExtension); }
std::string ConfigParser::getCgiPath() { return (this->cgiPath); }
std::string ConfigParser::getUploadDirectory() { return (this->uploadDirectory); }