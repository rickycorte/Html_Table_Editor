/*
Html_Table_Editor
https://github.com/rickycorte/Html_Table_Editor

Copyright (c) 2016 Ricky Corte

Licenced under Apache 2.0 Licence
http://www.apache.org/licenses/LICENSE-2.0
*/
#pragma once
#include <map>
#include <functional>
#include <vector>
#include <string>
#include "CustomExceptions.h"
#include "Msg.h"

class Commands
{
private:
	typedef std::function< void(std::vector<std::string>)> CustomDelegate;
	std::map<std::string, CustomDelegate > CommandList;
public:
	Commands();
	~Commands();
	//add a command to list
	void RegisterCommand(std::string cmd, CustomDelegate callback);
	bool hasCommand(std::string cmd);
	void RunCommand(std::string cmd, std::vector<std::string> args);
	static void TestCmdCallback(std::vector<std::string> args);

};

