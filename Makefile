#Makefile
paaohjelma.exe: paaohjelma.o ali1.o ali2.o
    gcc ali1.o ali2.o paaohjelma.o -o paaohjelma.exe
paaohjelma.o: paaohjelma.c ali1.h ali2.h paaohjelma.h
    gcc paaohjelma.c -c -Wall -std=c99 -pedantic
ali1.o: ali1.c ali1.h paaohjelma.h
    gcc ali1.c -c -Wall -std=c99 -pedantic
ali2.o: ali2.c ali2.h paaohjelma.h
    gcc ali2.c -c -Wall -std=c99 -pedantic