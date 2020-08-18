#ifndef __MEJORA_H__
#define	__MEJORA_H__
#include <ctime>
#include <stdlib.h>

using namespace System::Drawing;
class CMejora
{
public:
	CMejora();
	~CMejora();
	Rectangle getRectangulo();
	void DibujarMejora(Graphics^ g, Bitmap^ bmpMejoras, int** matriz);
	void Animar();
	int getTipodemejora();

private:
	int i;
	int j;
	int indiceX;
	int indiceY;
	int ancho;
	int alto;
	int tipo_mejora;
	bool ubicado;
};

CMejora::CMejora()
{
	srand(time(NULL));
	tipo_mejora = rand() % 5 + 1;
	ubicado = false;
	i = rand() % 13 + 1;
	j = rand() % 15 + 1;
	ancho = 128 / 8;
	alto = 96 / 6;
	indiceX = 0;
	indiceY = 0;

}

CMejora::~CMejora()
{

}

Rectangle CMejora::getRectangulo()
{
	return Rectangle(j * 50, i * 50, ancho * 3.125, alto * 3.125);
}

void CMejora::DibujarMejora(Graphics^ g, Bitmap^ bmpMejoras, int** matriz)
{
	Rectangle espacioUsado = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

	while (ubicado == false)
	{
		if (matriz[i][j] == 3)
		{
			ubicado = true;
		}
		else
		{
			if (j < 17)
			{
				i++;
				if (i == 14)
				{
					i = 0;
					j++;
				}
			}
		}
	}
	Rectangle aumento = Rectangle(j * 50, i * 50, ancho * 3.125, alto * 3.125);
	g->DrawImage(bmpMejoras, aumento, espacioUsado, GraphicsUnit::Pixel);

}

void CMejora::Animar()
{
	switch (tipo_mejora)
	{
	case 1:
		indiceX = 0;
		if (indiceY >= 0 && indiceY < 1)
		{
			indiceY++;
		}
		else
		{
			indiceY = 0;
		}

		break;
	
	case 2:
		indiceX = 4;
		if (indiceY >= 0 && indiceY < 1)
		{
			indiceY++;
		}
		else
		{
			indiceY = 0;
		}
		
		break;
	
	case 3:
		indiceX = 5;
		if (indiceY >= 0 && indiceY < 1)
		{
			indiceY++;
		}
		else
		{
			indiceY = 0;
		}
		break;
	
	case 4:
		indiceX = 8;
		if (indiceY >= 0 && indiceY < 1)
		{
			indiceY++;
		}
		else
		{
			indiceY = 0;
		}
		break;
	
	case 5:
		indiceX = 9;
		if (indiceY >= 0 && indiceY < 1)
		{
			indiceY++;
		}
		else
		{
			indiceY = 0;
		}
		break;
	
	default:
		break;
	}
}

int CMejora::getTipodemejora()
{
	return tipo_mejora;
}

#endif // !__MEJORA_H__

