# Makefile

# Linka códigos-objeto (cria executável bibtela)
default: bibtela.c libbibtela.a
	gcc tstbibtela.c -o tstbibtela -L. -l bibtela -l ncursesw
#	gcc $< -o $@ -L. -l bibtela -l ncursesw

# Compila bibtela.c (cria código-objeto bibtela.o)
libbibtela.a: bibtela.o
	ar rc libbibtela.a bibtela.o

# Compila bibtela.c (cria código-objeto bibtela.o)
bibtela.o: bibtela.c bibtela.h
	gcc -c bibtela.c -o bibtela.o 

# Remove executável e códigos-objeto
clean:
	rm -f tstbibtela *.o *.a