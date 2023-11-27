#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Produto {

private:
	int id;
	int quant;
	string validade;
	string nome;
	double preco;

public:

	Produto();
	Produto(int id, int quant, string validade, string nome, double preco);

	int getID();
	int getQuant();
	string getValidade();
	string getNome();
	double getPreco();

	//recibo
	void setNome(string nome);
	void setQuant(int quant);
	void setId(int id);
	void setValidade(string validade);
	void setPreco(double preco);

	string toString();
};