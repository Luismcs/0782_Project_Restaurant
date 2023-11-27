#include "Restaurante.h"


streamsize originalPrecision = cout.precision(); //definicao do tamanho default 


//Falta Imprimir Total do pedido completo

Restaurante::Restaurante()
{
	adicionaValor(); //adiciona os valores padrão
}


//CLIENTE


void Restaurante::menuCliente()
{


	int op = 99;
	string id_teste;
	int id;
	string valid;
	string opp;

	while (op != 0) {
		cout << "\n--Menu Cliente--\n";
		cout << "\n1-Registar Novo Cliente\n";
		cout << "2-Remover Cliente\n";
		cout << "3-Alterar nome de um Cliente\n";
		cout << "4-Imprimir lista Completa\n";
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //altera texto para vermelho
		cout << "0- Voltar para o menu\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //volta a alterar o texto para branco


		cout << "\nInsira a opcao: ";
		cin >> opp;


		if(verifMenu(opp)) {

			op = stoi(opp);

			system("cls");

			switch (op) {

			case 1:
				adicionaCliente();
				break;

			case 2:
				cout << "Introduza o id do cliente a remover: ";
				cin >> id_teste;

				if (verificaInt(id_teste) == false) { //verifica se o id contem letras
					return;

				}

				else {
					int id_def = stoi(id_teste); //converte uma string para int

					removeCliente(id_def);
					break;
				}

			case 3:
				cout << "Insira o id do cliente a alterar o nome: ";
				cin >> id_teste;

				if (verificaInt(id_teste) == false) { //verifica se o id contem letras
					return;

				}

				else {
					int id_def = stoi(id_teste); //converte uma string para int

					if (id_def <= 0) {
						cout << "Introduza um id válido!\n";
						return;
					}

					else {
						alteraNome(id_def);
						break;
					}
				}

			case 4:
				imprimeLista();
				break;

			case 0:
				return;

			default:
				cout << "Insira um opção válida!\n";
			}
		}


	}
}

void Restaurante::adicionaCliente()
{
	string nome, telefone, endereco;

	cout << "--Introduza os dados do Novo Cliente--\n\n";
	cout << "Insira o nome: ";
	cin.ignore(); //ler prato
	getline(cin, nome); //ler mais que uma palavra

	cout << "Insira o telefone: ";
	cin >> telefone;

	if (verificaInt(telefone) == false) {
		return;
	}

	cout << "Insira o endereco: ";
	cin.ignore(); //ler prato
	getline(cin, endereco); //ler mais que uma palavra

	for (int i = 0; i <= cIndex; i++) { //ou <index
		if (lcliente[i].getNome() == "Invalido") {
			lcliente[i] = Cliente(i + 1, nome, telefone, endereco);
			cIndex++;
			lcliente[cIndex] = Cliente();
			system("cls");
			cout << "Cliente adicionado!\n";
			return;
		}
	}
}

void Restaurante::removeCliente(int id)
{
	if (id <= 0) { //verifica a introdução de um id válido
		cout << "Introduza um valor válido!";
		return;
	}

	for (int i = 0; i <= cIndex; i++) {
		if (lcliente[i].getId() == id) { //(buscaPessoa(nome))
			lcliente[i] = Cliente();
			cIndex--;
			system("cls");
			cout << "Cliente Removido! \n";
			return;
		}
	}
	cout << "Cliente não encontrado! \n";
}

void Restaurante::alteraNome(int id)
{
	string nome;
	cout << "Introduza o nome para o qual quer alterar: ";
	cin.ignore(); //ler prato
	getline(cin, nome); //ler mais que uma palavra

	for (int i = 0; i <= cIndex; i++) {
		if (lcliente[i].getId() == id) { //(buscaPessoa(nome))
			lcliente[i].setNome(nome);
			system("cls");
			cout << "O nome da pessoa foi alterado! \n";
			return;
		}
	}

	cout << "Pessoa não encontrada! \n";
}

void Restaurante::imprimeLista() //imprime a lista dos cliente
{
	if (cIndex == 0) {
		cout << "Lista Vazia!\n";
		return;
	}

	cout << "Lista de Clientes \n";
	for (int i = 0; i <= cIndex; i++) {
		if (lcliente[i].getNome() != "Invalido")
			cout << "\nCliente " << i + 1 << " :" << lcliente[i].toString() << '\n';
	}
	cout << "Index: " << cIndex << '\n';
}


//STOCK

void Restaurante::menuStock()
{
	int op = 99;
	string opp;

	while (op != 0) {
		cout << "\n--Menu Stock--\n";
		cout << "1-Adicionar\n";
		cout << "2-Adicionar Stock\n";
		cout << "3-Remover\n";
		cout << "4-Imprimir listas\n";
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //altera texto para vermelhor
		cout << "0- Voltar para o menu\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //volta a alterar o texto para branco

		cout << "\nInsira a opcao: ";
		cin >> opp;

		if (verifMenu(opp)) {
			op = stoi(opp);

			system("cls");
			switch (op) {
			case 1:
				menuAdic();
				break;

			case 2:
				menuAddStock();
				break;

			case 3:
				menuRemov();
				break;

			case 4:
				menuListaStock();
				break;

			case 0:
				return;

			default:
				cout << "Insira um opção válida!\n";
			}
		}

	}
}

//menu de stock

void Restaurante::menuAdic()
{
	int op = 99;
	string opp;

	while (op != 0) {
		cout << "\n--Menu Adicionar--\n";
		cout << "1-Adicionar Prato\n";
		cout << "2-Adicionar Bebida\n";
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //altera texto para vermelhor
		cout << "0- Voltar para o menu\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //volta a alterar o texto para branco


		cout << "\nInsira a opcao: ";
		cin >> opp;

		
		if (verifMenu(opp)) {

			system("cls");
			op = stoi(opp);
			switch (op) {
			case 1:
				adicionaPrato();
				break;

			case 2:
				adicionaBebida();
				break;

			case 0:
				return;

			default:
				cout << "Insira um opção válida!\n";
			}
		}


	}
}

void Restaurante::menuRemov()
{
	int op = 99;
	string opp;

	while (op != 0) {
		cout << "\n--Menu Remover--\n";
		cout << "1-Remover Prato\n";
		cout << "2-Remover Bebida\n";
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //altera texto para vermelhor
		cout << "0- Voltar para o menu\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //volta a alterar o texto para branco


		cout << "\nInsira a opcao: ";
		cin >> opp;


		if (verifMenu(opp)) {

			system("cls");
			op = stoi(opp);
			switch (op) {
			case 1:
				removeProduto(lstock,lIndex);
				break;

			case 2:
				removeProduto(bstock,bIndex);
				break;

			case 0:
				return;

			default:
				cout << "Insira um opção válida!\n";
			}
		}

	}
}

void Restaurante::menuAddStock()
{
	int op = 99;
	string opp;

	while (op != 0) {
		cout << "\n--Menu Adicionar Stock--\n";
		cout << "1-Adicionar Stock a prato\n";
		cout << "2-Adicionar Stock a bebida\n";
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //altera texto para vermelhor
		cout << "0- Voltar para o menu\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //volta a alterar o texto para branco


		cout << "\nInsira a opcao: ";
		cin >> opp;

		if (verifMenu(opp)) {

			system("cls");
			op = stoi(opp);

			switch (op) {
			case 1:
				cout << "--Adicionar Stock a Prato existente--\n\n";

				validaStock(lstock, lIndex);
				break;

			case 2:
				cout << "--Adicionar Stock a Bebida existente--\n\n";

				validaStock(bstock, bIndex);
				break;
			case 0:
				return;

			default:
				cout << "Insira um opção válida!\n";
			}
		}

	}
}

void Restaurante::menuListaStock()
{
	int op = 99;
	string opp;

	while (op != 0) {
		cout << "\n--Menu Listar Stock--\n";
		cout << "1-Imprimir lista Completa de Pratos\n";
		cout << "2-Imprimir lista Completa de Bebidas\n";
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //altera texto para vermelho
		cout << "0- Voltar para o menu\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //volta a alterar o texto para branco

		cout << "\nInsira a opcao: ";
		cin >> opp;

		if (verifMenu(opp)) {

			op = stoi(opp);

			system("cls");
			switch (op) {
			case 1:
				imprimeListaP(lstock,lIndex);
				break;

			case 2:
				imprimeListaP(bstock,bIndex);
				break;

			case 0:
				return;

			default:
				cout << "Insira um opção válida!\n";
			}
		}

	}
}

void Restaurante::adicionaPrato()
{
	string nprato, vprato;
	int qprato;
	string ppratov, qpratov;
	double pprato;

	cout << "--Introduza o Novo Prato--\n";

	if (validaProduto(lstock, lIndex)) {
		lIndex++;
		lstock[lIndex] = Produto();
		system("cls");
		cout << "Prato adicionado com sucesso!";
	}
}

bool Restaurante::pesquisaProduto(string nprato, Produto lista[], int index) //valida se o prato existe
{
	for (int i = 0; i < index; i++) {
		if (lista[i].getNome() == nprato) {
			return true;
		}
	}
	return false;
}

void Restaurante::removeProduto(Produto lista[], int index)
{
	string nprato;
	cout << "Introduza o nome do produto a remover: ";
	cin.ignore();//ler prato
	getline(cin, nprato); //ler mais que uma palavra
	for (int i = 0; i <= index; i++) {
		if (lista[i].getNome() == nprato) {
			lista[i] = Produto();
			system("cls");
			cout << "Produto Removido com sucesso!\n";
			return;
		}
	}
	system("cls");
	cout << "O Produto que introduziu não existe\n";
}

void Restaurante::imprimeListaP(Produto lista[], int index) //imprime a lista de stock
{
	if (index == 0) {
		cout << "Lista Vazia!\n";
		return;
	}

	cout << "Lista do menu \n";
	for (int i = 0; i <= index; i++) {
		if (lista[i].getNome() != "Invalido")
			cout << lista[i].toString() << '\n';
	}
	cout << "Index: " << index << '\n';
}

bool Restaurante::validaProduto(Produto lista[],int index)
{
	string nprato, vprato;
	int qprato;
	string ppratov, qpratov;
	double pprato;

	cout << "Introduza o nome: ";
	cin.ignore();//ler prato
	getline(cin, nprato);//ler prato com mais que uma palavra

	if (verificaString(nprato) == false) { //verifica se foram introduzidas apenas letras
		system("cls");
		cout << "Introduza apenas letras!\n";
		return false;
	}

	//Verifica se o prato já existe em stock - Não deixa introduzir pratos repetidos
	if (pesquisaProduto(nprato, lista, index)) {
		system("cls");
		cout << "Produto já existente em stock!\n";
		return false;
	}

	cout << "Introduza a quantidade existente: ";
	cin >> qpratov;

	if (testeQuant(qpratov) == false) { //testa se introduziu uma letra ou o valor é menor que 0
		cout << "Introduza um valor válido!\n";
		return false;
	}

	if (verificaInt(qpratov) == false) {
		return false;
	}

	qprato = stoi(qpratov); //converte uma string para int

	cout << "Introduza a validade: ";
	cin >> vprato;
	cout << "Introduza o preço: ";
	cin >> ppratov;

	if (verificaInt(ppratov) == false) {
		return false;
	}

	pprato = stoi(ppratov); //converte uma string para int

	for (int i = 0; i <= index; i++) {
		if (lista[i].getNome() == "Invalido") {
			lista[i] = Produto(i + 1, qprato, vprato, nprato, pprato);
			return true;
		}
	}
}

void Restaurante::validaStock(Produto lista[], int index)
{
	string nprato;
	int stock;
	string stockv;

	cout << "Introduza o nome do produto que quer adicionar: ";
	cin.ignore();//ler prato
	getline(cin, nprato); //ler mais que uma palavra

	if (!pesquisaProduto(nprato,lista, index)) { //se o prato nao existe volta para o menu
		system("cls");
		cout << "O prato nao existe no menu! ";
		return;
	}

	cout << "Introduza a quantidade a adicionar: ";
	cin >> stockv;

	if (testeQuant(stockv) == false) { //testa se introduziu uma letra ou o valor é menor que 0
		cout << "Introduza um valor válido!\n";
		return;
	}

	stock = stoi(stockv); //converte uma string para int

	for (int i = 0; i <= index; i++) {
		if (lista[i].getNome() == nprato) {
			lista[i].setQuant(lista[i].getQuant() + stock);
			system("cls");
			cout << "Stock adicionado com sucesso!\n\n";
			return;
		}
	}
}

//BEBIDA

void Restaurante::adicionaBebida()
{
	string qbebidav; //quantidade que vai ser testada 
	string pbebidav;
	int qbebida;
	string nbebida, vbebida;
	double pbebida;

	//Introdução dos dados da bebida

	cout << "--Introduza a Nova Bebida--\n";

	if (validaProduto(bstock, bIndex)) {
		bIndex++;
		bstock[bIndex] = Produto();
		system("cls");
		cout << "Prato adicionado com sucesso!";
	}
}


//PEDIDO

void Restaurante::menuSelecao()
{
	int op = 99;
	double total;
	string opp;

	while (op != 0) {
		cout << "\nPedido";
		imprimeMenu();
		cout << "\n1- Adicionar Prato ao pedido\n";
		cout << "2- Adicionar Bebida ao Pedido\n";
		cout << "3- Imprime pedido\n";
		cout << "4- Imprime total do Pedido\n";
		cout << "5- Efetuar Pedido\n";
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //altera texto para vermelho
		cout << "0- Voltar para o menu\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //volta a alterar o texto para branco

		cout << "\nInsira a opcao: ";
		cin >> opp;

		if (verifMenu(opp)) {

			system("cls");

			op = stoi(opp);

			switch (op) {
			case 1:
				selecaoPrato();
				break;
			case 2:
				selecaoBebida();
				break;
			case 3:
				lpedido[lpedidoindex].imprimePedido(); //imprime o pedido atual
				break;
			case 4:
				lpedido[lpedidoindex].setPtotal(lpedido[lpedidoindex].calculaPrecoPedido()); //calcula o pedido
				cout << "Preço Total do pedido: " << setprecision(2) << lpedido[lpedidoindex].getPtotal() << "€\n"; //apresenta o pedido
				break;
			case 5:
				cout << "Pedido Efetuado com sucesso! \n";
				lpedido[lpedidoindex].setID(lpedidoindex + 1); //atribui id ao pedido
				lpedido[lpedidoindex].setPtotal(lpedido[lpedidoindex].calculaPrecoPedido()); //atribui um preco total ao pedido

				cout << "Id do Pedido: ";
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //altera texto para verde
				cout << lpedido[lpedidoindex].getID(); //imprime o id do pedido
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //volta a alterar o texto para branco


				lpedidoindex++; //prepara o proximo pedido
				break;


			case 0:
				return;
			default:
				cout << "Insira um opção válida!\n";
			}
		}

	}


}

void Restaurante::selecaoPrato()
{
	string nprato; //guarda o nome do prato pedido
	string qpratov;
	int qprato;
	//int qprato; //guarda a quantidade do prato pedido
	double pprato;//serve para colocar preco no pedido
	string pvalidade;//serve para colocar a validade no pedido
	int pid;//serve para colocar o id no pedido
	double total = 0;

	imprimeMenuP(lstock,lIndex);

	cout << "\nPedido\n\n";

	cout << "Introduza o nome do prato :";
	cin.ignore();//ler prato
	getline(cin, nprato); //ler mais que uma palavra
	if (pesquisaProduto(nprato,lstock,lIndex) == false) { //se o prato nao existe volta para o menu
		system("cls");
		cout << "O prato nao existe no menu! \n";
		return;
	}

	cout << "Introduza a quantidade do prato: ";
	cin >> qpratov;

	if (testeQuant(qpratov) == false) {
		cout << "Introduza um numero válido!\n";
		return;
	}


	qprato = stoi(qpratov); //converte uma string para int
	
	system("cls");


	if (verificaQuant(qprato, nprato) == false) {
		return;
	}

	pprato = atribuiPreco(nprato, qprato); //calcula o preço do prato
	pvalidade = atribuiValidade(nprato); //calcula o preço do prato
	pid = atribuiId(nprato); //calcula o preço do prato

	lpedido[lpedidoindex].adicionaPedido(nprato, qprato, pprato, pvalidade, pid); //adiciona o pedido
	cout << "\nPedido Efetuado!\n";

}
bool Restaurante::verificaQuant(int qprato, string nprato) { //Verifica se a quantidade é valida e subtrai ao stock
	for (int i = 0; i < lIndex; i++) {
		if (lstock[i].getNome() == nprato) {
			if (lstock[i].getQuant() - qprato < 0) {
				system("cls");
				cout << "Nao temos stock disponivel\n";
				cout << "Stock de " << lstock[i].getNome() << " :" << lstock[i].getQuant() << "\n";
				return false;
			}
			else {
				lstock[i].setQuant(lstock[i].getQuant() - qprato); //subtrai a quantidade ao stock
				return true;
			}
		}
	}
}

double Restaurante::atribuiPreco(string nprato, int qprato)
{
	double preco;
	for (int i = 0; i < lIndex; i++) {
		if (lstock[i].getNome() == nprato) {
			preco = (lstock[i].getPreco() * qprato);
			preco = preco + (preco * 0.30); //o preco de venda é aumentado em 30%
			return preco;
		}
	}
}

string Restaurante::atribuiValidade(string nprato)
{
	string validade;
	for (int i = 0; i < lIndex; i++) {
		if (lstock[i].getNome() == nprato) {
			validade = lstock[i].getValidade();
			return validade;
		}
	}
}

int Restaurante::atribuiId(string nprato)
{
	int id;
	for (int i = 0; i < lIndex; i++) {
		if (lstock[i].getNome() == nprato) {
			id = lstock[i].getID();
			return id;
		}
	}
}

void Restaurante::imprimeMenu()
{

	if (lIndex == 0) {
		cout << "\nMenu de Pratos Vazio!\n\n";
	}

	else {
		cout << "\n\nMenu de Pratos \n";
		for (int i = 0; i <= lIndex; i++) {
			if (lstock[i].getNome() != "Invalido") {
				cout << lstock[i].getNome() << endl;
			}
		}
	}

	if (bIndex == 0) {
		cout << "Menu de Bebidas Vazio!\n\n";
	}

	else {
		cout << "\nMenu de Bebidas \n";
		for (int i = 0; i <= bIndex; i++) {
			if (bstock[i].getNome() != "Invalido") {
				cout << bstock[i].getNome() << endl;
			}
		}
	}

}

void Restaurante::imprimeMenuP(Produto lista[],int index)
{
	if (index == 0) {
		cout << "Menu Vazio!\n\n";
	}

	else {
		cout << "Menu\n";
		for (int i = 0; i <= index; i++) {
			if (lista[i].getNome() != "Invalido") {
				cout << lista[i].getNome() << endl;
			}
		}
	}
}

void Restaurante::selecaoBebida()
{
	string nbebida; //guarda o nome da bebida pedido para verificar
	string qbebidav; //guarda o nome da bebida pedida
	int qbebida; //guarda a quantidade da bebida pedida
	double pbebida;//serve para colocar preco no pedido
	string bvalidade;//serve para colocar a validade no pedido
	int pid;//serve para colocar o id no pedido
	double total = 0;

	imprimeMenuP(bstock,bIndex);

	cout << "\nPedido\n\n";

	cout << "Introduza o nome da Bebida :";
	cin.ignore();//ler prato
	getline(cin, nbebida); //ler mais que uma palavra

	if (pesquisaProduto(nbebida,bstock, bIndex) == false) { //se o prato nao existe volta para o menu
		system("cls");
		cout << "A bebida nao existe no menu! \n";
		return;
	}

	cout << "Introduza a quantidade da bebida: ";
	cin >> qbebidav;

	if (testeQuant(qbebidav) == false) {
		cout << "Introduza um numero válido!\n";
		return;
	}

	qbebida = stoi(qbebidav); //converte uma string para int

	if (verificaQuantB(qbebida, nbebida) == false) { //se a quantidade for superior á existente volta para o menu
		return;
	}

	system("cls");

	pbebida = atribuiPrecoB(nbebida, qbebida); //calcula o preço do prato
	bvalidade = atribuiValidadeB(nbebida); //calcula o preço do prato
	pid = atribuiIdB(nbebida); //calcula o preço do prato

	lpedido[lpedidoindex].adicionaPedidoB(nbebida, qbebida, pbebida, bvalidade, pid); //adiciona o pedido
	cout << "\nPedido Efetuado!\n";

}

bool Restaurante::verificaQuantB(int qbebida, string nbebida)
{
	for (int i = 0; i < bIndex; i++) {
		if (bstock[i].getNome() == nbebida) {
			if (bstock[i].getQuant() - qbebida < 0) {
				system("cls");
				system("cls");
				cout << "Nao temos stock disponivel\n";
				cout << "Stock de " << bstock[i].getNome() << " :" << bstock[i].getQuant() << "\n";
				return false;
			}
			else {
				bstock[i].setQuant(bstock[i].getQuant() - qbebida); //subtrai a quantidade ao stock
				return true;
			}
		}
	}
}

double Restaurante::atribuiPrecoB(string nbebida, int qbebida)
{
	double preco;
	for (int i = 0; i < bIndex; i++) {
		if (bstock[i].getNome() == nbebida) {
			preco = (bstock[i].getPreco() * qbebida);
			preco = preco + (preco * 0.30); //o preco de venda é aumentado em 30%
			return preco;
		}
	}
}

string Restaurante::atribuiValidadeB(string nbebida)
{
	string validade;
	for (int i = 0; i < bIndex; i++) {
		if (bstock[i].getNome() == nbebida) {
			validade = bstock[i].getValidade();
			return validade;
		}
	}
}

int Restaurante::atribuiIdB(string nbebida)
{
	int id;
	for (int i = 0; i < bIndex; i++) {
		if (bstock[i].getNome() == nbebida) {
			id = bstock[i].getID();
			return id;
		}
	}
}


//RECIBO


void Restaurante::menuPagamento() //menu de pagamento
{
	int op = 99;
	int idped;
	string idped_teste;
	int numcliente;
	string valor_pagov;
	double valor_pago;
	string numclientev;
	string opp;

	while (op != 0) {
		cout << "\nPagamento\n";
		cout << "\n1- Efetuar Pagamento\n";
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //altera texto para vermelhor
		cout << "0- Voltar para o menu\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //volta a alterar o texto para branco

		cout << "\nInsira a opcao: ";
		cin >> opp;

		if (verifMenu(opp)) {

			system("cls");

			op = stoi(opp);

			switch (op) {

			case 1:

				//impõe um limite de registos na lista de vendas
				if (lvendasindex > 99) {
					cout << "O registo de vendas chegou ao seu limite! ";
					return;
				}

				cout << "Introduza o id do pedido: ";
				cin >> idped_teste;

				if (verificaInt(idped_teste) == false) { //verifica se o id contem letras
					return;
				}


				int idped = stoi(idped_teste); //converte uma string para int


				if (pesquisaId(idped) == false) { //se o id nao existe volta para o menu
					system("cls");
					cout << "O pedido nao existe no menu! \n";
					return;
				}

				cout << "Introduza o numero do cliente: ";
				cin >> numclientev; //ler mais que uma palavra

				if (verificaInt(numclientev) == false) {
					return;
				}

				int numcliente = stoi(numclientev);


				if (pesquisaCliente(numcliente) == false) { //se o id nao existe volta para o menu
					return;
				}

				cout << "Introduza com quanto vai pagar: ";
				cin >> valor_pagov;

				if (verificaInt(valor_pagov) == false) {
					return;
				}

				double valor_pago = stod(valor_pagov);


				if (valor_pago - lpedido[idped - 1].getPtotal() < 0) { //verifica se o valor introduzido é valido
					system("cls");
					cout << "O valor que introduziu nao é suficiente para efetuar o pagamento\n";
					return;
				}

				//Criação da Venda
				//Adiciona Pratos e Bebidas do Pedido á Venda

				int tam = lpedido[idped - 1].getPindex();
				int tam2 = lpedido[idped - 1].getBindex();
				int cont = 0; //conta a posicao onde vao ser inseridas as bebidas

				for (int i = 0; i < tam; i++) { //adiciona os pratos do pedido ao recibo
					Vendas[lvendasindex].addPrato(lpedido[idped - 1].getID(), lpedido[idped - 1].getPrecoP(i), tam, lpedido[idped - 1].getNomePrato(i), lpedido[idped - 1].getQuantPrato(i), i);
					cont++;
					Vendas[lvendasindex].setLimite(Vendas[lvendasindex].getLimite() + 1);
				}

				for (int i = 0; i < tam2; i++) { //adiciona as bebidas do pedido ao recibo
					Vendas[lvendasindex].addPrato(lpedido[idped - 1].getID(), lpedido[idped - 1].getPrecoB(i), tam, lpedido[idped - 1].getNomeBebida(i), lpedido[idped - 1].getQuantBebida(i), cont);
					cont++;
				}

				//Imprime o recibo
				system("cls");
				cout << "\nRecibo\n";

				//Regista o resto dos valores da Venda

				Vendas[lvendasindex].setHora();
				Vendas[lvendasindex].setNumPedido(lvendasindex);
				Vendas[lvendasindex].setNumCliente(numcliente);
				Vendas[lvendasindex].setTotal(lpedido[idped - 1].getPtotal());
				Vendas[lvendasindex].setValorPago(valor_pago);
				Vendas[lvendasindex].setTroco(valor_pago - lpedido[idped - 1].getPtotal());


				//Imprime os dados da Venda e faz o sorteio

				cout << Vendas[lvendasindex].getHora() << endl;
				cout << "Id do Pedido: " << Vendas[lvendasindex].getIdPed() + 1 << "\n";
				cout << "Numero do Cliente: " << Vendas[lvendasindex].getNumCli() << "\n";

				//Faz o sorteio

				if (sorteio() == true) { //sorteio do pedido de graca
					Vendas[lvendasindex].setTotal(0);
					Vendas[lvendasindex].setValorPago(0);
					Vendas[lvendasindex].setTroco(0);

					cout << "Parabens! Hoje o seu pedido é gratuito";
				}

				else {
					Vendas[lvendasindex].imprimeVenda();
					cout << "\n\nTotal: " << Vendas[lvendasindex].getTotal() << "€\n";
					cout << "Valor Pago: " << Vendas[lvendasindex].getValorPago() << "€\n";
					cout << "Troco: " << Vendas[lvendasindex].getTroco() << "€\n";
				}

				//Prepara a próxima Venda (pagamento)

				lvendasindex++;

				lpedido[idped - 1] = Pedido();
			}
		}

	}
}




bool Restaurante::pesquisaId(int idped) //valida se o Id introduzido existe na lista de pedidos
{
	for (int i = 0; i < lpedidoindex; i++) {
		if (lpedido[i].getID() == idped) {
			return true;
		}
	}
	return false;
}

bool Restaurante::pesquisaCliente(int numcli) //valida se o Id introduzido existe na lista de clientes
{
	for (int i = 0; i < cIndex; i++) {
		if (lcliente[i].getId() == numcli) {
			return true;
		}
	}
	system("cls");
	cout << "O cliente nao existe! \n";
	return false;
}

bool Restaurante::sorteio() //sorteia um numero. Se esse numero for 50 o pedido é gratuito
{
	int num;
	srand(time(0)); //gera um numero diferente cada vez que a função é chamada
	num = rand() % 101 + 1; //gera numero entre 1 e 100
	if (num == 50) {
		return true;
	}
	else
		return false;
}


//RELATORIOS


void Restaurante::menuRelatorios()
{
	int op = 99;
	double total;
	string opp;

	while (op != 0) {
		cout << "\nRelatório\n";
		cout << "\n1- Relatório de Stock\n";
		cout << "2- Relatorio de Vendas por Prato\n";
		cout << "3- Relatorio de Vendas total\n";
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //altera texto para vermelhor
		cout << "0- Voltar para o menu\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //volta a alterar o texto para branco

		cout << "\nInsira a opcao: ";
		cin >> opp;

		if (verifMenu(opp)) {
			op = stoi(opp);
			system("cls");
			switch (op) {
			case 1:
				relatorioStock();
				break;

			case 2:
				relatorioPrato();
				break;

			case 3:
				relatorioCliente();
				relatorioVenda();
				relatorioLucro();
				break;

			case 0:
				return;

			default:
				cout << "Insira um opção válida!\n";
			}
		}

	}
}

void Restaurante::relatorioStock()
{
	if (lIndex == 0) {
		cout << "Lista de Pratos Vazia!\n\n";
	}
	else {
		cout << "Lista de Stock \n\n";
		for (int i = 0; i < lIndex; i++) {
			if (lstock[i].getNome() != "Invalido")
				cout << "Prato: " << lstock[i].getNome() << "\n";
			cout << "Quantidade: " << lstock[i].getQuant() << "\n\n";
		}
	}

	if (bIndex == 0) {
		cout << "Lista de Bebidas Vazia!\n\n";
	}
	else {
		for (int i = 0; i < bIndex; i++) {
			if (bstock[i].getNome() != "Invalido")
				cout << "Prato: " << bstock[i].getNome() << "\n";
			cout << "Quantidade: " << bstock[i].getQuant() << "\n\n";
		}
	}
	return;

}

void Restaurante::relatorioPrato()
{
	string nprato;
	int tam;
	int quant = 0;
	cout << "Introduza o nome do prato: ";
	cin.ignore();//ler prato
	getline(cin, nprato); //ler mais que uma palavra

	for (int i = 0; i < lvendasindex; i++) {
		tam = Vendas[i].getPIndex();
		for (int j = 0; j <= tam; j++) {
			if (Vendas[i].getNomeP(j) == nprato) {
				quant = quant + Vendas[i].getQuantP(j);
			}
		}
	}

	system("cls");

	if (quant == 0) { //se nao houve contagem significa que o prato nunca foi vendido
		cout << "Este prato não foi vendido nenhuma vez!\n";
	}
	else {
		cout << "Nome do prato: " << nprato << "\n"; //senão algum resultado foi obtido
		cout << "Vendas: " << quant << "\n";
	}

}

void Restaurante::relatorioCliente()
{
	int quant;
	int tam;
	string nprato;
	int num;
	int conttemp = 0;
	int cont = 0;
	int numdef;
	int pos;
	bool ver = false;

	//conta quantas vezes o primeiro prato do primeiro pedido foi vendido

	for (int i = 0; i < lvendasindex; i++) { //compara o cliente de cada pedido com a lista inteira e faz a contagem
		tam = Vendas[i].getPIndex();
		int numtemp = Vendas[i].getNumCli();
		conttemp = 0;
		for (int j = 0; j <= lvendasindex; j++) {
			if (Vendas[j].getNumCli() == numtemp) { //conta o numero de pedidos do cliente
				conttemp++;
			}
		}
		if (conttemp > cont) { //se o contagem temporária for maior que a contagem final a contagem final passa a ser a contagem temporária
			cont = conttemp;
			numdef = numtemp;
			pos = i;
			ver = true;
		}
	}

	if (ver == false) {
		cout << "\nNão existe nenhum cliente que tenha comprado mais\n";
		return;
	}

	cout << "Cliente que mais comprou: \n";

	for (int i = 0; i < cIndex; i++) {
		if (lcliente[i].getId() == Vendas[pos].getNumCli()) { //guarda a posicao do cliente que mais comprou numa variavel
			cout << lcliente[i].toString();
		}
	}
	cout << "\n";
}

void Restaurante::relatorioVenda()
{
	int tam;
	int conttemp = 0;
	int cont = 0;
	string nometemp;
	string nomedef;
	int pos;
	int vendpos;
	bool ver = false;
	int limite;

	for (int i = 0; i < lvendasindex; i++) { //compara cada prato vendido com todos os pratos vendidos no restaurante
		tam = Vendas[i].getPIndex(); //tamanho do pedido
		limite = Vendas[i].getLimite(); //numero de pratos

		for (int j = 0; j < limite; j++) {
			nometemp = Vendas[i].getNomeP(j);
			conttemp = 0;

			for (int l = 0; l < lvendasindex; l++) {
				for (int k = 0; k < Vendas[l].getLimite(); k++) {
					if (Vendas[l].getNomeP(k) == nometemp) {
						conttemp = conttemp + Vendas[l].getQuantP(k);
					}
				}
			}

			if (conttemp > cont) { //se a contagem temporária for maior que a contagem final entao a contagem final vai passar a ser a contagem temporária
				ver = true;
				cont = conttemp;
				nomedef = nometemp;
				pos = j;
				vendpos = i;
			}
		}
	}

	if (ver == false) {
		cout << "\nNão existe prato mais vendido\n";
	}
	else {
		cout << "\nPrato mais vendido: " << Vendas[vendpos].getNomeP(pos) << "\n";
	}

	int contmin = cont;
	int minpos = 0;
	int minvendpos = 0;

	for (int i = 0; i < lvendasindex; i++) { //percorre todas as lista e compara todos os pratos de todas as listas
		tam = Vendas[i].getPIndex();
		limite = Vendas[i].getLimite();

		for (int j = 0; j < limite; j++) {
			nometemp = Vendas[i].getNomeP(j);
			conttemp = 0;

			for (int l = 0; l < lvendasindex; l++) {
				for (int k = 0; k < Vendas[l].getLimite(); k++) {
					if (Vendas[l].getNomeP(k) == nometemp) {
						conttemp = conttemp + Vendas[l].getQuantP(k); //conta as vendas de cada prato
					}
				}
			}

			if (conttemp < contmin) { //se a vendas temporaria for maior que a venda final a venda final passa a ser a venda temporária
				contmin = conttemp;
				nomedef = nometemp;
				minpos = j;
				minvendpos = i;
				ver = true;
			}
		}
	}

	if (ver == false) {
		cout << "\nNão existe prato menos vendido\n";
	}

	else {
		cout << "Prato menos vendido: " << Vendas[minvendpos].getNomeP(minpos) << "\n";
	}

}

void Restaurante::relatorioLucro()
{
	int tam;
	int conttemp = 0;
	int cont = 0;
	string nometemp;
	string nomedef;

	double receita = 0;
	double desconto;
	double lucro = 0;
	double lucrodef = 0;
	string nomelucro;
	bool ver = false;

	for (int i = 0; i < lvendasindex; i++) {
		tam = Vendas[i].getPIndex();
		for (int j = 0; j < tam; j++) {
			string nometemp = Vendas[i].getNomeP(j);
			receita = 0;
			for (int k = 0; k < tam; k++) {
				if (Vendas[i].getNomeP(k) == nometemp) {
					receita = receita + ((Vendas[i].getPrecoUnit(k) - (Vendas[i].getPrecoUnit(k) * 0.30)) * Vendas[i].getQuantP(k)); //á medida que vai percurendo faz o calculo do lucro de cada prato
				}
			}
			lucro = receita * 0.30;

			if (lucro > lucrodef) { //se lucro temporario for maior que o lucro final, o lucro final passa a ser o lucro temporário
				lucrodef = lucro;
				nomelucro = Vendas[i].getNomeP(j); //guarda o nome deste prato
				ver = true;
			}
		}
	}

	if (ver == false) {
		cout << "\nNão existe prato com mais lucro\n";
		return;
	}

	cout << "Prato com mais lucro: " << nomelucro << "\n";
	cout << "Lucro: " << lucrodef << "€" << endl;

}

bool Restaurante::verificaInt(string texto)
{
	for (char c : texto) {
		if (!isdigit(c)) {
			system("cls");
			cout << "Introduza um número que contenha apenas números!\n";
			return false; // se houver alguma letra retorna false
		}
	}
	return true;
}

bool Restaurante::verificaString(string texto)
{
	for (char c : texto) {
		if (isdigit(c)) {
			system("cls");
			cout << "Introduza num numero que contenha apenas letras! \n";
			return false; // se encontrar um número retorna false
		}
	}
	return true;
}

bool Restaurante::testeQuant(string texto)
{
	int qprato;

	if (verificaInt(texto) == false) {
		system("cls");
		return false;
	}

	qprato = stoi(texto); //converte uma string para int



	if (qprato <= 0) { //verifica a introdução de uma quantidade valida
		system("cls");
		return false;
	}

}

bool Restaurante::verifMenu(string opcao)
{
	for (char c : opcao) {
		if (!isdigit(c)) {
			system("cls");
			cout << "Insira uma opção válida!\n";
			return false; // se houver alguma letra retorna false
		}
	}
	return true;
}

void Restaurante::adicionaValor()
{
	lcliente[0] = Cliente(1, "Luis", "919191919", "Rua do Luis");
	lcliente[1] = Cliente(2, "Nubya", "818181818", "Rua da Nubya");
	lstock[0] = Produto(1, 10, "1/1/2024", "Arroz de Marisco", 5);
	lstock[1] = Produto(2, 10, "1/1/2024", "Francesinha", 8);
	bstock[0] = Produto(1, 10, "1/1/2024", "Agua", 1);
	bstock[1] = Produto(2, 10, "1/1/2024", "Coca Cola", 1.50);
}













