#ifndef URUNLISTELE_H
#define URUNLISTELE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "degiskenler.h"

//Uye islemleri
#include "uyeekle.h"
#include "uyesil.h"
#include "uyeguncelle.h"
#include "uyelistele.h"
#include "tarihgir.h"
//Urun islerimleri
#include "urunekle.h"
#include "urunsil.h"
#include "urunguncelle.h"

void urunlistele()
{
    printf("----------------\n");
    printf("-Urun Ve Bilgileri Listele-\n");
	printf("----------------\n\n");
    fpr = fopen("urunler.txt", "r");
   	while(fscanf(fpr,"%d %s %d",&urunno,&urunadi,&stok)!=EOF)
        printf("%d | %s | %d \n",urunno,urunadi,stok);
    fclose(fpr);
}

#endif