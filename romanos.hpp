#include <iostream>
#include <string>

using namespace std;

/*
Função para verificar se há apenas algarismos romanos.
*/
bool verificador_caracteres(const string& num_romano);

/*
As letras: V, L e D não podem aparecer duas vezes seguidas.
Função para verificar se há isso ocorre ou não.
*/
bool verificador_vld(const string& num_romano);

/*
Uma letra não pode aparecer mais de três vezes seguidas.
Função para verificar se há isso ocorre ou não.
*/
bool verificador_mais(const string& num_romano);

/*
Função para verificar se a subtração é válida.
*/
bool verificador_subtracoes(const string& num_romano);

/*
Função principal.
*/
int romanos_para_decimal(const string& num_romano);

