//
//		Implementation of the symbol table class.  This is the format I want for commenting functions.
//
#include "pch.h"
#include "SymTab.h"

/**/
/*
	SymbolTable::AddSymbol(string &a_symbol, int a_loc)

NAME

	SymbolTable::AddSymbol(string &a_symbol, int a_loc) - adding a symbol to the symbol table.

SYNOPSIS

	void SymbolTable::AddSymbol(string &a_symbol, int a_loc)
	a_symbol		 --> Symbol to be added.
	a_loc            --> Location of the symbol to be added.

DESCRIPTION

	This function adds a pair of symbol (a_symbol) and its corresponding location (a_loc) to the symbol table.	

RETURNS

	Nothing.

AUTHOR

	Yuval Ashkenazi

DATE
	1:24pm 12/12/2019
*/
/**/
void SymbolTable::AddSymbol(string &a_symbol, int a_loc)
{
	map<string, int>::iterator st;
	st = m_symbolTable.find(a_symbol);
	
	// If the symbol is already in the symbol table, record it as multiply defined.
	if (st != m_symbolTable.end()) {

		st->second = multiplyDefinedSymbol;
		return;
	}
	
	// Record a the location in the symbol table.
	m_symbolTable[a_symbol] = a_loc;
}

/**/
/*
	SymbolTable::DisplaySymbolTable()

NAME

	SymbolTable::DisplaySymbolTable() - prints the symbol table to the screen.

SYNOPSIS

	void SymbolTable::DisplaySymbolTable()

DESCRIPTION

	This functions displays the symbol table we created in the following way:
	symbol# (TAB) symbol (TAB) location.

RETURNS

	Nothing.

AUTHOR

	Yuval Ashkenazi

DATE
	1:29pm 12/12/2019
*/
/**/
void SymbolTable::DisplaySymbolTable() {
	map<string, int>::iterator st;
	st = m_symbolTable.begin();
	int i = 0;

	// First line of table (header).
	cout << "Symbol#\tSymbol\tLocation" << endl;

	// Going through the symbol table and printing its contents line by line in
	// the described format.
	while (st != m_symbolTable.end()) {
		cout << i << '\t' << st->first
			<< '\t' << st->second << '\n';
		st++;
		i++;
	}
	cout << endl;
	cout << "________________________________________________________" << endl;
}

/**/
/*
	SymbolTable::LookupSymbol(string & a_symbol, int & a_loc)

NAME

	SymbolTable::LookupSymbol(string & a_symbol, int & a_loc) - attempts to find a pair of 
	symbol, location similar to the given one.

SYNOPSIS

	bool SymbolTable::LookupSymbol(string & a_symbol, int & a_loc)
	a_symbol		--> the symbol to look up.
	a_loc			--> its corresponding location.

DESCRIPTION

	This functions looks up a pair of symbol, location in the symbol table.

RETURNS

	Returns true if pair found, false otherwise.

AUTHOR

	Yuval Ashkenazi

DATE
	12:23pm 12/21/2019
*/
/**/

bool SymbolTable::LookupSymbol(string & a_symbol, int & a_loc)
{

	// If symbol was found return true, otherwise false.
	if (m_symbolTable.count(a_symbol) != 0)
	{
		return true;
	}
	else return false;
}

/**/
/*
	SymbolTable::findLabelLoc(string &a_symbol)

NAME

	SymbolTable::findLabelLoc(string &a_symbol) - finds the location of a given label.

SYNOPSIS

	void SymbolTable::DisplaySymbolTable()
	a_symbol		--> Symbol to look up in the table.

DESCRIPTION

	This function finds the location corresponding to a given symbol.

RETURNS

	Returns the location of the symbol if found, else returns -1.

AUTHOR

	Yuval Ashkenazi

DATE
	1:33pm 12/12/2019
*/
/**/
int SymbolTable::findLabelLoc(string &a_symbol) {
	map<string, int>::iterator st;
	
	// If a symbol was found, return its corresponding location.
	if (m_symbolTable.count(a_symbol))
	{
		st = m_symbolTable.find(a_symbol);
		return st->second;
	}
	else
		return -1;
}

