//
//		Emulator class - supports the emulation of Duck2200 programs.
//
#ifndef _EMULATOR_H      // UNIX way of preventing multiple inclusions.
#define _EMULATOR_H

class emulator {

public:

	int emulatorErrCount = 0;	// This variable tracks the number of errors for emulator (if 0 we run the emulator).
	const static int MEMSZ = 10000;	// The size of the memory of the Duck2200.
	emulator() {

		memset(m_memory, 0, MEMSZ * sizeof(int));
	}
	// Records instructions and data into Duck2200 memory.
	bool insertMemory(int a_location, int a_contents);

	// Runs the Duck2200 program recorded in memory.
	bool runProgram();	// instr = m_memory[loc].


private:

	int m_memory[MEMSZ] = {};	// The memory of the Duck2200, initializing all spots to 0.
	int accumulator;	// The accumulator for the Duck2200.
};

#endif

