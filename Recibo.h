#pragma once

#pragma once
#include "Cliente.h"
#include "Produto.h"
#include <windows.h> //vai buscar a hora do sistema Microsoft
#include <stdio.h>
#include <string> 
#include <sstream> //converter cout para string Microsoft

class Recibo {

private:

	string hora;

	int num_pedido;
	int num_cliente;
	int num_linha;
	Produto pratos[99];
	int pratoindex = 0;
	double precounit[99];
	int precounitindex = 0;
	double total;
	double valor_pago;
	double troco;
	int limiteprato = 0;

public:

	void setNumPedido(int idped);
	void setNumCliente(int idcli);
	void setTotal(double total);
	void setValorPago(double valorpago);
	void setTroco(double troco);
	void setNumItens(int num);
	void setHora();

	int getIdPed();
	int getNumCli();
	double getTotal();
	double getValorPago();
	double getTroco();
	int getPIndex();
	string getNomeP(int i);
	int getQuantP(int i);
	string getHora();

	//adicionaprato
	void addPrato(int pid, double pprato, int tam, string nprato, int qprato, int i);
	void imprimeVenda();

	//adicionabebida 
	void addBebida(int pid, double pbebida, int tam, string nbebida, int qbebida, int t);

	//relatorio
	double getPrecoUnit(int i);

	//conta o numero de pratos que existem no pedido
	void setLimite(int limiteprato);
	int getLimite();
};