CFLAGS=-Wall
FUENTES=parser.cpp main.cpp tokens.cpp Codigo.cpp PilaTablaSimbolos.cpp TablaSimbolos.cpp

all: parser prueba

clean:
	rm parser.cpp parser.hpp parser tokens.cpp

parser.cpp parser.hpp: parser.y 
	bison -d -o $@ $<

tokens.cpp: tokens.l parser.hpp 
	lex -o $@ $<

parser: $(FUENTES) Codigo.hpp Structs.hpp
	g++ $(CFLAGS) -o $@ $(FUENTES) 

prueba:
	./parser <Pruebas/PruebaBuena1.in
	./parser <Pruebas/PruebaBuena2.in
	./parser <Pruebas/PruebaBuena3.in
	./parser <Pruebas/PruebaBuena4.in
	./parser <Pruebas/PruebaBuena5.in
	./parser <Pruebas/PruebaMala1.in
	./parser <Pruebas/PruebaMala2.in
