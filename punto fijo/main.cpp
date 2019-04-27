#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

// FunciÃ³n para IPF
inline double g(double x){
	double a=exp(x);
	double b=x^2;
	return (2.0-a+b)/3.0;
}

/*
IteraciÃ³n de punto fijo
p0: aproximaciÃ³n inicial
Nmax: nÃºmero mÃ¡ximo de iteraciones
T: tolerancia
*/

void fixedPoint(double p0, int Nmax, double T){
	
	double p;	

	for(int i=0; i< Nmax; i++){
		p = g(p0);		
		cout << setprecision(10) <<  i << "\t" << p0 << "\t" << p << "\t" <<abs(p-p0) <<endl;
		
		if(abs(p-p0) < T) {
			cout << "Objetivo logrado con " << i+1 << " iteraciones"<< endl;
			break;
		}
		
		p0 = p;
	}
	
}

int main(){

	fixedPoint(0, 100, pow(10, -9));		
	
	return 0;
}

/*  
Para saber que metodo es mas rapido:
- k=abs(dev(g(p)))
-k>0.5 IPF mas lento
-k<0.5 biseccion mas lento
-k=0.5 son igual de rapido

Para numero de iteraciones:
- k= fmax(abs(g’(x)),x,a,b)
- n>= (log(Error/max((b-p0),(p0-a)))/logk)

*/