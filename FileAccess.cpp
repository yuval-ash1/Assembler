//
//  Implementation of file access class.
//
#include "pch.h"
#include "FileAccess.h"

/**/
/*
	FileAccess::FileAccess( int argc, char *argv[] )

NAME

	FileAccess::FileAccess( int argc, char *argv[] ) - attempts to open the file.

SYNOPSIS

	FileAccess::FileAccess( int argc, char *argv[] )
	argc		--> The numbter of agruments entered in the command line.
	argv		--> The name of the file entered by user.

DESCRIPTION

	This function is the constructor of the FileAccess class. It is responsible of opening the file.
	If it fails to open the file it terminates the program.

RETURNS

	Nothing.
*/
/**/
FileAccess::FileAccess(int argc, char *argv[])
{

	// Check that there is exactly one run time parameter.
	if (argc != 2) {
		cerr << "Usage: Assem <FileName>" << endl;
		exit(1);
	}

	// Open the file.
	m_sfile.open(argv[1], ios::in);

	// If the open failed, report the error and terminate.
	if (!m_sfile) {
		cerr << "Source file could not be opened, assembler terminated."
			<< endl;
		exit(1);
	}
}

/**/
/*
	FileAccess::~FileAccess()

NAME

	FileAccess::~FileAccess() - closes the file after reading all lines.

SYNOPSIS

	FileAccess::~FileAccess( )

DESCRIPTION

	This function is the deconstructor of the FileAccess class. It is responsible of closing the file at
	the end of the program.

RETURNS

	Nothing.
*/
/**/
FileAccess::~FileAccess()
{
	// Not that necessary in that the file will be closed when the program terminates, but good form.
	m_sfile.close();
}

/**/
/*
	FileAccess::GetNextLine(string &a_buff)

NAME

	FileAccess::GetNextLine(string &a_buff) - attempts to read another line.

SYNOPSIS

	bool FileAccess::GetNextLine(string &a_buff)
	a_buff		--> This is the last line in the file that was opened and read.

DESCRIPTION

	This function is responsible of getting the next line in the file.

RETURNS

	Returns true of read was successful, false if there is no more lines to read.
*/
/**/
bool FileAccess::GetNextLine(string &a_buff)
{
	// If there is no more data, return false.
	if (m_sfile.eof()) {

		return false;
	}
	getline(m_sfile, a_buff);

	// Return indicating success.
	return true;
}

/**/
/*
	FileAccess::rewind()

NAME

	FileAccess::rewind() - clears all flags in order to read hte file again.

SYNOPSIS

	void FileAccess::rewind()

DESCRIPTION

	This function is responsible clearing all the neccessary flags in order to start
	reading the file from the beginning.

RETURNS

	Nothing.
*/
/**/
void FileAccess::rewind()
{

	// Clean all file flags and go back to the beginning of the file.
	m_sfile.clear();
	m_sfile.seekg(0, ios::beg);
}
    
