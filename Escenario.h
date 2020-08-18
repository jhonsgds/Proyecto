#ifndef __ESCENARIO_H__
#define __ESCENARIO_H__
#include <ctime>
#include <stdlib.h>
#define filas 15
#define columnas 17


using namespace System::Drawing;
class CEscenario
{
public:
	CEscenario();
	~CEscenario();
	void generarMatriz();
	void LlenarBase(Graphics^ g, Bitmap^ bmpBase);
	void LlenarMatriz(Graphics^ g, Bitmap^ bmpSolido, Bitmap^ bmpDestruible);
	int** getmatriz();

private:
	int** matriz;
};

CEscenario::CEscenario()
{
	matriz = new int* [filas];
}

CEscenario::~CEscenario()
{

}

void CEscenario::generarMatriz()
{
	srand(time(NULL()));
	for (int i = 0; i < filas; i++)
	{
		matriz[i] = new int[columnas];
	}

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (i == 0 || j == 0 || i == (filas - 1) || j == (columnas - 1))
			{
				matriz[i][j] = 1;
			}
			else
			{
				if (i % 2 == 0 && j % 2 == 0)
				{
					matriz[i][j] = 1;
				}
				else
				{
					if ((i == 1 && (j == 1 || j == 2)) || (j == 1 && i == 2) || (i == (filas - 2) && (j == (columnas - 3) || j == (columnas - 2))) || (i == (filas - 3) && j == (columnas - 2)))
					{
						matriz[i][j] = 0;
					}
					else
					{
						matriz[i][j] = rand() % 2 + 2;
					}
				}
			}
		}
	}
}

void CEscenario::LlenarBase(Graphics^ g, Bitmap^ bmpBase)
{
	int x, y = 0;
	for (int i = 0; i < filas; i++)
	{
		x = 0;
		for (int j = 0; j < columnas; j++)
		{
			if (matriz[i][j] == 0 || matriz[i][j] == 2)
			{
				g->DrawImage(bmpBase, x, y, 50, 50);
			}
			x += 50;
		}
		y += 50;
	}
}

void CEscenario::LlenarMatriz(Graphics^ g, Bitmap^ bmpSolido, Bitmap^ bmpDestruible)
{
	int x, y = 0;
	for (int i = 0; i < filas; i++)
	{
		x = 0;
		for (int j = 0; j < columnas; j++)
		{
			if (matriz[i][j] == 1)
			{
				g->DrawImage(bmpSolido, x, y, 50, 50);
			}
			else
			{
				if (matriz[i][j] == 3)
				{
					g->DrawImage(bmpDestruible, x, y, 50, 50);
				}
			}
			x += 50;
		}
		y += 50;
	}
}

int** CEscenario::getmatriz()
{
	return matriz;
}


#endif // !__ESCENARIO_H__

