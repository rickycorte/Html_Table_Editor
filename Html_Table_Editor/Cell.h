/*
Html_Table_Editor
https://github.com/rickycorte/Html_Table_Editor

Copyright (c) 2016 Ricky Corte

Licenced under Apache 2.0 Licence
http://www.apache.org/licenses/LICENSE-2.0
*/

#pragma once
#include<string>
#include<iostream>
#include"Common.h"
#include "FileManager.h"

class Cell
{
private:
	std::string content;
	int CellNumber;

	std::string style;

	std::string EditPatternIdentifier = "@c@";

	std::string JoinCurrentContentMarker = "@1@";
	std::string JoinOtherContentMarker = "@2@";

public:
	Cell(const std::string& input, const int cellNumber);
	~Cell();
	Cell();
	std::string GetContent() { return content; }
	int GetCellNumber() { return CellNumber; }
	void SetCellNumber(unsigned num) { CellNumber = num; }
	//get the content with a open and close tag
	std::string GetContentForOutPut(OutputKind kind, bool isLayout);
	//set the cell content, or use a pattern to edit it
	void SetContent(std::string newContent);

	//set the cell content based on a pattern and another string
	void JoinContent(std::string Pattern, std::string content2);
	//set the cell style
	void SetStyle(std::string newStyle) { style =" "+ newStyle; }

};

