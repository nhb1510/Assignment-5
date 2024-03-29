#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien
{
    char ho_ten[50];
    int MSV;
    float PGA;
};

void NHAP_DANH_SACH_SINH_VIEN (struct SinhVien *SV1)
{
    printf ("Nhập tên sinh viên: ");
    fgets ( SV1->ho_ten, sizeof (SV1->ho_ten), stdin);
    SV1->ho_ten [strcspn (SV1->ho_ten, "\n")] = '\0';

    printf ("Nhập Mã sinh viên: ");
    scanf ("%d", &(SV1->MSV));
    printf ("Nhập điểm trung bình: ");
    scanf ("%f", &(SV1->PGA));
}

void HIEN_THI_DANH_SACH_SINH_VIEN (struct SinhVien *SV2)
{
    printf ("\nHọ và tên: %s\n", SV2->ho_ten);
    printf ("Mã sinh viên: %d\n", SV2->MSV);
    printf ("Điểm trung bình: %0.2f\n", SV2->PGA );
}

int DIEM_CAO_NHAT (struct SinhVien *SV3, int num_input)
{
    int H_GPA = SV3[0].PGA;
    int index = 0;
    for (int i = 1 ; i < num_input ; i++){ 
        if (H_GPA < SV3[i].PGA)
            {
                H_GPA = SV3[i].PGA;
                index = i;
            }
    }
    return index;
}

int main ()
{
    int num_input;
    scanf ("%d", &num_input);
    while (getchar() != '\n');
    //printf (");
    struct SinhVien *ptrsv;
    ptrsv = calloc (num_input, sizeof ( struct SinhVien));

    for (int i = 0 ; i < num_input; i++)
    {
        NHAP_DANH_SACH_SINH_VIEN ( &ptrsv[i]);
        while (getchar() != '\n');
    }

    printf ("\n############\n");
    printf ("Danh sách sinh viên đã nhập:\n");
    for (int i = 0; i < num_input; i++)
    {
        HIEN_THI_DANH_SACH_SINH_VIEN (&ptrsv[i]);
    }
    printf ("\n############\n");

    int index = DIEM_CAO_NHAT( ptrsv , num_input);

    printf ("\nSinh viên có điểm cao nhất: %0.2f\n", ptrsv[index].PGA);   
    HIEN_THI_DANH_SACH_SINH_VIEN (&ptrsv[index]);

    free (ptrsv);
    return 0;
}