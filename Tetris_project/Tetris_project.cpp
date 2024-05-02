#include <fstream>

using namespace std;

int const F = 10;
int const C = 10;
int const MAX_FIGURES = 50;

typedef enum
{
	NO_FIGURA = 0,
	FIGURA_O = 1,
	FIGURA_I = 2,
	FIGURA_T = 3, 
	FIGURA_L = 4,
	FIGURA_J = 5,
	FIGURA_Z = 6,
	FIGURA_S = 7

} TipusFigura;

typedef enum
{
	POSICIO_BUIDA = 0,
	COLOR_GROC,
	COLOR_BLAUCEL,
	COLOR_MAGENTA,
	COLOR_TARONJA,
	COLOR_BLAUFOSC,
	COLOR_VERMELL,
	COLOR_VERD,
} ColorFigura;

typedef enum {
	GIR_HORARI = 0,
	GIR_ANTI_HORARI
}DireccioGir;

ColorFigura asignarColor(int num_color) {

	ColorFigura color;

	switch (num_color) {
	case 0:
		color = POSICIO_BUIDA;
		break;
	case 1:
		color = COLOR_GROC;
		break;
	case 2:
		color = COLOR_BLAUCEL;
		break;
	case 3:
		color = COLOR_MAGENTA;
		break;
	case 4:
		color = COLOR_TARONJA;
		break;
	case 5:
		color = COLOR_BLAUFOSC;
		break;
	case 6:
		color = COLOR_VERMELL;
		break;
	case 7:
		color = COLOR_VERD;
		break;
	}

	return color;
}

TipusFigura asignarTipo(int num_tipo) {

	TipusFigura tipo;

	switch (num_tipo) {
	case 0:
		tipo = NO_FIGURA;
		break;
	case 1:
		tipo = FIGURA_O;
		break;
	case 2:
		tipo = FIGURA_I;
		break;
	case 3:
		tipo = FIGURA_T;
		break;
	case 4:
		tipo = FIGURA_L;
		break;
	case 5:
		tipo = FIGURA_J;
		break;
	case 6:
		tipo = FIGURA_Z;
		break;
	case 7:
		tipo = FIGURA_S;
		break;
	}

	return tipo;
}



void TrasposarMatriz() {
	/* Recordar guardar la matriz en una matriz auxiliar para no perderla */
}

void invertirColumnas() {
	/* Recordar guardar la matriz en una matriz auxiliar para no perderla */
}

void invertirFilas() {
	/* Recordar guardar la matriz en una matriz auxiliar para no perderla */
}

class Figura {
public:

	// Metodos de inicialización
	Figura() { m_tipo = NO_FIGURA; m_color = POSICIO_BUIDA; m_pos_x = 0; m_pos_y = 0; }
	void InicialitzarFigura(TipusFigura tipo, ColorFigura color, const int x, const int y); // Completar
	~Figura() {}
	
	void setPos(int x, int y) { m_pos_x = x; m_pos_y = y; }

	// Metodos de retorno

	TipusFigura getTipo() const { return m_tipo; }
	ColorFigura getColor() const { return m_color; }
	int getX() const { return m_pos_x; }
	int getY() const { return m_pos_y; }

	//
	void GiraFigura(DireccioGir sentit);

private:
	TipusFigura m_tipo; 
	ColorFigura m_color;
	int m_pos_x;
	int m_pos_y;
	
};

Figura::~Figura() {

}

void Figura::InicialitzarFigura(TipusFigura tipo, ColorFigura color, const int x, const int y) {

}

void Figura::GiraFigura(DireccioGir sentit) {

}

// Termina clase figura





class Tauler {
public:
	
	void setSquare(ColorFigura color, int x, int y);
	void AddFigura(int giro, int x, int y, int num_tipo);

	bool ComprovaDesplazament(int x, int y);
	bool ComprovaGiro(int x, int y);
	void ColocaFigura(); // Comprueba si tiene que eliminar una columna, y si es asi desplaza la figura una posicion abajo, si no lo deja como estaba
	void MostraTauler();


private:
	ColorFigura m_tauler[F][C];
	void AddFigura_tipo1(int giro, int x, int y);
	void AddFigura_tipo2(int giro, int x, int y);
	void AddFigura_tipo3(int giro, int x, int y);
	void AddFigura_tipo4(int giro, int x, int y);
	void eliminarfila();
};

void Tauler::AddFigura_tipo1(int giro, int x, int y) {
	m_tauler[x][y] = COLOR_GROC;

	switch (giro) {
	case 0:
		m_tauler[x][y + 1] = COLOR_GROC;
		m_tauler[x][y - 1] = COLOR_GROC;
		m_tauler[x - 1][y - 1] = COLOR_GROC;
		break;
	case 1:
		m_tauler[x + 1][y] = COLOR_GROC;
		m_tauler[x - 1][y] = COLOR_GROC;
		m_tauler[x - 1][y + 1] = COLOR_GROC;
		break;
	case 2:
		m_tauler[x][y + 1] = COLOR_GROC;
		m_tauler[x][y - 1] = COLOR_GROC;
		m_tauler[x + 1][y + 1] = COLOR_GROC;
		break;
	case 3:
		m_tauler[x - 1][y] = COLOR_GROC;
		m_tauler[x + 1][y] = COLOR_GROC;
		m_tauler[x + 1][y - 1] = COLOR_GROC;
		break;
	}
}

void Tauler::AddFigura_tipo2(int giro, int x, int y) {
	m_tauler[x][y] = COLOR_TARONJA;

	switch (giro) {
	case 0:
		m_tauler[x][y - 1] = COLOR_TARONJA;
		m_tauler[x][y + 1] = COLOR_TARONJA;
		m_tauler[x - 1][y + 1] = COLOR_TARONJA;
		break;
	case 1:
		m_tauler[x + 1][y] = COLOR_TARONJA;
		m_tauler[x - 1][y] = COLOR_TARONJA;
		m_tauler[x + 1][y + 1] = COLOR_TARONJA;
		break;
	case 2:
		m_tauler[x][y + 1] = COLOR_TARONJA;
		m_tauler[x][y - 1] = COLOR_TARONJA;
		m_tauler[x + 1][y - 1] = COLOR_TARONJA;
		break;
	case 3:
		m_tauler[x - 1][y] = COLOR_TARONJA;
		m_tauler[x + 1][y] = COLOR_TARONJA;
		m_tauler[x - 1][y - 1] = COLOR_TARONJA;
		break;
	}
}

void Tauler::AddFigura_tipo3(int giro, int x, int y) {
	m_tauler[x][y] = COLOR_VERD;

	switch (giro) {
	case 0:
		m_tauler[x][y - 1] = COLOR_VERD;
		m_tauler[x - 1][y] = COLOR_VERD;
		m_tauler[x - 1][y + 1] = COLOR_VERD;
		break;
	case 1:
		m_tauler[x - 1][y] = COLOR_VERD;
		m_tauler[x][y + 1] = COLOR_VERD;
		m_tauler[x + 1][y + 1] = COLOR_VERD;
		break;
	case 2:
		m_tauler[x][y + 1] = COLOR_VERD;
		m_tauler[x + 1][y - 1] = COLOR_VERD;
		m_tauler[x + 1][y] = COLOR_VERD;
		break;
	case 3:
		m_tauler[x][y - 1] = COLOR_VERD;
		m_tauler[x + 1][y] = COLOR_VERD;
		m_tauler[x - 1][y - 1] = COLOR_VERD;
		break;
	}
}

/// Terminar
void Tauler::AddFigura_tipo4(int giro, int x, int y) {
	m_tauler[x][y] = COLOR_VERMELL;

	switch (giro) {
	case 0:
		m_tauler[x][y - 1] = COLOR_VERMELL;
		m_tauler[x - 1][y] = COLOR_VERMELL;
		m_tauler[x - 1][y + 1] = COLOR_VERMELL;
		break;
	case 1:
		m_tauler[x - 1][y] = COLOR_VERMELL;
		m_tauler[x][y + 1] = COLOR_VERMELL;
		m_tauler[x + 1][y + 1] = COLOR_VERMELL;
		break;
	case 2:
		m_tauler[x][y + 1] = COLOR_VERMELL;
		m_tauler[x + 1][y - 1] = COLOR_VERMELL;
		m_tauler[x + 1][y] = COLOR_VERMELL;
		break;
	case 3:
		m_tauler[x][y - 1] = COLOR_VERMELL;
		m_tauler[x + 1][y] = COLOR_VERMELL;
		m_tauler[x - 1][y - 1] = COLOR_VERMELL;
		break;
	}
}



void Tauler::setSquare(ColorFigura color, int x, int y) {

}


bool Tauler::ComprovaDesplazament(int x, int y) {

	return;
}

bool Tauler::ComprovaGiro(int x, int y) {

	return;
}

void Tauler::ColocaFigura() {

}

void Tauler::MostraTauler() {

}

void Tauler::eliminarfila() {

}



 



class Joc {
public:
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);

private:
	Tauler tauler;
	Figura figura_actual[MAX_FIGURES];
	float punts;
	int nivell;

};


void Joc::inicialitza(const string& nomFitxer) {
	ifstream fitxer;
	fitxer.open(nomFitxer);


	TipusFigura tipo;
	ColorFigura color;
	int i, j, fila, columna, num_tipo, giro, num_color;
	

	fitxer >> num_tipo >> fila >> columna >> giro;
	tipo = asignarTipo(num_tipo);
	color = asignarColor(num_tipo);

	figura_actual[0].InicialitzarFigura(tipo, color, fila, columna);

	for (i = 0; i < F; i++) {
		for (j = 0; j++; j < C) {
			fitxer >> num_color;
			color = asignarColor(num_color);
			tauler.setSquare(color, i, j);
		}
	}

	for (i = 0; i < giro; i++) {
		figura_actual[0].GiraFigura(GIR_HORARI);
	}





	fitxer.close();
}





