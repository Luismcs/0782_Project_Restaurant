#include "Pedido.h"


int Pedido::getID()
{
	return id;
}

double Pedido::getPtotal()
{
	return ptotal;
}

int Pedido::getPindex()
{
	return listapratoindex;
}

int Pedido::getBindex()
{
	return listabebidaindex;
}

void Pedido::setID(int id)
{
	this->id = id;
}

string Pedido::getNomePrato(int i)
{
	return listaprato[i].getNome();
}

int Pedido::getQuantPrato(int i) {
	return listaprato[i].getQuant();
}

string Pedido::getNomeBebida(int i)
{
	return listabebida[i].getNome();
}

int Pedido::getQuantBebida(int i)
{
	return listabebida[i].getQuant();
}

void Pedido::setPtotal(double ptotal)
{
	this->ptotal = ptotal;
}



void Pedido::adicionaPedido(string nprato, int qprato, double pprato, string pval, int pid)
{
	int id = 0;
	string vprato = "Invalido";
	for (int i = 0; i <= listapratoindex; i++) {
		if (listaprato[i].getNome() == "Invalido") {
			listaprato[i] = Produto(pid, qprato, pval, nprato, pprato);
			listapratoindex++;
			break;

		}
	}
}

double Pedido::getPrecoP(int i)
{
	return listaprato[i].getPreco();
}

double Pedido::getPrecoB(int i)
{
	return listabebida[i].getPreco();

}

void Pedido::imprimePedido()
{
	bool ver = false;

	for (int i = 0; i <= listapratoindex; i++) {
		if (listaprato[i].getNome() != "Invalido") {
			cout << "\nPrato: " << listaprato[i].getNome();
			cout << "\nQuantidade: " << listaprato[i].getQuant();
			cout << "\nPreco: " << fixed << setprecision(2) << listaprato[i].getPreco() << "\n\n";
			ver = true;
		}
	}

	for (int i = 0; i <= listabebidaindex; i++) {
		if (listabebida[i].getNome() != "Invalido") {
			cout << "Pedido " << i + 1 << " :";
			cout << "\nPrato: " << listabebida[i].getNome();
			cout << "\nQuantidade: " << listabebida[i].getQuant();
			cout << "\nPreco: " << fixed << setprecision(2) << listabebida[i].getPreco() << "\n\n";
			ver = true;
		}
	}

	if (ver == false) {
		cout << "Pedido Vazio\n";
	}
}


double Pedido::calculaPrecoPedido()
{
	double precop = 0;
	for (int i = 0; i <= listapratoindex; i++) {
		precop = precop + listaprato[i].getPreco();
	}

	for (int i = 0; i <= listabebidaindex; i++) {
		precop = precop + listabebida[i].getPreco();
	}

	return precop;
}

void Pedido::adicionaPedidoB(string nbebida, int qbebida, double pbebida, string bvalidade, int pid)
{
	int id = 0;
	string vbebida = "Invalido";
	for (int i = 0; i <= listabebidaindex; i++) {
		if (listabebida[i].getNome() == "Invalido") {
			listabebida[i] = Produto(pid, qbebida, bvalidade, nbebida, pbebida);
			listabebidaindex++;
			break;

		}
	}
}
