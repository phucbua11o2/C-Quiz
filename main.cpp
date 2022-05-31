 #include "RUN.h"

int main(int argc, char *argv[])
{
	dsLOP dsl;
	DanhSachCauHoi dsch;
	DanhSachMonHoc dsmh;
	SINHVIEN sv;
	docFileDSMonHoc(dsmh);
	docFileDSCauHoi(dsch);
	docFileDSLopSVDiem(dsl);
	initwindow(1360, 720);	
    runLogin(dsl,dsch,dsmh);
	while(!kbhit()) delay(1);
	return 0;
}

