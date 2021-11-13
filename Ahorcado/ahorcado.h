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

enum class EHint
{
	Correct,
	Incorrect
};

class FAhorcado
{
public:

	FAhorcado(); //Constructor

	//Getters y Setters

	int32 GetVidas() const;
	void SetVidas();
	int32 GetHit() const;
	void SetHit();

	int32 GetHiddenWordLength() const;

	FString GetHiddenWord() const;
	void SetHiddenWord();

	void GetMyWorkingWord();
	void SetFirstTimeWW();

	FString GetUsedChars() const;

	EHint SetMyWorkingWord(FString Guess);

	ESubmitStatus CheckGuessStatus(FString character);

	void Reset();

private:
	char GuessChar;
	
	FString MyHiddenWord;
	FString UsedChars;

	std::vector<char> MyWorkingWord;
	std::vector<FString> Words = {"ahorcado", "mandarina", "platano", "selva", "coche", "casa", "esternocleidomastoideo", "hola", "amigo", "ancestro"};
	
	int32 MyVidas = 7;
	int32 MyHits = 0;
	int32 HiddenWordLength = 0;
};

