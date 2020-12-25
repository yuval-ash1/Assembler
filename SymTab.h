//
//		This class is our symbol table.
//
#pragma once



class SymbolTable {

public:
	// Get rid of constructor and destructor if you don't need them.
	//SymbolTable() {};
	//~SymbolTable() {};

	// We will use this to indicate the symbol was already defined.
	const int multiplyDefinedSymbol = -999;

	// Add a new symbol to the symbol table.
	void AddSymbol(string &a_symbol, int a_loc);

	// Display the symbol table.
	void DisplaySymbolTable();

	// Lookup a symbol in the symbol table.
	bool LookupSymbol(string &a_symbol, int &a_loc);

	// Find the location of a certain label.
	int findLabelLoc(string &a_symbol);

private:

	// This is the actual symbol table, the symbol is the key to the map.
	map<string, int> m_symbolTable;

};
