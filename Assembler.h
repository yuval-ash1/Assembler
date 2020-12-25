//
//		Assembler class.  This is a container for all the components
//		that make up the assembler.
//
#pragma once 

#include "SymTab.h"
#include "Instruction.h"
#include "FileAccess.h"
#include "Emulator.h"


class Assembler {

public:
    Assembler( int argc, char *argv[] );
    ~Assembler( );

    // Pass I - establish the locations of the symbols.
    void PassI( );

    // Pass II - generate a translation.
	void PassII();

    // Display the symbols in the symbol table.
    void DisplaySymbolTable() { m_symtab.DisplaySymbolTable(); }
    
    // Run emulator on the translation.
	void RunProgramInEmulator() {
		// If errors- don't run emulator, else, run emulator
		if (m_emul.emulatorErrCount) {
			cout << "Since there are errors in the code the emulator will not run.\n";
		}
		else {
			m_emul.runProgram();
		}
	}

private:

    FileAccess m_facc;	    // File Access object.
    SymbolTable m_symtab;	// Symbol table object.
    Instruction m_inst;	    // Instruction object.
    emulator m_emul;        // Emulator object.
};

