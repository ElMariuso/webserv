/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Routes.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:59:27 by bvernimm          #+#    #+#             */
/*   Updated: 2023/06/22 10:07:34 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTES_HPP
# define ROUTES_HPP

/* Includes ***************************************************************** */

# include <iostream>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include <vector>

# include <cstdlib>
# include <cctype>

/* Class ******************************************************************** */

class Routes
{
    /* Member functions ********************************************************* */
    public:
        /* Constructor */
        Routes();

        /* Destructor */
        ~Routes();

		/* Assign values */
		void						getRouteFrom(std::string file);
		void						getDefaultRoutes();
		bool						get_bool_value(std::string attribute, std::string file);
		std::string					get_string_value(std::string attribute, std::string file);
		std::vector<std::string>	get_multiple_string_value(std::string attribute, std::string file);
		std::string					giveDefaultValue(std::string attribute);

        /* Debug */
        void                        printAll();

        /* Getters */
		std::string                 getRoute();
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
		std::string                 route;
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