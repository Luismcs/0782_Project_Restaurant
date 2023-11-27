#include "Recibo.h"
#include "Pedido.h"

void Recibo::setNumPedido(int numped)
{
	this->num_pedido = numped;
}

void Recibo::setNumCliente(int numcli)
{
	this->num_cliente = numcli;
}

void Recibo::setTotal(double total)
{
	this->total = total;
}

void Recibo::setValorPago(double valorpago)
{
	this->valor_pago = valorpago;
}

void Recibo::setTroco(double troco)
{
	this->troco = troco;
}

void Recibo::setHora()
{
	ostringstream stream;


	SYSTEMTIME st, lt;//hora
	SYSTEMTIME sd, ld;//dia

	SYSTEMTIME hora;

	GetSystemTime(&st);
	GetLocalTime(&lt);

	stream << st.wDay << "/" << st.wMonth << "/" << st.wYear << "   " << st.wHour << ":" << st.wMinute << endl;

	GetSystemTime(&hora);
	string result = stream.str();

	this->hora = result;
}

int Recibo::getIdPed()
{
	return num_pedido;
}

int Recibo::getNumCli()
{
	return num_cliente;
}

double Recibo::getTotal()
{
	return total;
}

double Recibo::getValorPago()
{
	return valor_pago;
}

double Recibo::getTroco()
{
	return troco;
}

int Recibo::getPIndex()
{
	return pratoindex;
}

string Recibo::getNomeP(int i)
{
	return pratos[i].getNome();
}

int Recibo::getQuantP(int i)
{
	return pratos[i].getQuant();
}

string Recibo::getHora()
{
	return hora;
}

void Recibo::addPrato(int pid, double pprato, int tam, string nprato, int qprato, int i)
{

	pratos[i] = Produto(pid, qprato, "0", nprato, pprato);
	precounit[precounitindex] = pratos[i].getPreco() / pratos[i].getQuant();
	precounitindex++;
	pratoindex++;

}

void Recibo::imprimeVenda()
{
	cout << "\n";
	cout << "\t\t   Artigo" << setw(20) << "Quantidade" << setw(21) << "Preço Unitario" << setw(22) << "Total\n";

	for (int i = 0; i <= pratoindex; i++) {
		if (pratos[i].getNome() != "Invalido") {
			cout << setw(5) << i + 1;
			cout << setw(20) << pratos[i].getNome();
			cout << setw(20) << pratos[i].getQuant();
			cout << setw(20) << fixed << setprecision(2) << pratos[i].getPreco() / pratos[i].getQuant() << "€";
			cout << setw(20) << fixed << setprecision(2) << pratos[i].getPreco() << "€\n";
		}
	}
}


double Recibo::getPrecoUnit(int i)
{
	return precounit[i];
}

void Recibo::setLimite(int limiteprato)
{
	this->limiteprato = limiteprato; //conta o numero de pratos que tem o pedido
}

int Recibo::getLimite()
{
	return limiteprato;
}















