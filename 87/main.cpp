#include <iostream>

using namespace std;


int main() {
    int *a = new int (5);
    unsigned char* p = (unsigned char *) &a;
    cout<<sizeof (a)<<endl;
    for(int i = 0; i < sizeof(int *); i++ )
        printf(" %.2x",p[i]);
    return 0;
}
