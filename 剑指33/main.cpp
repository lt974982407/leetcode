#include <iostream>
#include <vector>


using namespace std;

bool rec(vector<int> postorder, int start, int end){
    if(start >= end)
        return true;
    int i = start;
    for(;i < end; i++){
        if(postorder[i] > postorder[end]){
            break;
        }
    }
    for(int k = i; k < end; k++){
        if(postorder[k] < postorder[end])
            return false;
    }
    return rec(postorder,start, i - 1) && rec(postorder,i,end -1);
}

bool verifyPostorder(vector<int>& postorder) {
    if(postorder.size() == 0)
        return false;
    return rec(postorder,0,postorder.size() - 1);
}

int main() {
    vector<int> test= {1,6,3,2,5};
    std::cout << verifyPostorder(test) << std::endl;
    return 0;
}
