#include "file.h"
#include "folder.h"
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
    deleteFileFromFolderX(pL,cL,folderName);

    adrFolder P = first(cL);
    adrFile Q = first(pL);

    if (P == nil) {
        cout << "Tidak terdapat Folder"<< endl;
    }else if (next(P) == nil){
        if (info(P).name == folderName){
            first(cL) = nil;
        }
    }else {
        adrFolder temp;
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

// 6)Menghapus file dari folder X (10 poin)
void deleteFileFromFolderX(fileList &pL,folderList cL, string folderName){
    adrFolder cP = findFolder(cL,folderName);
    adrFile pP = first(pL);

    while (pP != nil){
        if (folder(pP) == cP){
            disconnectFolderFile(cL,pL,info(pP).name,folderName);
            deleteFile(pL,pP);
        }
        pP = next(pP);
    }
};
void deleteFile(fileList &L, adrFile P){
    if (P = first(L)){
        deleteFirstFile(L);
    }else {
        adrFile Q = first(L);
        adrFile K = first(L);
        while (next(Q) != nil){
            K = Q;
            Q = next(Q);
        }
        if (next(Q) == nil){
            deleteLastFile(L);
        }else {
            deleteAfterFile(K);
        }
    }
}
void deleteAfterFile(adrFile P){
    adrFile Q = next(P);
    next(P) = next(Q);
    next(Q) = nil;
}
void deleteFirstFile(fileList &L){
    adrFile P = first(L);
    first(L) = next(P);
    next(P) = nil;
}
void deleteLastFile(fileList &L) {
    adrFile P = first(L);
    while(next(next(P)) = nil){
        P = next(P);
    }
    next(P) = nil;
}

// 8)Mencari file Y dari folder X (5 poin)
adrFile findFileFromFolderX(fileList &L, string fileName, string folderName){};

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

// additional Function
void showMenu() {
    clearConsole();
    cout << "====================   MENU   ==================="<<endl;
    cout << "================================================="<<endl;
    cout << "| 1. Menambahkan folder baru                    |"<<endl;
    cout << "| 2. Menambahkan file baru                      |"<<endl;
    cout << "| 3. Menghapus folder tertentu                  |"<<endl;
    cout << "| 4. Menghapus file tertentu                    |"<<endl;
    cout << "| 5. Membuat relasi antara folder X             |"<<endl;
    cout << "| 6. Menghapus relasi antara folder X dan file Y|"<<endl;
    cout << "| 7. Menampilkan seluruh Folder                 |"<<endl;
    cout << "| 8. Menampilkan seluruh File                   |"<<endl;
    cout << "| 9. Menampilkan seluruh File dari Folder X     |"<<endl;
    cout << "|10. Mencari nama Folder dari File Y            |"<<endl;
    cout << "|11. Menampilkan Folder dengan file terbanyak   |"<<endl;
    cout << "|12. Menampilkan Data folder X                  |"<<endl;
    cout << "| 0. Exit                                       |"<<endl;
    cout << "================================================="<<endl;
    /*
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
    */
}
int getMenu() {
    showMenu();
    int chooseMenu;
    cout << "Silhkan pilih menu(0-12): ";cin >> chooseMenu;
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
void showConnection(folderList cL,fileList pL){
    adrFolder cP = first(cL);
    adrFile pP;
    string folderName;

    while(cP != nil){
        folderName = info(cP).name;
        cout << "Folder " << folderName << ": ";
        pP = first(pL);
        while(pP != nil){
            if (folder(pP) != nil){
                if (info(folder(pP)).name == folderName){
                    cout << info(pP).name << " - ";
                }
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
