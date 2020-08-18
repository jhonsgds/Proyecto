#ifndef __BOMBA_H__
#define __BOMBA_H__

using namespace System::Drawing;
enum Estado { inicial, explosion, desaparecer };
class CBomba
{
public:
	CBomba(int x, int y);
	~CBomba();
	Rectangle getRectangulo();
	bool ValidarLugar(int xJugador, int yJugador, int** matriz);
	void DibujarBomba(Graphics^ g, Bitmap^ bmpBomba, int xJugador, int yJugador, int** matriz);
	void Animar(); 
	void AnimarExplosion();
	void DibujarExplosion(Graphics^ g, Bitmap^ bmpExplosionCentro, int** matriz);
	Estado getEstado();
	int getx();
	int gety();
	void setx(int v);
	void sety(int v);

private:
	int x;
	int y;
	int ancho;
	int alto;
	int indiceX;
	int tiempo_anterior;
	Estado estado;
	int indiceEx;
	int indiceEy;
	int altoExp;
	int anchoExp;

};

CBomba::CBomba(int x, int y)
{
	this->x = x;
	this->y = y;
	estado = Estado::inicial;
	ancho = 66 / 3;
	alto = 24;
	indiceX = 0;
	tiempo_anterior = 0;
	indiceEx = 0;
	indiceEy = 0;
	altoExp = 160 / 8;
	anchoExp = 80 / 4;
}

CBomba::~CBomba()
{

}

Rectangle CBomba::getRectangulo()
{
	return Rectangle(x, y, 40, 40);
}

bool CBomba::ValidarLugar(int xJugador, int yJugador, int** matriz)
{
	if (matriz[yJugador/50][xJugador/50] == 0 || matriz[yJugador/50][xJugador/50] == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CBomba::DibujarBomba(Graphics^ g, Bitmap^ bmpBomba, int xJugador, int yJugador, int** matriz)
{
	if (ValidarLugar(xJugador, yJugador, matriz) == true)
	{
		Rectangle espacioUsado = Rectangle(indiceX * ancho, 0, ancho, alto);
		Rectangle aumento = Rectangle(x, y, 40, 40);
		g->DrawImage(bmpBomba, aumento, espacioUsado, GraphicsUnit::Pixel);
	}
	if (tiempo_anterior == 6)
	{
		estado = Estado::explosion;
	}
}

void CBomba::Animar()
{
	if (indiceX >= 0 && indiceX < 2)
	{
		indiceX++;
	}
	else
	{
		tiempo_anterior++;
		indiceX = 0;
	}
}

void CBomba::DibujarExplosion(Graphics^ g, Bitmap^ bmpExplosionCentro, int** matriz) {

	Rectangle porcionUsarCentro = Rectangle(indiceEx * anchoExp, indiceEy * altoExp, anchoExp, altoExp); // indiceY=0
	Rectangle centro = Rectangle(x, y, 50, 50);
	g->DrawImage(bmpExplosionCentro, centro, porcionUsarCentro, GraphicsUnit::Pixel);
	if (matriz[y / 50][(x - 50) / 50] != 1) 
	{
		Rectangle porcionUsarIzquierda = Rectangle(indiceEx * anchoExp, indiceEy + 2 * altoExp, anchoExp, altoExp); //indiceY = 2
		Rectangle izquierda = Rectangle(x - 50, y, 50, 50);
		g->DrawImage(bmpExplosionCentro, izquierda, porcionUsarIzquierda, GraphicsUnit::Pixel);

		if (matriz[y / 50][(x - 50) / 50] == 3)
		{ 
			matriz[y / 50][(x - 50) / 50] = 2; 
		}
	}


	if (matriz[y / 50][(x + 50) / 50] != 1) 
	{
		Rectangle porcionUsarDerecha = Rectangle(indiceEx * anchoExp, indiceEy + 4 * altoExp, anchoExp, altoExp); //indiceY = 4
		Rectangle derecha = Rectangle(x + 50, y, 50, 50);
		g->DrawImage(bmpExplosionCentro, derecha, porcionUsarDerecha, GraphicsUnit::Pixel);

		if (matriz[y / 50][(x + 50) / 50] == 3) 
		{
			matriz[y / 50][(x + 50) / 50] = 2;
		}

	}
	if (matriz[y / 50][(x + 50) / 50] != 1) 
	{
		Rectangle porcionUsarPuntaDerecha = Rectangle(indiceEx * anchoExp, indiceEy + 3 * altoExp, anchoExp, altoExp); //indiceY = 3
		Rectangle Puntaderecha = Rectangle(x + 100, y, 50, 50);
		g->DrawImage(bmpExplosionCentro, Puntaderecha, porcionUsarPuntaDerecha, GraphicsUnit::Pixel);

		if (matriz[y / 50][(x + 100) / 50] == 3 && matriz[y / 50][(x + 50) / 50] != 1)
		{

			matriz[y / 50][(x + 100) / 50] = 2;
		}
	}

	if (matriz[y / 50][(x - 50) / 50] != 1)
	{
		Rectangle porcionUsarPuntaIzquierda = Rectangle(indiceEx * anchoExp, indiceEy + 1 * altoExp, anchoExp, altoExp); //indiceY = 1
		Rectangle Puntaizquierda = Rectangle(x - 100, y, 50, 50);
		g->DrawImage(bmpExplosionCentro, Puntaizquierda, porcionUsarPuntaIzquierda, GraphicsUnit::Pixel);

		if (matriz[y / 50][(x - 100) / 50] == 3 && matriz[y / 50][(x - 50) / 50] != 1)
		{
			matriz[y / 50][(x - 100) / 50] = 2;
		}
	}

	Rectangle porcionUsarVerticales = Rectangle(indiceEx * anchoExp, indiceEy + 6 * altoExp, anchoExp, altoExp); //indiceY = 1
	Rectangle VerticalSuperior = Rectangle(x, y - 50, 50, 50);
	Rectangle VerticalInferior = Rectangle(x, y + 50, 50, 50);

	if (matriz[(y - 50) / 50][x / 50] != 1)
	{ 
		g->DrawImage(bmpExplosionCentro, VerticalSuperior, porcionUsarVerticales, GraphicsUnit::Pixel);
	}
	if (matriz[(y - 50) / 50][x / 50] == 3) 
	{ 
		matriz[(y - 50) / 50][x / 50] = 2; 
	}
	if (matriz[(y + 50) / 50][x / 50] != 1) 
	{ 
		g->DrawImage(bmpExplosionCentro, VerticalInferior, porcionUsarVerticales, GraphicsUnit::Pixel);
	}
	if (matriz[(y + 50) / 50][x / 50] == 3) 
	{ 
		matriz[(y + 50) / 50][x / 50] = 2; 
	}


	if (matriz[(y - 50) / 50][x / 50] != 1)
	{
		Rectangle porcionUsarPuntaSuperior = Rectangle(indiceEx * anchoExp, indiceEy + 5 * altoExp, anchoExp, altoExp); //indiceY = 5
		Rectangle PuntaSuperior = Rectangle(x, y - 100, 50, 50);
		g->DrawImage(bmpExplosionCentro, PuntaSuperior, porcionUsarPuntaSuperior, GraphicsUnit::Pixel);

		if (matriz[(y - 100) / 50][x / 50] == 3 && matriz[(y - 50) / 50][x / 50] != 1)
		{ 
			matriz[(y - 100) / 50][x / 50] = 2;
		}
	}


	if (matriz[(y + 50) / 50][x / 50] != 1)
	{
		Rectangle porcionUsarPuntaInferior = Rectangle(indiceEx * anchoExp, indiceEy + 7 * altoExp, anchoExp, altoExp); //indiceY = 7
		Rectangle PuntaInferior = Rectangle(x, y + 100, 50, 50);
		g->DrawImage(bmpExplosionCentro, PuntaInferior, porcionUsarPuntaInferior, GraphicsUnit::Pixel);
		if (matriz[(y + 100) / 50][x / 50] == 3 && matriz[(y + 50) / 50][x / 50] != 1)
		{
			matriz[(y + 100) / 50][x / 50] = 2;
		}
	}
}

void CBomba::AnimarExplosion()
{
	if (indiceEx >= 0 && indiceEx < 3)
	{
		indiceEx++;
	}
	else
	{
		estado = Estado::desaparecer;
	}
}

Estado CBomba::getEstado()
{
	return estado;
}
int CBomba::getx()
{
	return x;
}
int CBomba::gety()
{
	return y;
}
void CBomba::setx(int v)
{
	x = v;
}
inline void CBomba::sety(int v)
{
	y = v;
}

#endif // __BOMBA_H__

