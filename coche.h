#ifndef __COCHE_H__
#define __COCHE_H__

#include <allegro5/allegro.h>

class Coche {
  private:
  double x;
  double y;
  double vx;
  double vy;

  ALLEGRO_BITMAP *dibujo;

  public:
  Coche ();
  Coche (double x, double y);
  double get_x ();
  double get_y ();
 
  /* MUTADORES */
  void actualizate ();
  void cambia_vx (float VELOCIDAD_MOVIMIENTO);
  void cambia_vy (float VELOCIDAD_MOVIMIENTO);
  ALLEGRO_BITMAP *get_dibujo ();
  void set_dibujo (ALLEGRO_BITMAP * sprite);
};
#endif
