#ifndef __JUGADOR_H__
#define __JUGADOR_H__

using namespace System::Drawing;
enum Direcciones { Arriba, Abajo, Izquierda, Derecha, Ninguna };
class CJugador
{
public:
	CJugador(int x, int y);
	~CJugador();
	Rectangle getRectangulo();
	void setdx(int dx);
	void setdy(int dy);
	int getx();
	int gety();
	int getvidas();
	void setvidas(int v);
	void ValidarMovimiento(int** matriz);
	void DisminuirVidas();
	void DisminuirVidas(int Puntaizquierda, int Puntaderecha, int CentroinicioY, int CentrofinalY,int Puntasuperior, int Puntainferior, int CentroinicioX, int CentrofinalX);
	void DibujarJugador(Graphics^ g, Bitmap^ bmpJugador, int** matriz);
	void MoverJugador(Graphics^ g, Bitmap^ bmpJugador, int** matriz);
	void setDireccion(Direcciones direccion);
	Direcciones getDireccion();
	void setAcelerar(int v);
	int getAcelerar();


private:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	int vidas;
	int acelerar;
	Direcciones direccion;
	Direcciones ultima;
	Rectangle DeIz;
	Rectangle ArAb;
}; 

CJugador::CJugador(int x, int y)
{
	//Posicion del jugador
	this->x = x;
	this->y = y;
	//Movimiento del jugador
	dx = 0;
	dy = 0;
	acelerar = 0;
	//Animacion del sprite
	ancho = 18;
	alto = 26;
	indiceX = 0;
	indiceY = 0;
	//Cantidad de vidas iniciales
	vidas = 5;
	//variables de direccion
	direccion = Direcciones::Ninguna;
	ultima = Direcciones::Abajo;
}

CJugador::~CJugador()
{

}

Rectangle CJugador::getRectangulo()
{
	return Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3);
}

void CJugador::setdx(int dx)
{
	this->dx = dx;
}

void CJugador::setdy(int dy)
{
	this->dy = dy;
}

int CJugador::getx()
{
	return x + 2 * 3;
}

int CJugador::gety()
{
	return y + 15 * 3 + dy;
}

int CJugador::getvidas()
{
	return vidas;
}

void CJugador::setvidas(int v)
{
	vidas = v;
}

void CJugador::setDireccion(Direcciones direccion)
{
	this->direccion = direccion;
}

Direcciones CJugador::getDireccion()
{
	return direccion;
}

void CJugador::setAcelerar(int v)
{
	acelerar = v;
}

inline int CJugador::getAcelerar()
{
	return acelerar;
}

void CJugador::ValidarMovimiento(int** matriz)
{
	int X, Y = 0;
	for (int i = 0; i < filas; i++)
	{
		X = 0;
		for (int j = 0; j < columnas; j++)
		{
			Rectangle r1 = Rectangle(X, Y, 50, 50);
			if (matriz[i][j] == 1 || matriz[i][j] == 3)
			{
				if (DeIz.IntersectsWith(r1))dx = 0;
				if (ArAb.IntersectsWith(r1))dy = 0;
			}
			X += 50;
		}
		Y += 50;
	}
}

void CJugador::DisminuirVidas()
{
	x = 50;
	y = 50;
	vidas--;
}

void CJugador::DisminuirVidas(int Puntaizquierda, int Puntaderecha, int CentroinicioY, int CentrofinalY, int Puntasuperior, int Puntainferior, int CentroinicioX, int CentrofinalX)
{
	if (getx() >= Puntaizquierda && getx() <= Puntaderecha && gety() >= CentroinicioY && gety() <= CentrofinalY)
	{
		x = 50;
		y = 50;
		vidas--;
	}
	if (gety() >= Puntasuperior && gety() <= Puntainferior && getx() >= CentroinicioX && getx() <= CentrofinalX)
	{
		x = 50;
		y = 50;
		vidas--;
	}
}

void CJugador::DibujarJugador(Graphics^ g, Bitmap^ bmpJugador, int** matriz)
{
	DeIz = Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3);
	ArAb = Rectangle(x + 2 * 3, y + 15 * 3 + dy, (ancho - 4) * 3, (alto - 15) * 3);

	g->DrawRectangle(Pens::Transparent, DeIz);
	g->DrawRectangle(Pens::Transparent, ArAb);

	ValidarMovimiento(matriz);

	Rectangle EspacioUsado = Rectangle(indiceX * ancho, indiceY* alto, ancho, alto);
	Rectangle Aumento = Rectangle(x, y, ancho * 3, alto * 3);
	g->DrawImage(bmpJugador, Aumento, EspacioUsado, GraphicsUnit::Pixel);
	x += dx;
	y += dy;
}

void CJugador::MoverJugador(Graphics^ g, Bitmap^ bmpJugador, int** matriz)
{
	direccion == Arriba ? ancho = 17 : ancho = 18;
	switch (direccion)
	{
	case Direcciones::Arriba:
		indiceY = 0;
		if (indiceX >= 1 && indiceX < 3) 
		{
			indiceX++;
		}
		else
		{
			indiceX = 1;
		}
		dx = 0;
		dy = -10 - acelerar;
		ultima = Arriba;
		break;
	case Direcciones::Abajo:
		indiceX = 0;
		if (indiceY >= 1 && indiceY < 3)
		{
			indiceY++;
		}
		else
		{
			indiceY = 1;
		}
		dx = 0;
		dy = 10 + acelerar;
		ultima = Abajo;
		break;
	case Direcciones::Izquierda:
		indiceY = 3;
		if (indiceX >= 1 && indiceX < 3)
		{
			indiceX++;
		}
		else
		{
			indiceX = 1;
		}
		dx = -10 - acelerar;
		dy = 0;
		ultima = Izquierda;
		break;
	case Direcciones::Derecha:
		indiceY = 1;
		if (indiceX >= 1 && indiceX < 3)
		{
			indiceX++;
		}
		else
		{
			indiceX = 1;
		}
		dx = 10 + acelerar;
		dy = 0;
		ultima = Derecha;
		break;
	case Direcciones::Ninguna:
		dx = dy = 0;
		if (ultima == Direcciones::Abajo)
		{
			indiceX = 0;
			indiceY = 2;
		}
		if (ultima == Direcciones::Arriba)
		{
			indiceX = 0;
			indiceY = 0;
		}
		if (ultima == Direcciones::Derecha)
		{
			indiceX = 1;
			indiceY = 1;
		}
		if (ultima == Direcciones::Izquierda)
		{
			indiceX = 1;
			indiceY = 3;
		}
		break;
	default:
		break;
	}
	DibujarJugador(g, bmpJugador, matriz);
}

#endif // !__JUGADOR_H__

