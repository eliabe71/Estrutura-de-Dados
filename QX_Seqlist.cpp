#include <climits>
#include <iostream>
#include <cstdlib>
#include "QX_Seqlist.h"
#define endl "\n"
QX_Seqlist::QX_Seqlist(int n){
	if(n>0){
		vec = new int[n];
		size_vec = 0;
		capacidade =n;
	}
}
QX_Seqlist::~QX_Seqlist(){
	if(vec!= NULL)
		delete [] vec;
		std::cout<< "QX_Seqlist DELETADA Com Sucesso"<<endl;
}
int QX_Seqlist::size(){
	return this->size_vec;
}
bool QX_Seqlist::isEmpty(){
	if(size_vec <=0) return true;
	return false;
 }
 int QX_Seqlist::search(int x){
 	for(int i =0 ; i<size_vec ; i++)
 		if(vec[i]==x) return i;
 	return INT_MIN;
 }
 int QX_Seqlist::at(int k){
 	if(k>size_vec || k<0) return INT_MIN;
 	return vec[k];
 }
int *QX_Seqlist::realloc(int *vetor, int e){
 	int *d = new int[size_vec];
 	for(int i =0; i<size_vec;i++){
 		d[i] = vetor[i];
  	}
  	vetor = new int[e];
  	if(vetor== NULL) return NULL;
  	for(int i =0; i<size_vec;i++){
  		vetor[i] = d[i];
  	}
  	delete[] d;
  	d = NULL;
  	return vetor;
 }
 void QX_Seqlist::push_back(int x){
 	if(size_vec==capacidade){
 		vec = realloc(vec, sizeof(int)*capacidade*2);
 		capacidade *= 2;

 		if(vec==NULL) exit(1);
 		else{
 			vec[size_vec] = x;
 			size_vec+=1;
 		}
	}
	else{
		vec[size_vec]=x;
		size_vec++;
	}
	if(size_vec< capacidade/2){
		vec = realloc(vec, sizeof(int)*capacidade/2);
		capacidade /= 2;
	}
 }
 void QX_Seqlist::clear(){
 	this->size_vec =0;
 }
  void QX_Seqlist::print(){
  	if(size_vec == 0) std::cout<<endl<<"Lista JÁ Está Vazia"<<endl;
  	for(int i=0;i<size_vec;i++){
  		std::cout<<endl<<vec[i]<<" | "; 
  	}
  }
void QX_Seqlist::printReverse(){
	for(int i = size_vec-1;i>=0;i--)
		std::cout<<endl<<vec[i] <<" ";
}
void QX_Seqlist::removeAll(int x){
	int u =0;
	for(int w=0; w<size_vec ;w++) 
		if(vec[w]== x) u++;
	int *d = new int[size_vec-u];
	for(int  i=0,j =0; i<size_vec;i++){
		if(vec[i]== x) continue;
		d[j] = vec[i];
		j++;
	}
	size_vec -= u;
	delete[] vec;
	vec = new int[size_vec];
	for(int i =0;i<size_vec;i++){
		vec[i]=d[i];
	}
	delete [] d;
} 
void QX_Seqlist::remove(int x){
	int y =0;
	bool ver = false;
	for(int i=0; i<size_vec;i++){
		if(vec[i]==x) {
			y=i; 
			ver = true;
			break;
		}
	}
	if(ver==true){
		for(int j =y; j<size_vec;j++){
			vec[j] = vec[j+1];
		}
		size_vec--;
	}
	if(size_vec< capacidade/2){
		vec = realloc(vec, sizeof(int)*capacidade/2);
		capacidade /= 2;
	}


}
bool QX_Seqlist::pop_back(){
	if(size_vec==0){
		std::cout<<endl<<"Lista Já Está Vazia"<<endl;
		return false;
	}
	else {
		std::cout<<endl<< "Último da Lista Removido Com Sucesso"<<endl;
		vec[size_vec] =0;
		size_vec--;
		//Verifica o tamanho e capacidade para ver see não estão muitos discrepantes
		if(size_vec< capacidade/2){
			vec = realloc(vec, sizeof(int)*capacidade/2);
			capacidade /= 2;
	}

		return true;
	}
}


