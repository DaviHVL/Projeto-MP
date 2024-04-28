#include "romanos.hpp"
#include <unordered_map>

/*
 Implementação da função para verificar
 se há apenas algarismos romanos.
*/
bool verificador_caracteres(const string& num_romano) {
    const string letras = "IVXLCDM";
    for (char caracter : num_romano) {
        if (letras.find(caracter) == string::npos) {
            return false;
        }
    }
    return true;
}

/*
Implementação da função para verificar
se as letras: V, L e D aparecem duas vezes seguidas.
*/
bool verificador_vld(const string& num_romano) {
    if (num_romano.length() == 1) {
        return true;
    }

    if (num_romano.length() == 2  &&
         num_romano[0] == num_romano[1] &&
          num_romano[0] == 'V')  {
            return false;
    }

    if (num_romano.length() == 2  &&
         num_romano[0] == num_romano[1] &&
          num_romano[0] == 'L')  {
            return false;
    }

    if (num_romano.length() == 2  &&
         num_romano[0] == num_romano[1] &&
          num_romano[0] == 'D')  {
            return false;
    }
    for (size_t i =0; i < (num_romano.length()-2); i++) {
        if (num_romano[i] == num_romano[i+1] &&
             num_romano[i] == 'V') {
            return false;
        }
        if (num_romano[i] == num_romano[i+1] &&
             num_romano[i] == 'L') {
            return false;
        }
        if (num_romano[i] == num_romano[i+1] &&
             num_romano[i] == 'D') {
            return false;
        }
    }
    return true;
}

/*
Implementação da função para verificar
se uma letra aparece mais de três vezes seguidas.
*/
bool verificador_mais(const string& num_romano) {
    if (num_romano.length() < 4) {
            return true;
    }
    for (size_t i =0; i <= (num_romano.length()-4); i++) {
        if (num_romano[i] == num_romano[i+1] &&
             num_romano[i+1] == num_romano[i+2] &&
              num_romano[i+2] == num_romano[i+3]) {
            return false;
        }
    }
    return true;
}

/*
Função para verificar se a subtração é válida.
*/
bool verificador_subtracoes(const string& num_romano) {
    unordered_map<char, int>mapa_romano = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int ultValor = 0;

    for (int i = num_romano.length() - 1; i >= 0; --i) {
        char atualChar = num_romano[i];
        int atualValor = mapa_romano[atualChar];

        if (atualValor < ultValor) {
            if (!((atualValor == 1 && (ultValor == 5 || ultValor == 10)) ||
                  (atualValor == 10 && (ultValor == 50 || ultValor == 100)) ||
                  (atualValor == 100 &&
                    (ultValor == 500 || ultValor == 1000)))) {
                return false;
            }
        }
        ultValor = atualValor;
    }
    return true;
}

/*
Função principal.
*/
int romanos_para_decimal(const string& num_romano) {
    if (!verificador_caracteres(num_romano)) {
        return -1;
    }
    if (!verificador_vld(num_romano)) {
        return -1;
    }
    if (!verificador_mais(num_romano)) {
        return -1;
    }

    if (!verificador_subtracoes(num_romano)) {
        return -1;
    }

    unordered_map<char, int>mapa_romano = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int result = 0;

    for (size_t i = 0; i < (num_romano.length()); i++) {
        if (i+1 < num_romano.length() &&
             mapa_romano[num_romano[i+1]] > mapa_romano[num_romano[i]]) {
            result -= mapa_romano[num_romano[i]];
        } else {
            result += mapa_romano[num_romano[i]];
        }
    }

    if (result < 0) {
        return -1;
    } else {
        return result;
    }
}
