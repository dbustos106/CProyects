.DEFAULT_GOAL := Hilos
Hilos: correrHilos
	@echo "procesos finalizados"
correrHilos:
	gcc hilosMutex.c -lpthread -lm -o hilosMutex
	./hilosMutex