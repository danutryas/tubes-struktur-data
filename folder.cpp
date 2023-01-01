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
        cout <<"=> Folder Name: "<< info(P).name << endl;
        P = next(P);
        while (P != first(L)){
            cout <<"=> Folder Name: "<< info(P).name << endl;
            P = next(P);
        }
    }
    cout << "=========================="<<endl;
}
void deleteFolderFunc(folderList &L,adrFolder &P){
    adrFolder Q = first(L);
    if (Q == nil) {
        cout << "Tidak terdapat Folder"<< endl;
    }else if (next(Q) == first(L)){
        if (Q == P){
            first(L) = nil;
        }
    }else {
        adrFolder temp;
        if (Q == P){
            while (next(Q) != first(L)) {
                Q = next(Q);
            }
            temp = first(L);
            first(L) = next(first(L));
            next(Q) = first(L);
            next(temp) = nil;
        }else if(next(P) == first(L)){

            while (next(next(Q)) != first(L)){
                Q = next(Q);
            }
            temp = next(Q);
            next(Q) = first(L);
            next(temp) = nil;
        }else {
            while (next(Q) != first(L) && next(Q)!= P) {
                Q = next(Q);
            }
            temp = next(Q);
            next(Q) = next(temp);
            next(temp) = nil;
        }
    }
};
