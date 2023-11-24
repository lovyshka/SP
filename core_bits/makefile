all: serial deser


serial:
	gcc serialisation.c ../func.c -o serial -lm

deser:
	gcc deserialisation.c ../func.c -o deser -lm

clean:
	rm a.out binary deser serial binary.txt

rebuild: clean all
