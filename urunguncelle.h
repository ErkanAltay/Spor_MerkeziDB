#ifndef URUNGUNCELLE_H
#define URUNGUNCELLE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "degiskenler.h"

// Uye islemleri
#include "uyeekle.h"
#include "uyesil.h"
#include "uyeguncelle.h"
#include "uyelistele.h"
#include "tarihgir.h"

// Urun islemleri
#include "urunekle.h"
#include "urunsil.h"
#include "urunlistele.h"

// Urunu güncelleyen fonksiyon
void urunguncelle() 
{
    printf("----------------\n");
    printf("- Urun Guncelleme -\n");
    printf("----------------\n\n");

    FILE *fpr = fopen("urunler.txt", "r");
    if (fpr == NULL) {
        printf("Dosya acilirken hata olustu.\n");
        return;
    }

    int secilen;
    printf("Lutfen guncellemek istediginiz urunun no'sunu giriniz: ");
    scanf("%d", &secilen);

    FILE *fpw = fopen("tmp.txt", "w");
    if (fpw == NULL) {
        printf("Dosya acilirken hata olustu.\n");
        fclose(fpr);
        return;
    }


    while (fscanf(fpr, "%d %s %d", &urunno, turunadi, &tstok) != EOF) 
    {
        if (urunno == secilen) 
        {
            printf("Urun adini giriniz: ");
            scanf("%s", urunadi);
            printf("Yeni Stok giriniz: ");
            scanf("%d", &stok);
            bulundu = 1; // Ürünün bulunduğunu işaretle
        }
        else
        {
            // Eğer ürün güncellenmesi gerekmiyorsa (else bloğu),
            // mevcut ürün adı (turunadi) ve stok miktarı (tstok) değişkenlere atanır.
            strcpy(urunadi, turunadi);
            stok = tstok;
        }
        fprintf(fpw, "%d %s %d\n", urunno, urunadi, stok);
    }

    fclose(fpr);
    fclose(fpw);

    remove("urunler.txt");
    rename("tmp.txt", "urunler.txt");

    if (bulundu) 
        printf("%d no'lu urun guncellenmistir\n", secilen);
    else 
        printf("Belirtilen urun bulunamadi.\n");
}

#endif
