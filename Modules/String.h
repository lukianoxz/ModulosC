#ifndef C_MODULES_STRING_H
#define C_MODULES_STRING_H

#include <stdio.h>
#include "Vector.h"

typedef struct String String;
struct String {
    Vector_char* Data;

    void (*Append)(String* Self, const char* C_String);
    void (*Print)(String* Self);
    void (*Guin)(String* Self);
    void (*Concat)(String* Self, String* Value);
    void (*Destroy)(String* Self);
};

static void String_Append(String* Self, const char* C_String){
    size_t C_String_Size = 0;

    while(C_String[C_String_Size] != '\0'){
        C_String_Size++;
    }

    for(size_t i = 0; i < C_String_Size; i++){
        Self->Data->Push(Self->Data, C_String[i]);
    }
}

static void String_Print(String* Self){
    for(size_t i = 0; i < Self->Data->Size; i++){
        putchar(Self->Data->At(Self->Data, i));
    }
}

static void String_Guin(String* Self){
    int C;

    while((C = getchar()) != '\n' && C != EOF){
        Self->Data->Push(Self->Data, C);
    }
}

static void String_Concat(String* Self, String* Value){
    Self->Data->Concat(Self->Data, Value->Data);
}

static void Destroy_String(String* Self){
    Self->Data->Destroy(Self->Data);
    free(Self);
}

static String* New_String(){
    String* Temp = (String*)malloc(sizeof(String));

    Temp->Data = New_Vector_char();

    Temp->Append = String_Append;
    Temp->Print = String_Print;
    Temp->Guin = String_Guin;
    Temp->Destroy = Destroy_String;

    return Temp;
}

#endif