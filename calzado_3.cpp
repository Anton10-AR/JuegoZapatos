#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

class Calzado {
private:
	int talla;
	char ladoPie;
public:
	Calzado () {
		talla = 40;
		ladoPie = 'D';
	}
	
	Calzado (int tt, char lado) {
		talla = tt;
		ladoPie = lado;
	}
	
	bool esParDe(Calzado cal) {
		return (talla == cal.talla && ladoPie != cal.ladoPie) ? true : false;
	}
	
	Calzado crearPar() {
		Calzado par;
		par.talla = talla;
		par.ladoPie = talla == 'I' ? 'D' : 'I';
		return par;
	}
	
	void verDatos() {
		cout << "La talla es: " << talla << endl;
		if (ladoPie == 'I')
			cout << "Lado pie IZQUIERDA" << endl;
		else
			cout << "Lado pie DERECHA" << endl;
	}
	
	void dibujarPie() {
		switch (talla) {
		case 40:
			if (ladoPie == 'I') {
				cout << " ||    Talla: 40" << endl;
				cout << "oo|    Lado pie IZQUIERDO" << endl;
			}
			else {
				cout << "||     Talla : 40" << endl;
				cout << "|oo    Lado pie DERECHO" << endl;
			}
			break;
		case 41:
			if (ladoPie == 'I') {
				cout << "  ||   Talla: 41" << endl;
				cout << "ooo|   Lado pie IZQUIERDO" << endl;
			}
			else {
				cout << "||     Talla: 41" << endl;
				cout << "|ooo   Lado pie DERECHO" << endl;
			}
			break;
		case 42:
			if (ladoPie == 'I') {
				cout << "   ||  Talla: 42" << endl;
				cout << "oooo|  Lado pie IZQUIERDO" << endl;
			}
			else {
				cout << "||     Talla: 42" << endl;
				cout << "|oooo  Lado pie: DERECHO" << endl;
			}
			break;
		}
	}
	
	void randomizar() {
		int lado = rand() % 2;
		if (lado == 0) //0 = izquierdo, 1 = derecho
			ladoPie = 'I';
		else
			ladoPie = 'D';
		talla = 40 + rand() % 3;
	}
};

int main(int argc, char *argv[]) {
	srand(time(NULL));
	Calzado a, b, c;
	int flag = 1;
	int cont = 0;
	while (flag == 1) {
		cout << "Indica si existe un par de zapatos entre 'a', 'b' y 'c', o cualquier otra tecla si no existe un par." << endl;
		a.randomizar();
		b.randomizar();
		c.randomizar();
		cout << "-------------------------" << endl;
		cout << "Opcion A" << endl;
		cout << endl;
		a.dibujarPie();
		cout << endl;
		cout << "-------------------------" << endl;
		cout << "Opcion B" << endl;
		cout << endl;
		b.dibujarPie();
		cout << endl;
		cout << "-------------------------" << endl;
		cout << "Opcion C" << endl;
		cout <<endl;
		c.dibujarPie();
		cout << endl;
		cout << "-------------------------" << endl;
		cout << endl;
		string resp;
		cin >> resp;
		cout << endl;
		int aux;
		if ((resp == "ab") || (resp == "AB") || (resp == "ba") || (resp == "BA")) {
			aux = 1;
		}
		else {
			if((resp == "bc") || (resp == "BC") || (resp == "cb") || (resp == "CB")) {
				aux = 2;
			}
			else {
				if ((resp == "ac") || (resp == "AC") || (resp == "ca") || (resp == "CA")) {
					aux = 3;
				}
				else {
					aux = 4;
				}
			}
		}
		switch (aux) {
		case 1:
			if (a.esParDe(b)) {
				cout << "Acertaste!" << endl;
				cout << endl;
				cont += 1;
			}
			else {
				cout << "No es correcto" << endl;
				cout << endl;
				flag = 0;
			}
			break;
		case 2:
			if (b.esParDe(c)) {
				cout << "Acertaste!" << endl;
				cout << endl;
				cont += 1;
			}
			else {
				cout << "No es correcto" << endl;
				cout << endl;
				flag = 0;
			}
			break;
		case 3:
			if (a.esParDe(c)) {
				cout << "Acertaste!" << endl;
				cout << endl;
				cont += 1;
			}
			else {
				cout << "No es correcto" << endl;
				cout << endl;
				flag = 0;
			}
			break;
		case 4:
			if (!a.esParDe(b) && !a.esParDe(c) && !b.esParDe(c)) {
				cout << "Acertaste!" << endl;
				cout << endl;
				cont += 1;
			}
			else {
				cout << "No es correcto" << endl;
				cout << endl;
				flag = 0;
			}
			break;
		}
		
	}
	cout << "Numero de aciertos: " << cont << endl;
	return 0;
}

