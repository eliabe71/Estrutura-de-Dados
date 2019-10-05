#include <iostream>
#include "QX_SeqList.h"
#include <climits>
#define endl "\n"
void laco(QX_SeqList *lista);
void print(){
	std::cout<<"[1]-> Para Remover o Elemento na Posição K"<<endl<<"[2]-> Para Ver o Tamanho da Lista "<<endl<<"[3]-> Para Inserir no final da Lista"<<
	endl<<"[4]-> Imprime Ao Contrário a Lista "<<endl<<"5 Imprime de Forma Sequêncial "<<endl<<"6 Apaga Toda a Lista Mas Ainda é possível fazer operações"<<
	endl<<"[7]-> Cria uma lista  Nova e Copia Os valores da Atual Para a Mesma" << endl <<"[8]-> Analisa se a Lista Atual Está Vazia"<<endl<<
	"[9]-> Elimina o último elemento da lista"<<endl<<"[10]-> Remove a Primeira ocorrência de um K "<<endl<<"[11]-> Remove todas as Ocorrências de K"  <<endl<<
	"[12]-> Inserir entre o k e o k+1 "<<endl<<"[13]-> Concatena duas Listas "<<endl<<"[14]-> Copia os elementos de um vetor e Coloca Na Lista "<<endl<<
	"[15]-> Determina se duas Lista São Iguais"<<endl<<"[16]-> Sepera a Lista A partir de um N"<<endl<<"[17]-> Escalona duas Listas"<<endl<<"[18]-> Sair do Progama"<<endl;
}
int main (){
	QX_SeqList *lista = new QX_SeqList ();
	int c = 0;
	bool start = true;
	while(start){
		print();
		std::cout<<"Digite Operação"<<endl;
		std::cin>>c;
		switch(c){
			case 1:
				std::cout<<"Digite a Posição"<<endl;
				int k1;
				std::cin>>k1;
				int s;
				s = lista->removeNodeAt(k1);
				std::cout<<"Elemento "<<s<<"Removido Com Sucesso"<<endl;
				break;
			case 2:
				std::cout<<"Tamanho Da Lista Atual "<<lista->size()<<endl;
				break;
			case 3:
				bool start2;
				start2 = true;
				while(start2){
					int t;
					std::cout<<"Digite o Elemento a Ser Inserido"<<endl;
					std::cin>>t;
					lista->push_back(t);
					std::cout<<"Lista Atual {";
					lista->print();
					std::cout<<"}";
					std::cout<<"Continuar Adicionando [Sim = 1, Não = 2]"<<endl;
					std::cin>>t;
					if(t==1)continue;
					else start2 = false;
				}

				break;
			case 4:
				lista->printReverse();
				break;
			case 5:
				std::cout<<"Lista Atual {";
				lista->print(); //Imprime
				std::cout<<"}";
				break;
			case
			 6:
				lista->clear();
				break;
			case 7:
				std::cout<<"-----------------------------"<<endl;
				std::cout<<"Operações Com a Nova Lista"<<endl;
				std::cout<<"-----------------------------"<<endl;
				QX_SeqList *lista2;
				lista2 = lista->copy();
				std::cout<<endl;
				laco(lista2);
				std::cout<<endl<<"Terminado"<<endl;
				break;
			case 8:
				if(lista->isEmpty()) std::cout<<"True"<<endl;
				else std::cout<<"False"<<endl;
				break;
			case 9:
				 int e1;
				 e1 = lista->pop_back();
				 std::cout<<"Elemento Removido"<<e1;
				 break;
			case 10:
				std::cout<<"Digite o Elemento"<<endl;
				int d1;
				std::cin>>d1;
				lista->remove(d1);
				break;
			case 11:
				int e4;
				std::cout<<"Digite o Valor : ";
				std::cin>>e4;
				lista->removeAll(e4);
				break;
			case 12:
				int e2,d2;
				std::cout<<"Digite a Posição e o Valor Do Inteiro que Será Inserido"<<endl;
				std::cin>>e2>>d2;
				lista->inseritAfter(d2, e1);
				break;
			case 13:
				QX_SeqList *nova1;
				nova1 = new QX_SeqList();
				while(true){
				std::cout<<"Digite Os Elementos à Ser Inserido"<<endl;
					int r =0, t=0;
					std::cin>>r;
					nova1->push_back(r);
					std::cout<<"Continuar Adicionando [Sim = 1, Não = 2]"<<endl;
					std::cin>>t;
					if(t==1)continue;
					else break;
				}
				lista->concat(nova1);
				std::cout<<"Concatenada Com Sucesso"<<endl;
				break;
			case 14:
				std::cout<<"Digite o Tamanho do Vetor"<<endl;
				int e;
				int *array;
				std::cin>>e;
				array = new int [e];
				std::cout<<"Agora Insira os Valores no Vetor"<<endl;
				for(int i=0;i<e;i++){
					std::cout<<"Elemento "<<i+1<<" ";
					int u =0;
					std::cin>>u;
					array[i] = u;
				}
				lista->copyArray(array,e);
				std::cout<<"Vetor Passado pra Lista Com Sucesso"<<endl;
				std::cout<<"Lista Após a Inserção { ";
				lista->print();
				std::cout<<"}";
				delete array;
				break;
			case 15:
				QX_SeqList *nova2;
				nova2 = new QX_SeqList();
				while(true){
				std::cout<<"Digite Os Elementos à Ser Inserido"<<endl;
					int r =0, t=0;
					std::cin>>r;
					nova2->push_back(r);
					std::cout<<"Continuar Adicionando [Sim = 1, Não = 2]"<<endl;
					std::cin>>t;
					if(t==1)continue;
					else break;
				}
				if(lista->equal(nova2))
					std::cout<<"A lista Atual é Igual A nova Criada "<<endl;
				else std::cout<<"A lista Atual é Diferente A nova Criada"<<endl;
				break;
			case 16:
				std::cout<<"Digite o Número para a partir dele a Lista Ser Dividida"<<endl;
				int k;
				QX_SeqList *nova3;
				nova3 = lista->separate(e);
				std::cout<<"Lista Original{ ";
				lista->print();
				std::cout<<"}";
				if(nova3->isEmpty())std::cout<<"Lista Esta Vazia Não Foi Encontrado Elementos"<<endl;
				else nova3->print();
				break;
			case 17:
				QX_SeqList *nova4;
				nova4 = new QX_SeqList();
				while(true){
				std::cout<<"Digite Os Elementos à Ser Inserido"<<endl;
					int r =0, t=0;
					std::cin>>r;
					nova4->push_back(r);
					std::cout<<"Continuar Adicionando [Sim = 1, Não = 2]"<<endl;
					std::cin>>t;
					if(t==1)continue;
					else break;
				}
				std::cout<<"Escalonando Elementos Com a Lista Original"<<endl;
				lista->merge_lists(nova4);
				std::cout<<"-----------------------------"<<endl;
				std::cout<<"Lista Atual : ";
				lista->print();
				std::cout<<endl;
				std::cout<<"-----------------------------"<<endl;
				break;
			case 18:
				std::cout<<"Progama FINALIZADO com Sucesso";
				start =false;
				break;
			default:
			std::cout<<"Operação Inválida, Progama Será Encerrado"<<endl;
			exit(10); 
		}
	}
	std::cout<<"Progama Terminado Com Sucesso";
	return 0;
} 
void laco(QX_SeqList *lista){
	bool start = true;
	while(start){
		print();
		int c;
		c=0;
		std::cout<<"Digite Operação"<<endl;
		std::cin>>c;
		switch(c){
			case 1:
				std::cout<<"Digite a Posição"<<endl;
				int k1;
				std::cin>>k1;
				int s;
				s = lista->removeNodeAt(k1);
				std::cout<<"Elemento "<<s<<"Removido Com Sucesso"<<endl;
				break;
			case 2:
				std::cout<<"Tamanho Da Lista Atual "<<lista->size();
				break;
			case 3:
				bool start2;
				start2 = true;
				while(start2){
					int t;
					std::cout<<"Digite o Elemento a Ser Inserido"<<endl;
					std::cin>>t;
					lista->push_back(t);
					std::cout<<"Lista Atual {";
					lista->print();
					std::cout<<"}";
					std::cout<<"Continuar Adicionando [Sim = 1, Não = 2]"<<endl;
					std::cin>>t;
					if(t==1)continue;
					else start2 = false;
				}

				break;
			case 4:
				lista->printReverse();
				break;
			case 5:
				std::cout<<"Lista Atual {";
				lista->print(); //Imprime
				std::cout<<"}";
				break;
			case
			 6:
				lista->clear();
				break;
			case 7:
				QX_SeqList *lista2;
				lista2 = lista->copy();
				std::cout<<"Operações Com a Nova Lista"<<endl;
				break;
			case 8:
				if(lista->isEmpty()) std::cout<<"True"<<endl;
				else std::cout<<"False"<<endl;
				break;
			case 9:
				 int e1;
				 e1 = lista->pop_back();
				 std::cout<<"Elemento Removido"<<e1;
				 break;
			case 10:
				std::cout<<"Digite o Elemento"<<endl;
				int d1;
				std::cin>>d1;
				lista->remove(d1);
				break;
			case 11:
				int e4;
				std::cout<<"Digite o Valor : ";
				std::cin>>e4;
				lista->removeAll(e4);
				break;
			case 12:
				int e2,d2;
				std::cout<<"Digite a Posição e o Valor Do Inteiro que Será Inserido"<<endl;
				std::cin>>e2>>d2;
				lista->inseritAfter(d2, e1);
				break;
			case 13:
				QX_SeqList *nova1;
				nova1 = new QX_SeqList();
				while(true){
				std::cout<<"Digite Os Elementos à Ser Inserido"<<endl;
					int r =0, t=0;
					std::cin>>r;
					nova1->push_back(r);
					std::cout<<"Continuar Adicionando [Sim = 1, Não = 2]"<<endl;
					std::cin>>t;
					if(t==1)continue;
					else break;
				}
				lista->concat(nova1);
				std::cout<<"Concatenada Com Sucesso"<<endl;
				break;
			case 14:
				std::cout<<"Digite o Tamanho do Vetor"<<endl;
				int e;
				int *array;
				std::cin>>e;
				array = new int [e];
				std::cout<<"Agora Insira os Valores no Vetor"<<endl;
				for(int i=0;i<e;i++){
					std::cout<<"Elemento "<<i+1<<" ";
					int u =0;
					std::cin>>u;
					array[i] = u;
				}
				lista->copyArray(array,e);
				std::cout<<"Vetor Passado pra Lista Com Sucesso"<<endl;
				std::cout<<"Lista Após a Inserção { ";
				lista->print();
				std::cout<<"}";
				delete array;
				break;
			case 15:
				QX_SeqList *nova2;
				nova2 = new QX_SeqList();
				while(true){
				std::cout<<"Digite Os Elementos à Ser Inserido"<<endl;
					int r =0, t=0;
					std::cin>>r;
					nova2->push_back(r);
					std::cout<<"Continuar Adicionando [Sim = 1, Não = 2]"<<endl;
					std::cin>>t;
					if(t==1)continue;
					else break;
				}
				if(lista->equal(nova2))
					std::cout<<"A lista Atual é Igual A nova Criada "<<endl;
				else std::cout<<"A lista Atual é Diferente A nova Criada"<<endl;
				break;
			case 16:
				std::cout<<"Digite o Número para a partir dele a Lista Ser Dividida"<<endl;
				int k;
				QX_SeqList *nova3;
				nova3 = lista->separate(e);
				std::cout<<"Lista Original{ ";
				lista->print();
				std::cout<<"}";
				if(nova3->isEmpty())std::cout<<"Lista Esta Vazia Não Foi Encontrado Elementos"<<endl;
				else nova3->print();
				break;
			case 17:
				QX_SeqList *nova4;
				nova4 = new QX_SeqList();
				while(true){
				std::cout<<"Digite Os Elementos à Ser Inserido Na Lista Nova"<<endl;
					int r =0, t=0;
					std::cin>>r;
					nova4->push_back(r);
					std::cout<<"Continuar Adicionando [Sim = 1, Não = 2]"<<endl;
					std::cin>>t;
					if(t==1)continue;
					else break;
				}
				std::cout<<"Escalonando Elementos Com a Lista Original"<<endl;
				lista->merge_lists(nova4);
				std::cout<<"Lista Atual: {";
				lista->print();
				std::cout<<"}";
				break;
			case 18:
			if(c==18){
				std::cout<<endl<<"FINALIZADO COM SUCESSO"<<endl;
				start =false;
			}
				break;
			default:
			std::cout<<"Operação Inválida, Progama Será Encerrado"<<endl;
			exit(10); 
			break;
		}
	}
}