#include <iostream>
#include <fstream>
#include "Page.cpp"
using namespace std;

//219114630 NKOSI LM LabEx2
class PageManager {
public:
    Page loadPageFromFile(string fileName)//This method reads the content of the specified file into a Page object and return this Page.
    {
        ifstream file(fileName);
        string file = "encrypt1.txt";
        Page page;

        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                page.addSentence(line);
            }
            file.close();
        }

        return page;
    }

    void writePageToFile(string fileName, Page page)//This method writes the content of a Page object into the specified file.
    {
        ofstream file(fileName);
        string file = "encrypt2.txt";

        if (file.is_open())
        {
            int numSentences = page.getNumberOfSentences();
            for (int i = 0; i < numSentences; i++)
            {
              file << page.getSentenceAt(i) << endl;
            }
            file.close();
        }
    }
};
