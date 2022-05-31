#include "CauHoi.h"
#include "Lop.h"
using namespace std;
const int H= 700;
const int W=1360;
int MID[1350][680];
void inDSCauHoi(CauHoi *ds,int n,int trang);
void MessageBoxLoi(char *err)
{
    int msgboxID = MessageBox(
        NULL,
       err,
       NULL,
        MB_ICONHAND
    );

}
void khoitaoID()
{
	for(int i=10;i<1350;i++)
	{
		for(int j=10;j<680;j++)
		MID[i][j]=0;
	}
}
void taoID(int x1,int y1,int x2,int y2, int ID)
{
	for(int i=x1;i<x2;i++)
	{
		for(int j=y1;j<y2;j++)
		MID[i][j]=ID;
	}
}
const int ENTER = 13;
const int BACKSPACE = 8;



void button(int x1, int y1, int x2, int y2, int ID, char* s,int cochu, int clbar, int clw)
{
	setfillstyle(1,clbar);
	bar(x1,y1,x2,y2);
	setcolor(clw);
	setbkcolor(clbar);
	settextstyle(0,0,cochu);
	outtextxy(x1+10,y1+10,s);	
	taoID(x1,y1,x2,y2,ID);
	setcolor(15);
	setbkcolor(0);
}
void taoo(int x1,int y1,int x2, int y2, int ID,int mau, int mauvien)
{
	setfillstyle(1,mau);
	bar(x1,y1,x2,y2);
	
	setcolor(mauvien);
	rectangle(x1,y1,x2,y2);
	
	taoID(x1,y1,x2,y2,ID);
	setcolor(15);
	setbkcolor(0);
}
void taodong(int x1,int y1, int docao,int Mangdodai[], int mau, int mauvien,int ID , int socot)
{
	int y2= y1+docao;
	int	x2;
	
	for(int i=0;i<socot;i++)
	{
	    x2=x1+Mangdodai[i];
		taoo(x1,y1,x2,y2,ID,mau,mauvien);
		x1=x2;
	
	}
}
void taobang(int x1,int y1, int docao,int socot,int Mangdodai[], int mau, int mauvien,int soluong, int ID, int trang,char td[][50] )
{
	setcolor(0);
	setbkcolor(mau);
	settextstyle(0,0,2);
	int y=y1;
	for(int i=1;i<=soluong;i++)
	{
		taodong(x1,y1,docao,Mangdodai,mau, mauvien,ID+i,socot);
		if(i!=1)
		{
			char temp[4];
			itoa((i-1)+10*(trang-1),temp,10);
			outtextxy(x1+5,y1+5,temp);
		}
		y1=y1+docao;
		
	}
	for(int i=0;i<socot;i++)
	{
		outtextxy(x1+5,y+5,td[i]);
		x1=x1+Mangdodai[i];
	}
}
void taobang1(int x1,int y1, int docao,int socot,int Mangdodai[], int mau, int mauvien,int soluong, int ID, int trang,char td[][50] )
{
	setcolor(0);
	setbkcolor(mau);
	settextstyle(0,0,2);
	int y=y1;
	for(int i=1;i<=soluong;i++)
	{
		taodong(x1,y1,docao,Mangdodai,mau, mauvien,ID+i,socot);
		y1=y1+docao;
		
	}
	for(int i=0;i<socot;i++)
	{
		outtextxy(x1+5,y+5,td[i]);
		x1=x1+Mangdodai[i];
	}
}

char* doiSangChuoi(int n){
	char s[200];
	if(n==0){
		strcpy(s,"0");
		return s;
	}
	char c[100];
	int i=0;
	while(n>0){
		c[i] = (n%10)+'0';
		n/=10;
		i++;
	}
	
	for(int j=0; j<i; j++){
		s[j] = c[i-j-1];
	}
	s[i]='\0';
	return s;
}

int doiSangSo(char s[]){
	int len = strlen(s);
	int n=0;
	for(int i=0; i<len; i++){
		n = n*10+(s[i]-'0');
	}
	return n;
}

char* doiSangChuoiThuc( float diem){
	char* s = new char[5];
	strcpy(s,"");
	int a = floor(diem);
	char chrA[5]="";
	itoa(a, chrA, 10);
	strcat(s, chrA);
	a = floor(((float)diem-a)*100);
	itoa(a, chrA, 10);
	strcat(s, ".");
	strcat(s, chrA);
}



//#define PATH_FILE "matcngaunhien.txt"




void ScannerMa(char s[],int max, int px ,int py,int ID,int &IDnext)
{
	setcolor(15);
	setbkcolor(0);
	settextstyle(1,0,1);
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
		s[l] ='|';
		s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{
				
				if(c=='-')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='a' && c<='z')
				{
					c=c+'A'-'a';
					s[l] = c;
					l++;
					s[l]=0;
				//	continue;
				}
				
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				outtextxy(px,py,s);	
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);	
				s[l-1] =' ';
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]=0;
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}
void ScannerString(char s[],int max, int px ,int py,int ID,int &IDnext)
{
	setcolor(15);
	setbkcolor(0);	
	settextstyle(1,0,1);
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
{ 
         delay(0.1);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			cout<<" thoat";
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{
				if((l==0||s[l-1]==' '))
				{
					if(c<='z'&&c>='a')
					c=c+'A'-'a';
					else
					c=c;
					
				}
				else if(c<='Z'&&c>='A')
				c=c-'A'+'a';
				if(c=='_')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(l>0) if(s[l-1]!=' ' && c == ' ')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if((l==0||s[l-1]==' ')&&(s[l]>='a'||s[l]<='z'))
				s[l]=s[l]+'A'-'a';
				s[l+1]=0;
				outtextxy(px,py,s);	
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);	
				s[l-1] =' ';
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]=0;
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}
void ScannerNoiDung(char s[],int max, int px ,int py,int ID,int &IDnext)
{
	setcolor(15);
	setbkcolor(0);
	settextstyle(1,0,1);
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
{ 
         delay(0.1);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			cout<<" thoat";
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{
				if(l==0)
				{
					if(c<='z'&&c>='a')
					c=c+'A'-'a';
					else
					c=c;
					
				}
				else if(c<='Z'&&c>='A')
				c=c-'A'+'a';
				if(c=='_')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>=' ' && c<='/')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>=':' && c<'@')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(l>0) if(s[l-1]!=' ' && c == ' ')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if((l==0||s[l-1]==' ')&&(s[l]>='a'||s[l]<='z'))
				s[l]=s[l]+'A'-'a';
				s[l+1]=0;
				outtextxy(px,py,s);	
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);	
				s[l-1] =' ';
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]=0;
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}

void ScannerName(char s[],int max, int px ,int py,int ID, int &IDnext)
{
	setcolor(15);
	setbkcolor(0);
	settextstyle(1,0,1);
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{

				if((l==0||s[l-1]==' '))
				{
					if(c<='z'&&c>='a')
					c=c+'A'-'a';
					else
					c=c;
					
				}
				else if(c<='Z'&&c>='A')
				c=c-'A'+'a';

				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
					s[l]=0;
				}
				
				if(l>0) if(s[l-1]!=' ' && c == ' ')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l-1] =' ';
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]='\0';
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}

int ScannerNum(char s[], int max, int px ,int py,int ID, int &IDnext)
{
	setcolor(15);
	setbkcolor(0);
	settextstyle(1,0,1);

	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{
				
			char c = getch();
			
			if(l<max)
			{
				
				if(c>='0' && c<='9')
				{
					s[l] = c;
					s[l+1]=0;
				 outtextxy(px,py,s);
					l++;
				}
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0){
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l-1] =' ';
			
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]='\0';
		}
	}
	if((mx!=-1)&&(my!=-1)) 
	IDnext=MID[mx][my];
}

int ScannerFloat(char s[], int max, int px ,int py,int ID, int &IDnext)
{
	setcolor(15);
	setbkcolor(0);
	settextstyle(1,0,1);

	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{
				
			char c = getch();
			
			if(l<max)
			{
				
				if(c>='0' && c<='9' || c=='.')
				{
					s[l] = c;
					s[l+1]=0;
				 outtextxy(px,py,s);
					l++;
				}
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0){
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l-1] =' ';
			
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]='\0';
		}
	}
	if((mx!=-1)&&(my!=-1)) 
	IDnext=MID[mx][my];
}
void xoamanhinh(){
	setcolor(0);
	setbkcolor(15);
	cleardevice();
	khoitaoID();
}
void manHinhChinh()
{
	setcolor(15);
	setbkcolor(0);
	cleardevice();
	khoitaoID();
}

void manDangNhap()
{
	manHinhChinh();
	settextstyle(10,HORIZ_DIR,8);
	outtextxy(280,50," THI TRAC NGHIEM ");
	settextstyle(10,HORIZ_DIR,4);
	outtextxy(250,300,"MSSV: ");
	taoo(500,300,1000,350,1,15,3);
	settextstyle(10,HORIZ_DIR,4);
	setcolor(15);
	outtextxy(250,400,"MAT KHAU: ");
	taoo(500,400,1000,450,2,15,3);
	button(680,500,850,540,3,"DANG NHAP",2,15,3);
}
void manGiaoVien()
{
	manHinhChinh();
	settextstyle(10,HORIZ_DIR,8);
	outtextxy(280,50," THI TRAC NGHIEM ");
	button(500,150,900,200,1,"QUAN LY LOP",2,9,0);
	button(500,220,900,270,2,"QUAN LY SINH VIEN",2,10,0);
	button(500,290,900,340,3,"QUAN LY MON HOC",2,11,0);
	button(500,360,900,410,4,"QUAN LY CAU HOI THI",2,12,0);
	button(500,430,900,480,5,"QUAN LY DIEM THI",2,14,0);
	button(500,500,900,550,6,"THI TRAC NGHIEM",2,7,0);
	button(500,570,900,620,7,"THOAT",2,6,0);
}
void manQuanLyCauHoi()
{
	manHinhChinh();
	settextstyle(10,HORIZ_DIR,4);
	outtextxy(550,20," Quan ly cau hoi ");
	settextstyle(10,HORIZ_DIR,3);
	button(20,20,100,60,9999,"Back",2,12,15);
	
	outtextxy(60,90," Ma Cau Hoi: ");
	taoo(280,80,600,120,41,15,3);
	
//	button(620,80,700,120,42,"Tìm",2,11,3);
	
	button(800,80,900,120,43,"Thêm",2,12,3);
	
	button(1000,80,1100,120,44,"Sua",2,13,3);
	
	button(1200,80,1300,120,45,"Xóa",2,14,3);
	
	button(0,660,100,700,1111,"<<<",2,12,0);
	button(1250,660,1350,700,1112,">>>",2,12,0);
	
}
void bangCauHoi(int trang)
{
	int m[4]={55,100,1120,50};
	char td[][50]=
	{
		"ID",
		"MAMH",
		"NOIDUNG",
		"DA",
	};
	
	taobang1(20,150,40,4,m,0,15,11,3999,trang,td);
}
void inDanhSachCauHoi(DanhSachCauHoi dsch,int sl,int trang)
{
	int dem = 0;
	CauHoi ch[sl];
	danhSachCauHoiTuyenTinh(dsch.root,ch,dem);
	bangCauHoi(trang);
	
	if(sl==0)
	{
		return ;
	}
	int x,y,d;
	x=20;
	y=195;
	d=40;
	char buffer[20];
	
	for(int i=(trang-1)*10;i<(trang-1)*10+10&&i<sl;i++)
	{
	    itoa(ch[i].id,buffer,10);
		outtextxy(5+x,y+((i-(trang-1)*10)*40), buffer);
		outtextxy(10+x+50,y+((i-(trang-1)*10)*40), ch[i].maMH);
		outtextxy(10+x+50+100,y+((i-(trang-1)*10)*40), ch[i].noiDung);
//		outtextxy(10+x+50+100+400,y+((i-(trang-1)*10)*40), ch[i].dapAnA);
//		outtextxy(10+x+50+100+400+180,y+((i-(trang-1)*10)*40), ch[i].dapAnB);
//		outtextxy(10+x+50+100+400+180+180,y+((i-(trang-1)*10)*40), ch[i].dapAnC);
//		outtextxy(10+x+50+100+400+180+180+180,y+((i-(trang-1)*10)*40), ch[i].dapAnD);
    	outtextxy(10+x+50+100+400+180+180+180+180,y+((i-(trang-1)*10)*40), ch[i].dapAnDung);
	}
	delete ch;
}

void manThemCauHoi()
{
	manHinhChinh();
	settextstyle(10,HORIZ_DIR,4);
	outtextxy(550,20," Them cau hoi ");
	settextstyle(10,HORIZ_DIR,3);
	button(20,20,100,60,99999,"Back",2,12,15);
	
	outtextxy(60,110," Ma mon hoc: ");
	taoo(300,110,1200,140,431,11,3);
	
	outtextxy(60,170," Noi dung: ");
	taoo(300,160,1200,280,432,11,3);
	
	outtextxy(60,330," A: ");
	taoo(300,320,1200,360,433,11,3);
	
	outtextxy(60,390," B: ");
	taoo(300,380,1200,420,434,11,3);
	
	outtextxy(60,450," C: ");
	taoo(300,440,1200,480,435,11,3);
	
	outtextxy(60,510," D: ");
	taoo(300,500,1200,540,436,11,3);
	
	outtextxy(60,570," Dap an: ");
	taoo(300,560,1200,600,437,11,3);
	
	button(600,620,850,660,438,"Them cau hoi",2,2,3);
}
void manSuaCauHoi()
{
	manHinhChinh();
	settextstyle(10,HORIZ_DIR,4);
	outtextxy(550,20," Sua cau hoi ");
	settextstyle(10,HORIZ_DIR,3);
	button(20,20,100,60,9999,"Back",2,12,15);
	
	outtextxy(60,110," Ma mon hoc: ");
	taoo(300,110,1200,140,441,11,3);
	
	outtextxy(60,170," Noi dung: ");
	taoo(300,160,1200,280,442,11,3);
	
	outtextxy(60,330," A: ");
	taoo(300,320,1200,360,443,11,3);
	
	outtextxy(60,390," B: ");
	taoo(300,380,1200,420,444,11,3);
	
	outtextxy(60,450," C: ");
	taoo(300,440,1200,480,445,11,3);
	
	outtextxy(60,510," D: ");
	taoo(300,500,1200,540,446,11,3);
	
	outtextxy(60,570," Dap an: ");
	taoo(300,560,1200,600,447,11,3);
	
	button(600,620,850,660,448,"Sua cau hoi",2,2,3);
}
void manQuanLyMonHoc()
{
	manHinhChinh();
	settextstyle(10,HORIZ_DIR,4);
	outtextxy(550,20," Quan ly mon hoc ");
	settextstyle(10,HORIZ_DIR,3);
	button(20,20,100,60,9999,"Back",2,12,15);
	
	outtextxy(60,120," Ma mon hoc: ");
	taoo(300,110,1200,140,31,11,3);
	
	outtextxy(60,170," Ten mon hoc: ");
	taoo(300,160,1200,200,32,11,3);
	
	//button(400,220,500,260,33,"Tìm",2,11,3);
	
	button(600,220,700,260,34,"Thêm",2,12,3);
	
	button(800,220,900,260,35,"Sua",2,13,3);
	
	button(1000,220,1100,260,36,"Xóa",2,14,3);
	
	button(0,660,100,700,1111,"<<<",2,12,0);
	button(1250,660,1350,700,1112,">>>",2,12,0);
	
}
void bangMonHoc(int trang)
{
	int m[3]={100,300,500};
	char td[][50]=
	{
		"STT",
		"MA MON HOC",
		"TEN MON HOC",
	};
	taobang(300,300,35,3,m,0,15,11,2999,trang,td);	
}
void inDanhSachMonHoc(DanhSachMonHoc dsmh,int trang)
{
	bangMonHoc(trang);
	
	if(dsmh.sl==0) return ;
	for (int i = (trang-1)*10; i < dsmh.sl&&i<(trang-1)*10 +10; i++)
	{	
		outtextxy(405,345+((i-(trang-1)*10)*35), dsmh.ds[i]->maMH);
		outtextxy(705,345+((i-(trang-1)*10)*35), dsmh.ds[i]->tenMH);
	}
}
void khungThiSinhVien(SINHVIEN sv){
	manHinhChinh();
	rectangle(5,5,1359,690);
	rectangle(5,5,300,690);
	button(10,10,295,60,0,"THI TRAC NGHIEM",2,11,0);
	button(10,70,295,120,999999,"THOAT",2,12,0);
	char ten[40]="";
	strcat(ten, sv.HO);
	strcat(ten," ");
	strcat(ten,sv.TEN);
	outtextxy(10,150,sv.MASV);
	outtextxy(10,190,ten);
	
	rectangle(300,5,1359,200);
	outtextxy(310,10,"MA MON: ");
	taoo(450,10,800,50,61,15,0);
	outtextxy(810,10,"TEN MON: ");	
    taoo(950,10,1350,50,62,15,0);
    outtextxy(310,55,"THOI GIAN: ");
	taoo(490,55,800,95,63,15,0);
	outtextxy(810,55,"SO LUONG: ");	
 	taoo(950,55,1350,95,64,15,0);
    button(600,150,750,190,666,"BAT DAU",2,12,0);
  	rectangle(760,150,910,190);
  	button(310,655,390,690,1111,"<<<<",2,12,0);
    button(1270,655,1350,690,1112,">>>>",2,12,0);
    
}
void noiDungCauHoiSinhVien(int vt, CauHoi ch, int dachon){
//	setfillstyle(1,15);
//	bar(310,210,1300,500);
  	setbkcolor(0);			
   	setcolor(15);
   	char cau[10]="CAU ";
   	char so[4]="";
   	itoa(vt+1,so,10);
	strcat(cau,so);
	strcat(cau,":");
	outtextxy(310,220,cau); 
	outtextxy(310,255,ch.noiDung);
	button(330,290,360,325,6661,"A",2,9,0);
	button(330,335,360,370,6662,"B",2,9,0);
	button(330,380,360,415,6663,"C",2,9,0);
	button(330,425,360,460,6664,"D",2,9,0);	
	outtextxy(365,290,ch.dapAnA);
	outtextxy(365,335,ch.dapAnB);
	outtextxy(365,380,ch.dapAnC);
	outtextxy(365,425,ch.dapAnD);
	switch(dachon){
		case -1:{
				button(330,290,360,325,6661,"A",2,9,0);
				button(330,335,360,370,6662,"B",2,9,0);
				button(330,380,360,415,6663,"C",2,9,0);
				button(330,425,360,460,6664,"D",2,9,0);
			break;
		}
		case 1:{
				button(330,290,360,325,6661,"A",2,2,0);
			break;
		}
		case 2:{
				button(330,335,360,370,6662,"B",2,2,0);
			
			break;
		}
		case 3:{
				button(330,380,360,415,6663,"C",2,2,0);
			
			break;
		}
		case 4:{
				button(330,425,360,460,6664,"D",2,2,0);
			break;
		}
	}	 	
}
void manThiTracNghiem()
{
	manHinhChinh();
	settextstyle(10,HORIZ_DIR,4);
	outtextxy(550,20," Quan ly sinh vien ");
	settextstyle(10,HORIZ_DIR,3);
	button(20,20,100,60,9999,"Back",2,12,15);
	
	outtextxy(60,75," Ma Mon: ");
	taoo(270,70,600,100,61,11,3);
	
	outtextxy(700,75," Ten Mon: ");
	taoo(900,70,1300,100,62,11,3);
	
	outtextxy(60,130," Thoi Gian: ");
	taoo(270,120,600,150,63,11,3);
	
	outtextxy(700,130," So Luong: ");
	taoo(900,120,1300,150,64,11,3);
	
	button(450,180,600,220,666,"Bat Dau",2,12,0);
	taoo(620,180,800,220,65,11,3);
	
	button(0,660,100,700,1111,"<<<",2,12,0);
	button(1250,660,1350,700,1112,">>>",2,12,0);
}
void veThoiGian(int s){
	setbkcolor(0);
	setcolor(15);
	char tg[10]="", cmin[10]="", csec[10]="";	
	int min = s/60;
    itoa(min,cmin,10);
	int sec = s%60;
	itoa(sec,csec,10);
	strcpy(tg, cmin);
	strcat(tg, ":");
	strcat(tg, csec);
	outtextxy(700,200, tg);
	cout<<tg;
}
void veThoiGianSinhVien(int s){
	setbkcolor(0);
	setcolor(15);
	char tg[10]="", cmin[10]="", csec[10]="";	
	int min = s/60;
    itoa(min,cmin,10);
	int sec = s%60;
	itoa(sec,csec,10);
	strcpy(tg, cmin);
	strcat(tg, ":");
	strcat(tg, csec);
	outtextxy(800,170, tg);
	cout<<tg;
}
void noiDungCauHoi(int vitri,CauHoi ch,int dapan)
{
  	setfillstyle(1,0);
	bar(0,220,1300,600);
	char cau[10]="CAU ";
	char so[4]="";
	itoa(vitri+1,so,10);
	strcat(cau,so);
	strcat(cau,":"); 
	outtextxy(60,220,cau);
	outtextxy(60,260,ch.noiDung);
	button(60,380,100,420,6661,"A",2,12,0);
	outtextxy(120,380,ch.dapAnA);
	button(60,460,100,500,6662,"B",2,12,0);
	outtextxy(120,460,ch.dapAnB);
	button(60,540,100,580,6663,"C",2,12,0);
	outtextxy(120,540,ch.dapAnC);
	button(60,620,100,660,6664,"D",2,12,0);
	outtextxy(120,620,ch.dapAnD);
	switch(dapan){
		case -1:{
				button(60,380,100,420,6661,"A",2,9,0);
				button(60,460,100,500,6662,"B",2,9,0);
				button(60,540,100,580,6663,"C",2,9,0);
				button(60,620,100,660,6664,"D",2,9,0);
			break;
		}
		case 1:{
				button(60,380,100,420,6661,"A",2,2,0);
			break;
		}
		case 2:{
				button(60,460,100,500,6662,"B",2,2,0);
			
			break;
		}
		case 3:{
				button(60,540,100,580,6663,"C",2,2,0);
			
			break;
		}
		case 4:{
				button(60,620,100,660,6664,"D",2,2,0);
			break;
		}
	}	 	
}
void bangLopHoc(int trang)
{
	int m[3]={100,300,500};
	char td[][50]=
	{
		"STT",
		"MA LOP HOC",
		"TEN LOP HOC",
	};
	
	taobang(300,300,35,3,m,0,15,11,999,trang,td);	
}

void doDataVaoBangLopHoc (dsLOP ds,int trang)
{
	bangLopHoc(trang);
	if (ds.sl == 0)
	{
		return;
	}
	for (int i = (trang-1)*10; i < ds.sl&&i<(trang-1)*10 +10; i++)
	{
		outtextxy(405, 340 + ((i-(trang-1)*10)*35), ds.lop[i].MALOP);
		
		outtextxy(705, 340 + ((i-(trang-1)*10)*35), ds.lop[i].TENLOP);
	}
}

void manQuanLyLopHoc(int trang)
{
	manHinhChinh();

	settextstyle(10,HORIZ_DIR,4);
	outtextxy(550,20," Quan ly lop hoc ");
	settextstyle(10,HORIZ_DIR,3);
	button(20,20,100,60,9999,"Back",2,12,15);
	
	outtextxy(60,120," Ma lop hoc: ");
	taoo(300,110,1200,140,11,11,3);
	
	outtextxy(60,170," Ten lop hoc: ");
	taoo(300,160,1200,200,12,11,3);
	
//	button(400,220,500,260,13,"Tìm",2,11,3);
	
	button(600,220,700,260,14,"Thêm",2,12,3);
	
	button(800,220,900,260,15,"Sua",2,13,3);
	
	button(1000,220,1100,260,16,"Xóa",2,14,3);
	
	button(200,650,280,690,1111,"<<<",2,12,15);
	button(1220,650,1300,690,1112,">>>",2,12,15);
	bangLopHoc(trang);
}

void bangSinhVien(int trang)
{
	int m[4]={120,300,300,300};
	char td[][50]=
	{
		"STT",
		"MA SINH VIEN",
		"HO TEN",
		"GIOI TINH",
	};
	
	taobang(200,320,35,4,m,0,15,11,1999,trang,td);	
}

void inDanhSachSinhVien(dsSINHVIEN ds, int trang){
    bangSinhVien(trang);
    char hoten[50] = ""; 
	nodeSINHVIEN *node = ds.pHead;
	for(int i = 0; i < ds.sl; i++){
		if((trang-1)*10<=i&&i<(trang-1)*10 +10){
			strcpy(hoten,"");
	strcat(hoten,node->data.HO);
	strcat(hoten," ");
	strcat(hoten,node->data.TEN);
	outtextxy(325,360 + ((i-(trang-1)*10)*35),node->data.MASV);
	outtextxy(625,360 + ((i-(trang-1)*10)*35),hoten);
	outtextxy(930,360 + ((i-(trang-1)*10)*35),node->data.PHAI);
		}
	
	node = node->pNext;
	}
}
void inDanhSachSinhVienThuocLop(dsLOP dslop, char* malop,int trang){

	for(int i=0;i<dslop.sl;i++){
		if(strcmp(dslop.lop[i].MALOP,malop)==0){
		  inDanhSachSinhVien(dslop.lop[i].dssv,trang);
		}
	}
}
void manQuanLySinhVien()
{
	manHinhChinh();
	outtextxy(550,20," Quan ly sinh vien ");
	
	button(20,20,100,60,9999,"Back",2,12,15);
	
	outtextxy(60,75," Ma Lop: ");
	taoo(200,70,600,100,20,11,3);
	
	outtextxy(700,75,"Ten Lop: ");
	taoo(850,70,1300,100,299,11,3);
	
	outtextxy(60,75 + 50," MSSV: ");
	taoo(200,70+ 50,600,100+ 50,21,11,3);
	
	outtextxy(700,75 + 50," MK: ");
	taoo(850,70+ 50,1300,100+ 50,22,11,3);
	
	outtextxy(60,130+ 50," Ho: ");
	taoo(200,120+ 50,600,150+ 50,23,11,3);
	
	outtextxy(700,130+ 50," Ten: ");
	taoo(850,120+ 50,1300,150+ 50,24,11,3);
	
	outtextxy(450,170+ 50," Phai: ");
	button(600,160+ 50,700,200+ 50,25,"Nam",2,11,3);
	button(750,160+ 50,850,200+ 50,26,"Nu",2,11,3);
	
	button(400,220+ 50,500,260+ 50,27,"Tìm",2,11,3);
	
	button(600,220+ 50,700,260+ 50,28,"Thêm",2,12,3);

	button(800,220+50,900,260+50,29,"Sua",2,13,3);

	button(1000,220+50,1100,260+50,27,"Xóa",2,14,3);
	button(0,660,100,700,1111,"<<<",2,12,0);
	button(1250,660,1350,700,1112,">>>",2,12,0);
}
void bangDiemThi(int trang)
{
	int m[4]={200,300,400,200};
	char td[][50]=
	{
		"STT",
		"MSSV",
		"HO VA TEN",
		"DIEM",
	};
	taobang(150,300,35,4,m,0,15,11,4999,trang,td);	
}
void manQuanLyDiemThi(int trang)
{
	manHinhChinh();

	settextstyle(10,HORIZ_DIR,4);
	outtextxy(550,20," Quan ly diem thi ");
	settextstyle(10,HORIZ_DIR,3);
	button(20,20,100,60,9999,"Back",2,12,15);
	
	outtextxy(60,75," Ma Lop: ");
	taoo(270,70,600,100,51,11,3);
	
	outtextxy(700,75," Ten Lop: ");
	taoo(900,70,1300,100,52,11,3);
	
	outtextxy(60,130," Ma Mon: ");
	taoo(270,120,600,150,53,11,3);
	
	outtextxy(700,130," Ten Mon: ");
	taoo(900,120,1300,150,54,11,3);
	
	button(450,180,600,220,55,"Xem Diem",2,12,0);
	
	button(0,660,100,700,1111,"<<<",2,12,0);
	button(1250,660,1350,700,1112,">>>",2,12,0);

	bangDiemThi(trang);
}
void inDanhSachDiem(dsLOP dsl,char *malop,char *mamon,int trang)
{
	bangDiemThi(trang);

	LOP loptam = timLop(dsl,malop);
	nodeSINHVIEN *nodetam = loptam.dssv.pHead;
	char hoten[50] = ""; 
	if(strcmp(loptam.MALOP,"")==0)
	{
		return;
	}
	for (int i = (trang-1)*10; i < dsl.sl&&i<(trang-1)*10 +10; i++)
	{
		if(nodetam==NULL)
		{
			return;
		}
		else
		{
		strcpy(hoten,"");
		strcat(hoten,nodetam->data.HO);
		strcat(hoten," ");
		strcat(hoten,nodetam->data.TEN);
		outtextxy(365, 345 + ((i-(trang-1)*10)*35), nodetam->data.MASV);
		
		outtextxy(660, 345 + ((i-(trang-1)*10)*35) , hoten);
		float diem = timDIEMTHItheoMAMH(nodetam->data.dsdiem,mamon);
		if(diem==-1)
		{
			outtextxy(1055, 345 +((i-(trang-1)*10)*35) , "Chua thi" );
		}
		else
		{
		outtextxy(1055, 345 + ((i-(trang-1)*10)*35) , doiSangChuoiThuc(diem));
		}
		nodetam = nodetam->pNext;
		}
	}
}
