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
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
    }
    int type = 1;
};

class Suv : public CarType { 
public:
    Suv() : type(2) {}
    void setCarType() override {
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
    }
    int type = 2;
};

class Truck : public CarType { 
public:
    Truck() : type(3){}
    void setCarType() override {
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
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
