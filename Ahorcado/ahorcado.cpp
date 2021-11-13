#include "ahorcado.h"


FAhorcado::FAhorcado()
{
}

int32 FAhorcado::GetCurrentTry() const{	return MyCurrentTry;}
int32 FAhorcado::GetHiddenWordLength() const { return MyHiddenWord.length(); }
FString FAhorcado::GetHiddenWord() const { return MyHiddenWord; }

void FAhorcado::GetMyWorkingWord() {

	for (size_t i = 0; i < GetHiddenWordLength(); i++)
	{
		std::cout << MyWorkingWord[i] << " ";
	}
	
}

void FAhorcado::SetCurrentTry()
{
	MyCurrentTry++;
}

void FAhorcado::SetHiddenWord(FString HW)
{

	const FString HIDDEN_WORD = HW; //Placeholder
	MyHiddenWord = HIDDEN_WORD;

}

void FAhorcado::SetFirstTimeWW()
{
	for (int32 i = 0; i < GetHiddenWordLength(); i++)
	{
		MyWorkingWord.push_back('_');
	}
}

void FAhorcado::SetMyWorkingWord()
{

}

ESubmitStatus FAhorcado::CheckGuessStatus(FString character)
{

	if (character.length() > 1)
	{
		return ESubmitStatus::Not_A_Single_Letter;
	}
	else if (tolower(character[0])!=character[0])
	{
		return ESubmitStatus::Not_Lowercas;
	}

}

FString FAhorcado::SubmitGuess()
{
	return FString();
}
