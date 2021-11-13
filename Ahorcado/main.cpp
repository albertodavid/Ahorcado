// Ahorcado.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// En el mismo se controlara toda la salida y entrada de información por parte del usuario, para encontrar
// la lógica del programa id a ahorcado.cpp

#include <iostream>
#include <string>
#include <stdlib.h>
#include "ahorcado.h"

using FText = std::string;
using int32 = int;

void StartGame();
void PlayGame();
void PlayAgain();
FText GetGuess();


FAhorcado Ahorcado;

int main()
{
	StartGame();
	PlayGame();
}

void StartGame() //Empieza el juego e inicializa las variables importantes
{
	std::cout << "Bienvenido al juego del Ahorcado!" << std::endl;
	std::cout << "                       By @Scthch\n\n" << std::endl;

	Ahorcado.SetHiddenWord();
	Ahorcado.SetFirstTimeWW();
	

	std::cout << "La plabra que buscamos tiene: " << Ahorcado.GetHiddenWordLength() << " es: "; 
	Ahorcado.GetMyWorkingWord();
	std::cout << std::endl << std::endl;

}

void PlayGame() 
{
	do
	{
		switch (Ahorcado.SetMyWorkingWord(GetGuess()))
		{
		case EHint::Correct:
			
			if (Ahorcado.GetHint() == Ahorcado.GetHiddenWordLength())
			{
				
				std::cout << "\n\nFELICIDADES CHAMPION, HAS ACERTADO LA PALABRA!!!\n\n";
				PlayAgain();
			}
			break;
		case EHint::Incorrect:
			Ahorcado.SetVidas();

			break;
		default:
 			break;
		}

		std::cout << "La palabra va: ";
		Ahorcado.GetMyWorkingWord();
		std::cout << std::endl;

		std::cout << "Numero de vidas: " << Ahorcado.GetVidas() << std::endl;
		std::cout << "Las letras que has utilizado hasta ahora: " << Ahorcado.GetUsedChars() << std::endl;

	} while (Ahorcado.GetVidas() >= 1);

	std::cout << "\nGame Over! La palabra era: " << Ahorcado.GetHiddenWord();

	PlayAgain();
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

void PlayAgain() 
{
	FText Input;
	std::cout << "\n\nQuieres jugar otra vez? [Y/y]: ";
	
	getline(std::cin, Input);

	if (Input == "Y" || Input == "y")
	{
		Ahorcado.Reset();
		system("CLS");
		StartGame();
		PlayGame();
	}
	else {
		std::cout << "\n\nVaya que pena, ya nos veremos. ";

		system("EXIT");
	}

}