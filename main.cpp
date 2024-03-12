#include "Vector.h"
#include <iostream>
#include <initializer_list>

int main() {
    Vector<int> ob3 = {1,3,4,5};
    ob3.insert(2, 200);
    ob3.push_front(300);
    ob3.display();
}

