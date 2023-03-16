#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[100], tempatLahir[15], nik[17], pekerjaan[15], alamat[50];
    int agama, tanggalLahir, bulanLahir, tahunLahir, kewarganegaraan, jenisKelamin, status;
} informasi;

void banner()
{
    puts("======================================================================================================");
}

void tambah()
{
    int ulang = 0;
    informasi tambahData;
    FILE *out;
    out = fopen("data.bin", "ab+");
    printf("Masukan Data: \n");
    printf("NIK (16 Digit)\t: ");
    scanf("%s", tambahData.nik);
    if (strlen(tambahData.nik) != 16)
    {
        printf("Harus 16 Digit\n");
        return;
    }
    printf("Nama\t\t: ");
    scanf("\n%[^\n]%*c", tambahData.nama);
    printf("Tempat lahir\t: ");
    scanf("\n%[^\n]%*c", tambahData.tempatLahir);
    printf("Tanggal Lahir\t: ");
    scanf("\n%d", &tambahData.tanggalLahir);
    printf("Bulan Lahir\t: ");
    scanf("\n%d", &tambahData.bulanLahir);
    printf("Tahun Lahir\t: ");
    scanf("\n%d", &tambahData.tahunLahir);
    printf("Pekerjaan\t: ");
    scanf("\n%[^\n]%*c", tambahData.pekerjaan);
    printf("Alamat\t\t: ");
    scanf("\n%[^\n]%*c", tambahData.alamat);
    printf("Agama :\n1.) Islam\n2.) Kristen\n3.) Katolik\n4.) Hindu\n5.) Budha\n6.) Konghucu\nPilih : ");
    scanf("%d", &tambahData.agama);
    printf("\nKewarganegaraan :\n1.) WNI\n2.) WNA\nPilih : ");
    scanf("%d", &tambahData.kewarganegaraan);
    printf("\nStatus :\n1.) Kawin\n2.) Belum Kawin\n3.) Cerai Hidup\n4.) Cerai Mati\nPilih : ");
    scanf("%d", &tambahData.status);
    printf("\nJenis Kelamin :\n1.) Laki-laki\n2.) Perempuan\nPilih : ");
    scanf("%d", &tambahData.jenisKelamin);
    fwrite(&tambahData, sizeof(informasi), 1, out);
    fclose(out);
    printf("\nData Berhasil Disimpan\n");
}

void baca(char nama[])
{
    int ada = 0;
    FILE *out;
    out = fopen("data.bin", "rb");
    informasi bacainfor;
    while (fread(&bacainfor, sizeof(informasi), 1, out) == 1)
    {
        if (strcmp(bacainfor.nama, nama) == 0)
        {
            ada = 1;
            printf("Nama\t\t\t: %s\n", bacainfor.nama);
            printf("Tempat, Tanggal Lahir\t: %s, %02d-%02d-%d\n", bacainfor.tempatLahir, bacainfor.tanggalLahir, bacainfor.bulanLahir, bacainfor.tahunLahir);
            printf("Pekerjaan\t\t: %s\n", bacainfor.pekerjaan);
            printf("Alamat\t\t\t: %s\n", bacainfor.alamat);
            switch (bacainfor.agama)
            {
            case 1:
                printf("Agama\t\t\t: Islam");
                break;
            case 2:
                printf("Agama\t\t\t: Kristen");
                break;
            case 3:
                printf("Agama\t\t\t: Katolik");
                break;
            case 4:
                printf("Agama\t\t\t: Budha");
                break;
            case 5:
                printf("Agama\t\t\t: Konghucu");
                break;
            default:
                break;
            }
            puts("");
            switch (bacainfor.kewarganegaraan)
            {
            case 1:
                printf("Kewarganegaraan\t\t: WNI");
                break;
            case 2:
                printf("Kewarganegaraan\t\t: WNA");
                break;
            default:
                break;
            }
            puts("");
            switch (bacainfor.status)
            {
            case 1:
                printf("Status\t\t\t: Kawin");
                break;
            case 2:
                printf("Status\t\t\t: Belum Kawin");
                break;
            case 3:
                printf("Status\t\t\t: Cerai Hidup");
                break;
            case 4:
                printf("Status\t\t\t: Cerai Mati");
                break;
            default:
                break;
            }
            puts("");
            switch (bacainfor.jenisKelamin)
            {
            case 1:
                printf("Jenis Kelamin\t\t: Laki-Laki");
                break;
            case 2:
                printf("Jenis Kelamin\t\t: Perempuan");
                break;
            default:
                break;
            }
            puts("");
        }
    }

    if (!ada)
    {
        puts("Data tidak ditemukan");
    }

    fclose(out);
    banner();
}

void hapus(char nama[])
{
    FILE *out;
    FILE *out_tmp;
    int found = 0;
    informasi hapusinfor;
    out = fopen("data.bin", "rb");
    out_tmp = fopen("tmp.bin", "wb+");
    while (fread(&hapusinfor, sizeof(informasi), 1, out) == 1)
    {
        if (strcmp(nama, hapusinfor.nama) == 0)
        {
            printf("Data ditemukan dan dihapus.\n\n");
            found = 1;
        }

        else
        {
            fwrite(&hapusinfor, sizeof(informasi), 1, out_tmp);
        }
    }

    if (!found)
    {
        printf("Data tidak ditemukan: %s\n\n", nama);
    }

    fclose(out);
    fclose(out_tmp);

    remove("data.bin");
    rename("tmp.bin", "data.bin");
    puts("");
    banner();
}

void tampilkansemua_data()
{
    FILE *out;
    out = fopen("data.bin", "rb");
    informasi allinfor;
    int count = 0;
    while (fread(&allinfor, sizeof(informasi), 1, out) == 1)
    {
        banner();
        printf("NIK\t\t\t: %s\n", allinfor.nik);
        printf("Nama\t\t\t: %s\n", allinfor.nama);
        printf("Tempat, Tanggal Lahir\t: %s, %02d-%02d-%d\n", allinfor.tempatLahir, allinfor.tanggalLahir, allinfor.bulanLahir, allinfor.tahunLahir);
        printf("Pekerjaan\t\t: %s\n", allinfor.pekerjaan);
        printf("Alamat\t\t\t: %s\n", allinfor.alamat);
        count++;
        switch (allinfor.agama)
        {
        case 1:
            printf("Agama\t\t\t: Islam");
            break;
        case 2:
            printf("Agama\t\t\t: Kristen");
            break;
        case 3:
            printf("Agama\t\t\t: Katolik");
            break;
        case 4:
            printf("Agama\t\t\t: Budha");
            break;
        case 5:
            printf("Agama\t\t\t: Konghucu");
            break;
        default:
            break;
        }
        puts("");
        switch (allinfor.kewarganegaraan)
        {
        case 1:
            printf("Kewarganegaraan\t\t: WNI");
            break;
        case 2:
            printf("Kewarganegaraan\t\t: WNA");
            break;
        default:
            break;
        }
        puts("");
        switch (allinfor.status)
        {
        case 1:
            printf("Status\t\t\t: Kawin");
            break;
        case 2:
            printf("Status\t\t\t: Belum Kawin");
            break;
        case 3:
            printf("Status\t\t\t: Cerai Hidup");
            break;
        case 4:
            printf("Status\t\t\t: Cerai Mati");
            break;
        default:
            break;
        }
        puts("");
        switch (allinfor.jenisKelamin)
        {
        case 1:
            printf("Jenis Kelamin\t\t: Laki-Laki\n");
            break;
        case 2:
            printf("Jenis Kelamin\t\t: Perempuan\n");
            break;
        default:
            break;
        }
    }

    printf("\nBanyak Data : %d\n\n", count);
    banner();
    fclose(out);
}

int main()
{
    while (1)
    {
        int inputan;
        puts("\t\t\t\t\tMenu Utama");
        banner();
        printf("\nHalo Admin!\n\nPilih Menu\n1. Entri Data\n2. Cari Data\n3. Hapus Data\n4. Tampilkan Semua Data\n5. Keluar\n\nInput : ");
        scanf("%d", &inputan);
        while (inputan == 1)
        {
            int ulang;
            tambah();
            puts("\nApakah Input lagi ? (1) Ya\t(2) Tidak");
            printf("Input :");
            scanf("%d", &ulang);
            puts("");
            if (ulang == 2)
            {
                break;
            }
        }

        if (inputan == 2)
        {
            char nama[100];
            printf("\nCari Nama : ");
            scanf("%s", nama);
            baca(nama);
        }

        if (inputan == 3)
        {
            char nama[100];
            printf("\nNama : ");
            scanf("\n%[^\n]%*c", nama);
            hapus(nama);
        }

        if (inputan == 4)
        {
            tampilkansemua_data();
        }

        if (inputan == 5)
        {
            break;
        }
    }
}