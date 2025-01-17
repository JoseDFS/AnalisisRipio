#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

// g(a)?[a,b] y g(b)?[a,b]
// k = fmax(?g?(x)?,x,a,b)
//si  k < 1 positivo ... pfijo unico
// Función para IPF
inline double g(double x){
	double a=exp(x);
	double b=pow(x,2.0);
	return ((2.0-a+b)/3.0);
}



// Inline para calcular cada término de la sucesión de Aitken
inline long double p_hat(long double p0,long double p1,long double p2){ return p0 - pow( p1-p0 , 2.0)/(p2 - 2.0*p1 + p0);}

/*
p0: aproximación inicial
Nmax: número máximo de iteraciones
T: tolerancia
Si no se usa long double, algún dato se puede aproximar a 0
*/
void steffensen(long double p0, int Nmax, long double T){

	long double p, p1, p2;

	for(int i = 0; i <= Nmax; i++){
		
		p1 = g(p0);
		p2 = g(p1);
		p = p_hat(p0, p1, p2);

		if(i == 0) cout <<i << setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t"  << p << endl;
		else cout <<  i<<setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t"  << p << "\t"  << abs(p0 - p) << endl;


		if(abs(p0-p) < T){
			cout << "Objetivo logrado con " << i+1 << " iteraciones"<< endl;
			break;
		}

		p0 = p;
	}
}

int main(){
	steffensen(0, 100, pow(10, -9));
}