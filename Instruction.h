//
// Class to parse and provide information about instructions.
//
#ifndef _INSTRUCTION_N
#define _INSTRUCTION_N

#include <sstream>
#include <string>

// The elements of an instruction.
class Instruction {

public:

	Instruction();
	~Instruction();

	// Codes to indicate the type of instruction we are processing.
	enum InstructionType {
		ST_MachineLanguage, 	// A machine language instruction.
		ST_AssemblerInstr,  	// Assembler Language instruction.
		ST_Comment,          	// Comment or blank line.
		ST_End                  // End instruction.
	};

	InstructionType ParseInstruction(string &a_buff);
	int LocationNextInstruction(int a_loc);

	// To access the label.
	inline string &GetLabel() {

		return m_Label;
	};

	// To determine if a label is blank.
	inline bool isLabel() {
		return !m_Label.empty();
	};

	// Label getter.
	string getLabel();
	// OpCode getter.
	string getOpCode();
	// Operand getter.
	string getOperand();

	// Original line of instruction getter.
	string getInstruction();

	// Returns true of operand is numerical, false otherwise.
	bool getIfNumOperand();

private:

	// The elemements of an instruction.
	string m_Label;		// The label.
	string m_OpCode;	// The symbolic op code.
	string m_Operand;	// The operand.


	string m_instruction;	// The original instruction.

	// Derived values.
	int m_NumOpCode;		// The numerical value of the op code.
	InstructionType m_type;	// The type of the instruction.

	bool m_IsNumericOperand;	// == true if the operand is numeric.
	int m_OperandValue;			// The value of the operand if it is numeric.
};
#endif