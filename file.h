#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

struct file {
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

void createFileList(fileList &pL);
adrFile newFile(file info);
adrFile findFile(fileList L, string fileName);
void showFileList(fileList L);
// delete
void deleteFile(fileList &L, adrFile P);
void deleteFirstFile(fileList &L);
void deleteAfterFile(adrFile P);
void deleteLastFile(fileList &L);


// 5)Menambahkan file dari folder X (5 poin)
// void insertFileFromFolderX(fileList &L,string folderName);                      //
void insertFile(fileList &L, adrFile P);

// 12)Mencari nama folder dari file Y (10 poin)
string findFolderNameFromFileY(fileList L,string fileName);                       //


#endif // FILE_H_INCLUDED
