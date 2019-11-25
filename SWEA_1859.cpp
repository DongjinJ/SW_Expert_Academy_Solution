#include <iostream>

using namespace std;

int cost[1000000];

int main(){
    int T = 0;
    long long answer = 0;

    cin >> T;

    for(int i = 0;i < T;i++){
        int N;
        cin >> N;
        answer = 0;
        for(int j = 0;j < N;j++){
            cin >> cost[j];
        }                           // 한번에 다 입력받은 후

        int max = cost[N-1];        // 뒤에서부터 탐색, 현재 판매액 중에 맨 끝자리를 최대라고 보고 시작
        for(int j = N-2;j >= 0;j--){
            if(cost[j] > max)       // 판매 금액 최대값 갱신
                max = cost[j];
            else                    // 현재 금액이 최대일 경우 사들이고 나중에 되판다고 생각
                answer += max - cost[j];
        }
        printf("#%d %lld\n", i+1, answer);
    }
}