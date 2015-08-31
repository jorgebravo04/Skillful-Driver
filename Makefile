CXX = g++ 
CXXFLAGS = -g 
LDLIBS = -lallegro -lallegro_image -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_font -lallegro_ttf

DEPS = mi_allegro.h coche.h
OBJ = mi_allegro.o coche.o juego.o 

skillful: $(OBJ) 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS) 
	
%.o: %.cpp $(DEPS) 
	$(CXX) -c -o $@ $< $(CXXFLAGS)
	
.PHONY: clean 

clean:
	$(RM) *.o *~
