#ifndef __ARRENEMIGOS_H__
#define __ARRENEMIGOS_H__
#include <vector>
#include "Enemigo.h"

using namespace std;

class CArrEnemigos
{
public:
	CArrEnemigos();
	~CArrEnemigos();
	void CrearEnemigos();
	void DibujarEnemigos(Graphics^ g, Bitmap^ bmpEnemigo, int** matriz);
	vector<CEnemigo*> getvector_enemigos();

private:
	vector<CEnemigo*>vector_enemigos;
};

CArrEnemigos::CArrEnemigos()
{
	vector_enemigos = vector<CEnemigo*>();
}

CArrEnemigos::~CArrEnemigos()
{
}

void CArrEnemigos::CrearEnemigos()
{
	CEnemigo* nuevo = new CEnemigo();
	vector_enemigos.push_back(nuevo);
}

void CArrEnemigos::DibujarEnemigos(Graphics^ g, Bitmap^ bmpEnemigo, int** matriz)
{
	for (int i = 0; i < vector_enemigos.size(); i++)
	{
		vector_enemigos.at(i)->DibujarEnemigo(g, bmpEnemigo, matriz);
		vector_enemigos.at(i)->Animar();
	}
}

vector<CEnemigo*> CArrEnemigos::getvector_enemigos()
{
	return vector_enemigos;
}

#endif // !__ARRENEMIGOS_H__

