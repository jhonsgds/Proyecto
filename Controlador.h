#ifndef __CONTROLADOR_H__
#define __CONTROLADOR_H__
#include "Escenario.h"
#include "Jugador.h"
#include "ArrBombas.h"
#include "ArrMejoras.h"
#include "ArrEnemigos.h"

class CControlador
{
public:
	CControlador();
	~CControlador();
	void NuevoNivel();
	void AgregarBombas();
	void Disminuir_vidas_por_enemigo();
	void Disminuir_vidas_por_bomba();
	void ObtenerMejoras();
	void Dibujar(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpDestruible, Bitmap^ bmpJugador, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, Bitmap^ bmpMejoras, Bitmap^ bmpEnemigo);
	void CrearEnemigoyMejora();
	CJugador* getobjJugador();
	CArrMejoras* getobjArrMejoras();
	CArrEnemigos* getobjArrEnemigos();
	int getNivel();
 
private:
	CEscenario* objEscenario;
	CJugador* objJugador;
	CArrBombas* objArrBombas;
	CArrMejoras* objArrMejoras;
	CArrEnemigos* objArrEnemigos;
	int nivel;
	bool habilidad;
};

CControlador::CControlador()
{
	objEscenario = new CEscenario();
	objJugador = new CJugador(50, 50);
	objArrBombas = new CArrBombas();
	objArrMejoras = new CArrMejoras();
	objArrEnemigos = new CArrEnemigos();
	nivel = 1;
	habilidad = false;
}

CControlador::~CControlador()
{

}

void CControlador::NuevoNivel()
{
	objEscenario->generarMatriz();
}

void CControlador::AgregarBombas()
{
	objArrBombas->CrearOtraBomba(objJugador->getx(), objJugador->gety());
}
void CControlador::Disminuir_vidas_por_enemigo()
{
	for (int i = 0; i < objArrEnemigos->getvector_enemigos().size(); i++)
	{
		if (objJugador->getRectangulo().IntersectsWith(objArrEnemigos->getvector_enemigos().at(i)->getRectangulo()))
		{
			objJugador->DisminuirVidas();
		}
	}
}

void CControlador::Disminuir_vidas_por_bomba()
{
	int Puntaizquierda;
	int Puntaderecha;
	int CentroinicioY;
	int CentrofinalY;
	int Puntasuperior;
	int Puntainferior; 
	int CentroinicioX;
	int CentrofinalX;
	for (int i = 0; i < objArrBombas->getarregloBombas().size(); i++)
	{ 
		Puntaizquierda = objArrBombas->getarregloBombas().at(i)->getx() - 100;
		Puntaderecha = objArrBombas->getarregloBombas().at(i)->getx() + 150;
		Puntasuperior = objArrBombas->getarregloBombas().at(i)->gety() - 100;
		Puntainferior = objArrBombas->getarregloBombas().at(i)->gety() + 150;
		CentroinicioY = objArrBombas->getarregloBombas().at(i)->gety();
		CentroinicioX = objArrBombas->getarregloBombas().at(i)->getx();
		CentrofinalX = objArrBombas->getarregloBombas().at(i)->getx() + 50;
		CentrofinalY = objArrBombas->getarregloBombas().at(i)->gety() + 50;

		if (objArrBombas->getarregloBombas().at(i)->getEstado() == Estado::explosion)
		{
			objJugador->DisminuirVidas(Puntaizquierda, Puntaderecha, CentroinicioY, CentrofinalY, Puntasuperior, Puntainferior, CentroinicioX, CentrofinalX);

		}
	}
}

void CControlador::ObtenerMejoras()
{
	for (int i = 0; i < objArrMejoras->getvector_mejoras().size(); i++)
	{
		if (objJugador->getRectangulo().IntersectsWith(objArrMejoras->getvector_mejoras().at(i)->getRectangulo()))
		{
			switch (objArrMejoras->getvector_mejoras().at(i)->getTipodemejora())
			{
			case 1://Aumentar numero de bombas
				objArrBombas->setBombas(objArrBombas->getBombas() + 1);
				break;
			case 2://Mover bomba
				habilidad = true;
				break;
			case 3://Disminuir una vida
				objJugador->setvidas(objJugador->getvidas() - 1);
				break;
			case 4://
				objJugador->setAcelerar(objJugador->getAcelerar() + 3);
				break;
			case 5://Aumentar una vida
				objJugador->setvidas(objJugador->getvidas() + 1);
				break;
			default:
				break;
			}
			objArrMejoras->eliminarenpos(i);
		}
	}
}

void CControlador::Dibujar(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpDestruible, Bitmap^ bmpJugador, Bitmap^ bmpBomba,
	Bitmap^ bmpExplosion, Bitmap^ bmpMejoras, Bitmap^ bmpEnemigo)
{
	objEscenario->LlenarBase(g, bmpBase);
	objArrMejoras->DibujarMejoras(g, bmpMejoras, objEscenario->getmatriz());
	objEscenario->LlenarMatriz(g, bmpSolido, bmpDestruible);
	objJugador->MoverJugador(g, bmpJugador,objEscenario->getmatriz());
	objArrBombas->DibujarOtraBomba(g, bmpBomba, bmpExplosion, objJugador->getx(), objJugador->gety(), objEscenario->getmatriz());
	objArrEnemigos->DibujarEnemigos(g, bmpEnemigo, objEscenario->getmatriz());
	Disminuir_vidas_por_bomba();
	Disminuir_vidas_por_enemigo();
	ObtenerMejoras();
}

void CControlador::CrearEnemigoyMejora()
{
	objArrEnemigos->CrearEnemigos();
	objArrMejoras->CrearMejoras();
}

CJugador* CControlador::getobjJugador()
{
	return objJugador;
}

CArrMejoras* CControlador::getobjArrMejoras()
{
	return objArrMejoras;
}

CArrEnemigos* CControlador::getobjArrEnemigos()
{
	return objArrEnemigos;
}

int CControlador::getNivel()
{
	return nivel;
}


#endif // !__CONTROLADOR_H__

