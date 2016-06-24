#include "FileHandler.h"



CFileHandler::CFileHandler()
{
}


CFileHandler::~CFileHandler()
{
}

CFileFinder * CFileHandler::GetFileFinderPtr() {
	return &filefinder; 
}

CFileReader * CFileHandler::GetFileReaderPtr() {
	return &filereader; 
}


CFileWriter * CFileHandler::GetFileWriterPtr() {
	return &filewriter; 
}

std::string CFileHandler::getSelectedFile() {

	return sSelectedFile; 
}

std::string CFileHandler::getSelectedFilePath() {

	return sSelectedFilePath;
}

void CFileHandler::setSelectedFileandPath(std::string sFileName) {
	
	sSelectedFile = sFileName; 
	sSelectedFilePath = filefinder.getPath()+"\\"+sFileName;
	bIsFileSelected = true;

	for (int i = sFileName.size(); i != 0; i--){

		if (sFileName[i] == '.'){

			sFileName.erase(i, sFileName.size() - i);
		}
	}

	sSelectedFileDisplayName = sFileName;



}

void CFileHandler::setSelectedFile(std::string s) {
	
	sSelectedFile = s;
	
	for (int i = s.size(); i != 0; i--){

		if (s[i] == '.'){

			s.erase(i, s.size() - i);
		}
	}

	sSelectedFileDisplayName = s;


}

void CFileHandler::setSelectedFilePath(std::string s) {

	sSelectedFilePath = s; 

}

std::string CFileHandler::getSelectedFileDisplayName(){

	return sSelectedFileDisplayName;
}




bool CFileHandler::IsFileSelected() {

	if (bIsFileSelected) {

		bIsFileSelected = false; 
		return true;
	}


	return false; 
}

void CFileHandler::SetDoNewFile(bool b){

	bDoNewFile = b; 
}


bool CFileHandler::DoNewFile(){

	if (bDoNewFile){
		bDoNewFile = false; 
		return true; 

	}

	return false; 
}