#include "gmock/gmock.h"
#include "car.cpp"

TEST(GroupCarType, carTypeCheck1) {
	Car car = Car::getInstance();
	car.selectCarType(1);
	EXPECT_EQ(1, car.getCarType());
}

TEST(GroupCarType, carTypeCheck2) {
	Car car = Car::getInstance();
	car.selectCarType(2);
	EXPECT_EQ(2, car.getCarType());
}

TEST(GroupCarType, carTypeCheck3) {
	Car car = Car::getInstance();
	car.selectCarType(3);
	EXPECT_EQ(3, car.getCarType());
}

TEST(GroupEngine, EngineCheck1) {
	Car car = Car::getInstance();
	car.selectEngine(1);
	EXPECT_EQ(1, car.getEngine());
}

TEST(GroupEngine, EngineCheck2) {
	Car car = Car::getInstance();
	car.selectEngine(2);
	EXPECT_EQ(2, car.getEngine());
}

TEST(GroupEngine, EngineCheck3) {
	Car car = Car::getInstance();
	car.selectEngine(3);
	EXPECT_EQ(3, car.getEngine());
}

TEST(GroupEngine, EngineCheck4) {
	Car car = Car::getInstance();
	car.selectEngine(4);
	EXPECT_EQ(4, car.getEngine());
}

TEST(GroupBrakeSystem, BrakeSystemCheck1) {
	Car car = Car::getInstance();
	car.selectBrakeSystem(1);
	EXPECT_EQ(1, car.getBrakeSystem());
}

TEST(GroupBrakeSystem, BrakeSystemCheck2) {
	Car car = Car::getInstance();
	car.selectBrakeSystem(2);
	EXPECT_EQ(2, car.getBrakeSystem());
}

TEST(GroupBrakeSystem, BrakeSystemCheck3) {
	Car car = Car::getInstance();
	car.selectBrakeSystem(3);
	EXPECT_EQ(3, car.getBrakeSystem());
}

TEST(GroupSteeringSystem, SteeringSystemCheck1) {
	Car car = Car::getInstance();
	car.selectSteeringSystem(1);
	EXPECT_EQ(1, car.getSteeringSystem());
}

TEST(GroupSteeringSystem, SteeringSystemCheck2) {
	Car car = Car::getInstance();
	car.selectSteeringSystem(2);
	EXPECT_EQ(2, car.getSteeringSystem());
}

TEST(GroupValidCheck, isValidCheck1) {
	Car car = Car::getInstance();
	car.selectCarType(1);
	car.selectBrakeSystem(2);
	bool ret = car.isValidCheck();
	car.testProducedCar();
	EXPECT_EQ(false, ret);
}

TEST(GroupValidCheck, isValidCheck2) {
	Car car = Car::getInstance();
	car.selectCarType(2);
	car.selectEngine(2);
	bool ret = car.isValidCheck();
	car.testProducedCar();
	EXPECT_EQ(false, ret);
}

TEST(GroupValidCheck, isValidCheck3) {
	Car car = Car::getInstance();
	car.selectCarType(3);
	car.selectEngine(3);
	bool ret = car.isValidCheck();
	car.testProducedCar();
	EXPECT_EQ(false, ret);
}

TEST(GroupValidCheck, isValidCheck4) {
	Car car = Car::getInstance();
	car.selectCarType(3);
	car.selectBrakeSystem(1);
	bool ret = car.isValidCheck();
	car.testProducedCar();
	EXPECT_EQ(false, ret);
}

TEST(GroupValidCheck, isValidCheck5) {
	Car car = Car::getInstance();
	car.selectBrakeSystem(3);
	car.selectSteeringSystem(2);
	bool ret = car.isValidCheck();
	car.testProducedCar();
	EXPECT_EQ(false, ret);
}

TEST(GroupValidCheck, isValidCheck6) {
	Car car = Car::getInstance();
	car.selectBrakeSystem(3);
	car.selectSteeringSystem(1);
	bool ret = car.isValidCheck();
	car.testProducedCar();
	EXPECT_EQ(true, ret);
}

TEST(GroupRunProducedCar, runProducedCarCheck1) {
	Car car = Car::getInstance();
	car.selectCarType(1);
	car.selectEngine(1);
	car.selectBrakeSystem(1);
	car.selectSteeringSystem(1);
	bool ret = car.runProducedCar();
	EXPECT_EQ(true, ret);
}

TEST(GroupRunProducedCar, runProducedCarCheck2) {
	Car car = Car::getInstance();
	car.selectCarType(2);
	car.selectEngine(4);
	car.selectBrakeSystem(2);
	car.selectSteeringSystem(2);
	bool ret = car.runProducedCar();
	EXPECT_EQ(false, ret);
}

TEST(GroupRunProducedCar, runProducedCarCheck3) {
	Car car = Car::getInstance();
	car.selectCarType(3);
	car.selectEngine(2);
	car.selectBrakeSystem(3);
	car.selectSteeringSystem(1);
	bool ret = car.runProducedCar();
	EXPECT_EQ(true, ret);
}

TEST(GroupRunProducedCar, runProducedCarCheck4) {
	Car car = Car::getInstance();
	car.selectCarType(2);
	car.selectEngine(3);
	car.selectBrakeSystem(2);
	car.selectSteeringSystem(2);
	bool ret = car.runProducedCar();
	EXPECT_EQ(true, ret);
}

TEST(GroupRunProducedCar, runProducedCarCheck5) {
	Car car = Car::getInstance();
	car.selectCarType(2);
	car.selectEngine(2);
	car.selectBrakeSystem(2);
	car.selectSteeringSystem(2);
	bool ret = car.runProducedCar();
	EXPECT_EQ(false, ret);
}
