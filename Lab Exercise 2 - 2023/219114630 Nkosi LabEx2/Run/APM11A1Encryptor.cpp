#include "PageManager.cpp"
#include "Page.cpp"
#include <iostream>
#include <fstream>
using namespace std;

//219114630 NKOSI LM LabEx2
class APM11A1Encryptor
{
public:

    void setKey(int key)//This method will set the value of the key data member.
    {
      this->key = key;
    }
    protected:
        int key //key that will be used during the encryption process.
        {
            key = 0
        };
    // Caesar Cipher encryption method
    char encryptACharacter(char character)//This method  encrypts the received character by using the key class member.
    {
        char encryptedChar = character + key;

        if (encryptedChar > 'z')
        {
            encryptedChar = 'a' + (encryptedChar - 'z' - 1);
        }
        return encryptedChar;
    }

    // Page encryption method
    Page encryptPage(Page page)//This method encrypts the content of the received page parameter by making use of the encryptACharacter() method.
    {
        Page encryptedPage;
        for (int i = 0; i < page.getNumberOfSentences(); i++)
        {
            string sentence = page.getSentenceAt(i);
            string encryptedSentence = "";
            for (char character : sentence)
            {
                encryptedSentence += encryptACharacter(character);
            }
            encryptedPage.addSentence(encryptedSentence);
        }
        return encryptedPage;
    }

};