#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "image.h"

/* Funkcija koja inicijalizuje strukturu i vraca pokazivac na nju. */
Image *image_init(int width, int height){
	
	Image* image;

	/*u slucaju greske prekida se program*/
  	assert(width >= 0 && height >= 0);

  	/*alocira se prostor za smestanje clanova strukture*/
  	image = (Image*)malloc(sizeof(Image));
  	assert(image != NULL);

  	/*inicijalizuju se clanovi strukture*/
  	image->width = width;
  	image->height = height;

  	if(width == 0 || height == 0)
  		image->pixels = NULL;
  	else{
  		image->pixels = (char*)malloc(3 * width * height * sizeof(char));
  		assert(image->pixels != NULL);
  	}

  	return image;
}

/*
 * Funkcija koja oslobadja prostor u kojem su se cuvali
 * podaci o slici.
 */
void image_done(Image *image){

	free(image->pixels);
	free(image);
}

/*
 * Funkcija za ucitavanje podataka o slici koja se nalazi
 * u fajlu cije je ime filename u strukturu na koju pokazuje
 * image.
 */
void image_read(Image *image, char *filename){

	FILE* file;
	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;

	unsigned int i;
	unsigned char r, g, b, a;

	/*brise se prethodni sadrzaj strukture Image*/
	free(image->pixels);
	image->pixels = NULL;

	/*otvara se fajl koji sadrzi sliku u binarnom zapisu*/
	assert((file = fopen(filename, "rb")) != NULL);

	/*ocitavaju se podaci prvog zaglavlja*/
	fread(&bfh.type, 2, 1, file);
 	fread(&bfh.size, 4, 1, file);
  	fread(&bfh.reserved1, 2, 1, file);
  	fread(&bfh.reserved2, 2, 1, file);
  	fread(&bfh.offsetbits, 4, 1, file);

  	/*ocitavju se podaci drugog zaglavlja*/
  	fread(&bih.size, 4, 1, file);
  	fread(&bih.width, 4, 1, file);
  	fread(&bih.height, 4, 1, file);
  	fread(&bih.planes, 2, 1, file);
  	fread(&bih.bitcount, 2, 1, file);
  	fread(&bih.compression, 4, 1, file);
  	fread(&bih.sizeimage, 4, 1, file);
  	fread(&bih.xpelspermeter, 4, 1, file);
  	fread(&bih.ypelspermeter, 4, 1, file);
  	fread(&bih.colorsused, 4, 1, file);
  	fread(&bih.colorsimportant, 4, 1, file);

  	/*
  	od podataka iz drugog zaglavlja koristimo samo informacije
  	o dimenzijama slike
  	*/
  	image->width = bih.width;
  	image->height - bih.height;

  	/*
  	U zavisnosti od toga koliko bitova informacija se cita po pikselu
  	(R,G,B ili R,G,B,A) alociramo niz odgovarajuce duzine
  	*/
  	if(bih.bitcount == 24)
  		image->pixels = (char*)malloc(3 * bih.width * bih.height * sizeof(char));
  	else if(bih.bitcount == 32)
  		image->pixels = (char*)malloc(4 * bih.width * bih.height * sizeof(char));
  	else{
  		fprintf(stderr, "image_read(): Podrzane su samo slike koje po pikselu cuvaju 24 ili 32 bita podataka.\n");
  		exit(1);
  	}
  	assert(image->pixels != NULL);

  	/*ucitavaju se podaci o pikselima i smestaju u alocirani niz*/
  	if(bih.bitcount == 24){

  		for(i = 0; i < bih.width * bih.height; i++){
  			/*komponente boja se citaju u suprotnom smeru, po specifikaciji*/
  			fread(&b, sizeof(char), 1, file);
      		fread(&g, sizeof(char), 1, file);
      		fread(&r, sizeof(char), 1, file);

      		image->pixels[3*i] = r;
      		image->pixels[3*i + 1] = g;
      		image->pixels[3*i + 2] = b;
  		}
  	}
  	else if(bih.bitcount == 32){

  		for(i = 0; i < bih.width * bih.height; i++){

  			fread(&b, sizeof(char), 1, file);
      		fread(&g, sizeof(char), 1, file);
      		fread(&r, sizeof(char), 1, file);
      		fread(&a, sizeof(char), 1, file);

      		image->pixels[4*i] = r;
      		image->pixels[4*i + 1] = g;
      		image->pixels[4*i + 2] = b;
      		image->pixels[4*i + 3] = a;
  		}
  	}

  	fclose(file);
}