#ifndef UYEGUNCELLE_H
#define UYEGUNCELLE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "degiskenler.h"

// Uye islemleri
#include "uyeekle.h"
#include "uyesil.h"
#include "uyelistele.h"
#include "tarihgir.h"

// Urun islemleri
#include "urunekle.h"
#include "urunsil.h"
#include "urunlistele.h"

// Uyeyi güncelleyen fonksiyon
void uyeguncelle() 
{
    printf("----------------\n");
    printf("- Uye Guncelleme -\n");
    printf("----------------\n\n");

    FILE *fpr = fopen("kayit.txt", "r");
    if (fpr == NULL) {
        printf("Dosya acilirken hata olustu.\n");
        return;
    }

    printf("Lutfen guncellemek istediginiz uyenin no'sunu giriniz: ");
    scanf("%d", &secilen);

    FILE *fpw = fopen("tmp.txt", "w");
    if (fpw == NULL) 
    {
        printf(" Gecici Dosya acilirken hata olustu.\n");
        fclose(fpr);
        return;
    }

    while (fscanf(fpr, "%d %s %s %d %d %d %d\n", &tuyeno, tuyeadi, tuyesoyadi, &gun, &ay, &yil, &taidat) != EOF) 
    {
        if (tuyeno == secilen) 
        {
            printf("Uye adini giriniz: ");
            scanf("%s", tuyeadi);
            printf("Yeni Uye Soyadini giriniz: ");
            scanf("%s", tuyesoyadi);
            printf("Yeni kayit tarihini giriniz (GG AA YY): ");
            scanf("%d %d %d", &gun, &ay, &yil);
            printf("Yeni alinacak aidat miktarini giriniz: ");
            scanf("%d", &taidat);
            bulundu = 1; // Üyenin bulunduğunu işaretle
        }
        else
        {
            strcpy(uyeadi, tuyeadi);
            uyeno = tuyeno;
        }
        fprintf(fpw, "%d %s %s %d %d %d %d\n", tuyeno, tuyeadi, tuyesoyadi, gun, ay, yil, taidat);
    }

    fclose(fpr);
    fclose(fpw);

    remove("kayit.txt");
    rename("tmp.txt", "kayit.txt");

    if (bulundu) 
        printf("%d no'lu uye guncellenmistir\n", secilen);
    else 
        printf("Belirtilen uye bulunamadi.\n");
}

#endif
