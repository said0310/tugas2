#include <iostream>
#include <string>
using namespace std;

const int maxQueue = 100;

struct Pesanan
{
    string nama;
    string jenisRoti;
    float totalHarga;
};

Pesanan queue[maxQueue];
int belakang = -1;

void buatQueue()
{
    belakang = -1;
}

bool queueKosong()
{
    return belakang == -1;
}

bool queuePenuh()
{
    return belakang == maxQueue - 1;
}

void enqueue(Pesanan p)
{
    if (queuePenuh())
    {
        cout << "Antrean penuh. Tidak bisa menambahkan pesanan baru.\n";
    }
    else
    {
        belakang++;
        queue[belakang] = p;
        cout << "Pesanan berhasil ditambahkan ke antrean.\n";
    }
}

void dequeue(Pesanan riwayat[], int &jumlahRiwayat)
{
    if (queueKosong())
    {
        cout << "Antrean kosong.\n";
    }
    else
    {
        Pesanan dilayani = queue[0];
        riwayat[jumlahRiwayat++] = dilayani;
        for (int i = 0; i < belakang; i++)
        {
            queue[i] = queue[i + 1];
        }
        belakang--;
        cout << "Pesanan atas nama " << dilayani.nama << " telah dilayani.\n";
    }
}

void tampilkanAntrean()
{
    if (queueKosong())
    {
        cout << "Antrean kosong.\n";
    }
    else
    {
        cout << "Daftar Pesanan dalam Antrean:\n";
        for (int i = 0; i <= belakang; i++)
        {
            cout << i + 1 << ". " << queue[i].nama << " - " << queue[i].jenisRoti
                 << " - Rp" << queue[i].totalHarga << endl;
        }
    }
}

void batalkanPesanan()
{
    if (queueKosong())
    {
        cout << "Tidak ada pesanan yang bisa dibatalkan.\n";
    }
    else
    {
        cout << "Pesanan atas nama " << queue[belakang].nama << " telah dibatalkan.\n";
        belakang--;
    }
}

void tampilkanRiwayat(Pesanan riwayat[], int jumlahRiwayat)
{
    if (jumlahRiwayat == 0)
    {
        cout << "Belum ada pesanan yang dilayani.\n";
    }
    else
    {
        cout << "Riwayat Pesanan yang Sudah Dilayani:\n";
        for (int i = 0; i < jumlahRiwayat; i++)
        {
            cout << i + 1 << ". " << riwayat[i].nama << " - " << riwayat[i].jenisRoti
                 << " - Rp" << riwayat[i].totalHarga << endl;
        }
    }
}

int main()
{
    bool jalan = true;
    int pilihan;
    Pesanan p;
    Pesanan riwayat[maxQueue];
    int jumlahRiwayat = 0;

    buatQueue();

    while (jalan)
    {
        cout << "\n=== Sistem Antrean Toko Roti Manis Lezat ===\n";
        cout << "1. Ambil Antrean\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Tampilkan Pesanan\n";
        cout << "4. Batalkan Pesanan\n";
        cout << "5. Tampilkan History Pesanan\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cin.ignore();
            cout << "Nama: ";
            getline(cin, p.nama);
            cout << "Jenis Roti: ";
            getline(cin, p.jenisRoti);
            cout << "Total Harga: ";
            cin >> p.totalHarga;
            enqueue(p);
            break;
        case 2:
            dequeue(riwayat, jumlahRiwayat);
            break;
        case 3:
            tampilkanAntrean();
            break;
        case 4:
            batalkanPesanan();
            break;
        case 5:
            tampilkanRiwayat(riwayat, jumlahRiwayat);
            break;
        case 6:
            jalan = false;
            cout << "Terima kasih telah menggunakan sistem ini.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}
