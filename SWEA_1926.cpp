#include <iostream>

using namespace std;

int main(){
    int N;

    scanf("%d", &N);

    for(int i = 1;i <= N;i++){
        string num = to_string(i);              // 문자열로 변환
        int count = 0;
        for(int j = 0;j < num.length();j++){
            if(num[j] == '3' || num[j] == '6' || num[j] == '9'){                // 각 자리 숫자가 3, 6, 9 일 떄, '-' 출력  
                printf("-");
                count++;
            }
            else 
                ;
        }
        if(count == 0)
            printf("%d ", i);               // 3, 6, 9가 없을 경우 숫자 그대로 출력 
        else   
            printf(" ");                    // 3, 6, 9가 있을 경우 공백 출력
    }

    return 0;
}