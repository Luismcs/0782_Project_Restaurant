#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cliente {

private:
	int id;
	string nome;
	string telefone;
	string endereco;


public:

	Cliente();
	Cliente(int id, string nome, string telefone, string endereco);

	int getId();
	string getNome();
	string getTelefone();
	string getEndereco();

	void setNome(string nome);
	void setId(int id);
	void setTelefone(string telefone);
	void setEndereco(string endereco);


	string toString();
};