/*
Html_Table_Builder
https://github.com/RickyCoDev/Html_Table_Editor

Copyright (c) 2016 RickyCoDev

Licenced under Apache 2.0 Licence
http://www.apache.org/licenses/LICENSE-2.0
*/
#pragma once
#include <string>
#include <vector>
#include "Common.h"
#include "Cell.h"
class Row
{
private:
	bool isLayout;
	int RowNumber;
	std::vector<Cell> Cells;

	void PopulateCells(std::string input);
public:
	Row(const std::string& input,const int rowNumber);
	~Row();

	int GetRowNumber() { return RowNumber; }

};

