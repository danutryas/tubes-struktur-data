// 1.Insert data parent dari depan/belakang (5)
void insertLastParent(pList &pL,adrParent P){
};
// 5.Insert data child (10)
void insertLastChild(cList &cL,adrChild C){};

// 4.Mencari data parent (5)
elmParent findParent(pList &pL, infotype info){};

// 8.Mencari data child pada parent tertentu (10)
elmChild findChild(pList pL, elmParent P){};

// 6.Menghubungkan data parent ke data child (10)
void connectParentChild(adrParent P,adrChild C){};

// 3.Menghapus data parent dan childnya (5)
void deleteParentChild(pList pL, elmParent P){};

// 9.Menghapus data child pada parent tertentu (15)
void deleteChild(pList pL){};

// 2.Show all data parent (5)
void showPList(pList pL){};

// 7.Menampilkan seluruh data parent beserta childnya (15)
void showAll(pList pL){};

// 10.Menghitung jumlah data child dari parent tertentu (10)
int countChild(pList pL, elmParent P){};
