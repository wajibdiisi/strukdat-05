/* 
Nama : Ahmad Irfan Fadholi
NPM : 140810180034
Kelas : B
Tgl : 27 Maret 2019
Deskripsi : Latihan double linked list */

#include <iostream>
#include <string.h>
using namespace std;


struct Pembalap {
   int nomor;
   char nama;
   int waktu;
   Pembalap* next;
   Pembalap* prev;
};
typedef Pembalap* pointer; 
typedef pointer List;

void createNode(Pembalap* &p,  int nomor, char nama){
	p = new Pembalap; 
	p->nomor=nomor;
	p->nama=nama;
	p->waktu=0;
	p->next = NULL; 
	p->prev = NULL; 

};
void insertFirst(Pembalap* &head, Pembalap* pBaru){
	if (head==NULL)           
		head=pBaru;
	else { 						
		pBaru->next=head; 		 
		head->prev = pBaru; 	 
		head=pBaru; 			 
	}
}
void insertBefore(Pembalap* &head, int nomorKey, Pembalap* node){
	Pembalap* pBantu=head;
    if (head->nomor==nomorKey){
        node->next=head;
        head->prev=node;
        head=node;
    }
    else{
        while(pBantu!=NULL){
            if(pBantu->nomor==nomorKey){
                node->next=pBantu;
                node->prev=pBantu->prev;
                pBantu->prev->next=node;
                pBantu->prev=node;
                break;
            }
            else
                pBantu=pBantu->next;
        }
    }
}

void deleteByKey(Pembalap* &head, int nomorKey, Pembalap* &deletedNode){
	Pembalap* pBantu=head;
    if (head->nomor==nomorKey){
        deletedNode=head;
        head=head->next;
        head->prev=NULL;
        deletedNode=NULL;
    }
    else{
        while(pBantu!=NULL){
            if(pBantu->nomor==nomorKey){
                pBantu->prev->next=pBantu->next;
                pBantu->next->prev=pBantu->prev;
                deletedNode=pBantu;
                deletedNode=NULL;
                break;
            }
            else
                pBantu=pBantu->next;
        }
    }
}

void search(Pembalap* &firstNode, int nomorKey, Pembalap* &pToUpdate){
	Pembalap* pBantu=firstNode;
    while(pBantu!=NULL){
        if(pBantu->nomor==nomorKey){
            pToUpdate=pBantu;
            break;
        }
        else
            pBantu=pBantu->next;
    }
}
void traversal(Pembalap* head){
	pointer pBantu;
	if (head == NULL){
		cout << "List Kosong"<<endl;
	}
	else {
		pBantu = head;					// catat elemen pertama
		do {
			cout<<"Nomor : "<<pBantu->nomor<<endl;
			cout<<"Nama  : "<<pBantu->nama<<endl;
			cout<<"Waktu : "<<pBantu->waktu<<endl;
			cout<<endl;		// proses cetak
			pBantu = pBantu->next;		// pindah ke berikutnya
		} while (pBantu != NULL);	
		cout << endl;
	}
}


void update(Pembalap* firstNode, int nomorKey){
	Pembalap* pBantu=firstNode;

    search(firstNode,nomorKey,pBantu);
    pBantu->nama='k';
    pBantu->nomor=24;
    pBantu->waktu=10;

    cout<<"nama: "<<pBantu->nama<<endl;
    cout<<"nomor: "<<pBantu->nomor<<endl;
    cout<<"waktu: "<<pBantu->waktu<<endl<<endl;

}
int main() {
	Pembalap* head = NULL;
	Pembalap* pBaru = NULL;
	Pembalap* pHapus = NULL;
	Pembalap* pToUpdate = NULL;
	char nama = 'a';
 	for (int i = 0; i < 4; i++) {
   		createNode(pBaru, i+1, nama++);
   		insertFirst(head, pBaru);
 	}
 	cout << "\n>>> List" << endl;
 	traversal(head);int keyNomor = 2;

    cout << "\n>>> Insert Before nomor " << keyNomor << endl;
    createNode(pBaru, 99, 'z');
    insertBefore(head, keyNomor, pBaru);
    traversal(head);
    cout << "\n>>> SortingByNomor" << endl;
    traversal(head);
    
	keyNomor = 3;
    cout << "\n>>> Delete nomor " << keyNomor << endl;
    deleteByKey(head, keyNomor, pHapus);
    traversal(head);

    keyNomor = 4;
    cout << "\n>>> Update nomor " << keyNomor << endl;
    update(head, keyNomor);

    cout << "\n>>> Updated list\n";
    traversal(head);
}

