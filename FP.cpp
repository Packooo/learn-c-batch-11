#include <iostream>
#include <iomanip>
using namespace std;

int n, ntiket = 0, price = 0, nprice = 0, nppn = 0, total = 0, pay = 0, kembalian = 0;
float ppn = 0;

void printElse(){
    cout << "MAAF PILIHAN TIDAK DI TEMUKAN" << endl;
    cin.ignore();
    cout << "Tekan ENTER Untuk Kembali Ke-Menu";
    cin.get();
    system("cls");
}

int calculator(int n, int harga, float appn){
    ntiket += n;
    price = n * harga;
    nprice += price;
    ppn = appn * price;
    nppn += ppn;
    pay = ppn + price;
    total += ppn + price;
    cout << endl;
    return ntiket, nprice, nppn, total;
}

void printPay(int n, int price, int ppn, int pay){
    cout << "Jumlah Tiket\t = " << n << endl;
    cout << "Harga Tiket\t = Rp." << price << endl;
    cout << "PPN\t\t = Rp." << ppn << endl;
    cout << "Total Pembayaran = Rp." << pay << endl << endl;
}

int inputUang(int uang, int total){
    if (uang >= total){
        kembalian = uang - total;
        system("cls");
    }else if (uang < total){
        cout << "MAAF KAK DILARANG NGUTANG" << endl;
        cin.ignore();
        cout << "Tekan ENTER Untuk Kembali Ke-Menu Pembayaran";
        cin.get();
        system("cls");
    }
    return uang, total, kembalian;
}

int main(){
    char pilihan;
    int uang = 0;

    // jumlah array
    int ntabel = 3;
    // jadwal
    string jadwal[ntabel] = {"Yogyakarta - Klaten", "Yogyakarta - Solo", "Yogyakarta - Madiun"};
    string waktu[ntabel] = {"17:05", "18:00", "20:30"};
    // Ekonomi
    string ekonomi[ntabel] = {"Rp.50k", "Rp.60k", "Rp.70k"};
    int hargaE[ntabel] = {50000, 60000, 70000};
    // Bisnis
    string bisnis[ntabel] = {"Rp.80k", "Rp.90k", "Rp.100k"};
    int hargaB[ntabel] = {80000, 90000, 100000};
    // Eksekutif
    string eksekutif[ntabel] = {"Rp.110k", "Rp.120k", "Rp.130k"};
    int hargaX[ntabel] = {110000, 120000, 130000};
    // array PPN
    float appn[3] = {0, 0.05, 0.1};

menu:
    cout << "+-----------------SELAMAT DATANG----------------+" << endl;
    cout << "|\tSilahkan Pilih Menu Yang ada dibawah\t|" << endl;
    cout << "+-----------------------------------------------+" << endl;
    cout << "|\t1. Lihat Jadwal BUS\t\t\t|" << endl;
    cout << "|\t2. Lihat Harga Tiket\t\t\t|" << endl;
    cout << "|\t3. Pesan Tiket\t\t\t\t|" << endl;
    cout << "+```````````````````````````````````````````````+" << endl;
    cout << "Masukan Menu pilihan: ";
    cin >> pilihan;
    system("cls");

    // Pilihan Menu
    switch (pilihan){
    case '1':
        cout << " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~+" << endl;
        cout << " |         TUJUAN             |   WAKTU  |" << endl;
        cout << " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~+" << endl;
        for (int i = 0; i < ntabel; i++){
            cout << " | " << setiosflags(ios::left) << setw(27) << jadwal[i] << "|";
            cout << "   " << setiosflags(ios::left) << setw(7) << waktu[i] << "|";
            cout << endl;
        }
        cout << " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~+" << endl;
        system("pause");
        system("cls");
        goto menu;
        break;
    case '2':
        cout << " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~+~~~~~~~~~~~~~+~~~~~~~~~~~~~~+" << endl;
        cout << " |         TUJUAN             |   EKONOMI   |   BISNIS    |   EKSEKUTIF  |" << endl;
        cout << " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~+~~~~~~~~~~~~~+~~~~~~~~~~~~~~+" << endl;
        for (int i = 0; i < ntabel; i++){
            cout << " | " << setiosflags(ios::left) << setw(27) << jadwal[i] << "|";
            cout << "   " << setiosflags(ios::left) << setw(10) << ekonomi[i] << "|";
            cout << "   " << setiosflags(ios::left) << setw(10) << bisnis[i] << "|";
            cout << "   " << setiosflags(ios::left) << setw(11) << eksekutif[i] << "|";
            cout << endl;
        }
        cout << " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~+~~~~~~~~~~~~~+~~~~~~~~~~~~~~+" << endl;
        system("pause");
        system("cls");
        goto menu;
        break;
    case '3':
    menuPesan:
        cout << " +~~~~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~+~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~+" << endl;
        cout << " | NO |         TUJUAN             |   WAKTU  |   EKONOMI(E)   |   BISNIS(B)    |   EKSEKUTIF(X)  |" << endl;
        cout << " +~~~~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~+~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~+" << endl;
        for (int i = 0; i < ntabel; i++){
            cout << " | " << setiosflags(ios::left) << setw(3) << i + 1;
            cout << "| " << setiosflags(ios::left) << setw(27) << jadwal[i] << "|";
            cout << "   " << setiosflags(ios::left) << setw(7) << waktu[i] << "|";
            cout << "   " << setiosflags(ios::left) << setw(13) << ekonomi[i] << "|";
            cout << "   " << setiosflags(ios::left) << setw(13) << bisnis[i] << "|";
            cout << "   " << setiosflags(ios::left) << setw(14) << eksekutif[i] << "|";
            cout << endl;
        }
        cout << " +~~~~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~+~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~+" << endl;
        cout << "Masukan Kota Tujuan: ";
        cin >> pilihan;
        // 1
        if (pilihan == '1'){
            cout << "Kota Tujuan Anda\t\t : " << jadwal[0] << endl;
            cout << "Pilih Kelas(E/B/X)\t\t : ";
            cin >> pilihan;
            if (pilihan == 'e' || pilihan == 'E'){
                cout << "Jumlah Tiket Yang Di Pesan\t : ";
                cin >> n;
                calculator(n, hargaE[0], appn[0]);
            }else if (pilihan == 'b' || pilihan == 'B'){
                cout << "Jumlah Tiket Yang Di Pesan\t : ";
                cin >> n;
                calculator(n, hargaB[0], appn[1]);
            }else if (pilihan == 'x' || pilihan == 'X'){
                cout << "Jumlah Tiket Yang Di Pesan\t : ";
                cin >> n;
                calculator(n, hargaX[0], appn[2]);
            }else{
                printElse();
                goto menuPesan;
            }
        }
        // 2
        else if (pilihan == '2'){
            cout << "kota tujuan anda\t\t : " << jadwal[1] << endl;
            cout << "Pilih Kelas(E/B/X)\t\t : ";
            cin >> pilihan;
            if (pilihan == 'e' || pilihan == 'E'){
                cout << "Jumlah Tiket Yang Di Pesan\t : ";
                cin >> n;
                calculator(n, hargaE[1], appn[0]);
            }else if (pilihan == 'b' || pilihan == 'B'){
                cout << "Jumlah Tiket Yang Di Pesan\t : ";
                cin >> n;
                calculator(n, hargaB[1], appn[1]);
            }else if (pilihan == 'x' || pilihan == 'X'){
                cout << "Jumlah Tiket Yang Di Pesan\t : ";
                cin >> n;
                calculator(n, hargaX[1], appn[2]);
            }else{
                printElse();
                goto menuPesan;
            }
        }
        // 3
        else if (pilihan == '3'){
            cout << "kota tujuan anda\t\t  : " << jadwal[2] << endl;
            cout << "Pilih Kelas(E/B/X)\t\t  : ";
            cin >> pilihan;
            if (pilihan == 'e' || pilihan == 'E'){
                cout << "Jumlah Tiket Yang Di Pesan\t  : ";
                cin >> n;
                calculator(n, hargaE[2], appn[0]);
            }else if (pilihan == 'b' || pilihan == 'B'){
                cout << "Jumlah Tiket Yang Di Pesan\t  : ";
                cin >> n;
                calculator(n, hargaB[2], appn[1]);
            }else if (pilihan == 'x' || pilihan == 'X'){
                cout << "Jumlah Tiket Yang Di Pesan\t  : ";
                cin >> n;
                calculator(n, hargaX[2], appn[2]);
            }else{
                printElse();
                goto menuPesan;
            }
        }else{
            printElse();
            goto menuPesan;
        }
        break;

    default:
        printElse();
        goto menu;
        break;
    }

pembayaran:
    printPay(n, price, ppn, pay);
    cout << "Tekan [Y] Untuk Menambah Tiket " << endl;
    cout << "Tekan [N] Untuk Ke-Menu Pembayaran" << endl;
    cout << "PILIH = ";
    cin >> pilihan;
    if (pilihan == 'y' || pilihan == 'Y'){
        system("cls");
        goto menuPesan;
    }
    system("cls");
    printPay(ntiket, nprice, nppn, total);
    cout << "Masukan Uang Pembayaran = ";
    cin >> uang;
    inputUang(uang, total);
    if (uang < total){
        goto pembayaran;
    }

    cout << "Jumlah Tiket\t = " << ntiket << endl;
    cout << "Total Pembayaran = Rp." << total << endl;
    cout << "Uang\t\t = Rp." << uang << endl;
    cout << "Kembalian\t = Rp." << kembalian << endl << endl;
    cout << "TERIMAKASIH KAK SUDAH BERKUNJUNG " << endl;

    cin.get();
    return 0;
}