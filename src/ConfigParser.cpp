/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:49:55 by root              #+#    #+#             */
/*   Updated: 2023/06/02 13:57:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ConfigParser.hpp"

/* Constructor */
ConfigParser::ConfigParser() 
{
    int ret;
    
    this->configFile = "config/default.conf";
    ret = this->configParsing();
    if (ret == -1)
        throw (std::runtime_error("Can't open file!"));
}

ConfigParser::ConfigParser(std::string path)
{
    int ret;
    
    this->configFile = path;
    ret = this->configParsing();
    if (ret == -1)
        throw (std::runtime_error("Can't open file!"));
}

/* Destructor */
ConfigParser::~ConfigParser() {}

/* Utils */
std::string ConfigParser::readFile(std::string path)
{
    std::string         buffer;
    std::ostringstream  o_buffer;
    std::ifstream       file(path.c_str());

    if (file)
    {
        o_buffer << file.rdbuf();
        buffer = o_buffer.str();
        file.close();
    }
    else
        return ("");
    return (buffer);
}

int ConfigParser::configParsing()
{
    std::string buffer;
    
    buffer = this->readFile(this->configFile);
    if (buffer == "")
        return (-1);
    std::cout << buffer << std::endl;
    return (0);
}

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