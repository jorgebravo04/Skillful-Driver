#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "mi_allegro.h"
#include "atributos.h"

#define COCHE_USUARIO "imagenes/orange_car_up.png"
#define FONDO1 "imagenes/carretera1.png"
#define FONDO2 "imagenes/carretera2.png"
#define VELOCIDAD_MOVIMIENTO 0.58

enum { KEY_LEFT, KEY_RIGHT }; // USAMOS LAS TECLAS IZQUIERDA Y DERECHA PARA MOVERNOS

int main (int argc, char **argv){
  Prota mi_coche;
  ALLEGRO_BITMAP *portada = NULL;
  ALLEGRO_BITMAP *car = NULL;
  ALLEGRO_BITMAP *fondo = NULL;
  ALLEGRO_BITMAP *titulo = NULL;
  bool tecla[2] = { false, false };

  /* INICIAR ALLEGRO */
  iniciar_allegro ();
  /* CARGAR IMÁGENES */
  car = al_load_bitmap(COCHE_USUARIO);
  fondo = al_load_bitmap(FONDO1);

  if (!car){
      al_show_native_message_box (display, "Error", "Error", "Error al crear el bitmap.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_timer (timer);
      al_destroy_display (display);
      exit (EXIT_FAILURE);
    }

  mi_coche.set_dibujo (car);

  while (1)
    {				
      ALLEGRO_EVENT ev;
      ALLEGRO_TIMEOUT timeout;
      al_init_timeout (&timeout, 0.06);

      bool get_event = al_wait_for_event_until (event_queue, &ev, &timeout);

      if (get_event)
	{
	  if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	    break;
	  if (ev.type == ALLEGRO_EVENT_TIMER)
	    redraw = true;
	  if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
	      switch (ev.keyboard.keycode){
		case ALLEGRO_KEY_LEFT:
		  tecla[KEY_LEFT] = true;
		  break;
		case ALLEGRO_KEY_RIGHT:
		  tecla[KEY_RIGHT] = true;
		  break;
		}
	    }
	  if (ev.type == ALLEGRO_EVENT_KEY_UP){
	      switch (ev.keyboard.keycode){
		case ALLEGRO_KEY_LEFT:
		  tecla[KEY_LEFT] = false;
		  break;
		case ALLEGRO_KEY_RIGHT:
		  tecla[KEY_RIGHT] = false;
		  break;
		}
	    }
	}
	
      /* ACTUALIZA LA POSICIÓN DEL COCHE DESPUÉS DE PULSAR UNA TECLA */
      if (tecla[KEY_LEFT])
	  mi_coche.cambia_vx(-VELOCIDAD_MOVIMIENTO);
      if (tecla[KEY_RIGHT])
	  mi_coche.cambia_vx(VELOCIDAD_MOVIMIENTO);

      mi_coche.actualizate();

      if (redraw && al_is_event_queue_empty (event_queue))
	{
	  al_clear_to_color (al_map_rgb (0, 0, 0));
	  al_draw_bitmap_region(fondo, 0, 0, 400, 595, 0, 0, 0);
	  al_draw_bitmap_region (car, 0, 0, 119, 119, mi_coche.get_x (), 450, 0);  //EL COCHE SE MUEVE EN EL EJE HORIZONTAL
          al_flip_display ();
	  redraw = false;
	}

    }

  al_destroy_bitmap (portada);
  al_destroy_bitmap (car);
  al_destroy_bitmap (fondo);
  destruir_allegro ();

  return 0;
}
