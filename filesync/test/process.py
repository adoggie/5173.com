# -*- coding:utf-8 -*-
import os,os.path


def killProcess(name,times):
	import win32com.client
	WMI = win32com.client.GetObject('winmgmts:')
	os_wmi = wmi.WMI()
	for p in os_wmi.Wind32_Process():
		print process

def check_exsit(process_name):
	import win32com.client
	WMI = win32com.client.GetObject('winmgmts:')
	#processCodeCov = WMI.ExecQuery('select * from Win32_Process where Name="%s"' % process_name)
	processCodeCov = WMI.ExecQuery("select * from Win32_Process ")
	for n in processCodeCov:
		print n.ProcessId,n.Name
		
import win32process,win32api,win32con

def test2():
	allPIDs = win32process.EnumProcesses()
	for PID in allPIDs:
		try:
			hProcess = win32api.OpenProcess(win32con.PROCESS_ALL_ACCESS, False, PID)
			hProcessFirstModule = win32process.EnumProcessModules(hProcess)[0]
			currentprocessname = os.path.split(win32process.GetModuleFileNameEx(hProcess, hProcessFirstModule))[1]
			if 'QQ.exe' == currentprocessname:
				
				print PID
		except Exception, e:
			pass#print PID, '\t', e[0], '\t', e[1], '\t', e[2]

if __name__ == '__main__':
	test2()
	#killProcess('firefox.exe')

