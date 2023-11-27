#include "Cliente.h"

Cliente::Cliente()
{
	id = 0;
	nome = "Invalido";
	telefone = "Invalido";
	endereco = "Invalido";
}

Cliente::Cliente(int id, string nome, string telefone, string endereco)
{
	this->id = id;
	this->nome = nome;
	this->telefone = telefone;
	this->endereco = endereco;
}


int Cliente::getId()
{
	return id;
}

string Cliente::getTelefone()
{
	return telefone;
}

string Cliente::getEndereco()
{
	return endereco;
}

string Cliente::getNome() {
	return nome;
}

void Cliente::setNome(string nome) {
	this->nome = nome;
}

void Cliente::setId(int id)
{
	this->id = id;
}

void Cliente::setTelefone(string telefone)
{
	this->telefone = telefone;
}

void Cliente::setEndereco(string endereco)
{
	this->endereco = endereco;
}

string Cliente::toString()
{
	return "\nId: " + to_string(id) + "\nNome: " + nome + " \nTelefone: " + telefone + "\nEndereco: " + endereco;
}

