/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:49:55 by root              #+#    #+#             */
/*   Updated: 2023/06/13 13:01:37 by bvernimm         ###   ########.fr       */
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
    
    buffer = this->readFile(this->configFile);
    if (buffer == "")
        return (-1);
	//std::cout << "\n" << buffer << "\n" << std::endl;
    // if (this->isInRightFormat() == false)
    //     return (-2);
	get_value_from_file(buffer, 0);
    return (0);
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

/* Read file */

void ConfigParser::get_value_from_file(std::string file, int start)
{
	std::size_t	found;
	std::string serverBlock;
	int			bracketLevel;
	ServerConf	newServer;
	
	found = file.find("server {", start);
	if (found == std::string::npos && start == 0)
		throw (std::runtime_error("No valid server block found"));
	else if (found == std::string::npos && start != 0)
		return ;
	bracketLevel = 1;
	found = found + 8;
	while (file[found] && bracketLevel > 0)
	{
		serverBlock.push_back(file[found]);
		if (file[found] == '{')
			bracketLevel++;
		else if (file[found] == '}')
			bracketLevel--;
		found++;
	}
	newServer.getValuesFrom(serverBlock);
	this->serverData.push_back(newServer);
	get_value_from_file(file, found);
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
	std::cout << std::endl;
	
	std::cout << "Server : " << std::endl;
	serverData[0].printAll();
	std::cout << std::endl;
	
	std::cout << "Server : " << std::endl;
	serverData[1].printAll();
	std::cout << std::endl;
	// for (int i = 0; serverData[i]; i++)
	// {
	// 	std::cout << "Server : " << std::endl;
	// 	serverData[i].printAll();
	// 	std::cout << std::endl;
	// }
}

/* Getters */
std::string ConfigParser::getConfigFile() { return (this->configFile); }