#ifndef URUNBUL_H
#define URUNBUL_H

void urunbul(const char* arananurun_adi) {
    FILE *fpr = fopen("urunler.txt", "r");

    if (fpr == NULL) 
    {
        printf("Dosya acilirken hata olustu.\n");
        return;
    }
    
    int bulunan_kayit_sayisi = 0;

    // Dosyadan üye bilgilerini oku ve ekrana yazdır
    while (fscanf(fpr, "%d %s %d", &urunno, urunadi, &stok) != EOF) 
    {
        if (strcmp(arananurun_adi, urunadi) == 0) {
            printf("%d | %s | %d\n", urunno, urunadi,stok);
            bulunan_kayit_sayisi++;
        }
    }

    fclose(fpr);

    // Bulunan kayıt sayısına göre mesaj yazdır
    if (bulunan_kayit_sayisi == 0) 
        printf("Aranan urun adina ait kayit bulunamadi.\n");
}
#endif