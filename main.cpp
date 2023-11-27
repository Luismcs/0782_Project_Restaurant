#include <iostream>
#include "Restaurante.h"
#include <Windows.h> //serve para alterar as cores

bool verif(string texto)
{
	for (char c : texto) {
		if (!isdigit(c)) {
			system("cls");
			cout << "Insira uma opcao válida!\n";
			return false; // se houver alguma letra retorna false
		}
	}
	return true;
}

void menu() {

	cout << "\n- Delícias C++inárias -\n";
	cout << "\n-Menu-\n";
	cout << "\n-Cliente-\n";
	cout << "1 - Gestão de Clientes\n";
	cout << "\n-Stock-\n";
	cout << "2 - Gestão de Stock\n";
	cout << "\n-Pedido-\n";
	cout << "3 - Fazer Pedido\n";
	cout << "\n-Pagamento-\n";
	cout << "4 - Efetuar pagamento\n";
	cout << "\n-Relatórios-\n";
	cout << "5 - Visualizar Relatórios\n";


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n\n0- Sair\n\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	Restaurante A;

	int op = 99;
	string opp;
	int id;
	string nome;
	string telefone;
	string endereco;

	while (op != 0) {
		menu();
		cout << "Insira a opcao: ";
		cin >> opp;

		

		if (verif(opp)) {

			op = stoi(opp);

			system("cls");
			switch (op) {

			case 1:
				A.menuCliente();
				break;

			case 2:
				A.menuStock();
				break;

			case 3:
				A.menuSelecao();
				break;

			case 4:
				A.menuPagamento();
				break;

			case 5:
				A.menuRelatorios();
				break;

			case 0:
				cout << "A sair...";
				return 0;

			default:
				cout << "Insira um opção válida!";
			}
		}


	}
}


