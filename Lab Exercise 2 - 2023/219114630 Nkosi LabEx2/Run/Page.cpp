#include <string>
using namespace std;

//219114630 NKOSI LM LabEx2
class Page {
private:
    string cSentences[34];//Array that will store a record of 34 sentences.
    int cSentenceCounter;//This member will store the number of sentences on the page.

public:Page()//A default constructor that will initialise cSentenceCounter to zero.
{
    cSentenceCounter = 0;
}

      void addSentence(string sentence)//This method will place add a sentence to the Page. You must make use of the cSentences[] array.
      {
          if (cSentenceCounter < 34)
          {
              cSentences[cSentenceCounter] = sentence;
              cSentenceCounter++;
          }
      }

      string getSentenceAt(int index)//This method will retrieve a sentence.
      {
          if (index >= 0 && index < cSentenceCounter)
          {
              return cSentences[index];
          }
          else
          {
              return "";
          }
      }

      int getNumberOfSentences()//This method will return the number of sentences there are on the Page.
      {
          return cSentenceCounter;
      }
};
