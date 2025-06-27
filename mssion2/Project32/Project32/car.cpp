#include <stdio.h>
enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK
};

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA
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
        carType = static_cast<CarType>(answer);
        if (answer == 1)
            printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
        if (answer == 2)
            printf("차량 타입으로 SUV을 선택하셨습니다.\n");
        if (answer == 3)
            printf("차량 타입으로 Truck을 선택하셨습니다.\n");
    }

    CarType getCarType() {
        return carType;
    }

    void selectEngine(int answer) {
        engine = static_cast<Engine>(answer);
        if (answer == 1)
            printf("GM 엔진을 선택하셨습니다.\n");
        if (answer == 2)
            printf("TOYOTA 엔진을 선택하셨습니다.\n");
        if (answer == 3)
            printf("WIA 엔진을 선택하셨습니다.\n");
    }

    Engine getEngine() {
        return engine;
    }

    void selectBrakeSystem(int answer) {
        brakeSystem = static_cast<BrakeSystem>(answer);
        if (answer == 1)
            printf("MANDO 제동장치를 선택하셨습니다.\n");
        if (answer == 2)
            printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
        if (answer == 3)
            printf("BOSCH 제동장치를 선택하셨습니다.\n");
    }

    BrakeSystem getBrakeSystem() {
        return brakeSystem;
    }

    void selectSteeringSystem(int answer) {
        steeringSystem = static_cast<SteeringSystem>(answer);
        if (answer == 1)
            printf("BOSCH 조향장치를 선택하셨습니다.\n");
        if (answer == 2)
            printf("MOBIS 조향장치를 선택하셨습니다.\n");
    }

    SteeringSystem getSteeringSystem() {
        return steeringSystem;
    }

    int isValidCheck()
    {
        if (carType == SEDAN && brakeSystem == CONTINENTAL)
            return false;
        else if (carType == SUV && engine == TOYOTA)
            return false;
        else if (carType == TRUCK && engine == WIA)
            return false;
        else if (carType == TRUCK && brakeSystem == MANDO)
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
            if (engine == 4)
            {
                printf("엔진이 고장나있습니다.\n");
                printf("자동차가 움직이지 않습니다.\n");
                return false;
            }
            else
            {
                if (carType == 1)
                    printf("Car Type : Sedan\n");
                if (carType == 2)
                    printf("Car Type : SUV\n");
                if (carType == 3)
                    printf("Car Type : Truck\n");
                if (engine == 1)
                    printf("Engine : GM\n");
                if (engine == 2)
                    printf("Engine : TOYOTA\n");
                if (engine == 3)
                    printf("Engine : WIA\n");
                if (brakeSystem == 1)
                    printf("Brake System : Mando");
                if (brakeSystem == 2)
                    printf("Brake System : Continental\n");
                if (brakeSystem == 3)
                    printf("Brake System : Bosch\n");
                if (steeringSystem == 1)
                    printf("SteeringSystem : Bosch\n");
                if (steeringSystem == 2)
                    printf("SteeringSystem : Mobis\n");

                printf("자동차가 동작됩니다.\n");
                return true;
            }
        }
    }

    void testProducedCar(){
        if (carType == SEDAN && brakeSystem == CONTINENTAL)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Sedan에는 Continental제동장치 사용 불가\n");
        }
        else if (carType == SUV && engine == TOYOTA)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("SUV에는 TOYOTA엔진 사용 불가\n");
        }
        else if (carType == TRUCK && engine == WIA)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 WIA엔진 사용 불가\n");
        }
        else if (carType == TRUCK && brakeSystem == MANDO)
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
    CarType carType;
    Engine engine;
    BrakeSystem brakeSystem;
    SteeringSystem steeringSystem;
};
