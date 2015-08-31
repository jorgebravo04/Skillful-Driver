#include <stdlib.h>
#include "coche.h"

#define VLIM 1.15 
#define ROZAMIENTO 0.1

Coche::Coche () {
  static int i = 0;		
  this->x = 0 + 5 * i++;
  this->y = 10;
  this->vx = 0;
  this->vy = 0;
  this->dibujo = NULL;
}

/* ACCEDENTES */
double Coche::get_x () {
  return this->x;
}

double Coche::get_y () {
  return this->y;
}

void Coche::cambia_vx (float VELOCIDAD_MOVIMIENTO) {
    this->vx += VELOCIDAD_MOVIMIENTO;
}

void Coche::cambia_vy (float VELOCIDAD_MOVIMIENTO) {
    this->vy += VELOCIDAD_MOVIMIENTO;
}

ALLEGRO_BITMAP *Coche::get_dibujo () {
  return this->dibujo;
}

void Coche::set_dibujo (ALLEGRO_BITMAP * sprite) {
  this->dibujo = sprite;
}

void Coche::actualizate () {
    this->vx -= ROZAMIENTO * this->vx;
    this->x += this->vx;
	/* LÍMITE POR LA IZQUIERDA */    
    	if(this->x < 48)
	    this->x = 48;
	/* LÍMITE POR LA DERECHA */
	if(this->x > 284)
	    this->x = 284;
}
