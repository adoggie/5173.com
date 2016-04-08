// distsign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <vector>


#define IDHEADER "Vendor:"
int MAX_ID_LEN=20;

int _tmain(int argc, _TCHAR* argv[])
{
	FILE * fp = fopen(argv[2],"rb");
	int filesize;
	fseek(fp,0,SEEK_END);
	filesize = ftell(fp);
	fseek(fp,0,SEEK_SET);
	std::vector<unsigned char> bytes;
	fread(&bytes[0],bytes.size(),1,fp);
	
	int pos;
	
	
	
	if(argv[1] == std::string("print")){
	
	}else if(argv[1] == std::string("write")){
		
	}
	
	fclose(fp);
	return 0;
}

