#ifndef QXSEQLIST_H
#define QXSEQLIST_H
#include <iostream>
class QX_Seqlist{
	private: 
		int *vec = NULL;
		int size_vec= 0;
		int capacidade =0;
		int *realloc(int *vetor, int e);
	public: 
	QX_Seqlist(int n);

	~QX_Seqlist();
	
	int size();
	
	bool isEmpty();
 	
 	int search(int x);
    
    int at(int k);
 	void push_back(int x);
 	
 	void clear();
  	void remove(int x);
  	void print();
	
	void printReverse();
	
	void removeAll(int x);
	
	bool pop_back();
};
#endif