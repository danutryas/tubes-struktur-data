#include "MLL.h"
#include <iostream>

using namespace std;

// 1)Menambahkan folder baru (5 poin)
void insertFolder(folderList &L, adrFolder P){
    adrFolder Q = first(L);
    if (Q == nil){
        first(L) = P;
    }else {
        while(next(Q) != nil){
            Q = next(Q);
        }
        next(Q) = P;
    }
};
// 2)Menampilkan data folder X (5 poin)
void showDataFolder(folderList L, string folderName){
    adrFolder P = first(L);
    if (P == nil){
        cout << "Tidak Terdapat Folder"  << endl;
    }else {
        while(P != nil && info(P).name != folderName){
            P = next(P);
        }
        if (P == nil){
            cout << "Folder Tidak ditemukan!" << endl;
        } else {
            cout << "===========================" << endl;
            cout << "Folder Name : "<< info(P).name << endl;
            cout << "Total File  : "<< info(P).totalFile << endl;
            cout << "Folder Size : "<< info(P).size << endl;
            cout << "===========================" << endl;
        }
    }
};
// 3)Menghapus folder tertentu (10 poin)
void deleteFolder(fileList &pL,folderList &cL,string folderName){
    adrFolder P = first(cL);
    adrFile Q = first(pL);
    adrFolder temp;
    while(Q != nil ){
        if (info(folder(Q)).name == folderName){
            // delete all file
            // disconnectFolderFile(pL,info(Q).name,folderName);
        }
        Q = next(Q);
    }if (P == nil) {
        cout << "Tidak terdapat Folder"<< endl;
    }else if (next(P) == nil && info(P).name == folderName){
        first(cL) = nil;
    }else {
        while (next(P) != nil && info(next(P)).name != folderName) {
            P = next(P);
        }
        temp = next(P);
        next(P) = next(temp);
        next(temp) = nil;
    }
};
// 4)Mencari folder X (5 poin)
adrFolder findFolder(folderList L, string folderName){
    adrFolder P = first(L);
    while(P != nil && info(P).name != folderName){
        P = next(P);
    }
    return P;
};

// 5)Menambahkan file dari folder X (5 poin)
void insertFileFromFolderX(fileList &L,string folderName){};
// 6)Menghapus file dari folder X (10 poin)
void deleteFileFromFolderX(){};

// 7)Menampilkan seluruh file dari folder X (5 poin)
void showAllFileFromFolderX(fileList L,string folderName){
    adrFile P = first(L);
    if (P == nil){
        cout << "List Kosong" << endl;
    }else {
        while(P != nil){
            if (info(folder(P)).name == folderName){
                cout << "===========================" << endl;
                cout << "File Name : "<< info(P).name << endl;
                cout << "File Type : "<< info(P).type << endl;
                cout << "File Size : "<< info(P).size << endl;
                cout << "===========================" << endl;
            }
            P = next(P);
        }
    }
};

// 8)Mencari file Y dari folder X (5 poin)
adrFile findFileFromFolderX(fileList &L, string fileName, string folderName){};
// 9)Membuat relasi antara folder X dan file Y (15 poin)
void connectFolderFile(string fileName, string folderName){};
// 10)Menghapus relasi antara folder X dan file Y (15 poin)
void disconnectFolderFile(fileList L,string fileName, string folderName){};
// 11)Menampilkan folder yang memiliki jumlah file yang paling banyak dan menampilkan file tersebut(10 poin)
void showMostFileInFolder(fileList L){};

// 12)Mencari nama folder dari file Y (10 poin)
string findFolderNameFromFileY(fileList L,string fileName){
    adrFile P = first(L);
    while (P != nil && info(P).name != fileName){
        P = next(P);
    }

    if (P == nil){
        return "";
    }

    return info(P).name;
};

// additional Function
void createFileList(fileList &pL){
    first(pL) = nil;
};
void createFolderList(folderList &cL){
    first(cL) = nil;
};
adrFile newFile(file info){
    adrFile P = new elmFile;
    info(P) = info;
    folder(P) = nil;
    next(P) = nil;
    return P;
};
adrFolder newFolder(folder info){
    adrFolder C = new elmFolder;
    info(C) = info;
    next(C) = nil;
    return C;
}
void showMenu() {
    cout << "====================   MENU   ==================="<<endl;
    cout << "================================================="<<endl;
    cout << "| 1. Menambahkan folder baru                    |"<<endl;
    cout << "| 2. Menampilkan data folder X                  |"<<endl;
    cout << "| 3. Menghapus folder tertentu                  |"<<endl;
    cout << "| 4. Mencari folder X                           |"<<endl;
    cout << "| 5. Menambahkan file dari folder X             |"<<endl;
    cout << "| 6. Menghapus file dari folder X               |"<<endl;
    cout << "| 7. Menampilkan seluruh file dari folder X     |"<<endl;
    cout << "| 8. Mencari file Y dari folder X               |"<<endl;
    cout << "| 9. Membuat relasi antara folder X             |"<<endl;
    cout << "|10. Menghapus relasi antara folder X dan file Y|"<<endl;
    cout << "|11. Menampilkan folder yang memiliki jumlah file yang paling banyak dan menampilkan file tersebut|"<<endl;
    cout << "|12. Mencari nama folder dari file Y            |"<<endl;
    cout << "| 0. Exit                                       |"<<endl;
    cout << "================================================="<<endl;
}
int getMenu() {
    showMenu();
    int chooseMenu;
    cout << "Silhkan pilih menu(1-11): ";cin >> chooseMenu;
    return chooseMenu;
}
bool backMenu(){
    char goBack;
    cout << "Kembali Ke Menu (y/n): "; cin >> goBack;
    if (goBack == 'y'|| goBack == 'Y'){
        return true;
    }
    return false;
}


/*
                                                                                // 5.Insert data child (10)
void insertLastChild(cList &cL,adrChild C){
    adrChild Q = first(cL);
    if (Q == nil){
        first(cL) = C;
    }else {
        while(nextC(Q) != nil){
            Q = nextC(Q);
        }
        nextC(Q) = C;
    }
};
                                                                                // 6.Menghubungkan data parent ke data child (10)
void connectParentChild(adrParent P,adrChild C){
    child(P) = C;
};

adrChild findChild(pList pL, adrParent P){};                                    // 8.Mencari data child pada parent tertentu (10)
// void deleteChild(pList pL){};                                                // 9.Menghapus data child pada parent tertentu (15)
// int countChild(pList pL, adrParent P){};                                    // 10.Menghitung jumlah data child dari parent tertentu (10)

*/
