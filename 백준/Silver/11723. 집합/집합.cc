#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#define BufferSize 3
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;
    cin.ignore();

    char * mBuffer = new char[BufferSize];
    memset(mBuffer, 0, BufferSize);

    while(M--)
    {
        string str;
        getline(cin, str);

        int blank_pos = str.find(" ");

        if(blank_pos == -1)
        {
            if(str == "empty")
            {
                memset(mBuffer, 0, BufferSize);
            }
            else if(str == "all")
            {
                memset(mBuffer, 255, BufferSize);
            }
        }
        else
        {
            string command = str.substr(0, blank_pos);

            size_t bit_pos = static_cast<size_t>(stoi(str.substr(blank_pos + 1)));
            size_t byte_idx = bit_pos / 8;
            size_t bit_idx = bit_pos % 8;

            if(command == "add")
            {
                mBuffer[byte_idx] |= (1 << bit_idx);
            }
            else if(command == "check")
            {
                if((mBuffer[byte_idx] >> bit_idx) & 1)
                    cout << 1 << "\n";
                else
                    cout << 0 << "\n";
            }
            else if(command == "toggle")
            {
                if((mBuffer[byte_idx] >> bit_idx) & 1)
                    mBuffer[byte_idx] ^= (1 << bit_idx);
                else
                    mBuffer[byte_idx] |= (1 << bit_idx);
            }
            else if(command == "remove")
            {
                if((mBuffer[byte_idx] >> bit_idx) & 1)
                    mBuffer[byte_idx] ^= (1 << bit_idx);
            }
        }

        // for(int i = 0; i < BufferSize; i++)
        // {
        //     cout << "[Byte " << i << "] " << bitset<8>(mBuffer[i]) << "\n";
        // }
        // cout << endl;
    }

    delete[] mBuffer;

    return 0;
}