//
//  main.cpp
//  Lab 5
//
//  Created by Aim Kim on 2022-06-29.
//


#include <iostream>
#include <fstream>

using namespace std;
int NEXT_CHAPTER = 18;
int get_next_number()
{
    if (NEXT_CHAPTER == 0)
    {
        NEXT_CHAPTER = 18;
        return NEXT_CHAPTER--;
    }
    return NEXT_CHAPTER--;
}
int main()
{
    int x = 0;
    ifstream inStream;

    inStream.open("answers.txt");

    if (inStream.fail())
    {
        cout << "Something is wrong!." << endl;
    }
    else
    {
        cout << "Everything is OK." << endl;
    }

    while (true)
    {
        cout << "Plz, enter your next question" << endl;
        string question;

        cin >> question;

        // provide an answer - todo
        // string anAnswer;;
        char anAnswer[100];

        // if(inStream >> anAnswer)
        //     cout << anAnswer << endl;
        // else    {
        //     inStream.close();
        //     inStream.open("answers.txt");
        //     inStream >> anAnswer;
        //     cout << anAnswer << endl;
        
        // have to make loop for file to close and reopen when it detects inStream.eof()
        
        // }
        int counter = 0;
        bool ignore_the_N = false;
        // read the next char.
        inStream.get(anAnswer[counter++]);
        while (!inStream.eof())//after assigning the dot the while statement quits as it is the end of file
            //make sure the last question prints out before the loop is over or restarted
        {
            // I need to read the whole line
            if (anAnswer[counter - 1] == '\n')
            {
                // provide an answer
                for (int i = 0; i < counter -1; i++)
                                    cout << anAnswer[i];
                counter = 0;
                
                cout << "\nPlease enter your question" << endl;
                                 cin >> question;
            }
            else if (anAnswer[counter - 1] == '#')
            {
                // let us get the next number and
                // it to the answer array
                x = get_next_number(); //  get_next_number();
                if (x >= 10)
                {
                    anAnswer[counter - 1] = '1';
                    anAnswer[counter++] = (x - 10) + '0'; // '6'
                }
                else
                {
                    anAnswer[counter - 1] = x + '0'; // '6'
                }
                ignore_the_N = true;
                inStream.get(anAnswer[counter++]);
            }
             if (ignore_the_N && anAnswer[counter - 1] == 'N')
            {
                counter--;
                inStream.get(anAnswer[counter++]);
                continue;
            }

            // continue reading the character
            // read the next char.
            inStream.get(anAnswer[counter++]);
            if (inStream.eof())
            {
                anAnswer[counter++] = '\n';
            }
            //there is no endl literally end thats why we cant read it
        }
        inStream.close();
        inStream.open("Answers.txt");
        //the thing get only to dot, it needs to read \n
        for (int i = 0; i < counter; i++)
                            cout << anAnswer[i];
    }

    return -77;
}
    

    
    

