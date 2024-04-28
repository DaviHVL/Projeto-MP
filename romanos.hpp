#include <iostream>
#include <string>

using namespace std;

/*
Fun��o para verificar se h� apenas algarismos romanos.
*/
bool verificador_caracteres(const string& num_romano);

/*
As letras: V, L e D n�o podem aparecer duas vezes seguidas.
Fun��o para verificar se h� isso ocorre ou n�o.
*/
bool verificador_vld(const string& num_romano);

/*
Uma letra n�o pode aparecer mais de tr�s vezes seguidas.
Fun��o para verificar se h� isso ocorre ou n�o.
*/
bool verificador_mais(const string& num_romano);

/*
Fun��o para verificar se a subtra��o � v�lida.
*/
bool verificador_subtracoes(const string& num_romano);

/*
Fun��o principal.
*/
int romanos_para_decimal(const string& num_romano);

