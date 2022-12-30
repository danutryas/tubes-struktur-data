#include "MLL.h"
#include <iostream>
#include <stdlib.h>

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
    while( Q != nil ){
        if (info(folder(Q)).name == folderName){
            // delete all file
            // disconnectFolderFile(pL,info(Q).name,folderName);
        }
        Q = next(Q);
    }
    if (P == nil) {
        cout << "Tidak terdapat Folder"<< endl;
    }else if (next(P) == nil && info(P).name == folderName){
        first(cL) = nil;
    }else {
        if (info(P).name == folderName){
            first(cL) = next(P);
            next(P) = nil;
        }else {
            while (next(P) != nil && info(next(P)).name != folderName) {
                P = next(P);
            }
            temp = next(P);
            next(P) = next(temp);
            next(temp) = nil;
        }
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
// void insertFileFromFolderX(fileList &L,string folderName){};
void insertFile(fileList &L, adrFile P){
    adrFile Q = first(L);
    if (Q == nil){
        first(L) = P;
    }else {
        while(next(Q) != nil){
            Q = next(Q);
        }
        next(Q) = P;
    }
};

// 6)Menghapus file dari folder X (10 poin)
void deleteFileFromFolderX()
{

};
// 8)Mencari file Y dari folder X (5 poin)
adrFile findFileFromFolderX(fileList &L, string fileName, string folderName)
{
    
};

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
// 9)Membuat relasi antara folder X dan file Y (15 poin)
void connectFolderFile(folderList cL,fileList &pL,string fileName, string folderName){
    adrFolder P = findFolder(cL,folderName);
    adrFile Q = findFile(pL,fileName);
    if (P != nil && Q != nil){
        folder(Q) = P;
    }
};
// 10)Menghapus relasi antara folder X dan file Y (15 poin)
void disconnectFolderFile(folderList cL,fileList &pL,string fileName,string folderName){
    adrFolder P = findFolder(cL,folderName);
    adrFile Q = findFile(pL,fileName);
    if (P != nil && Q != nil){
        folder(Q) = nil;
    }
};
// 11)Menampilkan folder yang memiliki jumlah file yang paling banyak dan menampilkan file tersebut(10 poin)
void showMostFileInFolder(fileList pL,folderList cL){
    // find mostFileInFolder
    int mostDegree = inDegreeFolder(pL,info(first(cL)).name);
    string nameMostDegree = info(first(cL)).name;
    int countDegree = 0;
    adrFolder P = next(first(cL));
    while(P != nil){
        countDegree = inDegreeFolder(pL,info(P).name);
        if (countDegree > mostDegree){
            mostDegree = countDegree;
            nameMostDegree = info(P).name;
        }
        P = next(P);
    }
    // show mostFileInFolder
    adrFile Q = first(pL);
    cout << "Folder yang memiliki file terbanyak: " << nameMostDegree << endl;
    while(Q != nil){
        if (info(folder(Q)).name == nameMostDegree){
            cout << "===========================" << endl;
            cout << "File Name : "<< info(Q).name << endl;
            cout << "File Type : "<< info(Q).type << endl;
            cout << "File Size : "<< info(Q).size << endl;
            cout << "===========================" << endl;
        }
        Q = next(Q);
    }
};
// 12)Mencari nama folder dari file Y (10 poin)
string findFolderNameFromFileY(fileList L,string fileName){
    adrFile P = first(L);
    while (P != nil && info(P).name != fileName){
        P = next(P);
    }
    if (P == nil) return "File tidak terhubung ke Folder";
    return info(folder(P)).name;
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
    clearConsole();
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
    clearConsole();
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
int inDegreeFolder(fileList L, string folderName) {
    adrFile P = first(L);
    int count = 0;
    while (P != nil){
        if (info(folder(P)).name == folderName){
            count++;
        }
        P = next(P);
    }
    return count;
}
adrFile findFile(fileList L, string fileName){
    adrFile P = first(L);
    while(P != nil && info(P).name != fileName){
        P = next(P);
    }
    return P;
};
void clearConsole(){
    if (system("CLS")) system("clear");
};
void showFolderList(folderList L) {
    adrFolder P = first(L);
    cout << "=========================="<<endl;
    if (P == nil) {
        cout << "List Folder Kosong!!!"<<endl;
    }else {
        while (P != nil){
            cout <<"=> Folder Name: "<< info(P).name << endl;
            P = next(P);
        }
    }
    cout << "=========================="<<endl;
}
void showFileList(fileList L) {
    adrFile P = first(L);
    cout << "=========================="<<endl;
    if (P == nil) {
        cout << "List File Kosong!!!"<<endl;
    }else {
        while (P != nil){
            cout <<"=> File Name: "<< info(P).name << endl;
            P = next(P);
        }
    }
    cout << "=========================="<<endl;
}
void showConnection(folderList cL,fileList pL){
    adrFolder cP = first(cL);
    adrFile pP;
    string folderName = "";
    while(cP != nil){
        folderName = info(cP).name;
        cout << "Folder " << folderName << ": ";
        pP = first(pL);
        while(pP != nil){
            if (info(folder(pP)).name == folderName){
                cout << info(pP).name << " - ";
            }
            pP = next(pP);
        }
        cout << endl;
        cP = next(cP);
    }
}
/*
adrChild findChild(pList pL, adrParent P){};                                    // 8.Mencari data child pada parent tertentu (10)
*/
