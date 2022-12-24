#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#define next(P) (P)->next
#define info(P) (P)->info
#define first(L) (L).first
#define NULL nil

struct infotype
{
};

typedef struct elmChild *adrChild;
typedef struct elmParent *adrParent;

struct elmChild
{
    infotype info;
    adrChild nextC;
};

struct elmParent
{
    infotype info;
    adrParent nextP;
    adrChild nextC;
};

typedef struct pList
{
    adrParent first;
};

typedef struct cList
{
    adrChild first;
};

// 1.Insert data parent dari depan/belakang (5)
void insertLastParent(pList &L,adrParent P);

// 2.Show all data parent (5)
void showPList(pList L);

// 3.Menghapus data parent dan childnya (5)

// 4.Mencari data parent (5)
void findPElmt(pList &L, infotype info);

// 5.Insert data child (10)
void insertLastChild(cList &L,adrChild P);

// 6.Menghubungkan data parent ke data child (10)
void connectParentChild(adrParent pP,adrChild pC);

// 7.Menampilkan seluruh data parent beserta childnya (15)
void showAll(pList L);

// 8.Mencari data child pada parent tertentu (10)

// 9.Menghapus data child pada parent tertentu (15)
void deleteChild(pList pL);

// 10.Menghitung jumlah data child dari parent tertentu (10)






#endif // MLL_H_INCLUDED
