#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int len = matrix.size();
    while (len > 1){
        for(int i = 0 ; i < len - 1; i++){
            int index = i;
            int tmp = matrix[(matrix.size() - len)/2][(matrix.size() - len)/2 + i];
            for(int j = 0; j < 4 ; j++){
                index += (len - 1);
                int row = 0, col = 0;
                int a = index % (4 * (len -1));
                int b = a % (len -1);
                a = a / (len -1);
                if(a == 0){
                    col = (matrix.size() - len)/2;
                    row = (matrix.size() - len)/2 + b;
                } else if(a == 1){
                    col = (matrix.size() - len)/2 + b;
                    row = matrix.size() - 1 - (matrix.size() - len)/2;
                } else if(a == 2){
                    col = matrix.size() - 1 - (matrix.size() - len)/2;
                    row = matrix.size() - 1 - (matrix.size() - len)/2 - b;
                } else if(a == 3){
                    col = matrix.size() - 1 - (matrix.size() - len)/2 - b;
                    row = (matrix.size() - len)/2 ;
                }
                int temp = matrix[col][row];
                matrix[col][row] = tmp;
                tmp = temp;
            }
        }
        len -= 2;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
