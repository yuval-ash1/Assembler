//
//  Implementation of the instruction class.
//
#include "pch.h"
#include "Instruction.h"


Instruction::Instruction() { };
Instruction::~Instruction() { };



/**/
/*
	Instruction::ParseInstruction(string &a_buff)

NAME

	Instruction::ParseInstruction(string &a_buff) - parses the line and sorts it to the different types.

SYNOPSIS

	InstructionType Instruction::ParseInstruction(string &a_buff)
	a_buff		--> the line in which we are parsing.

DESCRIPTION

	This function receives a line, and is responsible of processing it,
	breaking the contents down into different variables and figuring out
	what type of instruction it is.

RETURNS

	Returns the instruction type of the line.

AUTHOR

	Yuval Ashkenazi

DATE
	12:57pm 12/15/2019
*/
	/**/
Instruction::InstructionType Instruction::ParseInstruction(string &a_buff) {

	m_instruction = a_buff;		// Saving original line.
	string a = "", b = "", c = "", d = "";

	// Getting rid of comment.
	int comment_loc;
	comment_loc = a_buff.find(";");
	if (comment_loc != -1) {						// If a comment was found.
		a_buff = a_buff.substr(0, comment_loc);		// Now a_buff is free of comments.
	}
	for (int i = 0; a_buff[i]; i++) a_buff[i] = tolower(a_buff[i]);
	istringstream input(a_buff);		// Reading line into 4 different variables.
	input >> a >> b >> c >> d;

	if ((a_buff == "") || (a_buff == "\t") || (a_buff == " ")) {
		return ST_Comment;
	}
	if (a == "end") {
		return ST_End;
	}
	if ((a_buff[0] == ' ') || (a_buff[0] == '\t') || (a_buff[0] == NULL)) {		// This means we don't have a label.
		// No label, a is opcode, b is oprand.
		m_Label = "";
		m_OpCode = a;
		m_Operand = b;
	}
	// This means we have a label.
	else {
		// a is label, b is opcode, c is oprand.
		m_Label = a;
		m_OpCode = b;
		m_Operand = c;
	}
	// Making sure the opecand string contains numeric value.
	m_IsNumericOperand = true;
	for (size_t i = 0; i < m_Operand.length(); i++)
	{
		if (!isdigit(m_Operand[i]))
			m_IsNumericOperand = false;
	}
	if (((m_Label != "") && ((m_OpCode == "ds") || (m_OpCode == "dc"))) || ((m_Label == "") && (m_OpCode == "org"))) {
		return ST_MachineLanguage;
	}
	else {
		return ST_AssemblerInstr;
	}
}

/**/
/*
	Instruction::LocationNextInstruction(int a_loc)

NAME

	Instruction::LocationNextInstruction(int a_loc) - finds the location of the next line of code.

SYNOPSIS

	InstructionType Instruction::LocationNextInstruction(int a_loc)
	a_loc		--> the current location.

DESCRIPTION

	This function receives the current location and is responsible for
	adjusting it to the next line (accodrding to the line we just read).

RETURNS

	Returns the location of the next instruction (line).

AUTHOR

	Yuval Ashkenazi

DATE
	1:00pm 12/15/2019
*/
/**/
int Instruction::LocationNextInstruction(int a_loc) {

	// Determining the location according to the opCode.
	if (m_OpCode == "ds")
		a_loc = a_loc + atoi(m_Operand.c_str());
	else if (m_OpCode == "org") {
		if (getIfNumOperand())
			a_loc = (atoi(m_Operand.c_str()));
		else
			a_loc = 0;
	}
	else
		a_loc++;

	return a_loc;
}

// Label getter.
string Instruction::getLabel() {
	return m_Label;
}

// OpCode getter.
string Instruction::getOpCode() {
	return m_OpCode;
}

// Operand getter.
string Instruction::getOperand() {
	return m_Operand;
}

// Original line of instruction getter.
string Instruction::getInstruction() {
	return m_instruction;
}

// Returns true of operand is numerical, false otherwise.
bool Instruction::getIfNumOperand() {
	return m_IsNumericOperand;
}
