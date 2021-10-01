#include <iostream>

using namespace std;


int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int res = abs(ax1 - ax2) * abs(ay1 - ay2) + abs(bx1 - bx2) * abs(by2 - by1);
    if(min(max(ax1,ax2),max(bx1,bx2)) > max(min(ax1,ax2),min(bx1,bx2)) && min(max(ay1,ay2),max(by1,by2)) > max(min(ay1,ay2),min(by1,by2))){
        res = res - (min(max(ax1,ax2),max(bx1,bx2)) - max(min(ax1,ax2),min(bx1,bx2))) * (min(max(ay1,ay2),max(by1,by2)) -max(min(ay1,ay2),min(by1,by2)) );
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
