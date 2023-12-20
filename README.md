# AÇIK ARTIRMA PROGRAMI
Bu C programı, basit bir açık artırma simülasyonunu gerçekleştiren bir örnektir. Program, katılımcıların isimlerini, verdikleri teklifleri ve kazanan katılımcının ödeme bilgilerini takip eder. Bu açık artırma senaryosu, temel bir oyun teorisi uygulamasına benzer.
# Struct
Struct bir bellek bloğunda tek bir ad altında fiziksel olarak gruplandırılmış değişkenler listesini tanımlayan ve farklı değişkenlere tek bir işaretçi (pointer) aracılığıyla erişilmesine izin veren bileşik bir veri türüdür. Bu programda TeklifSahibi adlı struct, bir katılımcının adını (ad), verdiği teklifi (teklif), ve ödeme bilgisini (odeme) içerir.
# Typedef
Typedef bir veri türüyle aynı özellikte farklı isimde bir veri türü oluşturulur veya bu şekilde oluşturulmuş bir veri türünden farklı isimde ama aynı özellikte başka bir veri türü oluşturmak için kullanılır. Bu programda TeklifSahibi struct'ını kullanıcı tarafından daha rahat tanımlamak ve kullanmak için typedef ile kısaltılmıştır.
# İşaretçiler (Pointers)
Pointer, başka bir değişkenin bellekteki adresini işaret eden bir değişkendir. Bu programda TeklifSahibi türündeki verilerin dinamik olarak saklanması için işaretçiler kullanılmıştır. malloc fonksiyonu ile bellekten yer ayrılır ve bu bellek bloğunun adresi bir işaretçi tarafından saklanır.
# Açık Artırma ve Oyun Teorisi İlişkisi
Açık artırma, oyun teorisi kapsamında incelenebilecek bir konudur. Katılımcılar, verdikleri teklifler ile diğer katılımcılarla rekabet içindedir. Her bir katılımcının amacı, en uygun fiyatı vererek ürünü almak veya diğer katılımcıları yüksek fiyatlar ödemeye zorlamaktır.
Oyun teorisi, bu tür rekabetçi durumları analiz eder ve en uygun stratejileri belirler. Açık artırmada, her katılımcının en iyi stratejisi, kendi çıkarlarına en uygun şekilde açık artırmayı kazanmaktır.
Programın sonunda, kazanan katılımcı belirlenir ve kazananın ödemesi gereken toplam miktar hesaplanır. Bu, oyun teorisi kapsamında stratejik davranışların sonuçlarını gösteren bir örnek olabilir.
