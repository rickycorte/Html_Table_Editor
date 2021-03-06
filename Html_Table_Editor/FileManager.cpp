/*
Html_Table_Editor
https://github.com/rickycorte/Html_Table_Editor

Copyright (c) 2016 Ricky Corte

Licenced under Apache 2.0 Licence
http://www.apache.org/licenses/LICENSE-2.0
*/
#include "FileManager.h"

FileManager::FileManager() {
	myfile = new std::fstream();
} 

FileManager::FileManager(File ft)
{
	myfile = new std::fstream();
	try
	{
		switch (ft)
		{
		case FileManager::cleandata:
			myfile->open(CleanData, std::fstream::out | std::fstream::trunc);
			break;
		case FileManager::output:
			myfile->open(OutPut, std::fstream::out | std::fstream::trunc);
			break;
		}
	}
	catch(const std::exception& e)
	{
		Console::Msg::LogError( "E0010 - Sorry, can't open/create the output file.");
		Console::Msg::LogError("Details: " + (std::string)e.what());
		throw e;
	}
}


FileManager::~FileManager()
{
	myfile->close();
	delete myfile;
}

std::string FileManager::ReadFromFile(const std::string& filename)
{
	std::string temp;
	std::string fileContent;
	try
	{
		myfile->open(filename, std::fstream::in);
		if (!*myfile) throw CustomExceptions::FileError("Can't find file: " + filename);
		while (*myfile >> temp)
		{
			fileContent += temp;
		}
	}
	catch (const std::exception& e)
	{
		Console::Msg::LogError("E0011 - Sorry, can't read input file.");
		Console::Msg::LogError("Details: " + (std::string)e.what());
		throw e; // prevent the program to run with this error
	}
	myfile->close();
	Console::Msg::Log("Input: " + fileContent+"\n");
	return fileContent;
}

void FileManager::Write(std::string line)
{
	if (*myfile)
		*myfile << line;
	else
		throw CustomExceptions::FileError("E0016 - Unable to write on file!");
}
