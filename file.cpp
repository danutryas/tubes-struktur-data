#include "MLL.h"
#include "file.h"
#include "folder.h"


void createFileList(fileList &pL){
    first(pL) = nil;
};
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

// delete
void deleteFile(fileList &L, adrFile P){
    if (folder(P) != nil){
        folder(P) = nil;
    }

    if (P == first(L)){
        deleteFirstFile(L);
    }else if (next(P) == nil) {
        deleteLastFile(L);
    }else {
        adrFile Q = first(L);
        while (next(Q) != P){
            Q = next(Q);
        }
        deleteAfterFile(L,Q);
    }
}
void deleteAfterFile(fileList &L, adrFile P){
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
    adrFile Q;
    while(next(next(P)) != nil){
        P = next(P);
    }
    Q = next(P);
    next(P) = nil;
}
int inDegreeFolder(fileList L,folderList folderL, string folderName) {
    adrFile P = first(L);
    adrFolder pFolder = findFolder(folderL,folderName);
    int count = 0;
    while (P != nil){
        if (folder(P) == pFolder){
            count++;
        }
        P = next(P);
    }
    return count;
}
