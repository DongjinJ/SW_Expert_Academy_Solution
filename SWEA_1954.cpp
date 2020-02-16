#include <iostream>

using namespace std;

unsigned int snail[10][10];

int main(){
    int T;

    cin >> T;

    for(int i = 0;i < T;i++){
        int N;
        
        cin >> N;
        
        int x = -1, y = -1;
        int dx = N, dy = N;
        int count = 1;
        while(dx != x || dy != y){
            int j = x, k = y;
            for(j = x + 1;j < dx;j++){
                snail[k+1][j] = count++;
            }
            if(count > N*N)
                break;
            j--;
            y++;

            for(k = y + 1;k < dy;k++){
                snail[k][j] = count++;
            }
            k--;
            dx--;
            dy--;
            
            for(j = dx - 1;j > x;j--){
                snail[k][j] = count++;
            }
            if(count > N*N)
               break;
            j++;

            for(k = dy - 1;k > y;k--){
                snail[k][j] = count++;
            }
            x++;
        }
        cout << "#" << i + 1 << endl;
        for(int j = 0;j < N;j++){
            for(int k = 0;k < N;k++){
                cout << snail[j][k] << " ";
            }
            cout << endl;
        }
    }



    
}