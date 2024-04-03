#include "APM11A1Encryptor.cpp"
#include <iostream>
#include <fstream>

//219114630 NKOSI LM LabEx2
class AdvancedAPM11A1Encryptor
{
    //encryptPage(Page page)//Inherited Methods
    //setKey(int key)//Inherited Methods
public:
    protected:
        int key//This member will store the key that will be used during the encryption process.
        {

        };

    

    char encryptACharacter(char character)//This method encrypts the received character by using the key class member and the Exclusive-OR encryption technique.
    {
        return character ^ key;
    }
    
};