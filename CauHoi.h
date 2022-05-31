#include "MonHoc.h"

using namespace std;

struct CauHoi{
	int id;
	char maMH[15];
	char noiDung[300];
	char dapAnA[300];
	char dapAnB[300];
	char dapAnC[300];
	char dapAnD[300];
	char dapAnDung[2];
};

struct NodeCauHoi{
	int height=0;
	CauHoi cauHoi;
	NodeCauHoi *left = NULL;
	NodeCauHoi *right = NULL;
};

struct DanhSachCauHoi{
	NodeCauHoi *root = NULL;
	int soLuong = 0;
};

CauHoi taoCauHoi(int id, char maMH[], char noiDung[], char dapAnA[], char dapAnB[], char dapAnC[], char dapAnD[], char dapAnDung[]){
	CauHoi cauHoiMoi;
	cauHoiMoi.id = id;
	strcpy(cauHoiMoi.maMH, maMH);
	strcpy(cauHoiMoi.noiDung, noiDung);
	strcpy(cauHoiMoi.dapAnA, dapAnA);
	strcpy(cauHoiMoi.dapAnB, dapAnB);
	strcpy(cauHoiMoi.dapAnC, dapAnC);
	strcpy(cauHoiMoi.dapAnD, dapAnD);
	strcpy(cauHoiMoi.dapAnDung, dapAnDung);
	return cauHoiMoi;
}

NodeCauHoi* taoNodeCauHoi(CauHoi cauHoi){
	NodeCauHoi* nodeCauHoi = new NodeCauHoi;
	nodeCauHoi->cauHoi = cauHoi;
	nodeCauHoi->left=NULL;
	nodeCauHoi->right=NULL;
	
	return nodeCauHoi;
}

bool kiemTraMaCauHoi(NodeCauHoi *node,int id)
{
	if(node==NULL)
	{
		return 0;
	}
	else
	{
		if(node->cauHoi.id == id)
		{
			return 1;
		}
		else if(node->cauHoi.id<id)
		{
			kiemTraMaCauHoi(node->right,id);
		}
		else
		{
			kiemTraMaCauHoi(node->left,id);
		}
	}
}

int taoMaCauHoi(NodeCauHoi *node)
{
	int id;
	do
	{
		id = rand()%1000 + 1;
	}while(kiemTraMaCauHoi(node,id)==true);
	return id;
}

int getHeight(NodeCauHoi* node)
{
	return (node==NULL)? -1:node->height;
}
int max(int a, int b)
{
	return a>b?a:b;
}

NodeCauHoi * RR_Rotate(NodeCauHoi* k2)
{
	NodeCauHoi* k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
	k1->height = max(getHeight(k1->left), k2->height) + 1;
	return k1;
}

NodeCauHoi* LL_Rotate(NodeCauHoi* k2)
{
	NodeCauHoi* k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
	k1->height = max(getHeight(k1->right), k2->height) + 1;
	return k1;
}

NodeCauHoi* LR_Rotate(NodeCauHoi* k3)
{
	k3->left = LL_Rotate(k3->left);
	return RR_Rotate(k3);
}

NodeCauHoi* RL_Rotate(NodeCauHoi* k3)
{
	k3->right = RR_Rotate(k3->right);
	return LL_Rotate(k3);
}

NodeCauHoi* Insert(NodeCauHoi* root, CauHoi ch)
{
	if(root == NULL){
			return (root = taoNodeCauHoi(ch));
	}
	
	else if(ch.id < root->cauHoi.id){
			root->left = Insert(root->left, ch);
	//		printf("quatrai \n");
	}
	
	else //key >= root->key
	{
			root->right = Insert(root->right, ch);
		//	printf("qua phai \n");
	}
	
	//	printf("doichieu cao \n");
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	if(getHeight(root->left) - getHeight(root->right) == 2)
	{
		if(ch.id < root->left->cauHoi.id)
			root = RR_Rotate(root);
		else
			root = LR_Rotate(root);
	}
	else if(getHeight(root->right) - getHeight(root->left) == 2)
	{
		if(ch.id < root->right->cauHoi.id)
			root = RL_Rotate(root);
		else
			root = LL_Rotate(root);
	}
	return root;
}

NodeCauHoi* Delete(NodeCauHoi* root, CauHoi ch)
{
	if(!root)
		return NULL;
	if(ch.id == root->cauHoi.id)
	{
		if(root->right == NULL)
		{
			NodeCauHoi* temp = root;
			root = root->left;
			delete(temp);
			return root;
		}
		else
		{
			NodeCauHoi* temp = root->right;
			while(temp->left)
				temp = temp->left;
			root->cauHoi = temp->cauHoi;
			root->right = Delete(root->right, temp->cauHoi);
		}
	}
	else if(ch.id < root->cauHoi.id)
		root->left = Delete(root->left, ch);
	else
		root->right = Delete(root->right, ch);
	
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	if(getHeight(root->right) - getHeight(root->left) == 2)
	{
		if(getHeight(root->right->right) >= getHeight(root->right->left))
			root = LL_Rotate(root);
		else
			root = RL_Rotate(root);
	}
	else if(getHeight(root->left) - getHeight(root->right) == 2)
	{
		if(getHeight(root->left->left) >= getHeight(root->left->right))
			root = RR_Rotate(root);
		else
			root = LR_Rotate(root);
	}
	return root;
}

void xuatCay(NodeCauHoi *root)
{
	if(root!=NULL)
	{
		xuatCay(root->left);
		xuatCay(root->right);
	}
}

void themNodeVaoCay(DanhSachCauHoi &danhSachCauHoi, CauHoi cauHoi)
{
    danhSachCauHoi.root=Insert(danhSachCauHoi.root,cauHoi);
	danhSachCauHoi.soLuong++;
}
void xoaNodeCauHoi(DanhSachCauHoi &danhSachCauHoi, CauHoi cauHoi)
{
	if(danhSachCauHoi.root==NULL|| danhSachCauHoi.soLuong==0) return;
    danhSachCauHoi.root=Delete(danhSachCauHoi.root,cauHoi);
	danhSachCauHoi.soLuong--;
	
}
NodeCauHoi *timCauHoi(DanhSachCauHoi &danhSachCauHoi, int id)
{
	
	NodeCauHoi *tmp = danhSachCauHoi.root;
		
	while(tmp!=NULL)
	{
		if(id<tmp->cauHoi.id){
			tmp=tmp->left;
		}
		else if(id>tmp->cauHoi.id){
			tmp=tmp->right;
		}
		else{
			return tmp;
		}
	}
	return NULL;
}

NodeCauHoi *timKiemCauHoi(DanhSachCauHoi &danhSachCauHoi, int id)
{
	NodeCauHoi *tam = danhSachCauHoi.root;
	while(tam!=NULL){
		if(tam->cauHoi.id == id){
			return tam;
		}
		else if(id < tam->cauHoi.id){
			tam=tam->left;
		}
		else if(id > tam->cauHoi.id){
			tam=tam->right;
		}
	}
	return NULL;
}

void hieuChinhCauHoiTheoMa(DanhSachCauHoi &danhSachCauHoi, int id, char maMH[], char noiDung[], char dapAnA[], char dapAnB[], char dapAnC[], char dapAnD[], char dapAnDung[])
{
	NodeCauHoi *tam = timKiemCauHoi(danhSachCauHoi, id);
	if(tam!=NULL)
	{
		strcpy(tam->cauHoi.maMH, maMH);
		strcpy(tam->cauHoi.noiDung, noiDung);
		strcpy(tam->cauHoi.dapAnA, dapAnA);
		strcpy(tam->cauHoi.dapAnB, dapAnB);
		strcpy(tam->cauHoi.dapAnC, dapAnC);
		strcpy(tam->cauHoi.dapAnD, dapAnD);
		strcpy(tam->cauHoi.dapAnDung, dapAnDung);
	}
}



void deQuyXoaNode(NodeCauHoi *node)
{
	if(node!=NULL)
	{
		deQuyXoaNode(node->left);
		deQuyXoaNode(node->right);
		delete node;
	}
}

void xoaDanhSachCauHoi(DanhSachCauHoi &dsch)
{
	deQuyXoaNode(dsch.root);
	dsch.root=NULL;
	dsch.soLuong=0;
}

void danhSachCauHoiTuyenTinhTheoMa(NodeCauHoi *node, CauHoi *&cauHoi, int &i, char maMH[])
{
	if(node!=NULL)
	{
		danhSachCauHoiTuyenTinhTheoMa(node->left, cauHoi, i, maMH);
		if(strcmp(node->cauHoi.maMH, maMH)==0)
		{
			*(cauHoi+i) = node->cauHoi;
			i++;
		}
		danhSachCauHoiTuyenTinhTheoMa(node->right, cauHoi, i, maMH);
	}
}
void danhSachCauHoiTuyenTinh(NodeCauHoi *node, CauHoi *cauHoi, int &i)
{
	if(node!=NULL)
	{
		danhSachCauHoiTuyenTinh(node->left, cauHoi, i);
		cauHoi[i++] = node->cauHoi;
		danhSachCauHoiTuyenTinh(node->right, cauHoi, i);
	}
}
CauHoi timCauHoiTheoViTri(NodeCauHoi *node, int vt,int sl)
{
    
	CauHoi ch[sl], chtk;
	int dem=0;
	danhSachCauHoiTuyenTinh(node,ch,dem);
	chtk= ch[vt];
	delete ch;
	return chtk;
	
}
CauHoi *doCayVaoMangTuyenTinh(DanhSachCauHoi &danhSachCauHoi, int &n, char maMH[])
{
	
	CauHoi *dsTT = new CauHoi[danhSachCauHoi.soLuong];
	n=0;
	
	if(danhSachCauHoi.root!=NULL)
	{
		danhSachCauHoiTuyenTinhTheoMa(danhSachCauHoi.root, dsTT, n, maMH);
	}
	
	return dsTT;
}

void layMangRad(int sl, int mang[]){
	for(int i=0;i<sl;i++)
	{
		mang[i]=i;
	}
	int chay=sl;
	for(int i=0;i<sl;i++)
	{
		int ans = rand() % chay  ;
		int t = mang[ans];
		mang[ans]=mang[chay];
		mang[chay]=t;	
		chay--;
		if(chay==0) return;
	}
}
CauHoi *layDanhSachCauHoiRand(int sl,DanhSachCauHoi &danhSachCauHoi , char *mamon, int &dem)
{
	dem=0;
	CauHoi *dsTT;
	dsTT= doCayVaoMangTuyenTinh(danhSachCauHoi,dem,mamon);
//	cout<<" o tat ca la ch:"<<dem<<"/n";
	if(dem<sl-1) return NULL;
	return dsTT;
}

void ghiFile(NodeCauHoi *node, std::fstream &file)
{
	if(node!=NULL)
	{
		file<<node->cauHoi.id<<std::endl;
		file<<node->cauHoi.maMH<<std::endl;
		file<<node->cauHoi.noiDung<<std::endl;
		file<<node->cauHoi.dapAnA<<std::endl;
		file<<node->cauHoi.dapAnB<<std::endl;
		file<<node->cauHoi.dapAnC<<std::endl;
		file<<node->cauHoi.dapAnD<<std::endl;
		file<<node->cauHoi.dapAnDung<<std::endl;
		ghiFile(node->left, file);
		ghiFile(node->right, file);
	}
}

void ghiFileDSCauHoi(DanhSachCauHoi &dsch){
	
	std::fstream file;
	
	file.open("CauHoi.txt", std::ios::out);
	file<<dsch.soLuong<<endl;
	ghiFile(dsch.root,file);
	
	file.close();
	
}

void docFileDSCauHoi(DanhSachCauHoi &dsch)
{
	std::fstream file;
	file.open("CauHoi.txt", std::ios::in);
	
	if(file==NULL) return;
	
	xoaDanhSachCauHoi(dsch);
	int slch=0;
	file>>slch;
	CauHoi ch;
    for(int i=0;i<slch;i++)
	{
    	file>>ch.id;
		file.ignore();
		file.getline(ch.maMH, sizeof(ch.maMH), '\n');
		file.getline(ch.noiDung, sizeof(ch.noiDung), '\n');
		file.getline(ch.dapAnA, sizeof(ch.dapAnA), '\n');
		file.getline(ch.dapAnB, sizeof(ch.dapAnB), '\n');
		file.getline(ch.dapAnC, sizeof(ch.dapAnC), '\n');
		file.getline(ch.dapAnD, sizeof(ch.dapAnD), '\n');
		file>>ch.dapAnDung;
		file.ignore();
		
		themNodeVaoCay(dsch, ch);
	}
	
	file.close();
}

bool kiemTraMonHocCoCauHoi(NodeCauHoi *root, char *mamon)
{
	if(root==NULL) return false;
	else
	{
		if(strcmp(root->cauHoi.maMH,mamon)==0) return true;
	kiemTraMonHocCoCauHoi(root->left,mamon);
	kiemTraMonHocCoCauHoi(root->right,mamon);	
	}
}

float tinhDiem(CauHoi ch[],int dapan[],int sl,int mangrd[])
{
	int dem = 0;
	for(int i=0;i<sl;i++)
	{
	int da=ch[mangrd[i]].dapAnDung[0] -'A'+1-dapan[i];
	if(da==0) dem++;
	}
	return dem*10.0/sl;
}

