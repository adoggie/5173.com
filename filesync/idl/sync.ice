
#ifndef _SYNC_ICE
#define _SYNC_ICE


module games {

dictionary<string,string>	HashValueSet;
dictionary<string,string>	ReturnValueT;
sequence<byte> 				StreamDataT;
sequence<string>			StringListT;
sequence<HashValueSet>	HashValueListT;
sequence<int>					IntListT;
sequence<StringListT>	StringListListT;


interface IService{
	void		invokeOneway(HashValueSet value,StreamDataT stream);
	string	getSequence();
	string	getType();	 		// das ,cmc,
	string	getId();				//service module id
	int 	getTimestamp();		//获取系统时钟  1970之后秒数
  string getVersion();	  //系统版本 2009.12.27
};


struct FileEntryT{
	string	filename;	//文件不能携带远端的存储路径
	int 		size;
	int 		timestamp;
	string 	digest;
};
sequence<FileEntryT>	FileEntryListT;


interface ISyncEndpoint extends IService{
	/***************************************************
		@methond: getFileDescList()
		@params:  读取指定目录文件描述信息
		@return: 
			{'succ':true/false,'errmsg':xxx}
	****************************************************/
	FileEntryListT getFileDescList(string path);
	
	/***************************************************
		@methond: getFileDigest()
		@params:  file - 远程文件名称 
		@return: 
			{'succ':true/false,'errmsg':xxx，'digest':''}
	****************************************************/
	ReturnValueT	getFileDigest(string file);
	/***************************************************
		@methond: Start()
		@params:
				file - 远程文件名称
		@return: 
			{'succ':true/false,'errmsg':xxx}
	****************************************************/
	ReturnValueT 	syncFileStart(string file);
	/***************************************************
		@methond: Data()
		@params: []
		@return: 
			{'succ':true/false,'errmsg':xxx}
	****************************************************/
	ReturnValueT 	syncFileData(string bytes);
	/***************************************************
		@methond: End()
		@params:
		@return: 
			{'succ':true/false,'digest':xxx,'errmsg':xxx}
			完成之后是否计算digest
	****************************************************/
	ReturnValueT 	syncFileEnd();
	
	/***************************************************
		@methond: launchApp()
		@params:
			{'app':'path','param':'xxx'}
		@return: 
			{'succ':true/false,'errmsg':xxx}
			运行进程
	****************************************************/
	ReturnValueT launchApp(HashValueSet params);
	
	/***************************************************
		@methond: deleteFile()
		@params:
			file - 文件名称或者目录 
		@return: 
			{'succ':true/false,'errmsg':xxx}
			运行进程
	****************************************************/
	ReturnValueT	deleteFile(string file);
	
	/***************************************************
		@methond: terminateGame()
			停止游戏运行 
		@params:
			game - 游戏目录名称 (英文)
		@return: 
			{'succ':true/false,'errmsg':xxx}
	****************************************************/
	ReturnValueT	terminateGame(string game);
	
	/***************************************************
		@methond: launchGame()
			加载游戏运行 
		@params:
			game - 游戏目录名称 (英文)
		@return: 
			{'succ':true/false,'errmsg':xxx}
	****************************************************/
	ReturnValueT	launchGame(string game);
	
	/***************************************************
		@methond: executeBatchFile()
			执行远程批处理文件
		@params:
			file - 文件全路径
		@return: 
			{'succ':true/false,'errmsg':xxx}
			运行进程
	****************************************************/
	ReturnValueT executeBatchFile(string file);
	
	/***************************************************
		@methond: killProcessByName()
		停止指定名称的进程
	****************************************************/
	ReturnValueT killProcessByName(string procname);
	
	/***************************************************
		@methond: startUpdate()
		启动endpoint的自我更新
		endpoint应当加载 update.exe ,然后令自己退出
		update.exe的位置在jerray.conf配置
	****************************************************/
	ReturnValueT startUpdate();
  
  //读取远端指定文件数据到本地,适合小文件
  StreamDataT getRemoteFile(string remotefile);
  //读取远端文件信息
  FileEntryT getFileDesc(string remotefile);
  //读取远端文件，offset-偏移位置,size-读取数据大小
  StreamDataT getRemoteFileData(string remotefile,int offset,int size);
  
  //关闭endpoint服务
  void shutdown(); 
  
	
};




};


#endif

