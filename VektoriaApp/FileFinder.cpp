
#include "FileFinder.h"



CFileFinder::CFileFinder()
{
}


CFileFinder::~CFileFinder()
{
}


void CFileFinder::Init(std::string sPathFragen) {
	findFiles(sPathFragen); 
}


std::set <std::string> * CFileFinder::getFiles() {
	return &setFiles;
}

std::set <std::string> * CFileFinder::getDirs() {
	return &setDirs;
}

void CFileFinder::findFiles(std::string sPath) { //Aus https://msdn.microsoft.com/en-us/library/windows/desktop/aa365200%28v=vs.85%29.aspx . fuer eigene Beduerfnisse angepasst.

	
	m_sPath = sPath;
	sPath += "\\*";

	WIN32_FIND_DATAA ffd;
	LARGE_INTEGER filesize;
	char szDir[MAX_PATH];
	HANDLE hFind = INVALID_HANDLE_VALUE;

	strcpy_s(szDir, sPath.c_str());

	hFind = FindFirstFileA(szDir, &ffd);

	if (INVALID_HANDLE_VALUE == hFind) {

		//ULDebug("No Files Found.");

		//std::cout << "No File." << std::endl;
	}
	else {

		do
		{
			if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				std::string s = ffd.cFileName;
				if ((s.compare("..") && s.compare("."))) {

					setDirs.insert(s);

				}

			}
			else
			{
				setFiles.insert(ffd.cFileName);
				//ULDebug("FindFiles: else");

			}
		} while (FindNextFileA(hFind, &ffd) != 0);
	}

	//ULDebug("FindFiles: Ende");
}



std::string CFileFinder::getPath() {
	return m_sPath;
}