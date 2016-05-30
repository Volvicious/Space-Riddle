#pragma once
#include "Vektoria\Root.h"
#include "TextOutput.h"
#include <list>
#include "FileFinder.h"
#include "FileReader.h"
#include "FileWriter.h"

//----------------------------------
//Klasse fuer das Verwalten von Files
//Author: Christoph Fischmann
//Aenderung: --
//----------------------------------

class CFileHandler
{
public:
	CFileHandler();
	~CFileHandler();
	
	CFileFinder * GetFileFinderPtr();
	CFileReader * GetFileReaderPtr(); 
	CFileWriter * GetFileWriterPtr();

	std::string getSelectedFile(); 
	std::string getSelectedFilePath();

	void setSelectedFileandPath(std::string sFileName);
	void setSelectedFile(std::string);
	void setSelectedFilePath(std::string);

	bool IsFileSelected(); 

	std::string getSelectedFileDisplayName();

private: 

	CFileFinder filefinder;  //Hat die Liste von allen Docnamen in einem Verzeichnis.
	CFileReader filereader;	 //Hat das komplette Dokument eingelesen.	
	CFileWriter filewriter;  //Schreibt in bestimmtes Dokument.
	
	std::string sSelectedFile;
	std::string sSelectedFileDisplayName; 
	std::string sSelectedFilePath;
	bool bIsFileSelected = false; 

};

