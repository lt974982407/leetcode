#include <iostream>
#include <vector>

using namespace std;


int minArray(vector<int>& numbers) {
    int num = numbers.size();
    int tmp = numbers[0];
    for (int i = 1; i < num ; i++){
        if (numbers[i] >= tmp){
            tmp = numbers[i];
        }
        else
            return numbers[i];
    }
    return numbers[0];

}

int minArray1(vector<int>& numbers){
    int i = 0;
    int j = numbers.size()-1;
    while(i < j){
        int m = (i + j)/2;
        if (numbers[j] > numbers[m])
            j = m;
        else if (numbers[j] < numbers[m])
            i = m + 1;
        else
            j--;
    }
    return numbers[j];
}

int main() {

    return 0;
}
