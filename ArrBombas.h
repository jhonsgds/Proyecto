#ifndef __ARRBOMBAS_H__
#define __ARRBOMBAS_H__
#include "Bomba.h"
#include <vector>

using namespace std;
class CArrBombas
{
public:
	CArrBombas();
	~CArrBombas();
	void CrearOtraBomba(int x, int y);
	void DibujarOtraBomba(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, int xJugador, int yJugador, int** matriz);
	vector<CBomba*>getarregloBombas();
	void setBombas(int v);
	int getBombas();


private:
	vector<CBomba*>arregloBombas;
	int totalBombas;
};

CArrBombas::CArrBombas()
{
	totalBombas = 1;
}

CArrBombas::~CArrBombas()
{
}

void CArrBombas::CrearOtraBomba(int x, int y)
{
	if (arregloBombas.size() < totalBombas)
	{
		CBomba* nueva_bomba = new CBomba(x, y);
		arregloBombas.push_back(nueva_bomba);
	}
}

void CArrBombas::DibujarOtraBomba(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, int xJugador, int yJugador, int** matriz)
{
	for (int i = 0; i < arregloBombas.size(); i++)
	{
		switch (arregloBombas.at(i)->getEstado())
		{
		case Estado::inicial:
			arregloBombas.at(i)->DibujarBomba(g, bmpBomba, xJugador, yJugador, matriz);
			arregloBombas.at(i)->Animar();
			break;
		case Estado::explosion:
			arregloBombas.at(i)->DibujarExplosion(g, bmpExplosion, matriz);
			arregloBombas.at(i)->AnimarExplosion();
			break;
		case Estado::desaparecer:
			arregloBombas.erase(arregloBombas.begin() + i);
			break;
		}
	}
}

vector<CBomba*> CArrBombas::getarregloBombas()
{
	return arregloBombas;
}

void CArrBombas::setBombas(int v)
{
	totalBombas = v;
}

int CArrBombas::getBombas()
{
	return totalBombas;
}

#endif // !__ARRBOMBAS_H__
