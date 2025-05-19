```c
#include <stdio.h>
#include <stdlib.h>



enum bentukdonasi{Beras_dan_bahan_baku,Makanan_Ringan,Suplemen,Olahan_hewan,Sayur_dan_buah};
enum benua{Amerika,Asia,Australia,Afrika,Eropa,Oseania};

typedef struct {
    char nama[50];
    float populasi_juta;         
    float kelaparan_juta;        
    float persentase_kelaparan;  
} NegaraAfrika;


typedef struct {
    char nama[50];
    int umur;   
    enum benua Benuaasal;
    char negaraasal[50];
    int nomorkependudukan[50];
} Donatur;

typedef struct {
    enum benua Benuaasal;
    char nama[50];
    int kodetelepon; 
}KodeTeleponBenua;

typedef struct{ 
    enum bentukdonasi barang;
    int jumlahdonasi; 
} Donasi;

int main() {
    int JumlahDonatur=0;
    int Kodepengiriman[10];
    
    NegaraAfrika data[15] = {
        {"Nigeria", 237.5, 31.8, 13.4},
        {"Rep. Dem. Kongo", 112.8, 23.4, 20.7},
        {"Ethiopia", 135.5, 15.8, 11.7},
        {"Sudan", 51.7, 25.6, 49.5},
        {"Afrika Selatan", 64.7, 7.1, 11.0},
        {"Somalia", 15.9, 4.3, 27.0},
        {"Chad", 27.6, 4.7, 17.0},
        {"Madagaskar", 30.3, 1.5, 5.0},
        {"Mozambik", 33.0, 3.3, 10.0},
        {"Zimbabwe", 15.0, 3.0, 20.0},
        {"Burkina Faso", 21.0, 2.7, 12.9},
        {"Rep. Afrika Tengah", 6.6, 2.3, 34.8},
        {"Mali", 21.7, 2.6, 12.0},
        {"Malawi", 20.0, 4.4, 22.0},
        {"Niger", 25.3, 4.3, 17.0}
    };
     
  
KodeTeleponBenua asia[45] = {
    {"Afghanistan", 93}, {"Armenia", 374}, {"Azerbaijan", 994}, {"Bahrain", 973},
    {"Bangladesh", 880}, {"Bhutan", 975}, {"Brunei", 673}, {"Cambodia", 855},
    {"China", 86}, {"Cyprus", 357}, {"Georgia", 995}, {"India", 91},
    {"Indonesia", 62}, {"Iran", 98}, {"Iraq", 964}, {"Israel", 972},
    {"Japan", 81}, {"Jordan", 962}, {"Kazakhstan", 7}, {"Kuwait", 965},
    {"Kyrgyzstan", 996}, {"Laos", 856}, {"Lebanon", 961}, {"Malaysia", 60},
    {"Maldives", 960}, {"Mongolia", 976}, {"Myanmar (Burma)", 95}, {"Nepal", 977},
    {"North Korea", 850}, {"Oman", 968}, {"Pakistan", 92}, {"Palestine", 970},
    {"Philippines", 63}, {"Qatar", 974}, {"Saudi Arabia", 966}, {"Singapore", 65},
    {"South Korea", 82}, {"Sri Lanka", 94}, {"Syria", 963}, {"Tajikistan", 992},
    {"Thailand", 66}, {"Timor-Leste", 670}, {"Turkey", 90}, {"Turkmenistan", 993},
    {"United Arab Emirates", 971}, {"Uzbekistan", 998}, {"Vietnam", 84}
};

KodeTeleponBenua eropa[45] = {
    {"Albania", 355}, {"Andorra", 376}, {"Austria", 43}, {"Belarus", 375},
    {"Belgium", 32}, {"Bosnia and Herzegovina", 387}, {"Bulgaria", 359}, {"Croatia", 385},
    {"Czech Republic", 420}, {"Denmark", 45}, {"Estonia", 372}, {"Finland", 358},
    {"France", 33}, {"Germany", 49}, {"Greece", 30}, {"Hungary", 36},
    {"Iceland", 354}, {"Ireland", 353}, {"Italy", 39}, {"Kosovo", 383},  // if applicable
    {"Latvia", 371}, {"Liechtenstein", 423}, {"Lithuania", 370}, {"Luxembourg", 352},
    {"Malta", 356}, {"Moldova", 373}, {"Monaco", 377}, {"Montenegro", 382},
    {"Netherlands", 31}, {"North Macedonia", 389}, {"Norway", 47}, {"Poland", 48},
    {"Portugal", 351}, {"Romania", 40}, {"Russia", 7}, {"San Marino", 378},
    {"Serbia", 381}, {"Slovakia", 421}, {"Slovenia", 386}, {"Spain", 34},
    {"Sweden", 46}, {"Switzerland", 41}, {"Ukraine", 380}, {"United Kingdom", 44},
    {"Vatican City", 379}
};

KodeTeleponBenua afrika[55] = {
    {"Algeria", 213}, {"Angola", 244}, {"Benin", 229}, {"Botswana", 267},
    {"Burkina Faso", 226}, {"Burundi", 257}, {"Cabo Verde", 238}, {"Cameroon", 237},
    {"Central African Republic", 236}, {"Chad", 235}, {"Comoros", 269}, {"Congo (Congo-Brazzaville)", 242},
    {"Democratic Republic of the Congo", 243}, {"Djibouti", 253}, {"Egypt", 20}, {"Equatorial Guinea", 240},
    {"Eritrea", 291}, {"Eswatini", 268}, {"Ethiopia", 251}, {"Gabon", 241},
    {"Gambia", 220}, {"Ghana", 233}, {"Guinea", 224}, {"Guinea-Bissau", 245},
    {"Ivory Coast", 225}, {"Kenya", 254}, {"Lesotho", 266}, {"Liberia", 231},
    {"Libya", 218}, {"Madagascar", 261}, {"Malawi", 265}, {"Mali", 223},
    {"Mauritania", 222}, {"Mauritius", 230}, {"Morocco", 212}, {"Mozambique", 258},
    {"Namibia", 264}, {"Niger", 227}, {"Nigeria", 234}, {"Rwanda", 250},
    {"Sao Tome and Principe", 239}, {"Senegal", 221}, {"Seychelles", 248}, {"Sierra Leone", 232},
    {"Somalia", 252}, {"South Africa", 27}, {"South Sudan", 211}, {"Sudan", 249},
    {"Tanzania", 255}, {"Togo", 228}, {"Tunisia", 216}, {"Uganda", 256},
    {"Zambia", 260}, {"Zimbabwe", 263}
};

KodeTeleponBenua amerika[40] = {
    {"Antigua and Barbuda", 1}, {"Argentina", 54}, {"Bahamas", 1}, {"Barbados", 1},
    {"Belize", 501}, {"Bolivia", 591}, {"Brazil", 55}, {"Canada", 1},
    {"Chile", 56}, {"Colombia", 57}, {"Costa Rica", 506}, {"Cuba", 53},
    {"Dominica", 1}, {"Dominican Republic", 1}, {"Ecuador", 593}, {"El Salvador", 503},
    {"Grenada", 1}, {"Guatemala", 502}, {"Guyana", 592}, {"Haiti", 509},
    {"Honduras", 504}, {"Jamaica", 1}, {"Mexico", 52}, {"Nicaragua", 505},
    {"Panama", 507}, {"Paraguay", 595}, {"Peru", 51}, {"Saint Kitts and Nevis", 1},
    {"Saint Lucia", 1}, {"Saint Vincent and the Grenadines", 1}, {"Suriname", 597}, {"Trinidad and Tobago", 1},
    {"United States", 1}, {"Uruguay", 598}, {"Venezuela", 58}
};

KodeTeleponBenua australia[1] = {
    {"Australia", 61}
};

KodeTeleponBenua oseania[9] = {
    {"Fiji", 679}, {"Kiribati", 686}, {"Marshall Islands", 692}, {"Micronesia", 691},
    {"Nauru", 674}, {"New Zealand", 64}, {"Palau", 680}, {"Papua New Guinea", 675},
    {"Samoa", 685}, {"Solomon Islands", 677}, {"Tonga", 676}, {"Tuvalu", 688},
    {"Vanuatu", 678}
};

int Donaturloop=0;    
printf("=====ZERO HUNGER FOR AFRICA=====\n"); 
printf("Jumlah Donatur(Sebutkan jumlah Individu yang ingin mendonasikan):  ");
scanf("%d",&DonaturLoop);
getchar(); 

Donatur *donatur = malloc(DonaturLoop * sizeof(Donatur));


for (int i=0;i<DonaturLoop;i++) {
printf("Kamu adalah Donatur ke -%d \n",i+1);

int namavalid=0;
do {
    printf("\n");
    printf("Nama:  "); 
    fgets(donatur[i].nama, sizeof(donatur[i].nama), stdin);
   if (strchr(donatur[i].nama, '\n') == NULL) {
                printf("Maksimal 50 karakter\n");
                
                while (getchar() != '\n');
            } 
    else { donatur[i].nama[strcspn(donatur[i].nama, "\n")] = '\0';
    namavalid+=1;
    }
    } while(namavalid!=1);
    
int umurvalid=0;  
do {
printf("\n");
printf("Umur:"); 
getchar(); 
scanf("%d",&donatur.umur[i]);

if(donatur.umur[i]<17&&donatur.umur[i]>0){ 
    printf("Maaf , anda belum cukup umur untuk donasi");
    i++ //break the loop; 
    
}
else if(donatur.umur[i]>=17){umurvalid+=1; }
else {
    printf("Masukkan umur yang valid");
}
}while(umurvalid!=1); 

printf("\n");
printf("Benua asal\n[0]Amerika \n[1]Asia \n[2]Australia \n[3]Afrika \n[4]Eropa \n[5]Oseania \n : "); 
scanf("%d",&donatur[i].Benuaasal); 
getchar(); 

switch(donatur[i].Benuaasal){ 
    case Amerika: 
    for(int i=0;i<Asia;i++){ 
        
    
case
int negaravalid=0;
do {


    
    

    
    return 0; 
}
    
```
