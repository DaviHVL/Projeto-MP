#include <iostream>
#include <string>

using namespace std;

//fun��o para verificar se h� apenas algarismos romanos
bool verificador_caracteres(const string& num_romano);

//As letras: V, L e D n�o podem aparecer duas vezes seguidas
//fun��o para verificar se h� isso ocorre ou n�o
bool verificador_vld(const string& num_romano);


int romanos_para_decimal(const string& num_romano);

