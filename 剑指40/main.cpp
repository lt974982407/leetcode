#include <iostream>
#include <vector>

using namespace std;

void div(vector<int>& a, int begin,int end,int k){
    int tmp = a[begin];
    int i = begin,j = end;
    while(i < j){
        while(i < j && a[j] >= tmp)
            j--;
        if (i < j){
            a[i] = a[j];
            i++;
        }
        while(i < j && a[i] <= tmp)
            i++;
        if(i < j){
            a[j] = a[i];
            j--;
        }
    }
    a[i] = tmp;
    if(i - begin + 1 == k)
        return;
    else if (i - begin + 1 > k)
        div(a,begin,end - 1,k);
    else
        div (a,i + 1,end,k - (i - begin + 1));
}

vector<int> getLeastNumbers1(vector<int>& arr, int k) {
    if(k >= arr.size())
        return arr;
    if (k == 0)
        return vector<int>(0);
    div(arr,0,arr.size()-1,k);
    vector<int> res;
    for(int i = 0; i < k ; i++){
        res.push_back(arr[i]);
    }
    return res;
}

void percolate(vector<int>& a,int hole,int size){
    int child;
    int tmp = a[hole];

    for(;hole * 2 + 1 < size; hole = child){
        child = hole * 2 + 1;
        if (child + 1 < size && a[child + 1] < a[child])
            child ++;
        if(a[child] < tmp)
            a[hole] = a[child];
        else
            break;
    }
    a[hole] = tmp;
}

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    if(k >= arr.size())
        return arr;
    if (k == 0)
        return vector<int>(0);
    for (int i = arr.size()/2 - 1; i >= 0; i--)
        percolate(arr,i,arr.size());
    vector<int> res;
    for (int i = 0; i < k ; i++){
        res.push_back(arr[0]);
        arr[0] = arr[arr.size() - 1 - i];
        percolate(arr,0,arr.size() - i);
    }
    return res;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
