
#ifndef _CONFIG_H
#define _CONFIG_H

#include <string>
#include <map>
#include <string>
#include <stdio.h>
#include <list>
#include "Mutex.h"

/*
class ConfigProperty{
public:
	ConfigProperty();

};*/

class ConfigProperties{
public:
	bool	loadFromFile(const std::string file);
	bool	saveToFile(const std::string file);
	void	setProperty(const std::string name,const std::string value,bool bWriteDisk=FALSE);	
	std::string getProperty(const std::string name,const std::string default_="");
	std::list<std::string> getProperyKeys();
	std::map<std::string,std::string>	getProperties();
private:
	swlib::Mutex			_mutex;
	std::string strip(const std::string s);
	std::map<std::string,std::string>	_props;
};



#endif

