#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>

#define next(P) (P)->next
#define info(P) (P)->info
#define folder(P) (P)->folder
#define first(L) (L).first
#define nil NULL

using namespace std;

// 6)Menghapus file dari folder X (10 poin)
void deleteFileFromFolderX(fileList &pL,folderList cL, string folderName);                                                   //
// 7)Menampilkan seluruh file dari folder X (5 poin)
void showAllFileFromFolderX(fileList L,string folderName);
// 8)Mencari file Y dari folder X (5 poin)
adrFile findFileFromFolderX(fileList &L, string fileName, string folderName);   //
// 9)Membuat relasi antara folder X dan file Y (15 poin)
void connectFolderFile(folderList cL,fileList &pL,string fileName, string folderName);                     //
// 10)Menghapus relasi antara folder X dan file Y (15 poin)
void disconnectFolderFile(folderList cL,fileList &pL,string fileName,string folderName);       //
// 11)Menampilkan folder yang memiliki jumlah file yang paling banyak dan menampilkan file tersebut(10 poin)
void showMostFileInFolder(fileList pL,folderList cL);                                          //

//aditional function
void showConnection(folderList cL,fileList pL);

// program function
void showMenu();
int getMenu();
bool backMenu();
void runProgram(int programNumber);
void clearConsole();

#endif // MLL_H_INCLUDED
