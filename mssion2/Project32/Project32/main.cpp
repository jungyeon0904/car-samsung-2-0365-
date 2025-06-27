#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "car.cpp"

#define CLEAR_SCREEN "\033[H\033[2J"

void delay(int ms);


// method refactoring
void printCommandByStep(const int& step);
void makeStringToken(char buf[]);
bool isExitCommand(const char buf[]);
bool isNotAnswerNumber(const char* checkNumber);
bool isNotValidAnswerForStep(const int& step, const int& answer);
bool backToBegginingStep(int& step, const int& answer);
bool backToPreviousStep(int& step, const int& answer);
void performByStep(Car car, int& step, const int& answer);

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

void delay(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}

int main()
{
    char buf[100];
    int step = CarType_Q;
    Car car = Car::getInstance();

    while (1)
    {
        printCommandByStep(step);
        fgets(buf, sizeof(buf), stdin);

        // 엔터 개행문자 제거
        makeStringToken(buf);

        if (isExitCommand(buf)) {
            break;
        }

        char* checkNumber;
        int answer = strtol(buf, &checkNumber, 10);

        if (isNotAnswerNumber(checkNumber)) {
            continue;
        }

        if (isNotValidAnswerForStep(step, answer)) {
            continue;
        }

        if (backToBegginingStep(step, answer)) {
            continue;
        }

        if (backToPreviousStep(step, answer)) {
            continue;
        }

        performByStep(car, step, answer);
    }
}

void printCommandByStep(const int& step)
{
    if (step == CarType_Q)
    {
        printf(CLEAR_SCREEN);

        printf("        ______________\n");
        printf("       /|            | \n");
        printf("  ____/_|_____________|____\n");
        printf(" |                      O  |\n");
        printf(" '-(@)----------------(@)--'\n");
        printf("===============================\n");
        printf("어떤 차량 타입을 선택할까요?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }
    else if (step == Engine_Q)
    {
        printf(CLEAR_SCREEN);
        printf("어떤 엔진을 탑재할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. 고장난 엔진\n");
    }
    else if (step == brakeSystem_Q)
    {
        printf(CLEAR_SCREEN);
        printf("어떤 제동장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }
    else if (step == SteeringSystem_Q)
    {
        printf(CLEAR_SCREEN);
        printf("어떤 조향장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }
    else if (step == Run_Test)
    {
        printf(CLEAR_SCREEN);
        printf("멋진 차량이 완성되었습니다.\n");
        printf("어떤 동작을 할까요?\n");
        printf("0. 처음 화면으로 돌아가기\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    printf("===============================\n");

    printf("INPUT > ");
}

void makeStringToken(char buf[])
{
    char* context = nullptr;
    strtok_s(buf, "\r", &context);
    strtok_s(buf, "\n", &context);
}

bool isExitCommand(const char buf[]) {
    if (!strcmp(buf, "exit"))
    {
        printf("바이바이\n");
        return true;
    }
    return false;
}

bool isNotAnswerNumber(const char* checkNumber) {
    // 입력받은 문자가 숫자가 아니라면
    if (*checkNumber != '\0')
    {
        printf("ERROR :: 숫자만 입력 가능\n");
        delay(5000);
        return true;
    }
    return false;
}

bool isNotValidAnswerForStep(const int& step, const int& answer) {
    if (step == CarType_Q && !(answer >= 1 && answer <= 3))
    {
        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
        delay(5000);
        return true;
    }

    if (step == Engine_Q && !(answer >= 0 && answer <= 4))
    {
        printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
        delay(5000);
        return true;
    }

    if (step == brakeSystem_Q && !(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
        delay(5000);
        return true;
    }

    if (step == SteeringSystem_Q && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
        delay(5000);
        return true;
    }

    if (step == Run_Test && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        delay(5000);
        return true;
    }
    return false;
}

bool backToBegginingStep(int& step, const int& answer) {
    // 처음으로 돌아가기
    if (answer == 0 && step == Run_Test)
    {
        step = CarType_Q;
        return true;
    }
    return false;
}

bool backToPreviousStep(int& step, const int& answer) {
    // 이전으로 돌아가기
    if (answer == 0 && step >= 1)
    {
        step -= 1;
        return true;
    }
    return false;
}

void performByStep(Car car, int& step, const int& answer) {
    if (step == CarType_Q)
    {
        car.selectCarType(answer);
        delay(5000);
        step = Engine_Q;
    }
    else if (step == Engine_Q)
    {
        car.selectEngine(answer);
        delay(5000);
        step = brakeSystem_Q;
    }
    else if (step == brakeSystem_Q)
    {
        car.selectBrakeSystem(answer);
        delay(5000);
        step = SteeringSystem_Q;
    }
    else if (step == SteeringSystem_Q)
    {
        car.selectSteeringSystem(answer);
        delay(5000);
        step = Run_Test;
    }
    else if (step == Run_Test && answer == 1)
    {
        car.runProducedCar();
        delay(5000);
    }
    else if (step == Run_Test && answer == 2)
    {
        printf("Test...\n");
        delay(5000);
        car.testProducedCar();
        delay(5000);
    }
}
#endif