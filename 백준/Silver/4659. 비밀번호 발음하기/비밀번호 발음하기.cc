#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char input[21] = "";

    while(1)
    {
        bool acceptable = true;
        cin >> input;

        if(!strcmp(input, "end")) 
            break;
        
        if(!(strchr(input, 'a') || strchr(input, 'e') || strchr(input, 'i') || strchr(input, 'o') || strchr(input, 'u')))
            acceptable = false;
        
        int consonants = 0, vowels = 0;
        for(int i = 0; i < strlen(input); i++)
        {
            if(input[i] == input[i + 1])
            {
                if(input[i] == 'e')
                    continue;

                if(input[i] == 'o')
                    continue;
                
                acceptable = false;
                break;
            }

            switch (input[i])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowels++;
                    consonants = 0;
                    break;
            
                default:
                    consonants++;
                    vowels = 0;
                    break;
            }
            if(vowels == 3 || consonants == 3)
            {
                acceptable = false;
                break;
            }
        }
        cout << "<" << input << "> "; 
        if(acceptable)
            cout << "is acceptable.\n";
        else
            cout << "is not acceptable.\n";

    }

    return 0;
}