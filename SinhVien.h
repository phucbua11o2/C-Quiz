#include "DiemThi.h"
#include <fstream>
using namespace std;

struct SINHVIEN 
{
	char MASV[15];
	char HO[30];
	char TEN[30];
	char PHAI[10];
	char password[15];
	dsDIEMTHI dsdiem;
};

struct nodeSINHVIEN 
{
	SINHVIEN data;
	nodeSINHVIEN* pNext= NULL;
};

struct dsSINHVIEN 
{
	nodeSINHVIEN* pHead= NULL;
	int sl=0;
};

nodeSINHVIEN *first = NULL; 

SINHVIEN taodataSINHVIEN (char* MASV, char* HO, char* TEN, char* PHAI, char* password) 
{
	SINHVIEN sv;
	strcpy(sv.MASV, MASV);
	strcpy(sv.HO, HO);
	strcpy(sv.TEN, TEN);
	strcpy(sv.PHAI, PHAI);
	strcpy(sv.password, password);
	return sv;
}

nodeSINHVIEN* taonodeSINHVIEN(SINHVIEN data) 
{
	nodeSINHVIEN* tam = new nodeSINHVIEN;
	tam -> pNext = NULL;
	tam -> data = data;
	return tam;
}
nodeSINHVIEN *timKiemSinhVienTheoMa(dsSINHVIEN &danhSachSinhVien, char maSV[]){
	nodeSINHVIEN *nodeChay = danhSachSinhVien.pHead;
	while(nodeChay!=NULL){
//		cout<<nodeChay->sinhVien.maSV<<" va "<<maSV<<endl;
		if(strcmp(nodeChay->data.MASV, maSV)==0){
			return nodeChay;
		}
		nodeChay=nodeChay->pNext;
	}
	return NULL;
}
void themSINHVIEN(dsSINHVIEN &ds, SINHVIEN data) 
{
	nodeSINHVIEN *nodeTam = taonodeSINHVIEN(data);
	if(ds.pHead == NULL) 
	{
		ds.pHead = nodeTam;
		ds.sl++;
		return;
	}
	nodeTam -> pNext = ds.pHead;
	ds.pHead = nodeTam;
	ds.sl++;
	return;
}
void themSinhVienVaoCuoiDS(dsSINHVIEN &danhSachSinhVien, SINHVIEN sv){
	nodeSINHVIEN *tmp = taonodeSINHVIEN(sv);
	
	if(danhSachSinhVien.pHead==NULL){
		danhSachSinhVien.pHead = tmp;
	}
	else{
		nodeSINHVIEN *nodeChay = danhSachSinhVien.pHead;
		while(nodeChay->pNext!=NULL){
			nodeChay = nodeChay->pNext;
		}
		
		nodeChay->pNext = tmp;
	}
	danhSachSinhVien.sl++;
	
}
void themSinhVienVaoDSCoThuTu(dsSINHVIEN &danhSachSinhVien, SINHVIEN sv){
	
	nodeSINHVIEN *tmp = taonodeSINHVIEN(sv);
	
	if(danhSachSinhVien.pHead==NULL){
		danhSachSinhVien.pHead = tmp;
		danhSachSinhVien.sl++;
		return;
	}
	
	if(strcmp(tmp->data.MASV, danhSachSinhVien.pHead->data.MASV)<0){
		tmp->pNext = danhSachSinhVien.pHead;
		danhSachSinhVien.pHead = tmp;
		danhSachSinhVien.sl++;
	}
	else{
		nodeSINHVIEN *nodeChay = danhSachSinhVien.pHead;
		
		while(true){
			if(nodeChay->pNext==NULL) break;
			if(strcmp(nodeChay->pNext->data.MASV,tmp->data.MASV)>0){
				tmp->pNext = nodeChay->pNext;
				nodeChay->pNext = tmp;
				danhSachSinhVien.sl++;
				return;
			}
			nodeChay=nodeChay->pNext;
		}
		
		themSinhVienVaoCuoiDS(danhSachSinhVien, sv);
	}	
	
}
void suaSINHVIEN(dsSINHVIEN &ds, SINHVIEN data) 
{
	for (nodeSINHVIEN* tam = ds.pHead; tam != NULL; tam = tam -> pNext)
	{
		if (strcmp(data.MASV, tam -> data.MASV) == 0) 
		{
			tam -> data = data;
			return;
		}
	}
}
void suaThongTinSinhVien(dsSINHVIEN &danhSachSinhVien, char maSV[], char hoMoi[], char tenMoi[], char phai[], char pass[]){
	nodeSINHVIEN *svCanSua = timKiemSinhVienTheoMa(danhSachSinhVien, maSV);
	strcpy(svCanSua->data.HO, hoMoi);
	strcpy(svCanSua->data.TEN, tenMoi);
	strcpy(svCanSua->data.PHAI, phai);
	strcpy(svCanSua->data.password, pass);
	
}
void xoaSINHVIEN(dsSINHVIEN &ds, SINHVIEN data)
{
	for (nodeSINHVIEN* tam = ds.pHead; tam != NULL; tam = tam -> pNext)
	{
		if (strcmp(data.MASV, tam -> data.MASV) == 0)
		{
			tam = tam->pNext;
			return;
		}
	}
}
void xoaSinhVienTheoMa(dsSINHVIEN &danhSachSinhVien, char maSV[]){
	if(strcmp(danhSachSinhVien.pHead->data.MASV,maSV)==0){
		nodeSINHVIEN *nodeXoa = danhSachSinhVien.pHead;
		danhSachSinhVien.pHead = danhSachSinhVien.pHead->pNext;
		delete nodeXoa;
	}
	else{
		nodeSINHVIEN *nodeChay = danhSachSinhVien.pHead;
		nodeSINHVIEN *nodeTruoc = NULL;
		
		while(strcmp(nodeChay->data.MASV,maSV)!=0 && nodeChay->pNext!=NULL){
			nodeTruoc = nodeChay;
			nodeChay = nodeChay->pNext;
		}
		
		if(strcmp(nodeChay->data.MASV,maSV)==0){
			nodeTruoc->pNext = nodeChay->pNext;
			delete nodeChay;
			danhSachSinhVien.sl--;
		}
	}
}
SINHVIEN timSVtheoMASV (dsSINHVIEN ds, char* MASV)
{
	SINHVIEN rong ;
	for (nodeSINHVIEN* tam = ds.pHead; tam != NULL; tam = tam->pNext)
	{
		if (strcmp(ds.pHead->data.MASV, tam->data.MASV) == 0)
		{
			return tam->data;
		}
	}
	strcpy(rong.MASV,"");
	return rong;
}

bool kiemtradathi(dsSINHVIEN ds, char* MASV)
{
	for (nodeSINHVIEN* tam = ds.pHead; tam != NULL; tam = tam -> pNext)
	{
		if (strcmp(tam->data.MASV, MASV) == 0)
		{
			if (tam->data.dsdiem.sl == 0)
			{
			return false;
			}
		}		
	}
	return true;
}

void themdiemSINHVIEN(dsSINHVIEN ds, char* MASV, DIEMTHI diemthi)
{
	for (nodeSINHVIEN* tam = ds.pHead; tam != NULL; tam = tam -> pNext)
	{
		if (strcmp(tam->data.MASV, MASV) == 0)
		{
			themDIEMTHI(tam->data.dsdiem, diemthi);
		}
	}
}

//void themSinhVienVaoDSCoThuTu(dsSINHVIEN &ds, SINHVIEN sv){
//	
//	nodeSINHVIEN *tmp = taonodeSINHVIEN(sv);
//	
//	if(ds.pHead==NULL){
//		ds.pHead = tmp;
//		ds.sl++;
//		return;
//	}
//	
//	if(strcmp(tmp->data.MASV, ds.pHead->data.MASV)<0){
//		tmp->pNext = ds.pHead;
//		ds.pHead = tmp;
//		ds.sl++;
//	}
//	else{
//		nodeSINHVIEN *nodeChay = ds.pHead;
//		
//		while(nodeChay->pNext->pNext!=NULL && strcmp(nodeChay->pNext->data.MASV,tmp->data.MASV)<0){
//			nodeChay=nodeChay->pNext;
//		}
//		
//		if(strcpy(tmp->data.MASV,nodeChay->pNext->data.MASV)>0){
//			themSINHVIEN(ds, sv);
//		}
//		else{
//			tmp->pNext = nodeChay->pNext;
//			nodeChay->pNext = tmp;
//			ds.sl++;
//		}
//	}	
//	
//}

float timDIEMTHItheoMASV(dsSINHVIEN ds, char* MASV, char* MAMH)
{
	for (nodeSINHVIEN* tam = ds.pHead; tam != NULL; tam = tam -> pNext) 
	{
		if (strcmp(tam->data.MASV, MASV) == 0)
		{
			return timDIEMTHItheoMAMH(tam->data.dsdiem, MAMH);
		}
	}
}

void themDiemVaoSinhVien(dsSINHVIEN &ds, char* MASV, DIEMTHI diem){
	nodeSINHVIEN *nodeChay = ds.pHead;
	while(nodeChay!=NULL){
		if(strcmp(nodeChay->data.MASV, MASV)==0){
			themDIEMTHI(nodeChay->data.dsdiem, diem);
			return;
		}
		nodeChay=nodeChay->pNext;
	}
}
SINHVIEN timsinhvientheostt(int stt, dsSINHVIEN ds){
	int i=0;
	for(nodeSINHVIEN *p= ds.pHead; p!=NULL; p= p->pNext){
		if(i==stt)
		return p->data;
		i++;
	}
	SINHVIEN sv;
	strcpy(sv.MASV,"");
	return sv;
}
//int timvitriSINHVIEN(dsSINHVIEN ds, char* MASV)
//{
//	int i=0;
//	for (nodeSINHVIEN* tam = ds.pHead; tam != NULL; tam = tam -> pNext)
//	{
//		if (strcmp(tam->data.MASV, MASV) == 0)
//		{
//			return i;
//		}
//		i++;
//	}
//	return -1;
//}

void xuatdssv(dsSINHVIEN ds)
{
	for (nodeSINHVIEN* temp = ds.pHead; temp != NULL; temp = temp -> pNext)
	{
	cout<< temp->data.MASV<<" :  "<<temp->data.HO<<" :  "<<temp->data.TEN<<" :  "<<temp->data.PHAI<<" :  "<<temp->data.password;
	}
}

//void ghiFileSinhVien (dsSINHVIEN ds)
//{
//	fstream outputFile;
//	outputFile.open("SinhVien.txt", ios::out);
//	
////	nodeSINHVIEN* tam = ds.pHead;
//	outputFile << ds.sl << endl;
//	for (nodeSINHVIEN* tam = ds.pHead; tam != NULL; tam = tam -> pNext)
//	{
//		outputFile << tam->data.MASV <<endl;
//		outputFile << tam->data.HO <<endl;
//		outputFile << tam->data.TEN <<endl;
//		outputFile << tam->data.PHAI <<endl;
//		outputFile << tam->data.password <<endl;
//		cout << "ghi dc roi";
//		
//		tam = tam->pNext;
//	}
//	outputFile.close();
//}
//
//void docFileSinhVien (dsSINHVIEN ds)
//{
//	fstream inputFile;
//	inputFile.open("SinhVien.txt", ios::in);
//	char masv[30];
//	char ho[50];
//	char ten[50];
//	char phai[10];
//	char pw[30];
//	
//	int sl = 0;
//	inputFile >> sl;
//	for (int i = 0; i < sl; i++) 
//	{
//		inputFile.getline(masv, sizeof(masv), '\n');
//		if(strlen(masv)==0) break;
//		inputFile.getline(ho, sizeof(ho), '\n');
//		inputFile.getline(ten, sizeof(ten), '\n');
//		inputFile.getline(phai, sizeof(phai), '\n');
//		inputFile.getline(pw, sizeof(pw), '\n');
//		inputFile.ignore();
//		themSINHVIEN(ds, taodataSINHVIEN(masv, ho, ten, phai, pw));
//	}
//	inputFile.close();
//}










