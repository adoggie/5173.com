
#include "config.h"
#include "util.h"


bool	ConfigProperties::loadFromFile(const std::string file){
	FILE * pf ;
	_props.clear();
	pf = fopen( file.c_str(),"rb");
	if(!pf)	return false;
	char line[1024];
	while( fgets(line,sizeof(line),pf)){
		std::string s,k,v;
		std::string::size_type index;
		s = line;
		index = s.find('=');
		if( index  == s.npos ){
			continue;
		}
		k.assign( s.begin(),s.begin()+index);
		k = swlib::strip(k);
		if( s.size() != index+1){
			v.assign(s.begin()+index+1,s.end());
		}
		v = swlib::strip(v);
		_props[k] = v;
	}
	fclose(pf);
	return true;
}

bool	ConfigProperties::saveToFile(const std::string file){
	std::map<std::string,std::string>::iterator itr;
	FILE * fp = fopen(file.c_str(),"w");
	if(!fp){
		return false;
	}
	for(itr=_props.begin();itr!=_props.end();itr++){
		std::string s ;
		s = itr->first+"="+itr->second+"\n";
		fwrite(s.c_str(),s.size(),1,fp);
	}
	fclose(fp);	
	return true;
}



void	ConfigProperties::setProperty(const std::string name,const std::string value, bool bWriteDisk){
	swlib::ScopeLocker l(_mutex);
	
	_props[name] = value;

	if(bWriteDisk)
	{
		
		FILE *file = fopen("\\NandFlashPartition\\gtd.conf","r");
		if(file ==NULL) return ;
		fseek(file,0,SEEK_END);
		int nFileLen = ftell(file);
		fseek(file,0,SEEK_SET);
		char *FileBuffer = new char[nFileLen];
		memset(FileBuffer,0,nFileLen);
		fread(FileBuffer,1,nFileLen,file);
		std::string str_content = FileBuffer;
		delete[] FileBuffer;
		int nIndex =str_content.find(name) ;
		if(nIndex != std::string::npos)
		{
			std::string str_first="";
			std::string str_second="";
			std::string str_third="";
			str_first.resize(nIndex);

			str_content.copy((char*)&str_first[0],nIndex,0);


			char *p=&str_content[nIndex];
			while( *p++ !=0x0A && nIndex<nFileLen)
			{
				nIndex++;
			}
			if(nIndex<nFileLen)
			{
				str_second.resize(strlen(&str_content[nIndex+1])+1);//nFileLen-nIndex);

				str_content.copy((char*)&str_second[0], strlen(&str_content[nIndex+1])+1,nIndex);

			}


			str_third = name;
			str_third+="=";
			str_third+=value;


			fclose(file);
			file = fopen("\\NandFlashPartition\\gtd.conf","w");
			fwrite(&str_first[0],1,str_first.size(),file);
			if(str_third.size()>0)
				fwrite(&str_third[0],1,str_third.size(),file);
			fwrite(&str_second[0],1,str_second.size(),file);

		}
		else
		{

			std::string str_new;// ='0x0d';
			str_new.append(1,0x0a);
			str_new +=name;
			str_new +="=";
			str_new +=value;
			file = fopen("\\NandFlashPartition\\gtd.conf","w");
			fwrite(&str_content[0],1,str_content.size(),file);
			fwrite(&str_new[0],1,str_new.size(),file);
		}
		fclose(file);
		
	}
}

std::string ConfigProperties::getProperty(const std::string name,const std::string default_){
	std::string prop;
	swlib::ScopeLocker l(_mutex);
	if( _props.find( name) == _props.end()){
		return default_;
	}
	prop = _props[name];
	return prop;
}

std::list<std::string> ConfigProperties::getProperyKeys(){
	std::list<std::string> keys;
	swlib::ScopeLocker l(_mutex);
	std::map<std::string,std::string>::iterator itr;
	for(itr=_props.begin();itr!=_props.end();itr++){
		keys.push_back( itr->first);
	}
	return keys;
}

std::map<std::string,std::string>	ConfigProperties::getProperties(){
	swlib::ScopeLocker l(_mutex);
	return _props;
}