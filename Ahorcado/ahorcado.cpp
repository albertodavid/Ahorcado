#include "ahorcado.h"
#include <string>
#include <stdlib.h>
#include <ctime>



FAhorcado::FAhorcado() //Constructor
{
}

//Getters
int32 FAhorcado::GetVidas() const{	return MyVidas;}
int32 FAhorcado::GetHiddenWordLength() const { return MyHiddenWord.length(); }
FString FAhorcado::GetHiddenWord() const { return MyHiddenWord; }
FString FAhorcado::GetUsedChars() const { return UsedChars; }
int32 FAhorcado::GetHint() const{	return MyHints;}

void FAhorcado::GetMyWorkingWord() {

	for (int i = 0; i < GetHiddenWordLength(); i++)
	{
		std::cout << MyWorkingWord[i] << " ";
	}

}

//Setters
void FAhorcado::SetHint()
{
	MyHints++;
}

void FAhorcado::SetVidas()
{
	MyVidas = MyVidas - 1;
}

void FAhorcado::SetHiddenWord()
{
	srand(time(NULL));
	MyHiddenWord = Words[rand()%10];
}


void FAhorcado::SetFirstTimeWW() //Setea la WorkingWord como '_________' en funcion de lo largo que sea la palabra oculta
{
	for (int32 i = 0; i < GetHiddenWordLength(); i++)
	{
		MyWorkingWord.push_back('_');
	}
}



EHint FAhorcado::SetMyWorkingWord(FString Guess)	//Setea como está la palabra respecto nuestros inputs
{													//Por ejemplo: a h _ _ _a _ _
	EHint Status = EHint::Incorrect;
	int32 found = MyHiddenWord.find(Guess);

	for (size_t i = 0; i < GetHiddenWordLength(); i++)
	{
		if (MyHiddenWord[i] == Guess[0])
		{
			MyWorkingWord[i] = Guess[0];
			SetHint();
			Status = EHint::Correct;
		}
	}
	
	UsedChars.push_back(Guess[0]); // Va creando el String con las letras que hemos utilizado
	
	return Status;

}

//Comprueba que los inputs del usuario funcionan correctamente

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

	return ESubmitStatus::Invalid_Status;
}

//Resetea la partida

void FAhorcado::Reset()
{
	MyVidas = 7;
	MyWorkingWord.clear();
	UsedChars = "";
	MyHints = 0;
}
