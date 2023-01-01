#include "file.h"
#include "folder.h"

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
adrFile findFile(fileList L, string fileName){
    adrFile P = first(L);
    while(P != nil && info(P).name != fileName){
        P = next(P);
    }
    return P;
};
adrFile newFile(file info){
    adrFile P = new elmFile;
    info(P) = info;
    folder(P) = nil;
    next(P) = nil;
    return P;
};
void createFileList(fileList &pL){
    first(pL) = nil;
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

// 12)Mencari nama folder dari file Y (10 poin)
string findFolderNameFromFileY(fileList L,string fileName){
    adrFile P = first(L);
    while (P != nil && info(P).name != fileName){
        P = next(P);
    }
    if (P == nil) return "File tidak terhubung ke Folder";
    return info(folder(P)).name;
};
