#include <iostream>
#include "QX_Seqlist.h"
#define MAX 50
#define endl "\n"
void print(){
	std::cout<<"-----Opções------";
		std::cout<< endl<<"Digite"<<endl;
		std::cout <<"[1]-> Para Ver o Tamanho"<<endl<<"[2]-> Para Ver se Está Vázia"<< endl<<"[3]-> Busca Elemento"<<endl
		<<"[4]-> Devolve o Elemento Da Posição k Digitado;"<<endl<< "[5]-> Adciona No Final Da Lista"<<endl<<"[6]-> Apaga Tudo"<<endl<<"[7]-> Imprime"<<endl<<"[8]-> Imprime Ao Contrário"<<endl<<"[9]-> Remove Elemento"
		<<endl<<"[10]-> Remove DO Final"<<endl<<"[11]-> Remove Por Remover"<<endl<<"[12]-> Para ACABAR COM O Progama"<<endl;
		std::cout<< "Digite A Opção :";
}
int main (){
	QX_Seqlist lista(MAX);
	int i =0;
	while(true){
		if(i>0) std::cout<<endl;
		print();
		int u=0;
		std::cin>>u;
		if(u==1) std::cout<<endl<<"Tamanho :"<<lista.size()<<endl<<endl; //1
		if(u==2) lista.isEmpty(); //2
	 	if(u==3){
	 		int x=0;
	 		std::cout<<"Digite o X a Ser Buscado"<<endl;
	 		std::cin>>x;
	 		lista.search(x); //3
	    }
	    if(u==4){
	    	int pos=0;
	    	std::cout<<"Digite a Posição"<<endl;
	    	std::cin>>pos;
	    	lista.at(pos); //4
	 	}
	 	if(u==5){
	 		int x =0;
	 		bool start =true;
	 		while(start){
	 			std::cout<<"Valor :";
	 			std::cin>>x;
	 			lista.push_back(x); //5
	 			std::cout<<endl;
	 			std::cout<<"Adcionado Com Suceso"<<endl;
	 			int t =0;
	 			std::cout<<"Continuar Adcionando? [SIM = 1, NÃO = 2] "<<endl;
	 			std::cin>>t;
	 			if(t==1)continue;
	 			else break; 
	 		}
	 	}
	 	if(u==6) 
	 		lista.clear();  //6
	  	if(u==7) 
	  		lista.print(); //7
		if(u==8) 
			lista.printReverse(); //8
		if(u==9) {
			int x =0;
			std::cout<<"Digite o Valor a Ser Removido Completamente"<<endl;
			std::cin>>x;
			lista.removeAll(x);  //9
		}
		if(u==10)lista.pop_back(); //10
		if(u==11) {
			int x=0; 
			std::cout<<"Digite o Valor a Ser Removido"<<endl;
			std::cin>>x;
			lista.remove(x);
		}
		if(u==12) 
			break;
		i+=1;
	}	
	
	return false;
}