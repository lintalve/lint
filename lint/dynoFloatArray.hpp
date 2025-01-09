//
//  dynoFloatArray.hpp
//  lint
//
//  Created by lint on 09.01.25.
//

#ifndef DYNO_FLOAT_ARRAY
#define DYNO_FLOAT_ARRAY
/*
 In this file we are still using 4 in stead of (int)sizeof(float)
 to be as simple and explicit as we can
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace lint {

class FloatDynoArray {
public:
    static const int size = 8;
    float* storage = nullptr;
    int index {};
    int totalSize {};
    int usedSpace {};
    

    FloatDynoArray() : usedSpace(index * 4) {
        storage = (float*)malloc(size);
        memset(storage, 0, size);
        totalSize = size;
    }
    void inflate(int inc = 4) {
        puts("\n");
        printf("entering inflate function\n");
        float* temp = (float*)malloc(index * 4 + inc);
        memset(temp, 0, index * 4 + inc);
        memcpy(temp, storage, index * 4);
        free(storage);
        storage = temp;
        totalSize = index * 4 + inc;
        printf("the total size is now %i\n", totalSize);
        
        printf("exiting append float function\n");
        puts("\n");
        
        
    }
    void append(float f) {
        printf("entering append float function\n");
        
        printf("the total size is now %i\n", totalSize);
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        if((totalSize - (index * 4)) < 4) inflate(8);
        //pointer arithmentic
        printf("assigning an element into the pointer of index %i\n", index);
        *(storage + index) = f;
        printf("and the contend in the index %i is %f\n", index, *(storage + index));
        printf("the used size is now %i\n", (totalSize - (totalSize - (index + 1) * 4)));
        printf("the total size is now %i\n", totalSize);
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        
        index++;
        printf("the unused space is %i bytes\n", totalSize - (index * 4));
        printf("exiting append float function\n");
        printf("and the contend in the index %i is %f\n", index-1, *(storage + (index-1)));
        puts("\n");
        
    }
    void append(float f[], size_t a_size) {
        if(totalSize - index < a_size) inflate(a_size);
        for(int i=0; i < a_size/4; i++) {
            *(storage + i) = f[i];
            index++;
        }
        usedSpace += a_size;
    }
    float get(int index) {
        return *storage;
    }
    float& operator[](int index) {
        return *(storage + index);
    }
    FloatDynoArray& operator+(const FloatDynoArray& fda) {
        return *this;
    }
    void print() {
        for(int i=0; i<index; i++) {
            printf("%f ", *(storage + i));
        }
    puts("\n");
    }
};

};
#endif //DYNO_FLOAT_ARRAY
