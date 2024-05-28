#include<stdio.h>
#include<string.h>
#include<stdbool.h>

struct Benhnhan{
	int tuoi;
	int id;
	char name[50];
	char ngaysinh[50];
	char diachi[50];
	long vienphi;
	char cd[50];
	char pp[50];
};
struct node{
	Benhnhan data;
	struct node* next;
};
typedef struct node* Linkedlist;
// ham khoi tao
void init(Linkedlist &H){
	H=NULL;
}
// ham tao ra node moi
node* createnode(Benhnhan K) {
  node* Q = new node;
  Q->data.tuoi = K.tuoi;
  Q->data.id= K.id;
  strcpy(Q->data.name, K.name);
  strcpy(Q->data.ngaysinh, K.ngaysinh);
  strcpy(Q->data.diachi, K.diachi);
  Q->data.vienphi = K.vienphi;
  strcpy(Q->data.cd, K.cd);
  strcpy(Q->data.pp, K.pp);
  Q->next = NULL;
  return Q;
}
// ham them node
void addpatient(Linkedlist &H , Benhnhan K ){
	node* newnode = createnode(K);
	if(H == NULL){
		H = newnode;
		return;
	}
	else{
	     newnode->next = H ; 
		 H = newnode;
		 return;	
	}
}
// ham them vao sau danh sach
void addafter(Linkedlist &H, Benhnhan K ){
	node* newnode = createnode(K);
	if(H == NULL){
		H = newnode;
		return;
	}
	else{
		Linkedlist temp = H;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
	}
	
}
void addafter(Linkedlist &H, node* K ){
		Linkedlist temp = H;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = K;
		
}
// ham hien thi node
void hienthi(node *Q){
	
	printf("+-------+---------+--------------------------------+-----------------+--------------------------------+----------------------+--------------------------+-----------------------+\n");
	printf("|  Age  |   ID    |              Name              |       DoB       |            Location            |      Medical Bill    |  Medical Condition Code  |  Treatment Plan Code  |\n");
	printf("+-------+---------+--------------------------------+-----------------+--------------------------------+----------------------+--------------------------+-----------------------+\n");

  // Patient rows using printf format specifiers
	printf("| %-4d  | %-6d  | %-30s | %-15s | %-30s |%-22ld|%-26s|%-23s|\n",Q->data.tuoi,Q->data.id, Q->data.name, Q->data.ngaysinh, Q->data.diachi, Q->data.vienphi, Q->data.cd, Q->data.pp );
	printf("+-------+---------+--------------------------------+-----------------+--------------------------------+----------------------+--------------------------+-----------------------+\n");
} 
// ham tim kiem theo id
void searchid(Linkedlist &H , int id){
	Linkedlist temp = H ; 
	bool check = false;
	node* saved = new node;    // dung de luu node co id can tim
	while(temp != NULL){
		if(temp->data.id == id){
			check = true;
			saved = temp;
			break;
		}
		else{
			temp = temp->next;
		}
	}
	if(check){
		printf("Da tim thay \n");
		hienthi(saved);  // in ra node da luu
	}
	else{
		printf("Khong tim thay \n");
	}
}
// ham tim kiem theo ten
void searchten(Linkedlist &H , char ten[50]){
	Linkedlist temp = H ; 
	bool check = false;
	node* saved = new node;    // dung de luu node co id can tim
	while(temp != NULL){
		if(strcmp(temp->data.name,ten)==0){
			check = true;
			saved = temp;
			break;
		}
		else{
			temp = temp->next;
		}
	}
	if(check){
		printf("Da tim thay \n");
		hienthi(saved);  // in ra node da luu
	}
	else{
		printf("Khong tim thay \n");
	}
}

//ham roi benhnhan theo id
void removebn(Linkedlist &H , int removeid){
	
	Linkedlist temp = H;
	node* remove = new node;
	remove = NULL;
	if(H == NULL){
		return;
	}
	else if(H->data.id == removeid){
		H = H->next;
		delete(H);
	}
	else{
		while(temp!=NULL){
			if(temp->next->data.id == removeid){
				remove = temp->next;
				temp->next = remove->next;
				break;
			}
			temp = temp->next;
		}
		if(remove == NULL){
			printf("Khong the xoa Benh nhan do ko co trong danh sach\n");
			return;
		}
		else{
			printf("da xoa thanh cong \n");
			delete(remove);
			return;
		}
	}
}

// ham sap xep theo ID
void sortid(Linkedlist &H){
	for(node* i = H ; i != NULL ; i = i->next){
		node* minnode = i;
		for(node* j = i ; j != NULL ; j = j->next){
			if(j->data.id < minnode->data.id){
				minnode = j;
			}
		}
		// ta chi can trao doi thong tin giua hai node ma khong can phai thay doi vi tri cua node
		Benhnhan temp = minnode->data;
		minnode->data = i->data;
		i->data = temp;
	}
}
// ham duyet
void duyet(Linkedlist &H) {
    Linkedlist Q = H;
	if (H == NULL) {
		printf("Khong co thong tin benh nhan de hien thi \n");
        return;
    }
	 else {
	 	printf("\nPatient Record:\n");
    printf("+-------+---------+--------------------------------+-----------------+--------------------------------+----------------------+--------------------------+-----------------------+\n");
	printf("|  Age  |   ID    |              Name              |       DoB       |            Location            |      Medical Bill    |  Medical Condition Code  |  Treatment Plan Code  |\n");
	printf("+-------+---------+--------------------------------+-----------------+--------------------------------+----------------------+--------------------------+-----------------------+\n");
        while (Q != NULL) {

  // Patient rows using printf format specifiers
			
			printf("| %-4d  | %-6d  | %-30s | %-15s | %-30s |%-22ld|%-26s|%-23s|\n", Q->data.tuoi,Q->data.id, Q->data.name, Q->data.ngaysinh, Q->data.diachi, Q->data.vienphi, Q->data.cd, Q->data.pp );
			printf("+-------+---------+--------------------------------+-----------------+--------------------------------+----------------------+--------------------------+-----------------------+\n");
			
            //printf("Medical Bill: %ld VND\n", Q->vienphi);
            //printf("Medical Condition Code: %s\n", Q->ba.cd);
            //printf("Treatment Plan Code: %s\n", Q->ba.pp); // Assuming treatment plan code is a string
        	
            Q = Q->next;
            
        }
    }
    
}
// Ham tinh tien tong
int tinhtientong(Linkedlist &H){
	Linkedlist temp = H;
	int sum = 0;
	if(H == NULL){
		return 0;
	}
	else{
		while(temp!=NULL){
			sum += temp->data.vienphi;
			temp = temp->next;
		}
		return sum;
	}
}
// Ham sale
void sale(Linkedlist &H){
	Linkedlist P = H;
	while(P!=NULL){
		if(P->data.tuoi>= 80){
			P->data.vienphi *= 0.2;
		}
		else if(P->data.tuoi < 80 && P->data.tuoi > 60){
			P->data.vienphi *= 0.6;
		}
		else if(P->data.tuoi <= 5){
			P->data.vienphi = P->data.vienphi * 0.6;
		}
		else{
			// Nhan voi 1 thi coi nhu cha lam cai deo gi nen de trong :))
		}
		P=P->next;
	}
}
int main(){
		Linkedlist H;
	init(H);
	Benhnhan I;
	I.tuoi = 35;
    I.id = 123456;
    strcpy(I.name,"A");
    strcpy(I.ngaysinh,"1989-01-01");
    strcpy(I.diachi,"Hanoi, Vietnam");
    I.vienphi = 1000000;
    strcpy(I.cd ,"D");
    strcpy(I.pp ,"0");
    Benhnhan P;
	P.tuoi = 81;
    P.id = 987654;
    strcpy(P.name,"B");
    strcpy(P.ngaysinh,"1964-03-15");
    strcpy(P.diachi,"Ho Chi Minh City, Vietnam");
    P.vienphi = 500000;
    strcpy(P.cd ,"S");
    strcpy(P.pp ,"1"); 
    Benhnhan M; 
    M.tuoi = 5;
    M.id = 789012;
    strcpy(M.name,"Y");
    strcpy(M.ngaysinh, "2019-12-25");
    strcpy(M.diachi, "Da Nang, Vietnam");
    M.vienphi = 200000;
    strcpy(M.cd ,"E");
    strcpy(M.pp ,"2");
    Benhnhan Q; 
    Q.tuoi = 61;
    Q.id = 357924;
    strcpy(Q.name,"C");
      strcpy(Q.ngaysinh, "1996-04-10");
      strcpy(Q.diachi, "Can Tho, Vietnam");
      Q.vienphi = 150000;
      strcpy(Q.cd ,"E");
    strcpy(Q.pp ,"6");
    addpatient(H,I);
    addpatient(H,P);
    addpatient(H,Q);
    duyet(H);
	return 0;
}
