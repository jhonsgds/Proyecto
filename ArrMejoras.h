#ifndef __ARRMEJORAS_H__
#define __ARRMEJORAS_H__
#include <vector>
#include "Mejora.h"

using namespace std;
class CArrMejoras
{
public:
	CArrMejoras();
	~CArrMejoras();
	void CrearMejoras();
	void DibujarMejoras(Graphics^ g, Bitmap^ bmpMejoras, int** matriz);
	vector<CMejora*> getvector_mejoras();
	void eliminarenpos(int pos);

private:
	vector<CMejora*>vector_mejoras;
};

CArrMejoras::CArrMejoras()
{
}

CArrMejoras::~CArrMejoras()
{
}

void CArrMejoras::CrearMejoras()
{
	CMejora* nueva_mejora = new CMejora();
	vector_mejoras.push_back(nueva_mejora);
}

void CArrMejoras::DibujarMejoras(Graphics^ g, Bitmap^ bmpMejoras, int** matriz)
{
	for (int i = 0; i < vector_mejoras.size(); i++)
	{
		vector_mejoras.at(i)->DibujarMejora(g, bmpMejoras, matriz);
		vector_mejoras.at(i)->Animar();
	}
}

vector<CMejora*> CArrMejoras::getvector_mejoras()
{
	return vector_mejoras;
}

void CArrMejoras::eliminarenpos(int pos)
{
	vector_mejoras.erase(vector_mejoras.begin() + pos);
}


#endif // !__ARRMEJORAS_H__

