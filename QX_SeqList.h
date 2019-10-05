#ifndef QX_SEQLIST_H
#define QX_SEQLIST_H
#include "QX_SeqList.h"
struct Node; 
class QX_SeqList{
	private:
		Node *head;
		void removeNode(Node *p); //Remove da lista o nó apontado pelo ponteiro p.
		Node *ultimoElemento(Node *head); //Último do ponteiro
	public:
		QX_SeqList(); // Construtor
	
		~QX_SeqList(); // Destrutor
		int removeNodeAt(int k); //Remove o k-ésimo nó da lista encadeada e retorna o
		//seu valor. Caso o k-ésimo nó não exista, o programa libera memória alocada e
		///finaliza.
	
		int size(); // tamanho da Lista CIRCULAR;
	
		void push_back(int key); //Insere um inteiro key ao final da lista.

		void printReverse(); //Imprime os elementos da lista em ordem reversa.
		
		void print(); //Imprime

		void clear(); //Limpa tudo

		QX_SeqList *copy(); //copia para uma lista nova e retorna a criada; 

		bool isEmpty(); //Retorna true se a lista estiver vazia e false caso contrário.
		
		int pop_back(); //Elimina o Último da lista

		void remove(int key); //remove primeira ocorecia de key 
		
		void removeAll(int key); //remove todas as ocorrrencias de key;
		
		void inseritAfter(int key, int k); // INSERI ENTRE ELEMENTOS

		void concat(QX_SeqList *lst); //Concatena a lista atual com a lista lst passada por
		//parâmetro. Após essa operação ser executada, lst será uma lista vazia, ou seja, o
		//único nó de lst será o nó cabeça.
		void copyArray(int *arr, int n); //Copia Os elementos deum vetor e coloca na fila;

		bool equal(QX_SeqList *lst); //determina se duas listas são iguais;
		QX_SeqList* separate(int n); //Separa apartir de um n  específico;
		void merge_lists(QX_SeqList *list2); //Escalona duas QX_SeqList;
};
#endif