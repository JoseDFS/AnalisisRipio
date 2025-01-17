#include <iostream> // std::cout, std::endl
#include <cmath> //exp, std::abs, pow
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;


//no podes usar P0 un punto critico 
// f(x) derivable
//
double b = -1.16583607818894, a = -1.25100322759761*pow(10,-4), r = 0.08205, g = 0.0542253936905836, t = 273.15, p1 = 200.0, p0 = (r * t) / p1;

double f(double v) {
	double z = r*t;
	return (z / v) + (b / pow(v, 2)) + (g / pow(v, 3)) + (a / pow(v, 4)) - p1; 
}
double df(double v) {
	double z = r*t;
	return (-z/ pow(v, 2)) - ((2 * b) / pow(v, 3)) - ((3 * g) / pow(v, 4)) - ((4 * a) / pow(v, 5)); 
}
/*
p0: AproximaciÃ³n inicial
TOL: tolerancia
Nmax: nÃºmero mÃ¡ximo de iteraciones
*/
void newton(double p0,double TOL,double Nmax){

	double p;
	for(int i=0; i < Nmax; i++){
		p = p0 - (f(p0)/df(p0));		
		cout << i << setprecision(9) << "\t" << p0 << 	"\t" << p << "\t" << abs(p0 - p) << endl;		
		if(abs(p - p0) < TOL)	break;
		p0 = p;				
	}

} 
	
int main(){
	double p0 =(0.08205)*(273.15); 	
	// Invocamos el mÃ©todo segÃºn los datos del problema
	newton(p0/200.0, pow(10, -9), 9);
	//cout<< setprecision(20)<<(f(1))<<endl;
	//cout<< setprecision(20)<<(df(1))<<endl;
	return 0;
}



//Condiciones
//Dentro del intervalo de trabajo [a,b], la derivada de f(x) debe ser diferente de cero.
//Dado un cierto intervalo de trabajo [a,b], dentro del mismo debe cumplirse que f(a)*f(b)<0.
//No lo vimos en la clase el siguiente
//La gráfica de la función f(x) dentro del intervalo de trabajo [a,b], debe ser cóncava, hacia arriba o hacia abajo. Para ello debe verificarse que :
//f ''(x) <= 0   ó   f ''(x) >= 0   para todo x que pertenezca a [a,b] 


//Orden de covergencia. (Quizas les sirva)
//Supongamos que{pn}∞n=0 es una sucesión que converge a p, con pn distinto p para todas las aproximaciones pn. Si existen constantes positivas α y λ con lim n→∞ |pn+1−p|/(|pn−p|)**α = λ  entonces {pn}∞n=0 converge a p con orden α y constante de error asintótica λ.Si α=1 y λ <1, la sucesión es linealmente convergente. Si α = 2,la sucesión es cuadráticamente convergente.

