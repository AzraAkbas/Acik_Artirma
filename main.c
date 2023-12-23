#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {//Katılımcıların adı,soyadı,yaptığı teklif ve ödemesini içeren yapı.
    char ad[100];
    double teklif;
    double odeme;
} TeklifSahibi;

int main() {
    double baslangicFiyati = 100;
    TeklifSahibi* enYuksekTeklifSahibi;// Katılımcı bilgilerini tutan dinamik dizi.
    double teklif;
    int katilimciSayisi;
    int i;
    int kazananIndex = -1; // Başlangıçta kazanan belirlenmemiş.

    printf("~~ Acik artirma basliyor ~~\n");
    printf("Baslangic fiyati: %lf $\n", baslangicFiyati);

    printf("Katilimci sayisini giriniz: ");
    scanf("%d", &katilimciSayisi);

    if (katilimciSayisi <= 0) {
        printf("Gecersiz katilimci sayisi girildi.\n");
        return 1;
    }

    // Katılımcı sayısına göre bellekten yer ayıran kısım.
    enYuksekTeklifSahibi = (TeklifSahibi*)malloc(katilimciSayisi * sizeof(TeklifSahibi));

    // Her bir katılımcının bilgileri kullanıcıdan alan kısım.
    for (i = 0; i < katilimciSayisi; ++i) {
        printf("%d. katilimcinin ismini giriniz: ", i + 1);
        scanf("%s", enYuksekTeklifSahibi[i].ad);
        enYuksekTeklifSahibi[i].teklif = baslangicFiyati;
        enYuksekTeklifSahibi[i].odeme = 0;
    }

    double enYuksekTeklif = baslangicFiyati;  // En yüksek teklifin başlangıç değeri.

    // Açık artırma döngüsü
    while (1) {
        printf("Teklif yapmak isteyen katilimci numarasini giriniz (Cikmak icin 0'a basiniz): ");
        scanf("%d", &i);

        if (i == 0) {
            printf("Acik artirma sona erdi.\n");
            while (getchar() != '\n');/*Kullanıcının scanf fonksiyonu ile giriş yaptığı değerin 
			ardından oluşan newline karakterini (Enter tuşuna basılması sonucu oluşan karakter) 
			temizlemek için kullanılır. */

            // En yüksek teklifi yapan katılımcıyı bulma işlemi.
            for (i = 0; i < katilimciSayisi; ++i) {
                if (kazananIndex == -1 || enYuksekTeklifSahibi[i].teklif > enYuksekTeklifSahibi[kazananIndex].teklif) {
                    kazananIndex = i;
                }
            }

            // Programın sonundaki kazanan katılımcı bilgilerini ve ödenecek tutarı ekrana yazdıran kısım.
            printf("En yuksek teklif: %lf$ (%s)\n", enYuksekTeklifSahibi[kazananIndex].teklif, enYuksekTeklifSahibi[kazananIndex].ad);

            double kazananOdeme = enYuksekTeklifSahibi[kazananIndex].teklif;
            printf("%s, Odemeniz gereken toplam tutar: %lf$\n", enYuksekTeklifSahibi[kazananIndex].ad, kazananOdeme + baslangicFiyati);

            free(enYuksekTeklifSahibi);  // Bellekten ayrılan alanı temizleyen ve sonlandıran kısım.
            return 0;
        }

        // Kullanıcının girdiği katılımcı numarasının geçerli olup olmadığını kontrol eden kısım.	
        if (i >= 1 && i <= katilimciSayisi) {
            printf("%d. %s, Teklifinizi giriniz (cikmak icin 0'a basiniz): $", i, enYuksekTeklifSahibi[i - 1].ad);
            scanf("%lf", &teklif);

            // Eğer kullanıcı 0'a basarsa programı sona erdiren kısım.
            if (teklif == 0) {
                printf("Acik artirma sona erdi.\n");
                continue;
            }

            // Yeni teklif en yüksek tekliften büyükse en yüksek teklifi güncelleyen kısım.
            if (teklif > enYuksekTeklif) {
                enYuksekTeklifSahibi[i - 1].teklif = teklif;
                enYuksekTeklif = teklif;
                printf("Yeni en yuksek teklif: %lf$ (%s)\n", enYuksekTeklif, enYuksekTeklifSahibi[i - 1].ad);
            } else {
                printf("Daha yuksek bir teklif vermelisiniz.\n");
            }
        } else {
            // Geçersiz bir katılımcı numarası girildiyse kullanıcıyı uyaran kısım.
            printf("Gecersiz katilimci numarasi. Lutfen tekrar deneyin.\n");
            int ch;
            while (getchar() != '\n');/*Kullanıcının scanf fonksiyonu ile giriş yaptığı değerin 
			ardından oluşan newline karakterini (Enter tuşuna basılması sonucu oluşan karakter) 
			temizlemek için kullanılır. */
        }
    }

    return 0;
}
