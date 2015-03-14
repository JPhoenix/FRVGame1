#include "simplestrategy.h"

unsigned char uno_[][5] = { { 0, 0, 0, 0, 0 } };
unsigned char dos_[][5] = { { 0, 0, 0, 0, 0 }, { 1, 0,
		0, 0, 0 } };
unsigned char tres_[][5] = { { 0, 0, 0, 0, 0 }, { 1, 0,
		0, 0, 0 }, { 2, 0, 0, 0, 0 } };
unsigned char cuatro_[][5] = { { 0, 0, 0, 0, 0 }, { 1, 0,
		0, 0, 0 }, { 2, 0, 0, 0, 0 }, { 3,
		0, 0, 0, 0 } };
unsigned char cinco_[][5] = { { 0, 0, 0, 0, 0 }, { 1, 0,
		0, 0, 0 }, { 2, 0, 0, 0, 0 }, { 3,
		0, 0, 0, 0 }, { 4, 0, 0, 0, 0 } };
unsigned char seis_[][5] = { { 0, 0, 0, 0, 0 }, { 1, 0,
		0, 0, 0 }, { 2, 0, 0, 0, 0 }, { 3,
		0, 0, 0, 0 }, { 4, 0, 0, 0, 0 }, {
		5, 0, 0, 0, 0 } };
unsigned char siete_[][5] = { { 0, 0, 0, 0, 0 }, { 1, 0,
		0, 0, 0 }, { 2, 0, 0, 0, 0 }, { 3,
		0, 0, 0, 0 }, { 4, 0, 0, 0, 0 }, {
		5, 0, 0, 0, 0 }, { 6, 0, 0, 0, 0 } };
unsigned char ocho_[][5] = { { 0, 0, 0, 0, 0 }, { 1, 0,
		0, 0, 0 }, { 2, 0, 0, 0, 0 }, { 3,
		0, 0, 0, 0 }, { 4, 0, 0, 0, 0 }, {
		5, 0, 0, 0, 0 }, { 6, 0, 0, 0, 0 },
		{ 7, 0, 0, 0, 0 } };
unsigned char nueve_[][5] =
		{ { 0, 0, 0, 0, 0 },
				{ 1, 0, 0, 0, 0 }, { 2, 0, 0, 0,
						0 }, { 3, 0, 0, 0, 0 }, { 4,
						0, 0, 0, 0 }, { 5, 0, 0,
						0, 0 }, { 6, 0, 0, 0, 0 }, {
						7, 0, 0, 0, 0 }, { 8, 0, 0,
						0, 0 } };

unsigned char uno_dos[][5] = { { 0, 0, 0, 0, 0 } };
unsigned char dos_dos[][5] = { { 1, 1, 0, 0, 0 }, { 1, 0,
		0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 1, 0,
		0, 0 } };
unsigned char tres_dos[][5] = { { 1, 1, 0, 0, 0 }, { 1, 0,
		0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 1, 0,
		0, 0 }, { 0, 2, 0, 0, 0 }, { 1, 2, 0,
		0, 0 }, { 2, 0, 0, 0, 0 }, { 2, 1, 0,
		0, 0 }, { 2, 2, 0, 0, 0 } };

unsigned char uno_tres[][5] = { { 0, 0, 0, 0, 0 } };
unsigned char dos_tres[][5] = { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0,
		0 }, { 0, 1, 0, 0, 0 }, { 0, 1, 1, 0, 0 }, {
		1, 0, 0, 0, 0 }, { 1, 1, 0, 0, 0 }, { 1, 0, 1,
		0, 0 }, { 1, 1, 1, 0, 0 } };

unsigned char uno_cuatro[][5] = { { 0, 0, 0, 0, 0 } };

unsigned char uno_cinco[][5] = { { 0, 0, 0, 0, 0 } };

vector<vector<vector<vector<char> > > > soluciones;

vector<vector<char> > hacerVector(unsigned char arreglo[][5], int n, int k) {
	vector<vector<char> > ans;
	for (int i = 0; i < n; i++) {
		vector<char> temp;
		for (int j = 0; j < k; j++) {
			char a = arreglo[i][j];
			temp.push_back(a);
		}
		ans.push_back(temp);
	}
	return ans;
}

void crearSoluciones() {
	vector<vector<char> > m;

	vector<vector<vector<char> > > uno;

	vector<vector<char> > uno1;
	uno1 = hacerVector(uno_, 1, 1);
	vector<vector<char> > uno2;
	uno2 = hacerVector(uno_dos, 1, 2);
	vector<vector<char> > uno3;
	uno3 = hacerVector(uno_tres, 1, 3);
	vector<vector<char> > uno4;
	uno4 = hacerVector(uno_cuatro, 1, 4);
	vector<vector<char> > uno5;
	uno5 = hacerVector(uno_cinco, 1, 5);

	uno.push_back(uno1);
	uno.push_back(uno2);
	uno.push_back(uno3);
	uno.push_back(uno4);
	uno.push_back(uno5);

	soluciones.push_back(uno);

	vector<vector<vector<char> > > dos;

	vector<vector<char> > dos1;
	dos1 = hacerVector(dos_, 2, 1);
	vector<vector<char> > dos2;
	dos2 = hacerVector(dos_dos, 4, 2);
	vector<vector<char> > dos3;
	dos3 = hacerVector(dos_tres, 8, 3);

	dos.push_back(dos1);
	dos.push_back(dos2);
	dos.push_back(dos3);

	soluciones.push_back(dos);

	vector<vector<vector<char> > > tres;

	vector<vector<char> > tres1;
	tres1 = hacerVector(tres_, 3, 1);
	vector<vector<char> > tres2;
	tres2 = hacerVector(tres_dos, 9, 2);

	tres.push_back(tres1);
	tres.push_back(tres2);

	soluciones.push_back(tres);

	vector<vector<vector<char> > > cuatro;

	vector<vector<char> > cuatro1;
	cuatro1 = hacerVector(cuatro_, 4, 1);

	cuatro.push_back(cuatro1);

	soluciones.push_back(cuatro);

	vector<vector<vector<char> > > cinco;

	vector<vector<char> > cinco1;
	cinco1 = hacerVector(cinco_, 5, 1);
	cinco.push_back(cinco1);

	soluciones.push_back(cinco);

	vector<vector<vector<char> > > seis;

	vector<vector<char> > seis1;
	seis1 = hacerVector(seis_, 6, 1);
	seis.push_back(seis1);

	soluciones.push_back(seis);

	vector<vector<vector<char> > > siete;

	vector<vector<char> > siete1;
	siete1 = hacerVector(siete_, 7, 1);
	siete.push_back(siete1);

	soluciones.push_back(siete);

	vector<vector<vector<char> > > ocho;

	vector<vector<char> > ocho1;
	ocho1 = hacerVector(ocho_, 8, 1);
	ocho.push_back(ocho1);

	soluciones.push_back(ocho);

	vector<vector<vector<char> > > nueve;

	vector<vector<char> > nueve1;
	nueve1 = hacerVector(nueve_, 9, 1);
	nueve.push_back(nueve1);

	soluciones.push_back(nueve);
}

unsigned char one_color[5];

void simplestrategy(int n, int k) {
	//if (n == 1){

	//	read_answer();
	//}
	n--;
	int k2 = k - 1;
	for (unsigned i = 0; i < soluciones[n][k2].size(); i++) {
		write(socket_desc, (char*)&(soluciones[n][k2][i][0]), k);
		read_answer();
		if (gR == k) {
			return;
		}
	}
}

