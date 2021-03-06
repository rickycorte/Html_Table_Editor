/*
Html_Table_Editor
https://github.com/rickycorte/Html_Table_Editor

Copyright (c) 2016 Ricky Corte

Licenced under Apache 2.0 Licence
http://www.apache.org/licenses/LICENSE-2.0
*/

#include "Cell.h"

Cell::Cell(const std::string& input,const int cellNumber) : CellNumber(cellNumber)
{
	try
	{
		if (CheckForPresence(input,CellOpenTag))
			content = Reduce(input, CellOpenTag + ">", CellCloseTag);
		else
			content = Reduce(input, HCellOpenTag + ">", HCellCloseTag);
	}
	catch (const std::exception& e)
	{

		Console::Msg::LogError("E0008 - Sorry, something went wrong reading cell "+ std::to_string(cellNumber) +".");
		Console::Msg::LogError("Details: " + (std::string)e.what());
		Console::Msg::LogError( "An empty cell will be created!");
		content = "";
	}

	Console::Msg::Log("Cell " + std::to_string(cellNumber+1) + ":\n" + content);
}

Cell::Cell()
{

}

Cell::~Cell()
{
}

std::string Cell::GetContentForOutPut(OutputKind kind, bool isLayout)
{
	std::string OpenTag, CloseTag;
	switch (kind)
	{
	case OutputKind::clean:
		OpenTag = " "; CloseTag = " |";
		break;
	case OutputKind::normal:
		if (isLayout)
		{
			OpenTag = "<th"+style+">"; CloseTag = "</th>";
		}
		else
		{
			OpenTag = "<td"+style+">"; CloseTag = "</td>";
		}
		break;
	}
	return OpenTag + content + CloseTag;
}

void Cell::SetContent(std::string newContent)
{
	if (CheckForPresence(newContent, EditPatternIdentifier))
	{
		content = Replace(newContent, EditPatternIdentifier, content); // replace pattern identifier with current content
	}
	else
	{
		content = newContent;
	}

}

void Cell::JoinContent(std::string Pattern, std::string content2)
{
	if (CheckForPresence(Pattern, JoinCurrentContentMarker))
		Pattern = Replace(Pattern, JoinCurrentContentMarker, content);
	if (CheckForPresence(Pattern, JoinOtherContentMarker))
		Pattern = Replace(Pattern, JoinOtherContentMarker, content2);

	content = Pattern;
}
