/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConf.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:59:21 by bvernimm          #+#    #+#             */
/*   Updated: 2023/06/21 10:29:43 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERCONF_HPP
# define SERVERCONF_HPP

/* Includes ***************************************************************** */

# include <iostream>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include <vector>

# include <cstdlib>
# include <cctype>
# include "Routes.hpp"

/* Class ******************************************************************** */

class ServerConf
{
    /* Member functions ********************************************************* */
    public:
        /* Constructor */
        ServerConf();

        /* Destructor */
        ~ServerConf();

		/* Assign values */
		void						getValuesFrom(std::string file);
		void						get_all_routes(std::string file, int start);
		int							get_int_value(std::string attribute, std::string file);
		std::vector<int>			get_multiple_int_value(std::string attribute, std::string file);
		std::string					get_string_value(std::string attribute, std::string file);
		std::vector<std::string>	get_multiple_string_value(std::string attribute, std::string file);
		std::string					giveDefaultValue(std::string attribute);

        /* Debug */
        void                        printAll();

        /* Getters */
        std::vector<int>            getPort();
        std::string                 getHost();
        std::vector<std::string>    getServerNames();
        std::string                 getDefaultServer();
        std::vector<std::string>    getErrorPage();
        int                         getMaxRequestBodySize();
		
		std::vector<Routes>			getRoute();
        // std::vector<std::string>    getAllowedMethods();
        // std::string                 getRedirection();
        // std::string                 getRootDirectory();
        // bool                        getEnableDirectoryListing();
        // std::string                 getDefaultFile();
        // std::string                 getCgiExtension();
        // std::string                 getCgiPath();
        // std::string                 getUploadDirectory();

    /* Attributes *************************************************************** */
    protected:
        std::vector<int>            port;
        std::string                 host;
        std::vector<std::string>    serverNames;
        std::string                 defaultServer;
        std::vector<std::string>	errorPage;
        int                         maxRequestBodySize;

		std::vector<Routes>			routes;
        // std::vector<std::string>    allowedMethods;
        // std::string                 redirection;
        // std::string                 rootDirectory;
        // bool                        enableDirectoryListing;
        // std::string                 defaultFile;
        // std::string                 cgiExtension;
        // std::string                 cgiPath;
        // std::string                 uploadDirectory;
};

#endif