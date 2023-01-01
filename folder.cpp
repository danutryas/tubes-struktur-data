#include "MLL.h"
#include "file.h"
#include "folder.h"

void createFolderList(folderList &cL){
    first(cL) = nil;
};
adrFolder newFolder(folder info){
    adrFolder C = new elmFolder;
    info(C) = info;
    next(C) = nil;
    return C;
}
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
void deleteFileFunc(folderList &L);
void deleteFolderFunc(folderList &L,adrFolder &P){
    adrFolder Q = first(L);

    if (Q == nil) {
        cout << "Tidak terdapat Folder"<< endl;
    }else if (next(Q) == nil){
        if (Q == P){
            first(L) = nil;
        }
    }else {
        adrFolder temp;
        if (Q == P){
            first(L) = next(Q);
            next(Q) = nil;
        }else {
            while (next(Q) != nil && next(Q)!= P) {
                Q = next(Q);
            }
            temp = next(Q);
            next(Q) = next(temp);
            next(temp) = nil;
        }
    }
};
