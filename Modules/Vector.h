#ifndef C_MODULES_VECTOR_H
#define C_MODULES_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#define DEFINE_VECTOR(TYPE) \
typedef struct Vector_##TYPE Vector_##TYPE; \
struct Vector_##TYPE { \
    TYPE* Data; \
    size_t Size; \
    size_t Type_Size; \
    size_t Capacity; \
\
    void (*Push)(Vector_##TYPE* Self, TYPE Value); \
    TYPE (*At)(Vector_##TYPE* Self, size_t Value); \
    void (*Concat)(Vector_##TYPE* Self, Vector_##TYPE* Value); \
    void (*Destroy)(Vector_##TYPE* Self); \
}; \
\
static void Vector_##TYPE##_Push(Vector_##TYPE* Self, TYPE Value){ \
    if (Self->Size == Self->Capacity){ \
        Self->Capacity *= 2; \
        Self->Data = (TYPE*)realloc(Self->Data, Self->Type_Size * Self->Capacity); \
    } \
\
    Self->Data[Self->Size] = Value; \
    Self->Size++; \
} \
static TYPE Vector_##TYPE##_At(Vector_##TYPE* Self, size_t Value){ \
    if (Self->Size == 0){ \
        fprintf(stderr, "Erro [C-Modules]: tentativa de acessar um vetor sem elementos\n"); \
        exit(1); \
    } \
    if (Value > Self->Size){ \
        fprintf(stderr, "Erro [C-Modules]: tentativa de acessar o indice (%zu) fora do limite do vetor (%zu)\n", Value, Self->Size - 1); \
        exit(1); \
    } \
    return Self->Data[Value]; \
} \
static void Vector_##TYPE##_Concat(Vector_##TYPE* Self, Vector_##TYPE* Value){ \
    for(size_t i = 0; i < Value->Size; i++){ \
        Self->Push(Self, Value->At(Value, i)); \
    } \
} \
static void Destroy_Vector_##TYPE(Vector_##TYPE* Self){ \
    free(Self->Data); \
    free(Self); \
} \
\
static Vector_##TYPE* New_Vector_##TYPE(){ \
    Vector_##TYPE* Temp; \
    Temp = (Vector_##TYPE*)malloc(sizeof(Vector_##TYPE)); \
\
    Temp->Size = 0; \
    Temp->Type_Size = sizeof(TYPE); \
    Temp->Capacity = 16; \
\
    Temp->Data = (TYPE*)malloc(Temp->Type_Size * Temp->Capacity); \
\
    Temp->Push = Vector_##TYPE##_Push; \
    Temp->At = Vector_##TYPE##_At; \
    Temp->Concat = Vector_##TYPE##_Concat; \
    Temp->Destroy = Destroy_Vector_##TYPE; \
\
    return Temp; \
}

DEFINE_VECTOR(int);
DEFINE_VECTOR(char);

#endif