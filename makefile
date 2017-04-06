all:
	gcc main.c LoRaMacCrypto.c cmac.c aes.c utilities.c -o main
clean:
	rm -f *.o main