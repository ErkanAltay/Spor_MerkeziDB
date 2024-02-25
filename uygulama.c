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
#include "uyeara.h"
//Urun islerimleri
#include "satis.h"
#include "urunekle.h"
#include "urunsil.h"
#include "urunguncelle.h"
#include "urunlistele.h"
#include "urunbul.h"
void cik()
{   
    exit(0);
}
int main()
{
    while (1) 
    {
        printf("ID giriniz: ");
        scanf("%s", girilenID);
        // Girilen ID, dogrru ID ile eslesiyorsa sifreyi iste
        if (strcmp(girilenID, dogruID) == 0) 
        {
            printf("Sifre giriniz: ");
            scanf("%s", girilenSifre);
            // Girilen sifre, dogru sifre ile eslesiyorsa dogru giris yapilmistir
            if (strcmp(girilenSifre, dogruSifre) == 0) 
            {
                printf("Dogru ID ve sifre! Giris basarili.\n");
                while (1) 
                {
                    while(getchar() != '\n');  
                    printf("\n%c", 6);
                    printf("Sistemimize Hos Geldiniz");
                    printf("%c\n", 6);
                    printf("-Unsal Atas SPOR MERKEZI Veri Tabani Sistemi-\n");
                    printf("------------------------------------\n");
                    printf("Lutfen islem seciniz\n");
                    printf("------------------------------------\n");
                    printf("(1) - Uye Kayit -\n");
                    printf("(2) - Urun Takip -\n");
                    printf("(9) - Uygulamadan Cikis -\n");
                    printf("------------------------------------\n");
                    printf("Seciminiz = ");
                    scanf("%d", &secim1);
                    system("CLS");
                    switch (secim1) 
                    {
                        case 1:
                            printf("=Unsal Atas SPOR MERKEZI Veri Tabani Sistemi Uye Kayit Sistemi=\n");
                            printf("------------------------------------\n");
                            printf("Lutfen islem seciniz\n");
                            printf("------------------------------------\n");
                            printf("(1) - Uye Ekle -\n");
                            printf("(2) - Kayit Silme -\n");
                            printf("(3) - Kayit Guncelle -\n");
                            printf("(4) - Kayitlari Listele -\n");
                            printf("(5) - Uye arama modu -\n");
                            printf("(9) - Uygulamadan Cikis -\n");
                            printf("------------------------------------\n");
                            printf("Seciminiz = ");
                            scanf("%d", &secim1);
                                switch (secim1) 
                                {
                                    case 9:
                                        cik();
                                        break;
                                    case 1:
                                        uyeekle();
                                        break;
                                    case 2:
                                        uyesil();
                                        break;
                                    case 3:
                                        uyeguncelle();
                                        break;
                                    case 4:
                                        uyelistele();
                                        break;
                                    case 5:
                                        printf("Uye arama modu\n");
                                        char aranan_uye_adi[50];
                                        printf("Aranan uye adini girin: ");
                                        scanf("%s", aranan_uye_adi);
                                        uyebul(aranan_uye_adi);
                                        break;
                                    default:
                                        printf("Yanlis Tuslama Yaptiniz\n");
                                        break;
                                }
                        break;
                        case 2:
                            printf("=Unsal Atas SPOR MERKEZI Veri Tabani Urun Kayit Sistemi=\n");
                            printf("------------------------------------\n");
                            printf("Lutfen islem seciniz\n");
                            printf("------------------------------------\n");
                            printf("(1) - Urun Ekle -\n");
                            printf("(2) - Urun Sil -\n");
                            printf("(3) - Urun Guncelle -\n");
                            printf("(4) - Urun Bilgilerini Listeleme-\n");
                            printf("(5) - Urun Arama -\n");
                            printf("(6) - Satis Bildir -\n");
                            printf("(9) - Uygulamadan Cikis -\n");
                            printf("------------------------------------\n");
                            printf("Seciminiz = ");
                            scanf("%d", &secim2);
                            switch (secim2) 
                            {
                                case 9:
                                    cik();
                                    break;
                                case 1:
                                    urunekle();
                                    break;
                                case 2:
                                    urunsil();
                                    break;
                                case 3:
                                    urunguncelle();
                                    break;
                                case 4:
                                    urunlistele();
                                    break;
                                case 5:
                                    printf("Urun arama modu\n");
                                    char arananurun_adi[50];
                                    printf("Aranan urun adini girin: ");
                                    scanf("%s", arananurun_adi);
                                    urunbul(arananurun_adi);
                                    break;
                                case 6:
                                    satisbildiri();
                                    break;
                                default:
                                    printf("Yanlis Tuslama Yaptiniz\n");
                                    break;
                            }
                        break;
                        case 0:   
                            break;
                        case 9:
                            cik();
                            break;
                        default:
                            printf("Yanlis Tuslama Yaptiniz");
                            break;
                    }
                }
            }
        }
        else 
        printf("Yanlis sifre. Tekrar deneyin.\n");
    }
}