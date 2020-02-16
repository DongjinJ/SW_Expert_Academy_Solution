#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(){
    int T;

    cin >> T;
    cin.ignore();


    for(int i = 0;i < T;i++){
        string Decoding;
        getline(cin, Decoding);

        cout << "#" << i+1 << " ";

        for(int j = 0;j < Decoding.length()/4;j++){
            int temp_Encoding = 0;
            for(int k = 0;k < 4;k++){
                if(Decoding[j*4 + k] >= 'A' && Decoding[j*4 + k] <= 'Z'){   
                    temp_Encoding |= ((int)Decoding[j*4 + k] - 'A') << 6*(3-k);
                }
                else if(Decoding[j*4 + k] >= 'a' && Decoding[j*4 + k] <= 'z'){
                    temp_Encoding |= (Decoding[j*4 + k] - 'a' + 26) << 6*(3-k);
                }
                else if(Decoding[j*4 + k] >= '0' && Decoding[j*4 + k] <= '9'){
                    temp_Encoding |= (Decoding[j*4 + k] - '0' + 52) << 6*(3-k);
                }
                else if(Decoding[j*4 + k] == '+'){
                    temp_Encoding |= 62 << 6*(3-k);
                }
                else{
                    temp_Encoding |= 63 << 6*(3-k);
                }
            }
            
            int First = (temp_Encoding & 0x00FF0000) >> 16;
            // cout << bitset<32>(First) << endl;
            int Second = (temp_Encoding & 0x0000FF00) >> 8;
            // cout << bitset<32>(Second) << endl;
            int Third = (temp_Encoding & 0x000000FF);
            // cout << bitset<32>(Third) << endl;

            cout << (char)First << (char)Second << (char) Third;
            // cout << "Index: " << First << " " << Second << " " << Third << endl;
            
        }
        cout << endl;
    }
}