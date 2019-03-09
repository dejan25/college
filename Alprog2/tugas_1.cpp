/**
 * @author Dejan Sandria S
 * @NPM 0617104029
**/
#include <iostream>
using namespace std;

struct customer {
    string name;
    int transport_id;
    int jml_tiket;
    double total_penjualan;
};

struct transportasi {
    string name;
    double harga;
};

customer cust[10];
transportasi trans[4];

int i, selected_cust;
double total_penjualan, nilai_penjualan;
char try_again;
bool found;

void set_trans()
{
    trans[0].name = "Bus";
    trans[0].harga = 50000;

    trans[1].name = "Kereta Api";
    trans[1].harga = 100000;

    trans[2].name = "Ferry";
    trans[2].harga = 75000;

    trans[3].name = "Pesawat";
    trans[3].harga = 200000;
}

main ()
{
    i = 0;
    found = false;

    set_trans();

    do {
        cout << "Nama Pemesan : "; cin >> cust[i].name;
        cout << "Kode Transportasi : "; cin >> cust[i].transport_id;
        cust[i].transport_id -= 1;

        cout << "Jumlah Tiket : "; cin >> cust[i].jml_tiket;

        total_penjualan = trans[cust[i].transport_id].harga * cust[i].jml_tiket;

        if (cust[i].jml_tiket > 3) cust[i].total_penjualan = total_penjualan - (total_penjualan * 0.1);
        else cust[i].total_penjualan = total_penjualan;

        cout << "Data Berhasil di Input ! Tambah Lagi (Y/n)? "; cin >> try_again;
        i++;
    } while (try_again == 'Y' || try_again == 'y');

    cout << endl << "Cari data yang total penjualannya lebih kecil dari (X) : "; cin >> nilai_penjualan;

    i = 0;
    while (i < 10 && !found) {
        if (cust[i].total_penjualan < nilai_penjualan) {
        	selected_cust = i;
            found = true;
        } else i++;
    }

    if (found) {
        cout << endl << "Rekap Penjualan Tiket : " << endl;
    	cout << "1." << endl;
    	cout << "Nama Pemesan : " << cust[i].name << endl;
    	cout << "Jenis Transportasi : " << trans[cust[i].transport_id].name << endl;
    	cout << "Total Penjualan : " << cust[i].total_penjualan << endl;
    } else {
    	cout << "Data Tidak Ditemukan";
    }

    system("pause");
}