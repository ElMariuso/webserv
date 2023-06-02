/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:46:59 by root              #+#    #+#             */
/*   Updated: 2023/06/02 13:55:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGPARSER_HPP
# define CONFIGPARSER_HPP

/* Includes ***************************************************************** */

# include <iostream>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include <vector>

/* Class ******************************************************************** */

class ConfigParser
{
    /* Member functions ********************************************************* */
    public:
        /* Constructor */
        ConfigParser();
        ConfigParser(std::string path);

        /* Destructor */
        ~ConfigParser();

        /* Utils */
        int                         configParsing();
        std::string                 readFile(std::string path);

        /* Getters */
        std::string                 getConfigFile();
        int                         getPort();
        std::string                 getHost();
        std::vector<std::string>    getServerNames();
        std::string                 getDefaultServer();
        std::string                 getErrorPage();
        int                         getMaxRequestBodySize();
        std::vector<std::string>    getAllowedMethods();
        std::string                 getRedirection();
        std::string                 getRootDirectory();
        bool                        getEnableDirectoryListing();
        std::string                 getDefaultFile();
        std::string                 getCgiExtension();
        std::string                 getCgiPath();
        std::string                 getUploadDirectory();

    /* Attributes *************************************************************** */
    protected:
        std::string                 configFile;
        int                         port;
        std::string                 host;
        std::vector<std::string>    serverNames;
        std::string                 defaultServer;
        std::string                 errorPage;
        int                         maxRequestBodySize;
        std::vector<std::string>    allowedMethods;
        std::string                 redirection;
        std::string                 rootDirectory;
        bool                        enableDirectoryListing;
        std::string                 defaultFile;
        std::string                 cgiExtension;
        std::string                 cgiPath;
        std::string                 uploadDirectory;
};

#endif