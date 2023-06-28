/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Routes.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:08:15 by bvernimm          #+#    #+#             */
/*   Updated: 2023/06/26 13:10:46 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Routes.hpp"

/* Constructor */
Routes::Routes() {}

/* Destructor */
Routes::~Routes() {}

/* Read file */

void Routes::getRouteFrom(std::string file)
{
	/* route */
	this->route = get_string_value("route", file);
	/* Allowed Methods */
	this->allowedMethods = get_multiple_string_value("allowed_methods", file);
    /* Redirection */
    this->redirection = get_string_value("redirection", file);
    /* Root Directory */
    this->rootDirectory = get_string_value("root_directory", file);
    /* Enable Directory Listing */
    this->enableDirectoryListing = get_bool_value("directory_listing", file);
	/* Default File */
    this->defaultFile = get_string_value("default_file", file);
    /* CGI Extension */
    this->cgiExtension = get_string_value("cgi_extension", file);
    /* CGI Path */
    this->cgiPath = get_string_value("cgi_path", file);
    /* Upload Directory */
    this->uploadDirectory = get_string_value("upload_directory", file);
}

void Routes::getDefaultRoutes()
{
	/* route */
	this->route = "";
	/* Allowed Methods */
	this->allowedMethods.push_back("");
    /* Redirection */
    this->redirection = "";
    /* Root Directory */
    this->rootDirectory = "";
    /* Enable Directory Listing */
    this->enableDirectoryListing = false;
	/* Default File */
    this->defaultFile = "";
    /* CGI Extension */
    this->cgiExtension = "";
    /* CGI Path */
    this->cgiPath = "";
    /* Upload Directory */
    this->uploadDirectory = "";
}

std::string Routes::giveDefaultValue(std::string attribute)
{
	if (attribute == "route")
		throw (std::runtime_error("no value for parameter 'route'"));
	if (attribute == "allowed_methods")
		return ("GET");
	if (attribute == "redirection")
		return ("");
	if (attribute == "root_directory")
		return ("");
	if (attribute == "default_file")
		return ("");
	if (attribute == "cgi_extension")
		return ("");
	if (attribute == "cgi_path")
		return ("");
	if (attribute == "upload_directory")
		return ("");
	return ("");
}

/* get values */

bool Routes::get_bool_value(std::string attribute, std::string file)
{
	std::size_t	found;
	std::string	error;
	std::string	str;

	found = file.find(attribute);
	error = "Missing value or incorrect writing for attribute : " + attribute;
	if (found == std::string::npos)
		return (false);
	found = found + attribute.length();
	while(file[found] && file[found] != '"')
	{
		if (file[found] != ' ')
			throw (std::runtime_error(error));
		found++;
	}
	if (!file[found])
		throw (std::runtime_error(error));
	found++;
	while(file[found] && file[found] != '"')
	{
		if (file[found] == '\n')
			throw (std::runtime_error(error));
		str.push_back(file[found]);
		found++;
	}
	if (file[found] != '"')
		throw (std::runtime_error(error));
	if (str == "true")
		return (true);
	return (false);
}

std::string Routes::get_string_value(std::string attribute, std::string file)
{
	std::size_t	found;
	std::string	error;
	std::string	str;

	found = file.find(attribute);
	error = "Missing value or incorrect writing for attribute : " + attribute;
	if (found == std::string::npos)
		return (giveDefaultValue(attribute));
	found = found + attribute.length();
	while(file[found] && file[found] != '"')
	{
		if (file[found] != ' ')
			throw (std::runtime_error(error));
		found++;
	}
	if (!file[found])
		throw (std::runtime_error(error));
	found++;
	while(file[found] && file[found] != '"')
	{
		if (file[found] == '\n')
			throw (std::runtime_error(error));
		str.push_back(file[found]);
		found++;
	}
	if (file[found] != '"')
		throw (std::runtime_error(error));
	return (str);
}

std::vector<std::string> Routes::get_multiple_string_value(std::string attribute, std::string file)
{
	std::size_t	found;
	std::string	error;
	std::string	str;
	std::vector<std::string> strVector;

	found = file.find(attribute);
	error = "Missing value or incorrect writing for attribute : " + attribute;
	if (found == std::string::npos)
		strVector.push_back(giveDefaultValue(attribute));
	while (found != std::string::npos)
	{
		found = found + attribute.length();
		while(file[found] && file[found] != '"')
		{
			if (file[found] != ' ')
				throw (std::runtime_error(error));
			found++;
		}
		if (!file[found])
			throw (std::runtime_error(error));
		found++;
		while(file[found] && file[found] != '"')
		{
			if (file[found] == '\n')
				throw (std::runtime_error(error));
			str.push_back(file[found]);
			found++;
		}
		if (file[found] != '"')
			throw (std::runtime_error(error));
		strVector.push_back(str);
		str = "";
		found = file.find(attribute, found);
	}
	return (strVector);
}

/* Debug */

void Routes::printAll()
{
	std::cout << " " << this->getRoute() << std::endl;
	if (this->getAllowedMethods().size() == 0)
        std::cout << "[1] - Allowed Method: Nothing" << std::endl;
    for (std::size_t i = 0; i < this->getAllowedMethods().size(); i++)
        std::cout << "[" << i + 1 << "] - Allowed Method: " << this->getAllowedMethods().at(i) << std::endl;
    std::cout << "Redirection: " << this->getRedirection() << std::endl;
    std::cout << "Root Directory: " << this->getRootDirectory() << std::endl;
    if (this->getEnableDirectoryListing() == 0)
		std::cout << "Enable Directory Listing: false" << std::endl;
	else
		std::cout << "Enable Directory Listing: true" << std::endl;
	std::cout << "Default File: " << this->getDefaultFile() << std::endl;
    std::cout << "CGI Extension: " << this->getCgiExtension() << std::endl;
    std::cout << "CGI Path: " << this->getCgiPath() << std::endl;
    std::cout << "Upload Directory: " << this->getUploadDirectory() << std::endl;
}

/* Getters */

std::string					Routes::getRoute() { return (this->route); }
std::vector<std::string>	Routes::getAllowedMethods() { return (this->allowedMethods); }
std::string					Routes::getRedirection() { return (this->redirection); }
std::string					Routes::getRootDirectory() { return (this->rootDirectory); }
bool						Routes::getEnableDirectoryListing() { return (this->enableDirectoryListing); }
std::string 				Routes::getDefaultFile() { return (this->defaultFile); }
std::string					Routes::getCgiExtension() { return (this->cgiExtension); }
std::string 				Routes::getCgiPath() { return (this->cgiPath); }
std::string					Routes::getUploadDirectory() { return (this->uploadDirectory); }