#pragma once

#pragma once
#include <iostream>
#include <string>
#include "Produto.h"

using namespace std;

class Pedido {

private:
	int id;
	Produto listaprato[10];
	int listapratoindex = 0;

	Produto listabebida[10];
	int listabebidaindex = 0;
	double ptotal;

public:

	int getID();
	double getPtotal();
	int getPindex();
	int getBindex();

	string getNomePrato(int i);
	int getQuantPrato(int i);

	string getNomeBebida(int i);
	int getQuantBebida(int i);

	double getPrecoP(int i);
	double getPrecoB(int i);

	void setID(int id);

	void setPtotal(double ptotal);

	void adicionaPedido(string nprato, int qprato, double pprato, string pvalidade, int pid);
	void imprimePedido();
	double calculaPrecoPedido();

	void adicionaPedidoB(string nbebida, int qbebida, double pbebida, string bvalidade, int pid);



};