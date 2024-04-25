#include "romano.hpp.hpp"

//implementação da função para verificar se há apenas algarismos romanos
bool verificador_caracteres(const string& num_romano) {
    const string letras = "IVXLCDM";
    for (char caracter : num_romano) {
        if (letras.find(caracter) == string::npos) {
            return false;
        }
    }
    return true;
}

//implementação da função para verificar se as letras: V, L e D aparecem duas vezes seguidas
bool verificador_vld(const string& num_romano){
    for (int i =0; i<(num_romano.length()-2); i++) {
        if (num_romano[i] == num_romano[i+1] && num_romano[i] == 'V'){
            return false;
        }
        if (num_romano[i] == num_romano[i+1] && num_romano[i] == 'L'){
            return false;
        }
        if (num_romano[i] == num_romano[i+1] && num_romano[i] == 'D'){
            return false;
        }
    return true;
    }
}

int romanos_para_decimal(const string& num_romano){
    if (!verificador_caracteres(num_romano)){
        return -1;
    }
    if (!verificador_vld(num_romano)){
        return -1;
    }
    return 0;
}

