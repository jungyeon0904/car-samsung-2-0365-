#include <stdio.h>
#include "carType.cpp"


enum cartype
{
    SEDAN = 1,
    SUV,
    TRUCK
};

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA,
    BROKEN
};

enum BrakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS
};

class Car {
public:
    static Car& getInstance() {
        static Car instance;
        return instance;
    }

    void selectCarType(int answer) {
        if (answer == SEDAN) {
            Factory* sedanFac = new SedanFactory();
            carType = sedanFac->makeCar();
        }
        if (answer == SUV) {
            Factory* suvFac = new SuvFactory();
            carType = suvFac->makeCar();
        }
        if (answer == TRUCK) {
            Factory* truckFac = new TruckFactory();
            carType = truckFac->makeCar();
        }
        carType->setCarType();
    }

    int getCarType() {
        return carType->type;
    }

    void selectEngine(int answer) {
        engine = static_cast<Engine>(answer);
        if (answer == GM)
            printf("GM 엔진을 선택하셨습니다.\n");
        if (answer == TOYOTA)
            printf("TOYOTA 엔진을 선택하셨습니다.\n");
        if (answer == WIA)
            printf("WIA 엔진을 선택하셨습니다.\n");
    }

    Engine getEngine() {
        return engine;
    }

    void selectBrakeSystem(int answer) {
        brakeSystem = static_cast<BrakeSystem>(answer);
        if (answer == MANDO)
            printf("MANDO 제동장치를 선택하셨습니다.\n");
        if (answer == CONTINENTAL)
            printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
        if (answer == BOSCH_B)
            printf("BOSCH 제동장치를 선택하셨습니다.\n");
    }

    BrakeSystem getBrakeSystem() {
        return brakeSystem;
    }

    void selectSteeringSystem(int answer) {
        steeringSystem = static_cast<SteeringSystem>(answer);
        if (answer == BOSCH_S)
            printf("BOSCH 조향장치를 선택하셨습니다.\n");
        if (answer == MOBIS)
            printf("MOBIS 조향장치를 선택하셨습니다.\n");
    }

    SteeringSystem getSteeringSystem() {
        return steeringSystem;
    }

    int isValidCheck()
    {
        if (carType->type == SEDAN && brakeSystem == CONTINENTAL)
            return false;
        else if (carType->type == SUV && engine == TOYOTA)
            return false;
        else if (carType->type == TRUCK && engine == WIA)
            return false;
        else if (carType->type == TRUCK && brakeSystem == MANDO)
            return false;
        else if (brakeSystem == BOSCH_B && steeringSystem != BOSCH_S)
            return false;
       
        return true;
    }

    bool runProducedCar() {
        if (isValidCheck() == false)
        {
            printf("자동차가 동작되지 않습니다\n");
            return false;
        }
        else
        {
            if (engine == BROKEN)
            {
                printf("엔진이 고장나있습니다.\n");
                printf("자동차가 움직이지 않습니다.\n");
                return false;
            }
            else
            {
                if (carType->type == SEDAN)
                    printf("Car Type : Sedan\n");
                if (carType->type == SUV)
                    printf("Car Type : SUV\n");
                if (carType->type == TRUCK)
                    printf("Car Type : Truck\n");
                if (engine == GM)
                    printf("Engine : GM\n");
                if (engine == TOYOTA)
                    printf("Engine : TOYOTA\n");
                if (engine == WIA)
                    printf("Engine : WIA\n");
                if (brakeSystem == MANDO)
                    printf("Brake System : Mando");
                if (brakeSystem == CONTINENTAL)
                    printf("Brake System : Continental\n");
                if (brakeSystem == BOSCH_B)
                    printf("Brake System : Bosch\n");
                if (steeringSystem == BOSCH_S)
                    printf("SteeringSystem : Bosch\n");
                if (steeringSystem == MOBIS)
                    printf("SteeringSystem : Mobis\n");

                printf("자동차가 동작됩니다.\n");
                return true;
            }
        }
    }

    void testProducedCar(){
        if (carType->type == SEDAN && brakeSystem == CONTINENTAL)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Sedan에는 Continental제동장치 사용 불가\n");
        }
        else if (carType->type == SUV && engine == TOYOTA)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("SUV에는 TOYOTA엔진 사용 불가\n");
        }
        else if (carType->type == TRUCK && engine == WIA)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 WIA엔진 사용 불가\n");
        }
        else if (carType->type == TRUCK && brakeSystem == MANDO)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 Mando제동장치 사용 불가\n");
        }
        else if (brakeSystem == BOSCH_B && steeringSystem != BOSCH_S)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");
        }
    }


private:
    CarType* carType;
    Engine engine;
    BrakeSystem brakeSystem;
    SteeringSystem steeringSystem;
};
