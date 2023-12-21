#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {//Kat�l�mc�lar�n ad�,soyad�,yapt��� teklif ve �demesini i�eren yap�.
    char ad[100];
    double teklif;
    double odeme;
} TeklifSahibi;

int main() {
    double baslangicFiyati = 100;
    TeklifSahibi* enYuksekTeklifSahibi;// Kat�l�mc� bilgilerini tutan dinamik dizi.
    double teklif;
    int katilimciSayisi;
    int i;
    int kazananIndex = 0;

    printf("~~ Acik artirma basliyor ~~\n");
    printf("Baslangic fiyati: %lf $\n", baslangicFiyati);

    printf("Katilimci sayisini giriniz: ");
    scanf("%d", &katilimciSayisi);

    if (katilimciSayisi <= 0) {
        printf("Gecersiz katilimci sayisi girildi.\n");
        return 1;
    }
	// Kat�l�mc� say�s�na g�re bellekten yer ay�ran k�s�m.
    enYuksekTeklifSahibi = (TeklifSahibi*)malloc(katilimciSayisi * sizeof(TeklifSahibi));
	// Her bir kat�l�mc�n�n bilgileri kullan�c�dan alan k�s�m.
    for (i = 0; i < katilimciSayisi; ++i) {
        printf("%d. katilimcinin ismini giriniz: ", i + 1);
        scanf("%s", enYuksekTeklifSahibi[i].ad);
        enYuksekTeklifSahibi[i].teklif = baslangicFiyati;
        enYuksekTeklifSahibi[i].odeme = 0;
    }
	double enYuksekTeklif = baslangicFiyati;  // En y�ksek teklifin ba�lang�� de�eri.
	// A��k art�rma d�ng�s�
    while (1) {
        printf("Teklif yapmak isteyen katilimci numarasini giriniz (Cikmak icin 0'a basiniz): ");
        scanf("%d", &i);

        if (i == 0) {// E�er kullan�c� 0'a basarsa, a��k art�rma sona eriyor.
            printf("Acik artirma sona erdi.\n");
			while (getchar() != '\n');

			// En y�ksek teklifi yapan kat�l�mc�y� bulma i�lemi.
            for (i = 1; i < katilimciSayisi; ++i) {
                if (enYuksekTeklifSahibi[i].teklif > enYuksekTeklifSahibi[kazananIndex].teklif) {
                    kazananIndex = i;
                }
            }
			//Program�n sonundaki kazanan kat�l�mc� bilgilerini ve �denecek tutar� ekrana yazd�ran k�s�m.
            printf("En yuksek teklif: %lf$ (%s)\n", enYuksekTeklifSahibi[kazananIndex].teklif, enYuksekTeklifSahibi[kazananIndex].ad);

            double kazananOdeme = enYuksekTeklifSahibi[kazananIndex].teklif;
            printf("%s, Odemeniz gereken toplam tutar: %lf$\n", enYuksekTeklifSahibi[kazananIndex].ad, kazananOdeme + baslangicFiyati);

            free(enYuksekTeklifSahibi);// Bellekten ayr�lan alan temizleyen ve sonland�ran k�s�m.

            return 0;
        }
		// Kullan�c�n�n girdi�i kat�l�mc� numaras�n�n ge�erli olup olmad���n� kontrol eden k�s�m.	
        if (i >= 1 && i <= katilimciSayisi) {
            printf("%d. %s, Teklifinizi giriniz (cikmak icin 0'a basiniz):$", i, enYuksekTeklifSahibi[i - 1].ad);
            scanf("%lf", &teklif);
			//E�er kullan�c� 0'a basarsa program� sona erdiren k�s�m.
            if (teklif == 0) {
                printf("Acik artirma sona erdi.\n");
                continue;
            }
			// Yeni teklif en y�ksek tekliften b�y�kse en y�ksek teklif g�ncelleniyor.
            if (teklif > enYuksekTeklif) {
                enYuksekTeklif = teklif;
                printf("Yeni en yuksek teklif!:%lf$ (%s)\n", enYuksekTeklif, enYuksekTeklifSahibi[i - 1].ad);
            } else {
                printf("Daha yuksek bir teklif vermelisiniz.\n");
            }
			// Kat�l�mc�n�n teklifi g�ncelleyen k�s�m.
            enYuksekTeklifSahibi[i - 1].teklif = teklif;
            
        } else { // Ge�ersiz bir kat�l�mc� numaras� girildiyse kullan�c�y� uyaran k�s�m.
            printf("Gecersiz katilimci numarasi. Lutfen tekrar deneyin.\n");
        }
        
    }

    return 0;
}
