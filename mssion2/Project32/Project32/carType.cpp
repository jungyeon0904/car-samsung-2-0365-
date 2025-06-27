#include <stdio.h>

class CarType { 
public:
    virtual void setCarType() = 0;
    int type;
};

class Sedan : public CarType { 
public:
    Sedan() :type(1) {}
    void setCarType() override {
        printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
    }
    int type = 1;
};

class Suv : public CarType { 
public:
    Suv() : type(2) {}
    void setCarType() override {
        printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
    }
    int type = 2;
};

class Truck : public CarType { 
public:
    Truck() : type(3){}
    void setCarType() override {
        printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
    }
    int type = 3;
};

//Creator
class Factory {
public:
    virtual CarType* makeCar() = 0;
};

class SedanFactory : public Factory {
public:
    CarType* makeCar() override {
        return new Sedan();
    }
};

class SuvFactory : public Factory {
public:
    CarType* makeCar() override {
        return new Suv();
    }
};

class TruckFactory : public Factory {
public:
    CarType* makeCar() override {
        return new Truck();
    }
};
