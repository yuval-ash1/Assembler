#include "pch.h"
#include "Errors.h"

vector<string> Errors::m_ErrorMsgs;	// Declaring the error vector.

/**/
/*
	Errors::InitErrorReporting()

NAME

	Errors::InitErrorReporting()

SYNOPSIS

	void Errors::InitErrorReporting() - makes sure the errors vector is empty when starting to look for error (PassII).

DESCRIPTION

	This function makes sure that the the vector m_ErrorMsgs is empty at the beginning of the program.

RETURNS

	Nothing.

AUTHOR

	Yuval Ashkenazi

DATE
	8:19pm 12/12/2019
*/
/**/
void Errors::InitErrorReporting() {
	if (m_ErrorMsgs.empty())
		return;
	else {
		m_ErrorMsgs.clear();
		return;
	}
}

/**/
/*
	Errors::RecordError(string &a_emsg)

NAME

	Errors::RecordError(string &a_emsg) - loads a string error to the wrrors vector.

SYNOPSIS

	void Errors::RecordError(string &a_emsg)
	a_emsg		--> The error message to record.

DESCRIPTION

	This function saves the error message in a vector and deleted it after it has been printed.

RETURNS

	Nothing.

AUTHOR

	Yuval Ashkenazi

DATE
	8:21pm 12/12/2019
*/
/**/
void Errors::RecordError(string &a_emsg) {
	
	// Pushing an error into the errors vector.
	m_ErrorMsgs.push_back(a_emsg);
}

/**/
/*
	Errors::DisplayErrors()

NAME

	Errors::DisplayErrors()

SYNOPSIS

	void Errors::DisplayErrors() - printing the errors after displaying the corresponding line.

DESCRIPTION

	This function displays all the errors for a current line in the order they were found.

RETURNS

	Nothing.

AUTHOR

	Yuval Ashkenazi

DATE
	8:23pm 12/12/2019
*/
/**/
void Errors::DisplayErrors() {

	// Prints all the errors that are in the erros vector.
	for (int i = 0; i < m_ErrorMsgs.size(); i++)
	{
		cout << "ERROR: " << m_ErrorMsgs[i] << endl;
	}

	// After printing the errors, popping them out of the vector.
	for (int i = 0; i < m_ErrorMsgs.size(); i++)
	{
		m_ErrorMsgs.pop_back();
	}
}