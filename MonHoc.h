#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <dos.h>
#include <fstream>
#include <iomanip>
#include<ctime>
#include <winbgim.h> 
#include <math.h>
#define MAXMONHOC 300
const int MAX=3001;
using namespace std;
struct MonHoc{
	char maMH[15];
	char tenMH[30];
};
struct DanhSachMonHoc{
	MonHoc *ds[MAXMONHOC];
	int sl=0;
};
MonHoc taoMonHoc(char maMH[],char tenMH[])
{
	MonHoc tmp;
	strcpy(tmp.maMH,maMH);
	strcpy(tmp.tenMH,tenMH);
	
	return tmp;
}
MonHoc *timKiemMonHoc(DanhSachMonHoc &dsmh,char maMH[])
{
	for(int i=0;i<dsmh.sl;i++)
	{
		if(strcmp(dsmh.ds[i]->maMH,maMH)==0)
		{
			return dsmh.ds[i];
		}
	}
	return NULL;
}
MonHoc *timMonHocTheoViTri(DanhSachMonHoc dsmh,int i)
{
	if (i > -1 && i < dsmh.sl)
	{
		return dsmh.ds[i];
	}
	MonHoc *mh;
	strcpy(mh->maMH,"");
	return mh;
}

void themMonHoc(DanhSachMonHoc &dsmh,MonHoc mh)
{
	dsmh.ds[dsmh.sl] = new MonHoc;
	*dsmh.ds[dsmh.sl]=mh;
	dsmh.sl++;
}
void suaMonHoc(DanhSachMonHoc &dsmh,char maMH[],char tenMH[])
{
	for(int i=0; i<dsmh.sl; i++){
		if(strcmp(dsmh.ds[i]->maMH, maMH)==0){
			strcpy(dsmh.ds[i]->tenMH, tenMH);
			return;
		}
	}
}
void xoaMonHoc(DanhSachMonHoc &dsmh,char maMH[])
{
	for(int i=0;i<dsmh.sl;i++)
	{
		if(strcmp(dsmh.ds[i]->maMH,maMH)==0)
		{
			for(int j=i;j<dsmh.sl-1;j++)
			{
				dsmh.ds[j] = dsmh.ds[j+1];
			}
			dsmh.sl--;
			return;
		}
	}
}
void ghiFileDSMonHoc(DanhSachMonHoc dsmh)
{
	fstream outputFile;
	outputFile.open("MonHoc.txt", ios::out);
	outputFile<<dsmh.sl<<endl;
	for(int i=0;i<dsmh.sl;i++)
	{
		outputFile<<dsmh.ds[i]->maMH<<endl;
		outputFile<<dsmh.ds[i]->tenMH<<endl;
	}
	outputFile.close();
}
void docFileDSMonHoc(DanhSachMonHoc &dsmh)
{
	char maMH[200];
	char tenMH[200];
	fstream inputFile;
	inputFile.open("MonHoc.txt",ios::in);
	int  sl=0;
	inputFile>>sl;
	inputFile.ignore();
	for(int i=0;i<sl;i++)
	{
		inputFile.getline(maMH,sizeof(maMH),'\n');
		inputFile.getline(tenMH,sizeof(tenMH),'\n');
		themMonHoc(dsmh,taoMonHoc(maMH,tenMH));
	}
	inputFile.close();
}
