#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct DIEMTHI {
	char MAMH[15];
	float DIEM;
};

struct nodeDIEMTHI{
	DIEMTHI data;
	nodeDIEMTHI *pNext;
};

struct dsDIEMTHI{
	nodeDIEMTHI *pHead = NULL;
	int sl=0;
};

DIEMTHI taodataDIEMTHI(char *MAMH,float diem){
	DIEMTHI d;
	strcpy(d.MAMH,MAMH);	
	d.DIEM=diem;
	return d;
	
}
nodeDIEMTHI *taonodeDIEMTHI(DIEMTHI data)
{
	nodeDIEMTHI *tam = new nodeDIEMTHI;
	tam->pNext= NULL ;
	tam->data=data;
	return tam;
}

void themDIEMTHI(dsDIEMTHI &ds, DIEMTHI data)
{
	nodeDIEMTHI *nodeTam= taonodeDIEMTHI(data);
	nodeTam->pNext=NULL;
	if(ds.pHead == NULL)
	{
		ds.pHead=nodeTam;
		ds.sl++;
		return;
	}
	nodeTam->pNext= ds.pHead;
	ds.pHead=nodeTam;
	ds.sl++;
	return;
}

void suaDIEMTHI(dsDIEMTHI &ds, DIEMTHI data){
	for(nodeDIEMTHI *tam= ds.pHead; tam!=NULL; tam= tam->pNext){
		if(strcmp(data.MAMH,tam->data.MAMH)==0)
		{
			tam->data=data;
			return;
		}
	}
}

float timDIEMTHItheoMAMH(dsDIEMTHI ds, char* MAMH)
{
	for (nodeDIEMTHI* temp = ds.pHead; temp != NULL; temp = temp -> pNext)
	{
		if (strcmp(temp->data.MAMH, MAMH) == 0)
		{
			return temp->data.DIEM;
		}
	}
	return -1;
}

void xuatdsdiem(dsDIEMTHI ds){
	for (nodeDIEMTHI* temp = ds.pHead; temp != NULL; temp = temp -> pNext)
	{
	cout<< temp->data.MAMH<<" :  "<<temp->data.DIEM;
	}
}

//void ghiFileDiem (dsDIEMTHI ds)
//{
//	fstream outputFile;
//	outputFile.open("DiemThi.txt", ios::out);
//	
//	outputFile << ds.sl << endl;
//	for (nodeDIEMTHI* tam = ds.pHead; tam != NULL; tam = tam -> pNext)
//	{
//		outputFile << tam->data.MAMH <<endl;
//		outputFile << tam->data.DIEM <<endl;
//		
//		cout << "ghi dc roi";
//		
//		tam = tam->pNext;
//	}
//	outputFile.close();
//}
//
//void docFileSinhVien (dsDIEMTHI ds)
//{
//	fstream inputFile;
//	inputFile.open("SinhVien.txt", ios::in);
//	char mamh[30];
//	float diem;
//	
//	int sl = 0;
//	inputFile >> sl;
//	for (int i = 0; i < sl; i++) 
//	{
//		inputFile.getline(mamh, sizeof(mamh), '\n');
//		if(strlen(mamh)==0) break;	
//		inputFile << diem;
//		inputFile.ignore();
//		themDIEMTHI(ds, taodataDIEMTHI(mamh, *diem));
//	}
//	inputFile.close();
//}







