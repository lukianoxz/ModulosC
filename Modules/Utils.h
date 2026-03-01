#ifndef C_MODULES_UTILS_H
#define C_MODULES_UTILS_H

#include "Vector.h"

static void Print_Int_Vector(Vector_int* Vector, int JumpLine){
    for(size_t i = 0; i < Vector->Size; i++){
        printf("%d", Vector->At(Vector, i));

        if(i != (Vector->Size - 1)){
            printf(", ");
        }
    }
    if(JumpLine){
        printf("\n");
    }
}

#endif