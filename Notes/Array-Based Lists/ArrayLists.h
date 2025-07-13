template <class elemType>
class ArrayBList {
    int *list;  //stores the array
    int length; //# of elements inside the list
    int maxSize;    //maximum size of the list
    public:
    ArrayBList(int );
    ArrayBList(const ArrayBList& );
    ~ArrayBList();
    bool isFull() const;
    bool isEmpty() const;
    int getListSize() const;
    int getListMaxSize() const;
    void print() const;
    bool isItemAtIndexEqual(int , const elemType &) const;
    void insertAtIndex(int , const elemType &);
    void removeAtIndex(int , const elemType &);
    void insertEnd(const elemType &);
    void replaceAt(int , const elemType &);
    void retrieveAt(int , elemType &) const;
    void clearList();
    ArrayBList& operator=(const ArrayBList &);
    int SequentialSearch(const elemType &) const;
    void insert(const elemType &);  
    void remove(const elemType &); 
};