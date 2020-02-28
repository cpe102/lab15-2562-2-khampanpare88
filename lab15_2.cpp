#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

//Write definition of randData(), showData() and findColSum()
void randData(double *dPtr,int N,int M){
	double y=0;
	for(int x=0;x<(N*M);x++){
			y=rand()%101;
			*(dPtr+x)=y/100;
	}
}
void findColSum(const double *dPtr,double *result,int N,int M){
	double y=0;
	for(int a=0;a<M;a++){
		for(int c=0;c<N*M;c=c+M){
			*(result+a)+=*(dPtr+c+a);
		}
	}
}
void showData(double *dPtr,int N,int M){
	for(int b=0;b<(N*M);b++){
			if(b!=0&&b%M==0){cout<<"\n";
			}
			cout<< *(dPtr+b)<<"\t";
	}
	cout<<"\n";
}