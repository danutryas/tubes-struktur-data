#ifndef FOLDER_H_INCLUDED
#define FOLDER_H_INCLUDED
#include "file.h"
#include "MLL.h"

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

typedef struct folderList {
    adrFolder first;
};

void createFolderList(folderList &cL);
adrFolder newFolder(folder info);
int inDegreeFolder(fileList L, string folderName);
void showFolderList(folderList L);

// 1)Menambahkan folder baru (5 poin)
void insertFolder(folderList &L, adrFolder P);
// 2)Menampilkan data folder X (5 poin)
void showDataFolder(folderList L, string folderName);
// 3)Menghapus folder tertentu (10 poin)
void deleteFolder(fileList &pL,folderList &cL,string folderName);
// 4)Mencari folder X (5 poin)
adrFolder findFolder(folderList L, string folderName);

#endif // FOLDER_H_INCLUDED
