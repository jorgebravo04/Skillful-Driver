#include "mi_allegro.h"

#define PORTADA "imagenes/portada1.png"


ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_DISPLAY *display;
ALLEGRO_TIMER *timer;
ALLEGRO_SAMPLE *sample;
ALLEGRO_BITMAP *bitmap;
ALLEGRO_FONT *font;
ALLEGRO_BITMAP *portada;
/*ALLEGRO_BITMAP *icon;*/ //PROBANDO
bool redraw;


/* MEDIDAS DEL DISPLAY */
int ANCHO_VENTANA = 400;
int ALTO_VENTANA = 595;


/* FUNCION INICIAR ALLEGRO */
void iniciar_allegro (){
  event_queue = NULL;
  display = NULL;
  timer = NULL;
  sample = NULL;
  redraw = true;

  
  /* Allegro */
  if (!al_init ()){
      al_show_native_message_box (display, "Error", "Error", "Error al cargar Allegro.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      exit (EXIT_FAILURE);
  }
  
  /* Imágenes */
  if (!al_init_image_addon ()){
      al_show_native_message_box (display, "Error", "Error", "Error al cargar el addon de imágenes.", NULL, ALLEGRO_MESSAGEBOX_ERROR); 
      exit (EXIT_FAILURE);
  }
  
  /* Teclado */
  if (!al_install_keyboard()){
      al_show_native_message_box (display, "Error", "Error", "Error al inicializar el teclado.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      exit (EXIT_FAILURE);
  }

  /* Timer */
  timer = al_create_timer (1.0 / FPS);
  if (!timer){
      al_show_native_message_box (display, "Error", "Error", "Error al crear un temporizador.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      exit (EXIT_FAILURE);
  }

  /* Display */
  display = al_create_display (	ANCHO_VENTANA, ALTO_VENTANA);
  if (!display){
      al_destroy_timer (timer);
      al_show_native_message_box (display, "Error", "Error", "Error al crear el display.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      exit (EXIT_FAILURE);
  }
  
  /* Cola de eventos */
  event_queue = al_create_event_queue ();
  if (!event_queue){
      al_destroy_timer (timer);
      al_destroy_display (display);
      al_show_native_message_box (display, "Error", "Error", "Error al crear la cola de eventos.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      exit (EXIT_FAILURE);
  }

  /* Nombre ventana */
  al_set_window_title(display, "Skillful Driver");
  if (!al_set_window_title){
      al_show_native_message_box (display, "Error", "Error", "Error al poner título de ventana.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      exit (EXIT_FAILURE);
  }

  /* Portada */
  portada = al_load_bitmap(PORTADA);

  /* Fuentes */
  al_init_font_addon();
  al_init_ttf_addon();
 /* if (!al_init_ttf_addon()){
      al_show_native_message_box (display, "Error", "Error", "Error al cargar las fuentes.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      exit (EXIT_FAILURE);
  }*/
  font = al_load_ttf_font("UpheavalPro.ttf"/*"David Sans.ttf"*/, 30, 0);

  /* Icono del ejecutable - PROBANDO
  icon = al_load_bitmap("sprites/icono.png");
  al_set_display_icon(display, icon);
  */

  /* Música */
  if (!al_install_audio()){
      al_show_native_message_box (display, "Error", "Error", "Error de audio.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      exit (EXIT_FAILURE);
  }

  if (!al_init_acodec_addon()){
      al_show_native_message_box (display, "Error", "Error", "Error de audio.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      exit (EXIT_FAILURE);
  }

  if (!al_reserve_samples(1)){
      al_show_native_message_box (display, "Error", "Error", "Error al reservar el sample.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      exit (EXIT_FAILURE);
  }

  sample = al_load_sample ("outrun.ogg");
  if (!sample){
      al_show_native_message_box (display, "Error", "Error", "Error al cargar el sample.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      exit (EXIT_FAILURE);
  }

  al_register_event_source (event_queue, al_get_timer_event_source (timer));
  al_register_event_source (event_queue, al_get_keyboard_event_source());
  al_register_event_source (event_queue, al_get_display_event_source (display));
  
  al_clear_to_color (al_map_rgb(255, 255, 255));
  al_draw_bitmap_region(portada, 0, 0, 400, 595, 0, 0, 0);
  al_draw_text (font, al_map_rgb(224, 224, 224), ANCHO_VENTANA/2, 495, ALLEGRO_ALIGN_CENTRE, "Cargando...");

  al_flip_display ();

  al_rest(5.0);
  
  al_start_timer (timer);
  
  al_play_sample (sample, 1.0, 0.0, 1.1, ALLEGRO_PLAYMODE_LOOP, NULL);
}

  
/* FUNCION DESTRUIR ALLEGRO */
void destruir_allegro (){
  al_destroy_font(font);
  al_destroy_sample (sample);
  al_destroy_timer (timer);
  al_destroy_display (display);
  al_destroy_event_queue (event_queue);
}
