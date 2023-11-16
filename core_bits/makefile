all: serial, deser


serial:
	gcc serialisation.c ../func.c -o serial

deser:
	gcc deserialisation.c ../func.c -o deser

clean:
	rm a.out binary deser serial

rebuild: clean all
