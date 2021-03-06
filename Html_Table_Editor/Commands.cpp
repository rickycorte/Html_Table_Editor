/*
Html_Table_Editor
https://github.com/rickycorte/Html_Table_Editor

Copyright (c) 2016 Ricky Corte

Licenced under Apache 2.0 Licence
http://www.apache.org/licenses/LICENSE-2.0
*/
#include "Commands.h"


Commands::Commands()
{
	RegisterCommand("test", TestCmdCallback);
}


Commands::~Commands()
{
}

void Commands::RegisterCommand(std::string cmd, CustomDelegate callback)
{
	CommandList.insert(std::pair <std::string, CustomDelegate>(cmd, callback));
}

bool Commands::hasCommand(std::string cmd)
{
	if (CommandList.find(cmd) != CommandList.end())//check the command is present in the list
		return true;
	else 
		return false;
}

void Commands::RunCommand(std::string cmd, std::vector<std::string> args)
{
	if (hasCommand(cmd))
		CommandList[cmd](args);
	else
		throw CustomExceptions::CmdError("E0015 - Invalid Command: " + cmd + " not found!");
}

void Commands::TestCmdCallback(std::vector<std::string> args)
{
	if (args.size() > 0)
	{
		Console::Msg::LogWarn("This command has no paramenter(s), ignoring the current one(s)!");
		args.clear();
	}
	Console::Msg::LogSucc("This is a test message. The commands are working correctly!");
}
