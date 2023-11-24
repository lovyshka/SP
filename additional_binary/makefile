all : dec enc

dec :
	gcc -lm binary_dec.c ../func.c -o dec

enc :
	gcc -lm binary_enc.c ../func.c -o enc

rebuild : clean all

clean:
	rm enc dec zero_and_one.txt