all : dec enc

dec :
	gcc -lm binary_dec.c ../func.c -o dec

enc :
	gcc binary_enc.c ../func.c -o enc

rebuild : clean all

clean:
	rm enc.exe dec.exe zero_and_one.txt