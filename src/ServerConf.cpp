#include "../include/ServerConf.hpp"

/* Constructor */
ServerConf::ServerConf() {}

/* Destructor */
ServerConf::~ServerConf() {}

/* Read file */

void ServerConf::getValuesFrom(std::string file)
{
	/* Port */
	this->port = get_multiple_int_value("port", file);
    /* Host */
	this->host = get_string_value("host", file);
	/* serverNames */
	this->serverNames = get_multiple_string_value("server_name", file);
    /* Default Server */
    this->defaultServer = get_string_value("defaultServer", file);
    /* Error Page */
	this->errorPage = get_multiple_string_value("error_page", file);
    /* Max Request Body Size */
    this->maxRequestBodySize = get_int_value("client_body_limit", file);
	/* Routes */
	get_all_routes(file, 0);
}

void ServerConf::get_all_routes(std::string file, int start)
{
	std::size_t	found;
	std::string routeBlock;
	Routes		newRoute;

	found = file.find("location {", start);
	if (found == std::string::npos && start == 0)
	{
		newRoute.getDefaultRoutes();
		this->routes.push_back(newRoute);
	}
	if (found == std::string::npos)
		return ;
	found = found + 10;
	while (file[found] && file[found] != '}')
	{
		routeBlock.push_back(file[found]);
		found++;
	}
	newRoute.getRouteFrom(routeBlock);
	this->routes.push_back(newRoute);
	get_all_routes(file, found);
}

/* int */

int ServerConf::get_int_value(std::string attribute, std::string file)
{
	std::size_t	found;
	std::string	error;
	std::string	nb;

	found = file.find(attribute);
	error = "Missing value or incorrect writing for attribute : " + attribute;
	if (found == std::string::npos)
		return (std::atoi(giveDefaultValue(attribute).c_str()));
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
		nb.push_back(file[found]);
		found++;
	}
	if (file[found] != '"')
		throw (std::runtime_error(error));
	return (std::atoi(nb.c_str()));
}

std::vector<int> ServerConf::get_multiple_int_value(std::string attribute, std::string file)
{
	std::size_t	found;
	std::string	error;
	std::string	nb;
	std::vector<int> nbVector;

	found = file.find(attribute);
	error = "Missing value or incorrect writing for attribute : " + attribute;
	if (found == std::string::npos)
		nbVector.push_back(std::atoi(giveDefaultValue(attribute).c_str()));
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
			nb.push_back(file[found]);
			found++;
		}
		if (file[found] != '"')
			throw (std::runtime_error(error));
		nbVector.push_back(std::atoi(nb.c_str()));
		nb = "";
		found = file.find(attribute, found);
	}
	return (nbVector);
}

/* String */

std::string ServerConf::get_string_value(std::string attribute, std::string file)
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
		str.push_back(file[found]);
		found++;
	}
	if (file[found] != '"')
		throw (std::runtime_error(error));
	return (str);
}

std::vector<std::string> ServerConf::get_multiple_string_value(std::string attribute, std::string file)
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

/* Default */

std::string ServerConf::giveDefaultValue(std::string attribute)
{
	if (attribute == "port")
		return ("80");
	if (attribute == "host")
		return ("localhost");
	if (attribute == "serverNames")
		return ("Default server name");
	if (attribute == "defaultServer")
		return ("");
	if (attribute == "errorPage")
		return ("error.html");
	if (attribute == "maxRequestBodySize")
		return ("1048576");
	if (attribute == "allowedMethods")
		return ("GET");
	if (attribute == "redirection")
		return ("");
	if (attribute == "rootDirectory")
		return ("./site/");
	if (attribute == "defaultFile")
		return ("index.html");
	if (attribute == "cgiExtension")
		return ("");
	if (attribute == "cgiPath")
		return ("");
	if (attribute == "uploadDirectory")
		return ("./upload/");
	return ("");
}


/* Debug */
void ServerConf::printAll()
{
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
	if (this->getErrorPage().size() == 0)
        std::cout << "[1] - Error Page: Nothing" << std::endl;
	for (std::size_t i = 0; i < this->getErrorPage().size(); i++)
        std::cout << "[" << i + 1 << "] - Error Page: " << this->getErrorPage().at(i) << std::endl;
    std::cout << "Max Request Body Size: " << this->getMaxRequestBodySize() << std::endl;
	if (this->getRoute().size() == 0)
        std::cout << "[1] - Route: Nothing" << std::endl;
	for (std::size_t i = 0; i < this->getRoute().size(); i++)
	{
		std::cout << "[" << i + 1 << "] - Route:";
		this->getRoute().at(i).printAll();
		std::cout << std::endl;
	}
}

/* Getters */
std::vector<int>			ServerConf::getPort() { return (this->port); }
std::string					ServerConf::getHost() { return (this->host); }
std::vector<std::string>	ServerConf::getServerNames() { return (this->serverNames); }
std::string					ServerConf::getDefaultServer() { return (this->defaultServer); }
std::vector<std::string>	ServerConf::getErrorPage() { return (this->errorPage); }
int							ServerConf::getMaxRequestBodySize() { return (this->maxRequestBodySize); }
std::vector<Routes>			ServerConf::getRoute() { return (this->routes); }