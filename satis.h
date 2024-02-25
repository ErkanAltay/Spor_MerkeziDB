// satissistemi.h
#ifndef SATIS_H
#define SATIS_H

#include <stdio.h>
#include <string.h>

#include "degiskenler.h"
#include "urunlistele.h"

void satisbildiri()
{ 
    urunlistele();
    printf("----------------\n");
    printf("- Satis Bildiri -\n");
    printf("----------------\n\n");

    FILE *fpr = fopen("urunler.txt", "r");
    if (fpr == NULL) 
    {
        printf("Dosya acilirken hata olustu.\n");
        return;
    }

    FILE *fpw = fopen("tmp.txt", "w");
    if (fpw == NULL) 
    {
        printf("Dosya acilirken hata olustu.\n");
        fclose(fpr);  // Dosyayı kapat ve işlemi sonlandır
        return;
    }

    printf("Lutfen satilan urunun no'sunu giriniz: ");
    scanf("%d", &secilen);
    printf("Lutfen satilan urun adetini giriniz: ");
    scanf("%d", &satisMiktari);

    bulundu = 0; // Her seferinde başlangıçta ürünün bulunmadığını belirtmek için sıfırla

    while (fscanf(fpr, "%d %s %d", &urunno, turunadi, &tstok) == 3) 
    {
        if (urunno == secilen) 
        {
            if (satisMiktari > tstok) 
            {
                printf("Hata: Satilan miktar stok miktarindan fazla olamaz.\n");
            }
            else 
            {
                stok = tstok - satisMiktari;
                if (stok < 5) {
                    printf("Uyari: %d no'lu urunun stok miktari 5'in altina dustu.\n", secilen);
                    stok = 5;  // Stok miktarını 5'in altına düşmesini önlemek için 5'e eşitle
                }

                // Eğer ürün bulunduysa, güncellenmiş bilgileri kopyala
                fprintf(fpw, "%d %s %d\n", urunno, turunadi, stok);
                bulundu = 1;
                continue;
            }
        }
        // eğer ürün bulunamadıysa veya stok azalmamışsa, aynı kaydı kopyala
        fprintf(fpw, "%d %s %d\n", urunno, turunadi, tstok);
    }

    fclose(fpr);
    fclose(fpw);

    remove("urunler.txt");
    rename("tmp.txt", "urunler.txt");

    if (bulundu) 
        printf("%d no'lu urunun stok miktari guncellenmistir\n", secilen);
    else 
        printf("Belirtilen urun bulunamadi.\n");
    
    urunlistele();
}

#endif
