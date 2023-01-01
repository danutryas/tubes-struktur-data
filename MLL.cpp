#include <iostream>
#include <stdlib.h>
#include "MLL.h"
#include "file.h"
#include "folder.h"

using namespace std;
// 1)Menambahkan folder baru (5 poin)
void insertFolder(folderList &L, adrFolder P){
    adrFolder Q = first(L);
    if (Q == nil){
        first(L) = P;
        next(P) = first(L);
    }else {
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
};
// 2)Menampilkan data folder X (5 poin)
void showDataFolder(folderList L, string folderName){
    adrFolder P = findFolder(L,folderName);
    if (P == nil){
        cout << "Folder Tidak ditemukan!" << endl;
    } else {
        cout << "===========================" << endl;
        cout << "Folder Name : "<< info(P).name << endl;
        cout << "Total File  : "<< info(P).totalFile << endl;
        cout << "Folder Size : "<< info(P).size << endl;
        cout << "===========================" << endl;
    }
};
// 3)Menghapus folder tertentu (10 poin)
void deleteFolder(fileList &pL,folderList &cL,string folderName){
    deleteFileFromFolderX(pL,cL,folderName);

    adrFolder Q = findFolder(cL,folderName);
    deleteFolderFunc(cL,Q);
};
// 4)Mencari folder X (5 poin)
adrFolder findFolder(folderList L, string folderName){
    adrFolder P = first(L);
    if (info(P).name == folderName){
        return P;
    }else {
        P = next(P);
        while(P != first(L) && info(P).name != folderName){
            P = next(P);
        }
        return P;
    }
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
void deleteFileFromFolderX(fileList &pL,folderList cL, string folderName){
    adrFolder pFolder = findFolder(cL,folderName);

    adrFile pFile = first(pL);
    adrFile currFile;
    while (pFile != nil){
        currFile = pFile;
        pFile = next(pFile);
        if (folder(currFile) == pFolder){
            deleteFile(pL,currFile);
        }
    }
};
// 8)Mencari file Y dari folder X (5 poin)
// adrFile findFileFromFolderX(fileList &L, string fileName, string folderName){};
adrFile newFile(file info){
    adrFile P = new elmFile;
    info(P) = info;
    folder(P) = nil;
    next(P) = nil;
    return P;
};
// 7)Menampilkan seluruh file dari folder X (5 poin)
void showAllFileFromFolderX(fileList L,folderList folderL,string folderName){
    adrFile P = first(L);
    adrFolder pFolder = findFolder(folderL,folderName);
    if (P == nil){
        cout << "List Kosong" << endl;
    }else {
        while(P != nil){
            if (folder(P) == pFolder){
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
    }else {
        if (P == nil){
            cout << "Folder tidak Ditemukan!!!" << endl;
        }
        if (Q == nil){
            cout << "File tidak Ditemukan!!!" << endl;
        }
    }
};
// 10)Menghapus relasi antara folder X dan file Y (15 poin)
void disconnectFolderFile(folderList cL,fileList &pL,string fileName,string folderName){
    adrFolder P = findFolder(cL,folderName);
    adrFile Q = findFile(pL,fileName);
    if (P != nil && Q != nil){
        folder(Q) = nil;
    }else {
        if (P == nil){
            cout << "Folder tidak Ditemukan!!!" << endl;
        }
        if (Q == nil){
            cout << "File tidak Ditemukan!!!" << endl;
        }
    }
};
// 11)Menampilkan folder yang memiliki jumlah file yang paling banyak dan menampilkan file tersebut(10 poin)
void showMostFileInFolder(fileList pL,folderList cL){
    // find mostFileInFolder
    int mostDegree = inDegreeFolder(pL,cL,info(first(cL)).name);
    string nameMostDegree = info(first(cL)).name;
    int countDegree = 0;
    adrFolder P = next(first(cL));
    while(P != first(cL)){
        countDegree = inDegreeFolder(pL,cL,info(P).name);
        if (countDegree > mostDegree){
            mostDegree = countDegree;
            nameMostDegree = info(P).name;
        }
        P = next(P);
    }
    // show fileInFolder
    adrFile Q = first(pL);
    adrFolder MostDegree = findFolder(cL,nameMostDegree);
    cout << "Folder yang memiliki file terbanyak: " << nameMostDegree << endl;
    showAllFileFromFolderX(pL,cL,nameMostDegree);
};
// 12)Mencari nama folder dari file Y (10 poin)
void findFolderNameFromFileY(fileList L,string fileName){
    adrFile Q = findFile(L,fileName);
    if (Q != nil && folder(Q) != nil) {
        cout << "Nama folder dari file "<< fileName << ": "<< info(folder(Q)).name << endl;
    }else {
        if (Q == nil){
            cout << "File tidak ditemukan!!!"<<endl;
        }else if (folder(Q) == nil){
            cout << "File tidak terhubung ke Folder!!!"<<endl;
        }
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
void clearConsole(){
    if (system("CLS")) system("clear");
};
void showConnection(folderList cL,fileList pL){
    adrFolder cP = first(cL);
    string folderName = info(cP).name;
    cout << "Folder " << info(cP).name << ": ";
    adrFile pP = first(pL);
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
    while(cP != first(cL)){
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
