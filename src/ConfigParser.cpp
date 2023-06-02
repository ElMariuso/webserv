/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:49:55 by root              #+#    #+#             */
/*   Updated: 2023/06/02 14:59:38 by root             ###   ########.fr       */
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
    else if (ret == -2)
        throw (std::runtime_error("Bad configuration format!"));
}

ConfigParser::ConfigParser(std::string path)
{
    int ret;
    
    this->configFile = path;
    ret = this->configParsing();
    if (ret == -1)
        throw (std::runtime_error("Can't open file!"));
    else if (ret == -2)
        throw (std::runtime_error("Bad configuration format!"));
}

/* Destructor */
ConfigParser::~ConfigParser() {}

/* Utils */
int ConfigParser::configParsing()
{
    std::string buffer;
    
    this->initDefaultValues();
    buffer = this->readFile(this->configFile);
    if (buffer == "")
        return (-1);
    if (this->isInRightFormat() == false)
        return (-2);
    return (0);
}

void ConfigParser::initDefaultValues()
{
    /* Port */
    this->port.push_back(80);
    /* Host */
    this->host = "localhost";
    /* Default Server */
    this->defaultServer = "";
    /* Error Page */
    this->errorPage = "error.html";
    /* Max Request Body Size */
    this->maxRequestBodySize = 1048576;
    /* Allowed Methods */
    this->allowedMethods.push_back("POST");
    this->allowedMethods.push_back("GET");
    /* Redirection */
    this->redirection = "";
    /* Root Directory */
    this->rootDirectory = "./site/";
    /* Enable Directory Listing */
    this->enableDirectoryListing = false;
    /* Default File */
    this->defaultFile = "index.html";
    /* CGI Extension */
    this->cgiExtension = "";
    /* CGI Path */
    this->cgiPath = "";
    /* Upload Directory */
    this->uploadDirectory = "./upload/";
}

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

/* Checkers */
bool ConfigParser::isInRightFormat()
{
    return (true);
}

/* Debug */
void ConfigParser::printAll()
{
    std::cout << "Config File: " << this->getConfigFile() << std::endl;
    if (this->getPort().size() == 0)
        std::cout << "[1] - Port: Nothing" << std::endl;
    for (std::size_t i = 0; i < this->getPort().size(); i++)
        std::cout << "[" << i + 1 << "] - Port: " << this->getPort().at(i) << std::endl;
    std::cout << "Host: " << this->getHost() << std::endl;
    if (this->getServerNames().size() == 0)
        std::cout << "[1] - Server Name: Nothing" << std::endl;
    for (std::size_t i = 0; i < this->getServerNames().size(); i++)
        std::cout << "[" << i + 1 << "] - Server Name: " << this->getServerNames().at(i) << std::endl;
    std::cout << "Default Server: " << this->getDefaultServer() << std::endl;
    std::cout << "Error Page: " << this->getErrorPage() << std::endl;
    std::cout << "Max Request Body Size: " << this->getMaxRequestBodySize() << std::endl;
    if (this->getAllowedMethods().size() == 0)
        std::cout << "[1] - Allowed Method: Nothing" << std::endl;
    for (std::size_t i = 0; i < this->getAllowedMethods().size(); i++)
        std::cout << "[" << i + 1 << "] - Allowed Method: " << this->getAllowedMethods().at(i) << std::endl;
    std::cout << "Redirection: " << this->getRedirection() << std::endl;
    std::cout << "Root Directory: " << this->getRootDirectory() << std::endl;
    std::cout << "Enable Directory Listing: " << this->getEnableDirectoryListing() << std::endl;
    std::cout << "Default File: " << this->getDefaultFile() << std::endl;
    std::cout << "CGI Extension: " << this->getCgiExtension() << std::endl;
    std::cout << "CGI Path: " << this->getCgiPath() << std::endl;
    std::cout << "Upload Directory: " << this->getUploadDirectory() << std::endl;
}

/* Getters */
std::string ConfigParser::getConfigFile() { return (this->configFile); }
std::vector<int> ConfigParser::getPort() { return (this->port); }
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