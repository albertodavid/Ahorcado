// Ahorcado.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// En el mismo se controlara toda la salida y entrada de información por parte del usuario, para encontrar
// la lógica del programa id a ahorcado.cpp

#include <iostream>
#include <string>
#include "ahorcado.h"

using FText = std::string;
using int32 = int;

void StartGame();
FText GetGuess();
FAhorcado Ahorcado;

int main()
{
	std::cout << "Bienvenido al juego del Ahorcado!" << std::endl;
	std::cout << "                       By @Scthch\n" << std::endl;

	StartGame();
	GetGuess();
}

void StartGame()
{

	Ahorcado.SetHiddenWord("Ahorcado");
	Ahorcado.SetFirstTimeWW();
	

	std::cout << "La plabra que buscamos tiene: " << Ahorcado.GetHiddenWordLength() << " es: "; 
	Ahorcado.GetMyWorkingWord();
	std::cout << std::endl << std::endl;

}

FText GetGuess() 
{
	FText Guess;
	ESubmitStatus Status = ESubmitStatus::Invalid_Status;

	do
	{
		std::cout << "Inserte una letra: ";
		getline(std::cin, Guess);
		std::cout << std::endl;

		Status = Ahorcado.CheckGuessStatus(Guess);

		switch (Status)
		{

		case ESubmitStatus::Not_A_Single_Letter:
			std::cout << "Por favor, inserte SOLO letra en minusculas" << std::endl;
			break;
		case ESubmitStatus::Not_Lowercas:
			std::cout << "Por favor, inserte una letra en MINUSCULAS" << std::endl;
			break;

		default:
			return Guess;
		}

	} while (Status != ESubmitStatus::OK);


	return Guess;
}

