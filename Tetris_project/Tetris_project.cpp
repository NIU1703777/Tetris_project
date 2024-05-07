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

void inicilizarMatriz(ColorFigura m[F][C], ColorFigura m_aux[F][C]) {
	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			m[i][j] = m_aux[i][j];
		}
	}
}

void invertirColumnas(ColorFigura m[F][C]) {
	ColorFigura m_aux[F][C];

	int w = C - 1;

	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			m_aux[i][w - j] = m[i][j];
		}
	}

	inicilizarMatriz(m, m_aux);

}

void invertirFilas(ColorFigura m[F][C]) {
	ColorFigura m_aux[F][C];

	int w = F - 1;

	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			m_aux[w - i][j] = m[i][j];
		}
	}

	inicilizarMatriz(m, m_aux);

}


void TrasposarMatriz(ColorFigura m[F][C]) {
	ColorFigura m_aux[F][C];

	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++;) {
			m_aux[j][i] = m[i][j];
		}
	}

	inicilizarMatriz(m, m_aux);
	
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
	ColorFigura getSquareFigura(const int pos_f, const int pos_c) const { return m_figura[pos_f][pos_c]; }
	int getFila() const { return m_pos_f; }
	int getColumna() const { return m_pos_C; }
	int getFilaInicial() const { return m_inici_f; }
	int getColumnaInicial() const { return m_inici_c; }
	int getFilaFinal() const { return m_final_f; }
	int getColumnaFinal() const { return m_final_c}
	int getGiro() const { return num_giro; }
	int getMaxLeft() const { return m_max_left; }
	int getMaxRight() const { return m_max right; }

	//
	void GiraFigura(DireccioGir sentit, int num_tipo);
	void CalculaExtremsMatriu();
	void CalculaMaxLeftAndRight();
	void BaixarFigura();

private:
	TipusFigura m_tipo; 
	ColorFigura m_color;
	ColorFigura m_figura[F][C];
	int num_giro; // 0 - 3 segun pdf
	int m_pos_f;
	int m_pos_c;
	int m_inici_f;
	int m_inici_c;
	int m_final_f;
	int m_final_c;
	int m_max_left;
	int m_max_right
	
};

Figura::~Figura() {

}

void Figura::InicialitzarFigura(TipusFigura tipo, ColorFigura color, const int x, const int y) { // Inicilizar figura con num_giro = 0

}

void Figura::GiraFigura(DireccioGir sentit) {
	if (sentit == GIR_HORARI) {
		if (m_tipo == FIGURA_I) {
			// Rellenar para figura 4x4
		}
		else {
			if (m_tipo != FIGURA_O) {
				TrasposarMatriz(m_figura);
				invertirColumnas(m_figura);
			}
		}
	}
	else {
		if (m_tipo == FIGURA_I) {
			// Rellenar para figura 4x4
		}
		else {
			if (m_tipo != FIGURA_O) {
				TrasposarMatriz(m_figura);
				invertirFilas(m_figura);
			}
		}
	}
}

void Figura::CalculaExtremsMatriu() {
	if (m_tipo == FIGURA_I) {
		m_inici_f = m_pos_f - 1;
		m_inici_c = m_pos_c - 2;
		m_final_f = m_pos_f + 2;
		m_final_c = m_pos_c + 1;
	}
	else {
		if (m_tipo == FIGURA_O) {
			m_inici_f = m_pos_f;
			m_inici_c = m_pos_c;
			m_final_f = m_pos_f + 1;
			m_final_c = m_pos_c + 1;
		}
		else {
			m_inici_f = m_pos_f - 1;
			m_inici_c = m_pos_c - 1;
			m_final_f = m_pos_f + 1;
			m_final_c = m_pos_c + 1;
		}
	}

}

void Figura::CalculaMaxLeftAndRight() {
	int right_max = 0, int left_max = 10, i = 0, j = 1;

	while (i < F - 1) {
		while (j < C - 1) {
			if ()
		}
	}
}

void Figura::BaixarFigura() {

}

// Termina clase figura





class Tauler {
public:
	
	void setSquare(ColorFigura color, int f, int c);
	void AddFigura(int giro, int x, int y, int num_tipo);

	bool ComprovaDesplazament(Figura figura, int f, int c);
	bool ComprovaGiro(int x, int y, int giro_inicial, DireccioGir sentit);
	void eliminarfila();
	void SetFiguraInTauler(Figura figura, int x, int y);


private:
	ColorFigura m_tauler[F][C];
	bool ComprovarChoques(int lon_f, int lon_c);
};


/*
ComprovarChoques(Figura figura, int lon_f, int lon_c):

Parametros: 
	Figura figura: Figura que esta cayendo en tablero.
	int lon_f: Numero de filas de la matriz m_figura de la clase Figura.
	int lon_c: Numero de columnas de la matriz m_figura de la clase Figura.

Descripción:
	Funcion que comprueba si no existe colision entre la figura que esta cayendo y las diferentes figuras que ya se encuentran en el tablero 

Retorno:
	Bool: Retorna un true si existe colision, y false en caso contrario

*/
bool Tauler::ComprovarChoques(Figura figura, int lon_f, int lon_c) {
	int i = 0, j = 0, w = figura.getFilaInicial(), z = figura.getColumnaInicial();
	bool out = true;

	while (i < lon_f) {
		while (j < lon_c) {
			if (figura.getSquareFigura(i, j) == POSICIO_BUIDA) {
				if (m_tauler[w + i][z + j] != POSICIO_BUIDA) {
					out = false;
				}
			}
			j++;
		}
		i++;
	}

	return out;
}

void Tauler::setSquare(ColorFigura color, int f, int c) {

}


bool Tauler::ComprovaDesplazament(Figura figura, int f, int c, int dirX) {
	bool desplazar;
	

	
	return;
}

bool Tauler::ComprovaGiro(Figura figura,  DireccioGir sentit) {
	bool gir = true;

	// Comprueba si existe colisiones con otras figuras ya colocadas

	if (figura.getTipo() == FIGURA_O) {
			gir = false;
	}
	else {
		gir = ComprovarChoques(figura, 3, 3);
	}


	if (gir) {
		if ((figura.getGiro() == 3) && (sentit == GIR_HORARI)) {
			gir = false;
		}
		if ((figura.getGiro() == 0) && (sentit == GIR_ANTI_HORARI)) {
			gir = false;
		}
		if ((figura.getTipo() = FIGURA_I) && (gir)) {
			if((figura.getGiro() == 0) && (sentit == GIR_HORARI)) {
				if (((m_tauler[figura.getFila() + 1][figura.getColumnaFinal()] != POSICIO_BUIDA) || (m_tauler[figura.getFila() + 1][figura.getColumnaFinal() + 1] != POSICIO_BUIDA)) || (figura.getFilaInicial() == 0)) {
					gir = false;
				}
			}
			if ((figura.getGiro() == 1) && (sentit == GIR_HORARI)) {
				if (((m_tauler[figura.getFila()][figura.getColumnaFinal()] != POSICIO_BUIDA) || (m_tauler[figura.getFila()][figura.getColumnaFinal() + 1] != POSICIO_BUIDA) || (m_tauler[figura.getFila()][figura.getColumnaFinal() - 1] != POSICIO_BUIDA) || (m_tauler[figura.getFila() - 1][figura.getColumnaFinal() - 1] != POSICIO_BUIDA)) || (figura.getColumnaFinal() == C - 1)) {
					gir = false;
				 }
			}
			if ((figura.getGiro() == 2) && (sentit == GIR_ANTI_HORARI)) {
				gir = ComprovarChoques(figura, 4, 4);
			}
			if ((figura.getGiro() == 2) && (sentit == GIR_HORARI)) {
				if ((m_tauler[figura.getFilaFinal()][figura.getColumna()] != POSICIO_BUIDA) || (m_tauler[figura.getFilaFinal()][figura.getColumna() + 1] != POSICIO_BUIDA) || (m_tauler[figura.getFilaFinal()][figura.getColumna() + 2] != POSICIO_BUIDA) || (m_tauler[figura.getFilaFinal() + 1][figura.getColumna()] != POSICIO_BUIDA) || (m_tauler[figura.getFilaFinal() + 1][figura.getColumna() + 1] != POSICIO_BUIDA) || (m_tauler[figura.getFilaFinal() + 1][figura.getColumna() + 2] != POSICIO_BUIDA) || (figura.getFilaFinal() == F - 2)) {
					gir = false;
				}
			}
			if ((figura.getGiro() == 3) && (sentit == GIR_ANTI_HORARI)) {
				gir = ComprovarChoques(figura, 4, 4);
			}

		}
		if ((figura.getColumnaFinal() == C) && (sentit == GIR_ANTI_HORARI)) {
			gir = false;
		}
		if ((figura.getFilaFinal() == F)) {
			gir = false;
		}

	}
	return gir;
}

void Tauler::MostraTauler() {

}

void Tauler::eliminarfila() {

}

void Tauler::SetFiguraInTauler(Figura figura, int f, int c) {

	int w = 0, z = 0;
	int i = figura.getFilaInicial(), j = figura.getColumnaInicial();

	while (i < figura.getColumnaFinal()) {
		while(j <  figura.getColumnaFinal()){
			if (m_tauler[i][j] == POSICIO_BUIDA) {
				m_tauler[i][j] = figura.m_figura[w][z];	
			}
			z++;
			j++;
		}
		i++;
		w++;
	}

	
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

	figura_actual[0].CalculaExtremsMatriu();

	for (i = 1; i <= giro; i++) {
		if (tauler.ComprovaGiro(figura_actual[0], GIR_HORARI) {
			figura_actual[0].GiraFigura(GIR_HORARI);
		}	
	}
	tauler.FiguraTauler(figura_actual, fila, columna);

	fitxer.close();
}





