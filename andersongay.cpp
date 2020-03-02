#include <iostream>
void booble_sort(int *v,int n){
	if(n <=1) return;
	else{
		eliabe:
		booble_sort(v,n-1);
		if(v[n-1] < v[n-2]){
			int aux = v[n-1];
			v[n-1] = v[n-2];
			v[n-2] = aux;
			goto eliabe;
    }
	}
}
int main (){
	int n;
	std::cin>>n;
	int e[n];
	int j =n;
	for(int i=0;i<n;i++,j--){
			e[i] = j;
	}
	booble_sort(e,n);
	std::cout<<"\n";
	std::cout<<"Ordenado :";
	for(int i =0;i<n ;i++){
			std::cout<<e[i] <<" ";
	} 
	
	return 0;
}
