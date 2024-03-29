#ifndef __MI_ALLEGRO_H__
#define __MI_ALLEGRO_H__

#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"


const float FPS = 60;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_TIMER *timer;
extern bool redraw;


#ifdef __cplusplus
extern "C"
{
#endif
  void iniciar_allegro ();
  void destruir_allegro ();
#ifdef __cplusplus
}
#endif

#endif
