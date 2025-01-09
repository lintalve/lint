//
//  main.cpp
//  lint
//
//  Created by lint on 10.11.24.
//

#include <iostream>
#include "dynoFloatArray.hpp"

int main(int argc, const char * argv[]) {
    using namespace lint;
    // insert code here...
    std::cout << "Hello, World!\n";
    
    typedef lint::FloatDynoArray Farray;
    puts("\n");
    
    Farray fa1;
    
    float f = 5.2;
    
    float ff1[] = {1.3, 5.5, 7.5, 4.2, 8.9};
    
    fa1.append(5.5f);
    fa1.append(3.5f);
    fa1.append(2.5f);
    fa1.append(7.5f);
    fa1.append(6.5f);
    fa1.append(9.5f);
    fa1.print();
    
    printf("adress %p %f\n", fa1.storage,  *(fa1.storage));
    printf("adress %p %f\n", fa1.storage+1,  *(fa1.storage+1));
    printf("adress %p %f\n", fa1.storage+2,  *(fa1.storage+2));

    
    
    printf("%zu", sizeof(float));
    
    return 0;
}
