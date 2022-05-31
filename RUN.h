#include"dohoa.h"
void runGiaoVien(dsLOP dsl,DanhSachCauHoi dsch,DanhSachMonHoc dsmh);
void runSinhVien(dsLOP dsl,DanhSachCauHoi dsch,DanhSachMonHoc dsmh,SINHVIEN sv);
void runLogin(dsLOP &dsl,DanhSachCauHoi dsch,DanhSachMonHoc dsmh)
{
   	char masv[15]="";
   	char password[30]="";
   	nodeSINHVIEN *sv = new nodeSINHVIEN;
   	manDangNhap();
   	int mx=-1,my=-1;
   	int key=0;
	while(1)
	{
		delay(0.01);
	    getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		key=MID[mx][my];
		vitritieptheo:
		if(key>0)
		{
		    trolai:
			switch(key)
			{
				case 1:
				{
					ScannerMa(masv,15,500,300,key,key);
					goto vitritieptheo;
				break;
				}
				case 2:
				{
					ScannerMa(password,30,500,400,key,key);
					goto vitritieptheo;
				break;	
				}
				case 3:
				{
					if(strcmp(masv,"")==0 || strcmp(password,"")==0)
					{
						MessageBoxLoi("Vui long dien day du thong tin."); break;
					}
					else if (strcmp(masv,"GV")==0&&strcmp(password,"GV")==0)
					{
						runGiaoVien(dsl,dsch,dsmh);
					}
					else
					{
						sv = timKiemTrongTatCaSinhVien(dsl,masv);
						if(sv==NULL)
						{
							MessageBoxLoi("Sinh vien khong ton tai."); break;
						}
						else
						{
							if(strcmp(password,sv->data.password)==0)
							{
								runSinhVien(dsl,dsch,dsmh,sv->data);
							}
							else
							{
								MessageBoxLoi("Sai mat khau."); break;
							}
						}
					}
					break;
				}
				default: 
				{
				break;
				}			
			}
		}
	}
}
void runSinhVien(dsLOP dsl,DanhSachCauHoi dsch,DanhSachMonHoc dsmh,SINHVIEN sv)
{
	khungThiSinhVien(sv);
	char mamh[15]="";
	char soluong[10]="";
	char thoigian[10]="";
	int mx=-1,my=-1;
	int key=0;
	while(1)
	{
		delay(0.01);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		key=MID[mx][my];
		vitritieptheoSV:
		switch(key)
		{
			case 999999:
			{
				runLogin(dsl,dsch,dsmh);
				goto vitritieptheoSV;
				break;
			}
			case 61:
			{
				ScannerMa(mamh,15,450,10,key,key);
				goto vitritieptheoSV;
				break;
			}
			case 62:
			{
				if(strcmp(timKiemMonHoc(dsmh,mamh)->maMH,"")!=0)
				{
					taoo(950,10,1350,50,22,15,0);
					outtextxy(950,10,timKiemMonHoc(dsmh,mamh)->tenMH);
				}
				else
				{
					MessageBoxLoi("Ma mon hoc khong ton tai.");
				}
				break;
			}
			case 63:
			{
				ScannerNum(thoigian,10,490,55,key,key);
				goto vitritieptheoSV;
				break;	
			}
			case 64:
			{
				ScannerNum(soluong,10,950,55,key,key);
				goto vitritieptheoSV;
				break;		
			}
			case 666:
			{
				int vt=0;
				int dem;
				int mangdapan[atoi(soluong)];
				for(int i=0;i<atoi(soluong);i++)
				{
					mangdapan[i]=-1;	
				}
				CauHoi *dschthi = new CauHoi[dsch.soLuong];
									
				dschthi=layDanhSachCauHoiRand(atoi(soluong),dsch,mamh,dem);
				if(dschthi== NULL)
				{				
					MessageBoxLoi("So luong cau hoi khong du");
				}
				else
				{
					int mangrd[dem];
					layMangRad(dem,mangrd);
					button(600,150,750,190,666,"NOP BAI",2,12,0);
					int demtg=0,demnguoc=atoi(thoigian)*60;
					noiDungCauHoiSinhVien(vt,dschthi[mangrd[vt]],mangdapan[vt]);
									
					while (1) 
					{
						delay(0.0001);
						demtg++;
						if(demtg==60)
						{
							veThoiGianSinhVien(demnguoc--);
							demtg=0;
							if(demnguoc==0)
							{
								key=6;
								goto vitritieptheoSV;
							}
						}
							getmouseclick(WM_LBUTTONDOWN, mx, my);
							clearmouseclick(WM_LBUTTONDOWN);
							key = MID[mx][my];
							switch (key)
							{
								case 666:
								{
									float diem =tinhDiem(dschthi,mangdapan,atoi(soluong),mangrd);
									char mss[30]=" ban dat duoc ";
									strcat(mss,doiSangChuoiThuc(diem));
									MessageBoxLoi(mss);
									themDiemVaoSinhVienOLop(dsl,sv.MASV,taodataDIEMTHI(mamh,diem));
									ghiFileDSLopSVDiem(dsl);
									key=6;
									goto vitritieptheoSV;
									break;
								}
								case 6661:
								case 6662:
								case 6663:
								case 6664:
								{
									button(330,290,360,325,6661,"A",2,9,0);
							        button(330,335,360,370,6662,"B",2,9,0);
						         	button(330,380,360,415,6663,"C",2,9,0);
						        	button(330,425,360,460,6664,"D",2,9,0);
						        	if(key-6660==1){
						        		button(330,290,360,325,6661,"A",2,2,0);
							             
									}
									if(key-6660==2){
										   button(330,335,360,370,6662,"B",2,2,0);
						         
									}
									if(key-6660==3){
											button(330,380,360,415,6663,"C",2,2,0);
						        
									}
									if(key-6660==4){
											button(330,425,360,460,6664,"D",2,2,0);
									}
									mangdapan[vt]=key-6660;
									break;
								}
								case 1111:
								{
									if(	vt<1) break;
									vt--;
									noiDungCauHoiSinhVien(vt,dschthi[mangrd[vt]],mangdapan[vt]);
									break;
								}
								case 1112:
								{
									if(vt==(atoi(soluong))-1) break;
									vt++;
									noiDungCauHoiSinhVien(vt,dschthi[mangrd[vt]],mangdapan[vt]);
									break;
								}
													
							}
						}
														
					}
					break;
				}
//				default:
//				{
//					if(key==1||key==2||key==3||key==4||key==5||key==6||key==7)
//					goto vitritieptheo6;
//					break;
//				}
			}
		}
	
}
void runGiaoVien(dsLOP dsl,DanhSachCauHoi dsch,DanhSachMonHoc dsmh)
{
	CauHoi* ch;
	MonHoc* mh;
	SINHVIEN sv; 
	int demch=0;
	manGiaoVien();
	int mx=-1,my=-1;
	int key=0;
	while(1)
	{
		delay(0.01);
	    getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		key=MID[mx][my];
		vitritieptheo:
		if(key>0)
		{
		    trolai:
			switch(key)
			{
				case 1:
					{
						int tranglop=1;
						char malop[15]="";
						char tenlop[30]="";
						manQuanLyLopHoc(tranglop);
						doDataVaoBangLopHoc(dsl,tranglop);
						while(1)
						{
							
							delay(0.01);
						    getmouseclick(WM_LBUTTONDOWN,mx,my);
							clearmouseclick(WM_LBUTTONDOWN);
							key=MID[mx][my];
							vitritieptheo1:
							if(key>0)
							{
							    trolai1:
								switch(key)
								{
									case 9999:
										{
											manGiaoVien();
											goto vitritieptheo;
										break;
										}
									case 11:
										{
//											cout<<"vo r11";
										ScannerMa(malop,15,300,110,key,key);
											goto vitritieptheo1;
										break;
										}
									case 12:
										{
//											cout<<"vo r12";
											ScannerString(tenlop,30,300,160,key,key);
											goto vitritieptheo1;
										break;
										}
									case 13:
										{
											
										break;	
										}
									case 14:
										{
											if (strcmp(malop, "")==0 || strcmp(tenlop, "")==0)	
											{
												MessageBoxLoi("Khong de trong."); break;
											}
											if (timvitriLOP(dsl, malop) != -1)
											{
												MessageBoxLoi("Ma lop bi trung."); break;
											}
											else 
											{
												themLOP(dsl, taodataLOP(malop, tenlop));
												MessageBoxLoi("Them thanh cong.");
												doDataVaoBangLopHoc(dsl,tranglop);
												ghiFileDSLopSVDiem(dsl);
											}
										break;		
										}
									case 15:
										{
											if (strcmp(malop, "")==0 || strcmp(tenlop, "")==0)	
											{
												MessageBoxLoi("Khong de trong."); break;
											}
											if (timvitriLOP(dsl, malop) != -1)
											{
												suaLop(dsl, taodataLOP(malop, tenlop));
												MessageBoxLoi("Sua thanh cong.");
												doDataVaoBangLopHoc(dsl,tranglop);	
												ghiFileDSLopSVDiem(dsl);
												break;
											}
											else 
											{
												MessageBoxLoi("Ma lop ko ton tai."); break;
											}
										break;	
										}
									case 16:
										{
											if (strcmp(malop, "")==0 || strcmp(tenlop, "")==0)	
											{
												MessageBoxLoi("Khong de trong."); break;
											}
											if (strcmp(timLop(dsl,malop).MALOP,"")==0)
											{
												MessageBoxLoi("Ma lop ko ton tai."); break;
											}
											if(kiemTraLopCoSinhVien(dsl,malop)==true)
											{
												MessageBoxLoi("Lop co sinh vien khong the xoa.");
											}
											else
											{
												xoaLop(dsl,malop);
												doDataVaoBangLopHoc(dsl,tranglop);	
												ghiFileDSLopSVDiem(dsl);
												MessageBoxLoi("Xoa thanh cong.");
												break;
											}
										break;	
										}
									case 1111:
										{
											if(tranglop>1)
											{
												tranglop--;
												doDataVaoBangLopHoc(dsl,tranglop);
											}
											break;
										}
									case 1112:
										{
											tranglop++;
											doDataVaoBangLopHoc(dsl,tranglop);
											break;
										}
									case 1001: case 1002: case 1003: case 1004: case 1005: case 1006: case 1007: case 1008: case 1009: case 1010:
										{
											if((key-1001)+ (tranglop-1)*10<dsl.sl)
											{
											    taoo(300,110,1200,140,11,11,3);
					                            taoo(300,160,1200,200,12,11,3);
										        strcpy(malop,dsl.lop[(key-1001)+ (tranglop-1)*10].MALOP);
										        strcpy(tenlop,dsl.lop[(key-1001)+ (tranglop-1)*10].TENLOP);
											    outtextxy(300,110,malop);
											    outtextxy(300,160,tenlop);
											}
											break;
										}
										default:
											{
												if(key==1||key==2||key==3||key==4||key==5||key==6||key==7)
												goto vitritieptheo;
												break;
											}
								}
							}
						}
						goto vitritieptheo;
					break;
					}
				case 2:
					{
						int trangsv=1;
						char masv[15]="";
						char ho[30]="";
						char ten[30]="";
						char phai[5]="";
						char pass[50]="";
						char malop[10]="";
						manQuanLySinhVien();
						bangSinhVien(trangsv);
						while(1)
						{
							
							delay(0.01);
						    getmouseclick(WM_LBUTTONDOWN,mx,my);
							clearmouseclick(WM_LBUTTONDOWN);
							key=MID[mx][my];
							vitritieptheo2:
							if(key>0)
							{
							    trolai2:
								switch(key)
								{
									case 9999:
										{
											manGiaoVien();
											goto vitritieptheo;
										break;
										}
									case 20:
										{
											ScannerMa(malop,30,200,70,key,key);
											goto vitritieptheo2;
										break;
										}
									case 21:
										{
											ScannerMa(masv,15,200,120,key,key);
											goto vitritieptheo2;
										break;
										}
									case 22:
										{
											ScannerString(pass,30,850,120,key,key);
											goto vitritieptheo2;
										break;	
										}
									case 23:
										{
											ScannerString(ho,30,200,170,key,key);
											goto vitritieptheo2;
										break;
										}
									case 24:
										{
											ScannerString(ten,30,850,170,key,key);
											goto vitritieptheo2;	
										break;	
										}
									case 25:
									{
											button(600,160+ 50,700,200+ 50,25,"Nam",2,11,3);
	                                        button(750,160+ 50,850,200+ 50,26,"Nu",2,11,3);
	                                        button(600,160+ 50,700,200+ 50,25,"Nam",2,2,3);
	                                        strcpy(phai,"Nam");
										break;
									}
									case 26:
									{
										button(600,160+ 50,700,200+ 50,25,"Nam",2,11,3);
                                    	button(750,160+ 50,850,200+ 50,26,"Nu",2,11,3);
                                    	button(750,160+ 50,850,200+ 50,26,"Nu",2,2,3);
                                    		strcpy(phai,"Nu");
										break;
									}
									case 27:
									{
										if(strcmp(malop,"")==0||strcmp(masv,"")==0||strcmp(ho,"")==0||strcmp(ten,"")==0||strcmp(phai,"")==0||strcmp(pass,"")==0)
										{
											MessageBoxLoi("vui long dien day du thong tin");
										}
										else if(strcmp(timLop(dsl,malop).MALOP,"")==0||timLop(dsl,malop).MALOP==NULL)
										{
											MessageBoxLoi("Lop khong ton tai");
										}
										else if(timKiemTrongTatCaSinhVien(dsl,masv)!=NULL){
											if(	timKiemTrongTatCaSinhVien(dsl,masv)->data.dsdiem.sl>0)
										 	MessageBoxLoi("Sinh vien nay khong xoa duoc");
									        else{
									        	  	xoaSinhVienTrongLop(dsl,malop,masv);
									        		MessageBoxLoi("Xoa thanh cong");
									        		inDanhSachSinhVienThuocLop(dsl,malop,trangsv);
													ghiFileDSLopSVDiem(dsl);
											}
										}
										
									break;
									}
									case 28:
										{
											if (strcmp(masv, "")==0 || strcmp(ho, "")==0 || strcmp(ten, "")==0 || strcmp(phai, "")==0 || strcmp(pass, "")==0)	
											{
												MessageBoxLoi("Khong de trong."); break;
											}
											else if(strcmp(timLop(dsl,malop).MALOP,"")==0||timLop(dsl,malop).MALOP==NULL)
											{
												MessageBoxLoi("Lop khong ton tai."); break;
											}
											else if(timKiemTrongTatCaSinhVien(dsl,masv)!=NULL)
											{
												MessageBoxLoi("Ma so sinh vien da ton tai");
											}
											else 
											{
												themSVvaoLop(dsl, malop, taodataSINHVIEN(masv, ho, ten, phai, pass));
												MessageBoxLoi("Them thanh cong.");
												inDanhSachSinhVienThuocLop(dsl,malop,trangsv);
												ghiFileDSLopSVDiem(dsl);
											}
										break;	
										}
									case 29:
										{
											if(strcmp(malop,"")==0||strcmp(masv,"")==0||strcmp(ho,"")==0||strcmp(ten,"")==0||strcmp(phai,"")==0||strcmp(pass,"")==0)
											{
												MessageBoxLoi("vui long dien day du thong tin");
											}
											else if(strcmp(timLop(dsl,malop).MALOP,"")==0||timLop(dsl,malop).MALOP==NULL)
											{
												MessageBoxLoi("Lop khong ton tai");
											}
											else
											{
												suaSinhVienTrongLop(dsl,malop,masv,ho,ten,phai,pass);
												MessageBoxLoi("Sua thanh cong");
												inDanhSachSinhVienThuocLop(dsl,malop,trangsv);
												ghiFileDSLopSVDiem(dsl);	
											}
										break;
										}
									case 299:
										{
											LOP lop;
											lop = timLop(dsl,malop);
											if(strcmp(lop.MALOP,"")==0||lop.MALOP==NULL)
											{
												MessageBoxLoi("Lop khong ton tai."); break;
											}
										//	outtextxy(700,75,"Ten Lop: ");
											taoo(850,70,1300,100,299,11,3);
											outtextxy(850,70,lop.TENLOP);
											inDanhSachSinhVienThuocLop(dsl,malop,trangsv);
											break;
										}
									case 2000: case 2001: case 2002: case 2003: case 2004: case 2005: case 2006: case 2007: case 2008: case 2009: case 2010:
										{
											SINHVIEN sv= timsinhvientheostt((key-2001)+(trangsv-1)*10,timLop(dsl,malop).dssv);
											cout<<"STT: "<<(key-2001)+(trangsv-1)*10<<endl;
											if(strcmp(sv.MASV,"")!=0){
											taoo(200,70+ 50,600,100+ 50,21,11,3);
											taoo(850,70+ 50,1300,100+ 50,22,11,3);
											taoo(200,120+ 50,600,150+ 50,23,11,3);
											taoo(850,120+ 50,1300,150+ 50,24,11,3);
											button(600,160+ 50,700,200+ 50,25,"Nam",2,11,3);
											button(750,160+ 50,850,200+ 50,26,"Nu",2,11,3);
											outtextxy(200,70+ 50,sv.MASV);
											outtextxy(850,70+ 50,sv.password);
											outtextxy(200,120+ 50,sv.HO);
											outtextxy(850,120+ 50,sv.TEN);
						                    if(strncmp(sv.PHAI,"Nam",3)==0)
						                    {
						                    button(600,160+ 50,700,200+ 50,25,"Nam",2,9,15);
						                	}
											else
											{
						                    button(750,160+ 50,850,200+ 50,26,"Nu",2,9,15);
						                	}
											strcpy(masv,sv.MASV);
						                    strcpy(ho,sv.HO);
						                    strcpy(ten,sv.TEN);
						                    strcpy(phai,sv.PHAI);
						                    strcpy(pass,sv.password);
											}
						            
											break;
										}
									case 1112:
										{
										    trangsv++;
										    inDanhSachSinhVienThuocLop(dsl,malop,trangsv);
											break;
										}
										case 1111:{
											if(trangsv>1)
											trangsv--;
											inDanhSachSinhVienThuocLop(dsl,malop,trangsv);
											break;
										}
										default:{
											if(key==1||key==2||key==3||key==4||key==5||key==6||key==7)
											goto vitritieptheo;
											break;
										}
								}
							}
						}		
						goto vitritieptheo;
					break;
					}
				case 3:
					{
						int trangmon =1;
						char mamh[15]="";
						char tenmh[30]="";
						manQuanLyMonHoc();
						inDanhSachMonHoc(dsmh,trangmon);
						while(1)
						{
							delay(0.01);
						    getmouseclick(WM_LBUTTONDOWN,mx,my);
							clearmouseclick(WM_LBUTTONDOWN);
							key=MID[mx][my];
							vitritieptheo3:
							if(key>0)
							{
							    trolai3:
								switch(key)
								{
									case 9999:
										{
											manGiaoVien();
											goto vitritieptheo;
										break;
										}
									case 31:
										{
											ScannerMa(mamh,15,300,110,key,key);
											goto vitritieptheo3;
										break;
										}
									case 32:
										{
											ScannerString(tenmh,30,300,160,key,key);
											goto vitritieptheo3;
										break;
										}
//									case 33:
//										{
//											MonHoc *foundMH = timKiemMonHoc(dsmh,mamh);
//											if (strcmp(mamh, "")==0)	
//											{
//												MessageBoxLoi("Khong de trong ma mon hoc."); break;
//											}
//											if(foundMH!=NULL)
//											{
//												cout<<"Ma mh: "<<foundMH->mamh<<endl;
//												cout<<"Ten mh: "<<foundMH->tenmh<<endl;
//											}
//											else
//											{
//												MessageBoxLoi("Ma mon hoc khong ton tai."); break;
//											}
//										break;	
//										}
									case 34:
										{
											MonHoc *foundMH = timKiemMonHoc(dsmh,mamh);
											if (strcmp(mamh, "")==0)	
											{
												MessageBoxLoi("Khong de trong ma mon hoc."); break;
											}
											if (strcmp(tenmh, "")==0)	
											{
												MessageBoxLoi("Khong de trong ten mon hoc."); break;
											}
											if(foundMH==NULL)
											{					
												themMonHoc(dsmh,taoMonHoc(mamh,tenmh));
												ghiFileDSMonHoc(dsmh);
												inDanhSachMonHoc(dsmh,trangmon);
												MessageBoxLoi("Them mon hoc thanh cong.");
												break;
											}
											else
											{
												MessageBoxLoi("Ma mon hoc da ton tai."); break;
											}
										break;		
										}
									case 35:
										{
											MonHoc *foundMH = timKiemMonHoc(dsmh,mamh);
											if (strcmp(mamh, "")==0)	
											{
												MessageBoxLoi("Khong de trong ma mon hoc."); break;
											}
											if (strcmp(tenmh, "")==0)	
											{
												MessageBoxLoi("Khong de trong ten mon hoc."); break;
											}
											else if(foundMH!=NULL)
											{
												suaMonHoc(dsmh,mamh,tenmh);
												ghiFileDSMonHoc(dsmh);
												inDanhSachMonHoc(dsmh,trangmon);
												MessageBoxLoi("Sua mon hoc thanh cong.");
												break;
											}
											else
											{
												MessageBoxLoi("Ma mon hoc khong ton tai."); break;
											}
										break;	
										}
									case 36:
										{
											if(kiemTraMonHocCoCauHoi(dsch.root,mamh)==true)
											{
												MessageBoxLoi("Mon hoc nay khong the xoa duoc.");
											}
											else
											{
											MonHoc *foundMH = timKiemMonHoc(dsmh,mamh);
											if (strcmp(mamh, "")==0)	
											{
												MessageBoxLoi("Khong de trong ma mon hoc."); break;
											}
											if(foundMH!=NULL)
											{
												xoaMonHoc(dsmh,mamh);
												ghiFileDSMonHoc(dsmh);
												inDanhSachMonHoc(dsmh,trangmon);
												MessageBoxLoi("Xoa mon hoc thanh cong.");
												break;
											}
											else 
											{
												MessageBoxLoi("Ma mon hoc khong ton tai."); break;
											}	
											}
										break;	
										}
									case 1111:
										{
											if(trangmon>1)
											{
												trangmon--;
												inDanhSachMonHoc(dsmh,trangmon);
											}
											break;
										}
									case 1112:
										{
											trangmon++;
											inDanhSachMonHoc(dsmh,trangmon);
											break;
										}
									case 3000: case 3001: case 3002: case 3003: case 3004: case 3005: case 3006: case 3007: case 3008: case 3009: case 3010:
										{
										if((key-3001)+(trangmon-1)*10<dsmh.sl)
										{
											strcpy(mamh,dsmh.ds[(key-3001)+(trangmon-1)*10]->maMH);
											strcpy(tenmh,dsmh.ds[(key-3001)+(trangmon-1)*10]->tenMH);
											taoo(300,110,1200,140,31,11,3);
											outtextxy(300,110,mamh);
											taoo(300,160,1200,200,32,11,3);
											outtextxy(300,160,tenmh);
										}
										break;
										}
								}
							}
						}						
						goto vitritieptheo;
					break;
					}
				case 4:
					{
						int trangch =1;
						char id[10]="";
						char maMH[200]="";
						char noiDung[200]="";
						char dapAnA[200]="";
						char dapAnB[200]="";
						char dapAnC[200]="";
						char dapAnD[200]="";
						char dapAnDung[2]="";
						manQuanLyCauHoi();
						inDanhSachCauHoi(dsch,dsch.soLuong,trangch);
						while(1)
							{
								delay(0.01);
							    getmouseclick(WM_LBUTTONDOWN,mx,my);
								clearmouseclick(WM_LBUTTONDOWN);
								key=MID[mx][my];
								vitritieptheo4:
								if(key>0)
								{
									trolai4:
									switch(key)
									{
										case 9999:
											{
											manGiaoVien();
											goto vitritieptheo;
											break;
											}
										case 41:
											{
												ScannerNum(id,10,280,80,key,key);
												goto trolai4;
											}
//										case 42:
//											{
//												int ma = atoi(id);
//												nodeCauHoi *found = findById(dsch,ma);
//												if (strcmp(id, "")==0)	
//												{
//													MessageBoxLoi("Khong de trong id cau hoi."); break;
//												}
//												if(found!=NULL)
//												{
//													cout<<"===========Tim thanh cong==========="<<endl;
//													cout<<found->data.id<<endl;
//													cout<<found->data.mamh<<endl;
//													cout<<found->data.noidung<<endl;
//													cout<<found->data.a<<endl;
//													cout<<found->data.b<<endl;
//													cout<<found->data.c<<endl;
//													cout<<found->data.d<<endl;
//													cout<<found->data.dapan<<endl;
//												}
//												else
//												{
//													MessageBoxLoi("ID khong ton tai."); break;
//												}
//											//	goto trolai1;
//											break;
//											}
										case 43:
											{
												manThemCauHoi();
												while(1)
												{
													delay(0.01);
												    getmouseclick(WM_LBUTTONDOWN,mx,my);
													clearmouseclick(WM_LBUTTONDOWN);
													key=MID[mx][my];
													vitritieptheo43:
													if(key>0)
													{
														trolai43:
														switch(key)
														{
															case 99999:
																{
																manQuanLyCauHoi();
																inDanhSachCauHoi(dsch,dsch.soLuong,trangch);
																goto vitritieptheo4;
																break;
																}
															case 431:
																{
																	ScannerMa(maMH,200,300,110,key,key);
																	goto vitritieptheo43;
																break;
																}
															case 432:
																{
																	ScannerNoiDung(noiDung,200,300,160,key,key);
																	goto vitritieptheo43;
																break;
																}
															case 433:
																{
																	ScannerString(dapAnA,200,300,320,key,key);
																	goto vitritieptheo43;
																break;
																}
															case 434:
																{
																	ScannerString(dapAnB,200,300,380,key,key);
																	goto vitritieptheo43;
																break;
																}
															case 435:
																{
																	ScannerString(dapAnC,200,300,440,key,key);
																	goto vitritieptheo43;
																break;
																}
															case 436:
																{
																	ScannerString(dapAnD,200,300,500,key,key);
																	goto vitritieptheo43;
																break;
																}
															case 437:
																{
																	ScannerMa(dapAnDung,200,300,560,key,key);
																	goto vitritieptheo43;
																break;
																}
															case 438:
																{
																	if (strcmp(maMH, "")==0)	
																	{
																		MessageBoxLoi("Khong de trong maMH cau hoi."); break;
																	}
																	if (strcmp(noiDung, "")==0)	
																	{
																		MessageBoxLoi("Khong de trong noi dung cau hoi."); break;
																	}
																	if (strcmp(dapAnA, "")==0)	
																	{
																		MessageBoxLoi("Khong de trong a."); break;
																	}
																	if (strcmp(dapAnB, "")==0)	
																	{
																		MessageBoxLoi("Khong de trong b."); break;
																	}
																	if (strcmp(dapAnC, "")==0)	
																	{
																		MessageBoxLoi("Khong de trong c."); break;
																	}
																	if (strcmp(dapAnD, "")==0)	
																	{
																		MessageBoxLoi("Khong de trong d."); break;
																	}
																	if (strcmp(dapAnDung, "")==0)	
																	{
																		MessageBoxLoi("Khong de trong dapan cau hoi."); break;
																	}
																	else 
																	{
																		MonHoc *foundMH = timKiemMonHoc(dsmh,maMH);
																		if(foundMH!=NULL)
																		{
																		if(strcmp(dapAnDung,"A")==0||strcmp(dapAnDung,"B")==0||strcmp(dapAnDung,"C")==0||strcmp(dapAnDung,"D")==0)
																		{
																			int id = taoMaCauHoi(dsch.root);
																			dsch.root= Insert(dsch.root,taoCauHoi(id,maMH,noiDung,dapAnA,dapAnB,dapAnC,dapAnD,dapAnDung));
																			dsch.soLuong++;
																			xuatCay(dsch.root);
																		//	inDSCauHoi(dsch,dsch.soLuong,trangch);
																			ghiFileDSCauHoi(dsch);
																			MessageBoxLoi("Them cau hoi thanh cong."); 
																			strcpy(maMH,"") ;
				
																			strcpy(noiDung,"");
																			strcpy(dapAnA,"");
																			strcpy(dapAnB,"");
																			strcpy(dapAnC,"");
																			strcpy(dapAnD,"");
																			strcpy(dapAnDung,"");
																			break;
																		}
																		else
																		{
																			MessageBoxLoi("Dap an chi co the la A hoac B hoac C hoac D."); break;
																		}
																		}
																		else
																		{
																			MessageBoxLoi("Ma mon hoc khong ton tai.");
																		}
																	}
//																	
																break;
																}	
														}
													}
												}
												goto vitritieptheo4;
											break;
											}
										case 44:
											{
												int ma = atoi(id);
												NodeCauHoi *findCH = timCauHoi(dsch,ma);
												if(findCH!=NULL)
												{
													manSuaCauHoi();
													while(1)
													{
														delay(0.01);
													    getmouseclick(WM_LBUTTONDOWN,mx,my);
														clearmouseclick(WM_LBUTTONDOWN);
														key=MID[mx][my];
														vitritieptheo44:
														if(key>0)
														{
															trolai44:
															switch(key)
															{
																case 9999:
																	{
																	manQuanLyCauHoi();
																	goto vitritieptheo4;
																	break;
																	}
																case 441:
																	{
																		ScannerMa(maMH,200,300,110,key,key);
																		goto vitritieptheo44;
																	break;
																	}
																case 442:
																	{
																		ScannerString(noiDung,200,300,160,key,key);
																		goto vitritieptheo44;
																	break;
																	}
																case 443:
																	{
																		ScannerString(dapAnA,200,300,320,key,key);
																		goto vitritieptheo44;
																	break;
																	}
																case 444:
																	{
																		ScannerString(dapAnB,200,300,380,key,key);
																		goto vitritieptheo44;
																	break;
																	}
																case 445:
																	{
																		ScannerString(dapAnC,200,300,440,key,key);
																		goto vitritieptheo44;
																	break;
																	}
																case 446:
																	{
																		ScannerString(dapAnD,200,300,500,key,key);
																		goto vitritieptheo44;
																	break;
																	}
																case 447:
																	{
																		ScannerMa(dapAnDung,200,300,560,key,key);
																		goto vitritieptheo44;
																	break;
																	}
																case 448:
																	{
																		if (strcmp(maMH, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong ma mon hoc cau hoi."); break;
																		}
																		if (strcmp(noiDung, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong noi dung cau hoi."); break;
																		}
																		if (strcmp(dapAnA, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong dap an A."); break;
																		}
																		if (strcmp(dapAnB, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong dap an B."); break;
																		}
																		if (strcmp(dapAnC, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong dap an C."); break;
																		}
																		if (strcmp(dapAnD, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong dap an D."); break;
																		}
																		if (strcmp(dapAnDung, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong dap an cau hoi."); break;
																		}
																		else 
																		{
																			MonHoc *foundMH = timKiemMonHoc(dsmh,maMH);
																		if(foundMH!=NULL)
																		{
																			if(strcmp(dapAnDung,"A")==0||strcmp(dapAnDung,"B")==0||strcmp(dapAnDung,"C")==0||strcmp(dapAnDung,"D")==0)
																			{
																				hieuChinhCauHoiTheoMa(dsch,ma,maMH,noiDung,dapAnA,dapAnB,dapAnC,dapAnD,dapAnDung);
																				ghiFileDSCauHoi(dsch);
																				MessageBoxLoi("Sua cau hoi thanh cong."); break;
																			}
																			else
																			{
																				MessageBoxLoi("Dap an chi co the la A hoac B hoac C hoac D."); break;
																			}
																		}
																		else{
																				MessageBoxLoi("Ma mon khong ton tai."); break;
																		}
																	}
																	break;
																	}	
															}
														}
													}
												}
												else
												{
													MessageBoxLoi("ID cau hoi khong ton tai."); break;
												}
											break;
											}
										case 45:
											{
												if (strcmp(id, "")==0)	
												{
													MessageBoxLoi("Khong de trong id cau hoi."); break;
												}
												CauHoi ch;
												ch.id = atoi(id);
												NodeCauHoi *found = timCauHoi(dsch,atoi(id));
												if(found!=NULL)
												{
													xoaNodeCauHoi(dsch,ch);
													ghiFileDSCauHoi(dsch);
													inDanhSachCauHoi(dsch,dsch.soLuong,trangch);
													MessageBoxLoi("Xoa cau hoi thanh cong."); break;
												}
												else
												{
													MessageBoxLoi("ID cau hoi khong ton tai."); break;
												}
												//goto vitritieptheo4;
											break;
											}
										case 1111:
											{
												if(trangch>1)
												{
													trangch--;
													inDanhSachCauHoi(dsch,dsch.soLuong,trangch);
												}
												break;
											}
										case 1112:
											{
												trangch++;
												inDanhSachCauHoi(dsch,dsch.soLuong,trangch);
												break;
											}
										case 4000: case 4001: case 4002: case 4003: case 4004: case 4005: case 4006: case 4007: case 4008: case 4009: case 4010:
										{
										
											if((key -4001)+(trangch-1)*10<dsch.soLuong)
											{
												manSuaCauHoi();
												int vt =(key -4001)+(trangch-1)*10;
												CauHoi chtam = timCauHoiTheoViTri(dsch.root,vt,dsch.soLuong);
												if(chtam.id!=-1)
												{
												//	cout<<"ID Find: "<<chtam.id<<endl;
													taoo(300,110,1200,140,441,11,3);
													outtextxy(300,110,chtam.maMH);
													taoo(300,160,1200,280,442,11,3);
													outtextxy(300,160,chtam.noiDung);
													taoo(300,320,1200,360,443,11,3);
													outtextxy(300,320,chtam.dapAnA);
													taoo(300,380,1200,420,444,11,3);
													outtextxy(300,380,chtam.dapAnB);
													taoo(300,440,1200,480,445,11,3);
													outtextxy(300,440,chtam.dapAnC);
													taoo(300,500,1200,540,446,11,3);
													outtextxy(300,500,chtam.dapAnD);
													taoo(300,560,1200,600,447,11,3);
													outtextxy(300,560,chtam.dapAnDung);
													strcpy(maMH,chtam.maMH);
													strcpy(noiDung,chtam.noiDung);
													strcpy(dapAnA,chtam.dapAnA);
													strcpy(dapAnB,chtam.dapAnB);
													strcpy(dapAnC,chtam.dapAnC);
													strcpy(dapAnD,chtam.dapAnD);
													strcpy(dapAnDung,chtam.dapAnDung);
													while(1)
													{
														delay(0.01);
													    getmouseclick(WM_LBUTTONDOWN,mx,my);
														clearmouseclick(WM_LBUTTONDOWN);
														key=MID[mx][my];
														vitritieptheo444:
															switch(key)
															{
																case 9999:
																	{
																	manQuanLyCauHoi();
																	goto vitritieptheo4;
																	break;
																	}
																case 441:
																	{
																		ScannerMa(chtam.maMH,200,300,110,key,key);
																		goto vitritieptheo444;
																	break;
																	}
																case 442:
																	{
																		ScannerString(chtam.noiDung,200,300,160,key,key);
																		goto vitritieptheo444;
																	break;
																	}
																case 443:
																	{
																		ScannerString(chtam.dapAnA,200,300,320,key,key);
																		goto vitritieptheo444;
																	break;
																	}
																case 444:
																	{
																		ScannerString(chtam.dapAnB,200,300,380,key,key);
																		goto vitritieptheo444;
																	break;
																	}
																case 445:
																	{
																		ScannerString(chtam.dapAnC,200,300,440,key,key);
																		goto vitritieptheo444;
																	break;
																	}
																case 446:
																	{
																		ScannerString(chtam.dapAnD,200,300,500,key,key);
																		goto vitritieptheo444;
																	break;
																	}
																case 447:
																	{
																		ScannerMa(chtam.dapAnDung,200,300,560,key,key);
																		goto vitritieptheo444;
																	break;
																	}
																case 448:
																	{
																		if (strcmp(chtam.maMH, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong ma mon hoc cau hoi."); break;
																		}
																		if (strcmp(chtam.noiDung, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong noi dung cau hoi."); break;
																		}
																		if (strcmp(chtam.dapAnA, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong dap an A."); break;
																		}
																		if (strcmp(chtam.dapAnB, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong dap an B."); break;
																		}
																		if (strcmp(chtam.dapAnC, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong dap an C."); break;
																		}
																		if (strcmp(chtam.dapAnD, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong dap an D."); break;
																		}
																		if (strcmp(chtam.dapAnDung, "")==0)	
																		{
																			MessageBoxLoi("Khong de trong dap an cau hoi."); break;
																		}
																		else 
																		{
																			MonHoc *foundMH = timKiemMonHoc(dsmh,chtam.maMH);
																		if(foundMH!=NULL)
																		{
																			if(strcmp(chtam.dapAnDung,"A")==0||strcmp(chtam.dapAnDung,"B")==0||strcmp(chtam.dapAnDung,"C")==0||strcmp(chtam.dapAnDung,"D")==0)
																			{
																				hieuChinhCauHoiTheoMa(dsch,chtam.id,chtam.maMH,chtam.noiDung,chtam.dapAnA,chtam.dapAnB,chtam.dapAnC,chtam.dapAnD,chtam.dapAnDung);
																				ghiFileDSCauHoi(dsch);
																				MessageBoxLoi("Sua cau hoi thanh cong."); break;
																			}
																			else
																			{
																				MessageBoxLoi("Dap an chi co the la A hoac B hoac C hoac D."); break;
																			}
																		}
																		else{
																				MessageBoxLoi("Ma mon khong ton tai."); break;
																		}
																	}
																	break;
																	}
															}
													}
												}
											}
										}
									}
								}
							}
						
						goto vitritieptheo;	
					break;
					}
				case 5:
					{
						int trangdiem =1;
						char malop[15]="";
						char maMH[30]="";
						manQuanLyDiemThi(trangdiem);
						while(1)
							{
								delay(0.01);
							    getmouseclick(WM_LBUTTONDOWN,mx,my);
								clearmouseclick(WM_LBUTTONDOWN);
								key=MID[mx][my];
								vitritieptheo5:
								if(key>0)
								{
									trolai5:
									switch(key)
									{
										case 9999:
											{
											manGiaoVien();
											goto vitritieptheo;
											break;
											}
										case 51:
											{
												ScannerMa(malop,15,270,70,key,key);
												goto vitritieptheo5;
												break;
											}
										case 52:
											{
												if(strcmp(timLop(dsl,malop).MALOP,"")!=0)
												{
													outtextxy(900,70,timLop(dsl,malop).TENLOP);
												}
												else
												{
													MessageBoxLoi("Khong tim thay lop."); break;
												}
												break;
											}
										case 53:
											{
												ScannerMa(maMH,30,270,120,key,key);
												goto vitritieptheo5;
												break;
											}
										case 54:
											{
												if(strcmp(timKiemMonHoc(dsmh,maMH)->maMH,"")!=0)
												{
													outtextxy(900,120,timKiemMonHoc(dsmh,maMH)->tenMH);
												}
												else
												{
													MessageBoxLoi("Ma mon hoc khong ton tai."); break;
												}
												break;
											}
										case 55:
											{
												inDanhSachDiem(dsl,malop,maMH,trangdiem);
												break;
											}
										case 1111:
											{
												if(trangdiem>1)
												{
													trangdiem--;
													inDanhSachDiem(dsl,malop,maMH,trangdiem);
												}
												
												break;
											}
										case 1112:
											{
												trangdiem++;
												inDanhSachDiem(dsl,malop,maMH,trangdiem);
												break;
											}
										default:
											{
												if(key==1||key==2||key==3||key==4||key==5||key==6||key==7)
												goto vitritieptheo;
												break;
											}
									}
								}
							}
						goto vitritieptheo;
					break;
					}
				case 6:
					{
						char maMH[15]="";
						char soluong[10]="";
						char thoigian[10]="";
						manThiTracNghiem();
						while(1)
						{
							delay(0.01);
							getmouseclick(WM_LBUTTONDOWN,mx,my);
							clearmouseclick(WM_LBUTTONDOWN);
							key=MID[mx][my];
							vitritieptheo6:
							if(key>0)
							{
								trolai6:
								switch(key)
								{
									case 9999:
									{
										manGiaoVien();
										goto vitritieptheo;
									break;
									}
									case 61:
									{
										ScannerMa(maMH,15,270,70,key,key);
										goto vitritieptheo6;
									break;
									}
									case 62:
									{
										if(strcmp(timKiemMonHoc(dsmh,maMH)->maMH,"")!=0)
										{
											outtextxy(900,70,timKiemMonHoc(dsmh,maMH)->tenMH);
										}
										else
										{
											MessageBoxLoi("Ma mon hoc khong ton tai.");
										}
									break;
									}
									case 63:
									{
										ScannerNum(thoigian,30,270,120,key,key);
										goto vitritieptheo6;
									break;	
									}
									case 64:
									{
										ScannerNum(soluong,30,900,120,key,key);
										goto vitritieptheo6;
									break;		
									}
									case 666:
									{
										int vt=0;
										int dem;
										int mangdapan[atoi(soluong)];
										for(int i=0;i<atoi(soluong);i++)
										{
										mangdapan[i]=-1;	
										}
										CauHoi *dschthi = new CauHoi[dsch.soLuong];
									
										dschthi=layDanhSachCauHoiRand(atoi(soluong),dsch,maMH,dem);
										if(dschthi== NULL)
										{
											
											MessageBoxLoi("So luong cau hoi khong du");
										}
										else
										{
											int mangrd[dem];
											layMangRad(dem,mangrd);
											button(450,180,600,220,666,"NOP BAI",2,12,0);
											int demtg=0,demnguoc=atoi(thoigian)*60;
											noiDungCauHoi(vt,dschthi[mangrd[vt]],mangdapan[vt]);
									
											while (1) 
											{
												delay(0.0001);
												demtg++;
												if(demtg==60)
												{
													veThoiGian(demnguoc--);
													demtg=0;
													if(demnguoc==0)
													{
														key=6;
														goto vitritieptheo6;
													}
												}
												getmouseclick(WM_LBUTTONDOWN, mx, my);
												clearmouseclick(WM_LBUTTONDOWN);
												key = MID[mx][my];
												switch (key)
												{
													case 9999:
														{
															float diem =tinhDiem(dschthi,mangdapan,atoi(soluong),mangrd);
															char mss[30]=" ban dat duoc ";
															strcat(mss,doiSangChuoiThuc(diem));
															MessageBoxLoi(mss);
															manGiaoVien();
															goto vitritieptheo;
															break;
														}
													case 666:
													{
														float diem =tinhDiem(dschthi,mangdapan,atoi(soluong),mangrd);
														char mss[30]=" ban dat duoc ";
														strcat(mss,doiSangChuoiThuc(diem));
														MessageBoxLoi(mss);
														key=6;
														goto vitritieptheo;
														break;
													}
													case 6661:
												    case 6662:
													case 6663:
													case 6664:
													{
														button(60,380,100,420,6661,"A",2,9,0);
												        button(60,460,100,500,6662,"B",2,9,0);
											         	button(60,540,100,580,6663,"C",2,9,0);
											        	button(60,620,100,660,6664,"D",2,9,0);
											        	if(key-6660==1)
														{
											        		button(60,380,100,420,6661,"A",2,2,0);
														}
														if(key-6660==2)
														{
															button(60,460,100,500,6662,"B",2,2,0);
											         
														}
														if(key-6660==3)
														{
															button(60,540,100,580,6663,"C",2,2,0);
														}
														if(key-6660==4)
														{
															button(60,620,100,660,6664,"D",2,2,0);
														}
														mangdapan[vt]=key-6660;
														break;
													}
													case 1111:
													{
														if(	vt<1) break;
														vt--;
														noiDungCauHoi(vt,dschthi[mangrd[vt]],mangdapan[vt]);
														break;
													}
													case 1112:
													{
														if(vt==(atoi(soluong))-1) break;
														vt++;
														noiDungCauHoi(vt,dschthi[mangrd[vt]],mangdapan[vt]);
														break;
													}
													
												}
										    }
														
										}
										break;
									}
									default:
									{
										if(key==1||key==2||key==3||key==4||key==5||key==6||key==7)
											goto vitritieptheo6;
											break;
									}
								}
							}
						}
						goto vitritieptheo;	
					break;
					}
				case 7:
					{
						runLogin(dsl,dsch,dsmh);
						goto vitritieptheo;	
					break;
					}
				default: 
					{
					break;
					}
			}
		}
	}	
}


