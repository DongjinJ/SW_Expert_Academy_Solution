#include <iostream>

using namespace std;

unsigned int snail[10][10];

void solution_1954(int x, int y, int N, int count){
    if(x == N || y == N || x == -1 || y == -1)
        return;

    snail[y][x] = count;
    solution_1954(x+1, y, N, count+1);
    solution_1954(x, y+1, N, count+1);
    solution_1954(x-1, y, N, count+1);
    solution_1954(x, y-1, N, count+1);
}
int main(){
    int T;

    cin >> T;

    for(int i = 0;i < T;i++){
        int N;
        
        
        cin >> N;
        solution_1954(0, 0, N, 1);

        cout << "#" << i + 1 << endl;
        for(int j = 0;j < N;j++){
            for(int k = 0;k < N;k++){
                cout << snail[j][k] << " ";
            }
            cout << endl;
        }
    }
}