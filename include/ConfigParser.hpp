/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:46:59 by root              #+#    #+#             */
/*   Updated: 2023/06/13 13:06:07 by bvernimm         ###   ########.fr       */
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

# include <cstdlib>
# include <cctype>
# include <stdexcept>
# include "ServerConf.hpp"

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

		/* Read file */
		void						get_value_from_file(std::string file, int start);

        /* Checkers */
        bool                        isInRightFormat();

        /* Debug */
        void                        printAll();

        /* Getters */
        std::string                 getConfigFile();

    /* Attributes *************************************************************** */
    protected:
		std::string				configFile;
        std::vector<ServerConf>	serverData;
};

#endif