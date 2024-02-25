#ifndef URUNSIL_H
#define URUNSIL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "degiskenler.h"

// Uye islemleri
#include "uyeekle.h"
#include "uyeguncelle.h"
#include "uyelistele.h"
#include "tarihgir.h"

// Urun islemleri
#include "urunekle.h"
#include "urunsil.h"
#include "urunguncelle.h"
#include "urunlistele.h"

void urunsil() 
{
    printf("-Urun Kaydi Silme-\n");
    printf("----------------\n\n");

    FILE *fpw = fopen("tmp.txt", "w");
    FILE *fpr = fopen("urunler.txt", "r");

    if (fpr == NULL || fpw == NULL) 
    {
        printf("Dosya acilirken hata olustu.\n");
        exit(1);
    }

    printf("Silmek istediginiz Urun No giriniz ");
    scanf("%d", &secilen);

    bool bulundu = false;

    while (fscanf(fpr, "%d %s %d", &urunno, urunadi, &stok) != EOF) 
    {
        if (urunno != secilen) 
        {
            fprintf(fpw, "%d %s %d\n", urunno, urunadi, stok);
        } 
        else 
        {
            bulundu = true; // Urun numarası bulundu
        }
    }

    fclose(fpr);
    fclose(fpw);

    if (bulundu) 
    {
        printf("%d = NO lu urun Kaydi silinmistir\n", secilen);
        remove("urunler.txt");
        rename("tmp.txt", "urunler.txt");
    } 
    else 
    {
        printf("%d = NO lu urun Kaydi bulunamamistir\n", secilen);
        remove("tmp.txt");
    }
}

#endif
