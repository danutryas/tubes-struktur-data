#ifndef FOLDER_H_INCLUDED
#define FOLDER_H_INCLUDED
#include <iostream>
#include "file.h"

using namespace std;

struct folder {
    string name;
    int totalFile;
    double size;
};

typedef struct elmFolder *adrFolder;

struct elmFolder {
    folder info;
    adrFolder next;
};

struct folderList {
    adrFolder first;
};

void createFolderList(folderList &cL);
adrFolder newFolder(folder info);
void showFolderList(folderList L);
void deleteFolderFunc(folderList &L,adrFolder &P);


#endif // FOLDER_H_INCLUDED
