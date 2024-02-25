#ifndef UYELISTELE_H
#define UYELISTELE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "degiskenler.h"

// Uye işlemleri
#include "uyeekle.h"
#include "uyesil.h"
#include "uyeguncelle.h"
#include "tarihgir.h"

// Urun işlemleri
#include "urunekle.h"
#include "urunsil.h"
#include "urunguncelle.h"
#include "urunlistele.h"

// Üyeleri listeleme işlemini gerçekleştiren fonksiyon
void uyelistele() 
{
    FILE *fpr = fopen("kayit.txt", "r");

    if (fpr == NULL) 
    {
        printf("Dosya acilirken hata olustu.\n");
        return;
    }

    // Dosyadan üye bilgilerini oku ve ekrana yazdır
    while (fscanf(fpr, "%d %s %s %d %d %d %d", &uyeno, uyeadi, uyesoyadi, &gun, &ay, &yil, &aidat) != EOF) 
        printf("%d | %s | %s | %d/%d/%d | %d\n", uyeno, uyeadi, uyesoyadi, gun, ay, yil, aidat);
    fclose(fpr);
}

#endif
