#ifndef PARTITION2_VECTOR_H
#define PARTITION2_VECTOR_H

template <class T>
class Vector {
public:
    Vector();
    Vector(const Vector& from);
    void initWithSize(int size);
    Vector& operator=(const Vector& other);
    bool operator==(const Vector& other);
    bool operator>(const Vector& other);
    bool operator<(const Vector& other);
    void push_back(T elementToAdd);
    void push_on_pos(T elementToAdd, int position);
    void clear();
    void clearRange(int from, int to);
    void clearContent();
    T& operator [] (int index);
    int size();
    void deleteAt(int index);
    ~Vector();
private:
    T* rawArray;
    int arraySize;
};

template<class T>
Vector<T>::Vector() {
    this->rawArray = new T[0]();
    this->arraySize = 0;
}

template<class T>
Vector<T>::Vector(const Vector& from) {
    this->rawArray = new T[from.arraySize];
    for (int i = 0; i < from.arraySize; i++) {
        this->rawArray[i] = from.rawArray[i];
    }
    arraySize = from.arraySize;
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    delete[] rawArray;
    this->rawArray = new T[other.arraySize];
    for (int i = 0; i < other.arraySize; i++) {
        this->rawArray[i] = other.rawArray[i];
    }
    arraySize = other.arraySize;
    return *this;
}

template<class T>
bool Vector<T>::operator==(const Vector& other) {
    if(this->arraySize != other.arraySize) return false;
    for (int i = 0; i < arraySize; i++) {
        if(rawArray[i] != other.rawArray[i]) return false;
    }
    return true;
}

template<class T>
bool Vector<T>::operator>(const Vector& other) {
    int size = arraySize;
    if(this->arraySize > other.arraySize) size = other.arraySize;
    for (int i = 0; i < size; i++) {
        if (rawArray[i] > other.rawArray[i]) return true;
        if (rawArray[i] < other.rawArray[i]) return false;
    }
    return false;
}

template<class T>
bool Vector<T>::operator<(const Vector& other) {
    int size = arraySize;
    if(this->arraySize > other.arraySize) size = other.arraySize;
    for (int i = 0; i < size; i++) {
        if (rawArray[i] < other.rawArray[i]) return true;
        if (rawArray[i] > other.rawArray[i]) return false;
    }
    return false;
}

template<class T>
void Vector<T>::push_back(T elementToAdd) {
    T* newArray = new T[this->arraySize+1]();
    for (int i = 0; i < this->arraySize; i++){
        newArray[i] = this->rawArray[i];
    }
    newArray[this->arraySize] = elementToAdd;
    delete[] this->rawArray;
    this->rawArray = newArray;
    this->arraySize++;
}

template<class T>
void Vector<T>::push_on_pos(T elementToAdd, int position) {
    T* newArray = new T[this->arraySize+1]();
    for (int i = 0; i <= this->arraySize; i++){
        if(i == position) {
            newArray[i] = elementToAdd;
            i++;
        }
        else newArray[i] = this->rawArray[i];
    }
    delete[] this->rawArray;
    this->rawArray = newArray;
    this->arraySize++;
}

template<class T>
void Vector<T>::clear() {
    this->arraySize = 0;
    delete[] this->rawArray;
    this->rawArray = new T[0]();
}

template<class T>
Vector<T>::~Vector() {
    delete[] this->rawArray;
}

template<class T>
T &Vector<T>::operator[](int index) {
    return this->rawArray[index];
}

template<class T>
int Vector<T>::size() {
    return this->arraySize;
}

template<class T>
void Vector<T>::deleteAt(int index) {
    T* newArray = new T[this->arraySize-1]();
    for(int i = 0; i < this->arraySize; i++) {
        if(i == index) continue;
        newArray[i < index ? i : i-1] = this->rawArray[i];
    }
    this->arraySize--;
    delete[](this->rawArray);
    this->rawArray = newArray;
}

template<class T>
void Vector<T>::initWithSize(int size) {
    delete[](this->rawArray);
    T* newArray = new T[size]();
    this->arraySize = size;
    this->rawArray = newArray;
}

template<class T>
void Vector<T>::clearRange(int from, int to) {
    for(int i = from; i <= to; i++) {
        rawArray[i] = 0;
    }
}

template<class T>
void Vector<T>::clearContent() {
    clearRange(0, size()-1);
}

#endif //PARTITION2_VECTOR_H
