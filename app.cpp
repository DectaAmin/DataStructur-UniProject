#include <iostream>
#include "sparce.h"

using namespace std;

int main(void){
    Node* p = getNode(2, 2 , 2);
    addNode(p, 0, 0, 1);
    addNode(p, 0, 1, 2);
    Node* q = getNode(2, 2, 2);
    addNode(q, 1, 0, 89);
    addNode(q, 0, 0, 56);
    
    Node* r = mult(q, p);
    print(r);
    cout << endl;
    r = add(p, q);
    print(r);
    cout << endl;
    r = Notadd(q, p);
    print(r);

    return 0;
}