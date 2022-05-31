#include "SinhVien.h"
#include <fstream>
using namespace std;

struct LOP {
	char MALOP[30];
	char TENLOP[30];
	dsSINHVIEN dssv;
};

struct dsLOP{
	LOP lop[100];
	int sl=0;
};

LOP taodataLOP(char* MALOP, char* TENLOP) {
	LOP lop;
	strcpy(lop.MALOP, MALOP);
	strcpy(lop.TENLOP, TENLOP);
	cout<<"<<dt<<"<<MALOP<<"/"<<TENLOP<<"/";
	return lop;
}

void themLOP(dsLOP &ds, LOP data)
{
	cout<<" data them v:"<<data.MALOP<<"/"<<data.TENLOP<<endl;
	if (ds.sl >= 100)
	{
		cout << "Hong be oi!";
		return;
	}
	else 
	{
//	int sl=ds.sl++;
//	ds.lop[ds.sl++]=data;
	strcpy(ds.lop[ds.sl].MALOP,data.MALOP)	;
	strcpy(ds.lop[ds.sl].TENLOP,data.TENLOP);
	ds.sl++;
	//	=data;
	}
}
nodeSINHVIEN *timKiemTrongTatCaSinhVien(dsLOP &danhSachLop, char maSV[]){
	for(int i=0; i<danhSachLop.sl; i++){
		if(timKiemSinhVienTheoMa(danhSachLop.lop[i].dssv, maSV)!=NULL){
			return timKiemSinhVienTheoMa(danhSachLop.lop[i].dssv, maSV);
		}
	}
	return NULL;
}
void xoaSinhVienTrongLop(dsLOP &danhSachLop, char maLop[], char maSV[]){
	for(int i=0; i<danhSachLop.sl; i++){
		if(strcmp(danhSachLop.lop[i].MALOP, maLop)==0){
			xoaSinhVienTheoMa(danhSachLop.lop[i].dssv, maSV);
			
			return;
		}
	}
}
void suaSinhVienTrongLop(dsLOP &danhSachLop, char maLop[], char maSV[],char ho[], char tenMoi[], char phai[], char pass[]){
	
	for(int i=0; i<danhSachLop.sl; i++){
		if(strcmp(danhSachLop.lop[i].MALOP, maLop)==0){
			suaThongTinSinhVien(danhSachLop.lop[i].dssv, maSV,ho,tenMoi,phai,pass);
			return;
		}
	}
	
}
int timvitriLOP(dsLOP ds, char* MALOP)
{
	
	for (int i = 0; i < ds.sl; i++)
	{
	//	cout<<"ds//"<<ds.lop[i].MALOP<<"//"<<MALOP<<"//";
		if (strcmp(ds.lop[i].MALOP, MALOP) == 0)
		{
		//	cout<<"bang r";
			return i;
		}
	}
	return -1;
}
LOP timLop(dsLOP ds, char* MALOP)
{
	
	for (int i = 0; i < ds.sl; i++)
	{
		if (strcmp(ds.lop[i].MALOP, MALOP) == 0)
		{
			return ds.lop[i];
		}
	}
	LOP l;
	strcpy(l.MALOP,"");
	strcpy(l.TENLOP,"");
	return l;
}

LOP timLoptheovitri(dsLOP ds, int i)
{
	if (i > -1 && i < ds.sl)
	{
		return ds.lop[i];
	}
	LOP l;
	strcpy(l.MALOP,"");
	return l;
}

void suaLop(dsLOP &ds, LOP data)
{
	for (int i = 0; i <= ds.sl; i++)
	{
		cout<<ds.lop[i].MALOP<<"//"<<data.MALOP<<"//";
		if (strcmp(data.MALOP, ds.lop[i].MALOP) == 0)
		{
			ds.lop[i] = data;
		}
	}
}

void xoaLop(dsLOP &ds, char maLop[])
{
	for (int i = 0; i < ds.sl; i++)
	{
		if (strcmp(ds.lop[i].MALOP, maLop) == 0)
		{
			for (int j = i; j < ds.sl-1; j++)
			{
				ds.lop[j] = ds.lop[j+1];
			}
			ds.sl--;
			return;
		}		
	}
}

bool kiemTraLopCoSinhVien(dsLOP ds, char* MALOP)
{
	for (int i = 0; i < ds.sl; i++)
	{
		if (strcmp(ds.lop[i].MALOP, MALOP) == 0)
		{
			if (ds.lop[i].dssv.sl != 0)
			{
				return true;
			}
		}
	}
	return false;
}

void themSVvaoLop(dsLOP &ds, char* MALOP, SINHVIEN sv)
{
	for (int i = 0; i < ds.sl; i++)
	{
		if (strcmp(ds.lop[i].MALOP, MALOP)==0)
		{
			themSinhVienVaoDSCoThuTu(ds.lop[i].dssv, sv);
			return;
		}
		
	}
	
}

void themDiemVaoSinhVienOLop(dsLOP &ds, char MASV[], DIEMTHI diem){
	for(int i=0; i<ds.sl; i++){
		
			themDiemVaoSinhVien(ds.lop[i].dssv, MASV, diem);
		
	}
}

dsSINHVIEN laydssvtheoLop(dsLOP ds, char* MALOP)
{
	dsSINHVIEN tam;
	for (int i = 0; i < ds.sl; i++)
	{
		if (strcmp(ds.lop[i].MALOP, MALOP)==0)
		{
			return ds.lop[i].dssv;
		}
	}
	return tam;
}

void inDIEMcua1MONcua1LOP(dsLOP ds, char* MALOP, char* MAMH )
{
	for (int i=0; i<ds.sl; i++)
	{
		if (strcmp(ds.lop[i].MALOP, MALOP)==0)
		{
			for (nodeSINHVIEN* tam = ds.lop[i].dssv.pHead; tam != NULL; tam = tam->pNext)
			{
				float diem = timDIEMTHItheoMAMH(tam->data.dsdiem, MAMH);
				cout << "tensv" << tam->data.TEN;
				if (diem == -1)
				{
					cout << "chua thi";
				}	
				cout << ".." << diem;
			}
		}
	}
}

SINHVIEN timSVtheoLOP (dsLOP ds, char* MASV)
{
	SINHVIEN sv;
	strcpy(sv.MASV, "");
	for (int i = 0; i < ds.sl; i++)
	{
		sv = timSVtheoMASV(ds.lop[i].dssv, MASV);
	}
	return sv;
}

void xuatdslop(dsLOP ds)
{
	for (int i = 0; i < ds.sl; i++)
	{
	cout<< ds.lop[i].MALOP;
	}
}

//void ghiFileLopHoc (dsLOP ds)
//{
//	fstream outputFile;
//	outputFile.open("LopHoc.txt", ios::out);
//	outputFile<<ds.sl<<endl;
//	for (int i = 0; i < ds.sl; i++)
//	{
//		outputFile << ds.lop[i].MALOP <<endl;
//		outputFile << ds.lop[i].TENLOP <<endl;
//		cout << "ghi dc r";
//	}
//	outputFile.close();
//}
//
//void docFileLopHoc (dsLOP ds)
//{
//	fstream inputFile;
//	inputFile.open("LopHoc.txt", ios::in);
//	char malop[30];
//	char tenlop[50];
//	int sl = 0;
//	inputFile>>sl;
//	for (int i = 0; i < sl; i++) 
//	{
//		inputFile.getline(malop, sizeof(malop), '\n');
//		if(strlen(malop)==0) break;
//		inputFile.getline(tenlop, sizeof(tenlop), '\n');
//		inputFile.ignore();
//		themLOP(ds, taodataLOP(malop, tenlop));
//	}
//	inputFile.close();
//}

void ghiFileDSLopSVDiem(dsLOP ds){
	
	fstream file;
	file.open("LopSinhVienDiem.txt", ios::out);
	
	file<<ds.sl<<std::endl;
	
	for(int i=0; i<ds.sl; i++){
		file<<ds.lop[i].MALOP<< endl;
		file<<ds.lop[i].TENLOP<< endl;
		
		file<<ds.lop[i].dssv.sl<<endl;
		nodeSINHVIEN *tmpSV = ds.lop[i].dssv.pHead;
		while(tmpSV!=NULL){
			file<<tmpSV->data.MASV<<endl;
			file<<tmpSV->data.HO<<endl;
			file<<tmpSV->data.TEN<<endl;
			file<<tmpSV->data.PHAI<<endl;
			file<<tmpSV->data.password<<endl;
			
			file<<tmpSV->data.dsdiem.sl<<endl;
			nodeDIEMTHI *tmpDiem = tmpSV->data.dsdiem.pHead;
			while(tmpDiem!=NULL){
				file<<tmpDiem->data.MAMH<<std::endl;
				file<<tmpDiem->data.DIEM<<std::endl;
				
				tmpDiem = tmpDiem->pNext;
			}
			
			tmpSV = tmpSV->pNext;
		}
		
	}
	
	file.close();
	
}

void docFileDSLopSVDiem (dsLOP &ds)
{
	fstream file;
	file.open("LopSinhVienDiem.txt", ios::in);
	LOP L;
	char malop[30];
	char tenlop[50];
	char masv[30];
	char ho[30];
	char ten[30];
	char phai[10];
	char pw[30];
	char mamh[30];
	float diem;
	
	int sl = 0;
	
	file >>sl;
		file.ignore();
	for (int i = 0; i < sl; i++)
	{
		file.getline(malop, sizeof(L.MALOP), '\n');
	//	if(strlen(malop)==0) break;
		file.getline(tenlop, sizeof(L.TENLOP), '\n');
//		cout<<"sjdfhsdfhsdj"<<malop<<tenlop;
		themLOP(ds, taodataLOP(malop, tenlop));
		cout<<ds.lop[i].MALOP<<"/"<<ds.lop[i].TENLOP;
		int slsv = 0;
		file >> slsv;
			file.ignore();
		for (int j = 0; j < slsv; j++)
		{
			file.getline(masv, sizeof(masv), '\n');
			file.getline(ho, sizeof(ho), '\n');
			file.getline(ten, sizeof(ten), '\n');
			file.getline(phai, sizeof(phai), '\n');
			file.getline(pw, sizeof(pw), '\n');
			themSVvaoLop(ds, malop, taodataSINHVIEN(masv, ho, ten, phai, pw));
			
			int sldiem = 0;
			file >> sldiem;
				file.ignore();
			for (int k = 0; k < sldiem; k++)
			{
				file.getline(mamh, sizeof(mamh), '\n');
				file >> diem;	
				
				file.ignore();
//				themDIEMTHI(ds.lop[i].dssv.pHead->data.dsdiem, taodataDIEMTHI(mamh, diem));
				themDiemVaoSinhVienOLop(ds, masv, taodataDIEMTHI(mamh, diem));
			}
		}
	}
	file.close();
}







