#include "Produto.h"

Produto::Produto()
{
	id = 0;
	quant = 0;
	validade = "Invalido";
	nome = "Invalido";
	preco = 0;

}

Produto::Produto(int id, int quant, string validade, string nome, double preco)
{
	this->id = id;
	this->quant = quant;
	this->validade = validade;
	this->nome = nome;
	this->preco = preco;
}

int Produto::getID()
{
	return id;
}

int Produto::getQuant()
{
	return quant;
}

string Produto::getValidade()
{
	return validade;
}

string Produto::getNome()
{
	return nome;
}

double Produto::getPreco()
{
	return preco;
}

string Produto::toString()
{
	return "\nId: " + to_string(id) + "\nQuant: " + to_string(quant) + "\nValidade: " + validade + "\nNome: " + nome + "\nPreco: " + to_string(preco) + "€";
}

//recibo

void Produto::setNome(string nome)
{
	this->nome = nome;
}

void Produto::setQuant(int quant)
{
	this->quant = quant;
}

void Produto::setId(int id)
{
	this->id = id;
}

void Produto::setValidade(string validade)
{
	this->validade = validade;
}

void Produto::setPreco(double preco)
{
	this->preco = preco;
}
