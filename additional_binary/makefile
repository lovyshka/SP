all : enc dec

dec :
	gcc -lm binary_dec.c ../func.c -o dec

enc :
	gcc -lm binary_enc.c ../func.c -o enc

rebuild : clean all

clean:
	rm enc dec *.txt