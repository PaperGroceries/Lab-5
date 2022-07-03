//
//  main.cpp
//  test3
//
//  Created by Aim Kim on 2022-07-02.
//

#include <iostream>
#include <fstream>

using namespace std;

int NUMBER_OF_CHAPTERS = 0;
int get_next_number() {
    return 18 - (NUMBER_OF_CHAPTERS++ % 18);
}

int main() {
    ifstream input_stream;
    while (true) {

        input_stream.open("answers.txt");
        if (input_stream.fail()) {
            cout << "Plz make sure that your file name correct";
        }

        //read a question
        cout << "\nPlease enter your question" << endl;
        string q; cin >> q;
        cin.ignore();

        char a_char;
        input_stream.get(a_char);
        int counter = 0;
        char answer_arr[100];

        bool hash_flag = false;
        while (!input_stream.eof()) {
            if (hash_flag && a_char == 'N') {

                input_stream.get(a_char);
                continue;
            }

            if (a_char == '\n') {
                // output the answer
                for (int i = 0; i < counter; i++)
                    cout << answer_arr[i];

                // ask for another questions
                // read a question
                cout << "\nPlease enter your question" << endl;
                string q; cin >> q;
                cin.ignore();

                counter = 0;
            }
            else if (a_char == '#') {
                // may be should get the next number 18, 17, 16, ...10, 9, 8, ..., 1, 18, 17, ...
                int x = get_next_number();
                // add this this to the array
                if (x >= 10) // two
                {
                    answer_arr[counter++] = '1';
                    answer_arr[counter++] = '0' + x - 10; // convert int -> char
                }
                else // one digit
                    answer_arr[counter++] = '0' + x;  //5 => '5'
                                            // 48 + 5 = 53

                // Also, we have to ignore 'N'
                hash_flag = true;

            }
            else {
                answer_arr[counter++] = a_char;
            }

            input_stream.get(a_char);
        }
        input_stream.close();
        // output the last answer
        for (int i = 0; i < counter; i++)
            cout << answer_arr[i];

    }
}

