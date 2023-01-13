#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "folder.h"
#include <iostream>
using namespace std;

typedef struct file {
    string name;
    string type;
    double size;
};

typedef struct elmFile *adrFile;

struct elmFile {
    file info;
    adrFile next;
    adrFolder folder;
};

typedef struct fileList {
    adrFile first;
};

int inDegreeFolder(fileList L,folderList folderL, string folderName);
void showFileList(fileList L);


adrFile newFile(file info);
void createFileList(fileList &pL);
void insertFile(fileList &L, adrFile P);
adrFile findFile(fileList L, string fileName);
void showFileInFolderX(fileList L, string folderName);
// delete
void deleteFile(fileList &L, adrFile P);
void deleteFirstFile(fileList &L);
void deleteAfterFile(fileList &L,adrFile P);
void deleteLastFile(fileList &L);

#endif // FILE_H_INCLUDED
