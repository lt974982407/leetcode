#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    vector<int> left,right;
    stack<int> s;
    for(int i = 0; i < heights.size(); i++){
        while(!s.empty() && heights[s.top()] >= heights[i])
            s.pop();
        if(s.empty())
            left.push_back(-1);
        else
            left.push_back(s.top());
        s.push(i);
    }
    s = stack<int>();
    for(int i = heights.size() - 1; i >= 0; i--){
        while(!s.empty() && heights[s.top()] >= heights[i])
            s.pop();
        if(s.empty())
            right.push_back(heights.size());
        else
            right.push_back(s.top());
        s.push(i);
    }
    int res = -1;
    for(int i = 0; i < heights.size(); i++){
        res = max(res,(right[heights.size() - 1 -i]  - left[i] -1) * heights[i]);
        cout<<(right[heights.size() - 1 -i]  - left[i] -1) * heights[i]<<endl;
        //cout<<left[i]<<' '<<right[heights.size() - 1 -i]<<endl;
    }
    return res;
}

int main() {
    vector<int> test = {2,1,5,6,2,3};
    cout<<largestRectangleArea(test);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
