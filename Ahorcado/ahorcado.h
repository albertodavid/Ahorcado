#pragma once
#include <iostream>
#include <vector>

using FString = std::string;
using int32 = int;

enum class ESubmitStatus
{
	Invalid_Status,
	Not_A_Single_Letter,
	Not_Valid_Character,
	Not_Lowercas,
	OK

};

class FAhorcado
{
public:

	FAhorcado(); 

	int32 GetCurrentTry() const;
	void SetCurrentTry();

	int32 GetHiddenWordLength() const;

	FString GetHiddenWord() const;
	void SetHiddenWord(FString HW);

	void GetMyWorkingWord();
	void SetFirstTimeWW();
	void SetMyWorkingWord();

	ESubmitStatus CheckGuessStatus(FString character);
	FString SubmitGuess();

private:
	char GuessChar;
	
	FString MyHiddenWord;
	FString MyUsedLetters;
	
	std::vector<char> MyWorkingWord;

	int32 MyCurrentTry;
	int32 HiddenWordLength;
};

