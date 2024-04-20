#include "romano.hpp.hpp"

//implementa��o da fun��o para verificar se h� apenas algarismos romanos
bool verificador_caracteres(const string& num_romano) {
    const string letras = "IVXLCDM";
    for (char caracter : num_romano) {
        if (letras.find(caracter) == string::npos) {
            return false;
        }
    }
    return true;
}

int romanos_para_decimal(const string& num_romano){
    if (!verificador_caracteres(num_romano)){
        return -1;
    }
    return 0;
}

