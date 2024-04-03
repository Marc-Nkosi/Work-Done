// 219114630_Nkosi_LabEx1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include<istream>
using namespace std;
int main()
{
     string Phrase, Colour, ColourDigit;
     int Phrase_Length,PhraseFinal, StandardPrice, MinimumPrice, MinimumPriceB,MinimumPriceG, FinalPrice,
         FinalPriceW, FinalPriceG, FinalPriceB, BlackChar,GoldChar, StandardPhrase,PhraseCalc;

     StandardPhrase = 6;
     MinimumPrice = 30;
     StandardPrice = 7;
     BlackChar = 10;
     GoldChar = 12;
 
     while (true)
     {
         
         std::cout << "Enter either letters, digits or END to Exit : ";

         std::cin >> Phrase;
         Phrase_Length = Phrase.length();

         if (Phrase == "END")
         {
             std::cout << "Program Closed..." << endl;
             exit(0);
         }

         std::cout << "Enter colour of the letters or digits : ";
         std::cin >> Colour;
         if (Phrase_Length > StandardPhrase)
         {
             PhraseCalc = Phrase_Length - StandardPhrase;
             PhraseFinal = PhraseCalc * StandardPrice;
         }
         else
         {
             PhraseCalc = StandardPhrase - Phrase_Length;
             PhraseFinal = 0;
         }

         if (Colour == "White")
         {
             FinalPriceW = MinimumPrice + PhraseFinal;
             std::cout << "The Amount due is : R" << FinalPriceW << endl;
         }
         if (Colour == "Black")
         {
             MinimumPriceB = MinimumPrice + BlackChar;
             FinalPriceB = MinimumPriceB + PhraseFinal;
             std::cout << "The Amount due is : R" << FinalPriceB << endl;
         }
         if (Colour == "Gold")
         {
             MinimumPriceG = MinimumPrice + GoldChar;
             FinalPriceG = MinimumPriceG + PhraseFinal;
             std::cout << "The Amount due is : R" << FinalPriceG << endl;
         }
     }
      //std::cout << "Enter colour of the letters or digits : ";
        // std::cin >> Colour;
}