#include <iostream>
#include <climits>
#include "QX_SeqList.h"
#define endl "\n"
struct Node{
	int key;
	Node *ant;
	Node *prox;
};
QX_SeqList::QX_SeqList(){
	head = new Node;
	head->ant= head;
	head->prox = head;
}
QX_SeqList::~QX_SeqList(){
	Node *aux = head->prox;
	Node *aux2 =NULL;
	while(aux!=head){
		aux2 = aux;
		aux = aux->prox;
		delete aux2;
	}
	delete head;
	aux=NULL;
	aux2 = NULL;
	std::cout<<endl<<"Progama Acabado Com Sucesso ......................"<<endl;
}

int QX_SeqList::size(){
	int i=0;
	Node *d = head->prox;
	while(d!=head){
		i++;
		d = d->prox;
	}
	return i;
}
void QX_SeqList::push_back(int key){     //Insere um inteiro key ao final da lista.
	if(head->prox==head){
		/*
			Nessa Funcao caso esteje vazia head anterio recebe  o novo nó e proximo tbm recebe o proximo nó;
		*/
		Node *novo = new Node;
		novo->key = key;
		novo->prox = head->prox;
		novo->ant = head->ant;
		head->ant = novo;
		head->prox = novo;
		
	}
	else {
		/*
			Caso ja contenha elementos o verifico o ultimo elemento atual e crio novo fazendo com que era atual proximo aponte para novo 
			e head anterior aponte para o novo para continuar com a circularidade;
		*/
		Node *d = head->prox;
		Node *aux = NULL;
		while(d!=head){
			aux = d;
			d = d->prox;
		}
		Node *novo = new Node;
		novo->key = key;
		novo->prox = aux->prox;
		novo->ant = aux;
		aux->prox = novo;
		head->ant = novo;
		Node *sea = head->prox;
	}


}
void QX_SeqList::print(){
	//Apenas ver o proximo enquanto seje diferente de head e imprime as chaves de cada nó;
	Node *aux = head->prox;
	while(aux!=head){
		std::cout<<aux->key<<" ";
		aux = aux->prox;
	}
}
int QX_SeqList::pop_back(){ //remove do final da Fila;
	Node *next = head->prox;
	Node *aux = NULL;
	if(next==head) {
		std::cout<<"Lista se Encontra Vazia";
		exit(3);
	}
	/* Funcao remove o ultimo da fila 
		faço um laco pra verficar quem é o ultimo pra ser removido
		faço acertos de ponteiros ou seja o anterior do head tem que receber o elemento anterior do que vai ser removido 
		e o anterior do que vai ser removido deve receber o próximo do que será removido. next recebe null só por boa prática. deleto null 
		e retorno o valor da chave  do elemento que vai ser removido.
	*/
	while(next!=head){
		aux = next;
		next = next->prox;
	}
	int j = aux->key;
	next = aux;
	aux = aux->ant;
	aux->prox = next->prox;
	head->ant = aux;
	delete next;
	next = NULL;
	return j;

}
void QX_SeqList::inseritAfter(int key, int k){ 
	if(k<0) exit(3);
	int i =  k;
	Node *a1 = head;
	/*
		inseri entre elementos verifico se k é mnor que zero entao retorno uma excessao caso isso que o usario tenha digitado.
		depois verifico se não esta vazia se estiver uso a funcao normal de insercao
		Caso nenhum seje verdade faço um while pra ver que estara atras do novo elemento \n
		 embora que o usuario digite um numero bem grande o while ficará rodando até o i ser meenor que zero necessariamente esta no intervalo \n

	*/
	if(a1->prox == head) {
		push_back(key);
		return; 
	}
	while(i>0){
		i--;
		a1= a1->prox;
		
	}
	if(a1->prox == head){
		head->key= 44;
		/*
			Aqui crio novo e verifico se o proximo do elemento é head pois se for anterior do head deve ser atualizado;
		*/
		Node *novo = new Node;
		novo->key = key;
		novo->prox = a1->prox;
		novo ->ant = a1;
		a1->prox = novo;
		head->ant = novo;
	}
	else{
		//Caso Não seje apenas acertos  os ponteiros anterior proximo receba novo e novo proximo recebea anterior proximo;
		Node *novo = new Node;
		novo->key = key;
		novo->prox = a1->prox;
		novo->ant = a1;
		a1->prox = novo;
	}
	
}
void QX_SeqList::remove(int key){
	/*
		Verfica até ultimo verificaa se é ultimo da lista pra fazer para que anterio da head aponte pra o anterio do que vai ser removido
		se não é só acertos de ponteiros e quando achar para o laço e acaba a funcao;
	*/
	Node *busca = head->prox;
	Node *aux = busca->ant;
	head->key = 221;
	while (busca!=head){
		if(busca->key==key){
			std::cout<<aux->prox->key;
			if(busca->prox==head){
				aux->prox = busca->prox;
				head->ant = aux;
				int i = busca->key;
				delete busca;
				std::cout<<i<<"Removido com Sucesso"<<endl;
				break;
			}
			else{

				aux->prox = busca->prox;
				busca->prox->ant = aux;
				int i = busca->key;
				delete busca;
				std::cout<<i<<"Removido com Sucesso"<<endl;
				break;
			}
		}
		else {
			aux = busca;
			busca = busca->prox;
		}
	}
} //Remove da lista a primeira ocorrência do inteiro key
void QX_SeqList::removeAll(int key){
	// Essa funcao é praticamente igual a anteterior a difereça é apenas que ela não para quando encontra o elemento;
	Node *busca = head->prox;
	Node *aux = busca->ant;
	while (busca!=head){
		if(busca->key==key){
			std::cout<<aux->prox->key;
			if(busca->prox==head){
				aux->prox = busca->prox;
				head->ant = aux;
				Node *aux2 = busca;
				int i = busca->key;
				busca = busca->prox;
				
				delete aux2;
				
			}
			else{
				
				aux->prox = busca->prox;
				busca->prox->ant = aux;
				int i = busca->key;
				Node *aux2 = busca;
				busca = busca->prox;
				delete aux2;
			}
		}
		else {
			aux = busca;
			busca = busca->prox;
		}
	}
} //Remove da lista a todas ocorrência do inteiro key
void QX_SeqList::removeNode(Node *p){//Remove da lista o nó apontado pelo ponteiro p.
	///Comeco com um laço verficando até o meu aux for  diferente de head por que se sim percorreu toda alista e nao acho
	//quando achar vejo se não é o ulitmo pois caso seje anterio do head recebe o nó anterior do que será removido 
	//Logo após desaloco memoria e faço o ponteiro p receber null
	//Caso o p não exista e como é uma operação de risco mato o progama;
	Node *aux = head->prox;
	Node *ant = head;
	while(aux!=head){
		if(p==aux){
			if(aux->prox==head){
				ant->prox = aux->prox;
				aux->prox->ant = ant;
				head->ant = ant;
				break;
			}
			else{
				ant->prox = aux->prox;
				aux->prox->ant = ant;
				break;
			}
		}
		else{
			ant = aux;
			aux= aux->prox;
		}
	}
	
} 
void QX_SeqList::clear(){
	Node *atual = head->prox;
	Node *aux = head;
	while(atual!=head){
		aux  = atual;
		atual= atual->prox;
		delete aux;
	}
}

//Remove o k-ésimo nó da lista encadeada e retorna o
//seu valor. Caso o k-ésimo nó não exista, o programa libera memória alocada e
//finaliza.
int QX_SeqList::removeNodeAt(int k){
	//mUITO PARECIDA COM A FUNCAO ANTEERIOR;
	if(k<0 || k>size()) {
		clear();
		std::cout<<endl<<"operação Inválida Progama Abortado"<<endl;
		exit(1);
	}
	else{
		Node *next = head;
		Node *anter = head;
		for(int i = 0;i<k;i++){
			anter = next;
			next = next->prox;
		}
		int  i =0;
		i = next->key;
		removeNode(next);
		return i;
	}
}
void QX_SeqList::printReverse(){
	Node *anter = head->ant;
	std::cout<<endl<<"Imprimindo ao Averso"<<endl;
	while(anter!=head){
		std::cout<< anter->key<<" ";
		anter = anter->ant;
	}
	std::cout<<endl;
}
bool QX_SeqList::isEmpty(){ //Retorna true se a lista estiver vazia e false caso contrário.
	 return (head->prox == head) ? true:false;
} 
Node *QX_SeqList::ultimoElemento(Node *head){ //Funcao privada só apenas para ver quem é últmio nó; 
	Node *aux = head->ant;	
	return aux;
}
void QX_SeqList::concat(QX_SeqList *lst){
	Node *ult = ultimoElemento(lst->head);
	ult->prox = head->ant->prox;
	head->ant->prox = lst->head->prox;
	lst->head->prox->ant = head->ant;
	head->ant = ult; 
	lst->head->prox = lst->head->ant = head; 
}
QX_SeqList *QX_SeqList::copy() {// Retorna um ponteiro para uma cópia desta lista.
	QX_SeqList *lst  = new QX_SeqList();
	Node *aux = head->prox;
	if(aux==head) {std::cout<<endl<<"Lista VaziaProgama Abortado"<<endl;
		exit(3);
	}
	while(aux!=head){
		int k = aux->key;
		lst->push_back(k);
		aux = aux->prox;
	}
	return lst;
}
void QX_SeqList::copyArray(int *arr, int n){
	for(int i =0 ; i<n;i++){
		push_back(arr[i]);
	}
} 
/*Copia os elementos do array arr para a lista.
O array arr tem n elementos. Todos os elementos anteriores da lista são mantidos
e os elementos do array arr devem ser adicionados após os elementos originais.*/

bool QX_SeqList::equal(QX_SeqList *lst){
	Node *aux = head->prox;
	Node *aux2 = lst->head->prox;
	int a1=0, a2 =0;
	a1 = size();
	a2 = lst->size();
	if(a1!= a2) return false;
	while(aux!=head && aux2!=head){
		if(aux->key != aux2->key) return false;
		aux = aux->prox;
		aux2 = aux2->prox;
	}
	return true;
}/*Determina se a lista passada por parâmetro é igual à
lista em questão. Duas listas são iguais se elas possuem o mesmo tamanho e o valor
do k-ésimo elemento da primeira lista é igual ao k-ésimo elemento da segunda lista.*/

QX_SeqList* QX_SeqList::separate(int n){
	/*
		Nessa funcao cria um while
	*/
	QX_SeqList *lst = new QX_SeqList();

	Node *aux = head->prox;
	while(aux!=head){
		if(aux->key==n){
			if(aux->prox!=head){
				Node *ultimo = ultimoElemento(head);
				Node *aux1 = aux;
				aux = aux->prox;

				aux1->prox  = ultimo->prox;
				head->ant= aux1;
				
				ultimo->prox = lst->head->prox;

				aux->ant = lst->head->prox;
				
				lst->head->prox = aux;
				
				lst->head->ant = ultimo;

				return lst;
			}

			else return lst;
		}
		else aux = aux->prox;
	}
	return lst;
}


//No trabalho original tem void o retorno mas não faz sentido criar uma lista e nao usá-la.
void QX_SeqList::merge_lists(QX_SeqList *lista2){ 
	/*
		Essa funcao inicia  criando  uma nova para no final ser passada para a original , depois faz um laco enquanto as duas lista tivere o tamanho maior que zero
		caso especias é quando uma das lista é vazia e outra não, caso seje então pega o ultimo elemento fazendo com que ele aponte 
		para o proximo do último elemento de que já tem ou não na lista e o anterio da cabeça da lista apontee para o uúltimo;

		Caso todas tenha elementos a intercalçao ocorre primeiro de uma lista depois da outra um auxiliar receber o alemento e chame se
		a funcao remove node para atualizar a posiçõa do proximo da head faz a inserção comum mas apenas com os ponteiros, logo após 
		faz o mesmmo passo pro elemento da proximo lista depois atualiza  os ponteiros pra sempre ficar no final da lista até que entre em algum if ou sai do while 
		depois disso faz com que a original receba a nova e termina a funcção dando um return de seguranca
	*/
	QX_SeqList *nova = new QX_SeqList();
	Node *aux1 = nova->head;
	while( isEmpty()==false || lista2->isEmpty()==false){
		if(isEmpty()==true){
			Node *ultimo = lista2->ultimoElemento(lista2->head);
			ultimo->prox = aux1->prox;
			lista2->head->prox->ant = aux1;
			aux1->prox = lista2->head->prox;
			nova->head->ant = ultimo;
			lista2->head->prox = lista2->head->ant = lista2->head;
			break;
		}
		if(lista2->isEmpty()==true){
			Node *ultimo = ultimoElemento(head);
			ultimo->prox = aux1->prox;
			head->prox->ant = aux1;
			aux1->prox = head->prox;
			nova->head->ant = ultimo;
			head->prox = head->ant = head;
			break;
		}
		Node *aux = head->prox;
		removeNode(head->prox);
		aux->prox= aux1->prox;
		aux->ant = aux1;
		aux1->prox = aux;
		nova->head->ant = aux;
		aux1 = aux1->prox;

		aux = lista2->head->prox;
		lista2->removeNode(lista2->head->prox);
		aux->prox= aux1->prox;
		aux->ant = aux1;
		aux1->prox = aux;
		nova->head->ant = aux;
		aux1= aux1->prox;
	}
	Node *ultimo = nova->ultimoElemento(nova->head);
	ultimo->prox = head->prox;
	nova->head->prox->ant = head;
	head->prox = nova->head->prox;
	head->ant = ultimo;
	nova->head->prox = nova->head->ant = head;
	return ;
}
