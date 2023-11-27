#pragma once

#pragma once
#include "Cliente.h"
#include "Pedido.h"
#include "Recibo.h"
#include "Produto.h"
#include "Windows.h" //altera as cores do texto, Hora do Sistem
#include <iomanip> //set precision total com 1 casa decimal setw
#include <iostream>
using namespace std;


class Restaurante {

private:

	//lista de clientes
	Cliente lcliente[10];
	int cIndex = 2;

	//lista de stock
	Produto lstock[10];
	int lIndex = 2;

	//lista de bebidas
	Produto bstock[10];
	int bIndex = 2;

	//lista de pedidos
	Pedido lpedido[10];
	int lpedidoindex = 0;

	//lista de recibos
	Recibo Vendas[10];
	int lvendasindex = 0;


public:
	Restaurante();

	//Gestão Cliente
	void menuCliente(); //menu
	void adicionaCliente(); //adiciona cliente
	void removeCliente(int id); //remove cliente
	void alteraNome(int id); //alterar nome de cliente
	void imprimeLista(); //imprimir lista de clientes

	//Menus Gestão Prato e Bebida
	void menuStock(); //menu do stock
	void menuAdic(); //menu adicionar prato ou bebida
	void menuRemov(); //menu remover prato ou bebida
	void menuAddStock(); //menu adicionar stock a prato ou bebida
	void menuListaStock(); //menu imprimir listas

	//Gestão Prato
	void adicionaPrato(); //adiciona prato
	void adicionaStock(); //adiciona stock a prato
	void removeProduto(Produto lista[], int index); //remove prato
	void imprimeListaP(Produto lista[], int index); //imprime lista de pratos

	bool validaProduto(Produto lista[],int index);
	bool pesquisaProduto(string nprato, Produto lista[], int index); //verifica se o prato existe
	void validaStock(Produto lista[], int index);

	//Gestão Bebida
	void adicionaBebida(); //adiciona bebida

	//Gestão Pedido
	void menuSelecao(); //menu seleção de pedido
	void imprimeMenu(); //imprime o menu do restaurante
	void imprimeMenuP(Produto lista[], int index);

	//Prato
	void selecaoPrato(); //selecionar o prato
	bool verificaQuant(int quant, string nprato); //verifica se a quantidade é válida
	double atribuiPreco(string nprato, int qprato); //atribui preco ao pedido
	string atribuiValidade(string nprato); //atribui validade 
	int atribuiId(string nprato); //atribui id

	//Bebida
	void selecaoBebida(); //selecionar a bebida
	bool verificaQuantB(int quant, string nprato); //verifica se a quantidade é válida
	double atribuiPrecoB(string nprato, int qprato); //atribui preco ao pedido
	string atribuiValidadeB(string nprato); //atribui validade
	int atribuiIdB(string nprato); //atribui id


	//Gestão de Pagamento e Recibos
	void menuPagamento(); //menu de pagamento
	bool pesquisaId(int idped); //pesquisa se o id do pedido existe
	bool pesquisaCliente(int numcli); //pesquisa se o id do cliente existe
	bool sorteio(); //faz o sorteio 


	//Relatórios
	void menuRelatorios(); //menu relatórios
	void relatorioStock(); //relatório de stock
	void relatorioPrato(); //relátório por prato

	//Relatório Total
	void relatorioCliente(); //relatório do cliente que mais comprou
	void relatorioVenda(); //relatório de prato menos vendido
	void relatorioLucro(); //relatório de prato com mais lucro

	//Adiciona os Valores padrão
	void adicionaValor();

	//Validações

	bool verificaInt(string texto); //verifica se existem letras no numero
	bool verificaString(string texto); //verifica se existem numeros no texto
	bool testeQuant(string texto); //verifica se a quantidade inserida é um número
	bool verifMenu(string opcao); //verifica se a opcao inserida é uma letra

};