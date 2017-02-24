/**
 * @author Shaotu Jia
 * @file test.cpp
 * @brief This file is to do unit test for PID controll program
 * @copyright, Shaotu Jia, All rights reserved
 */



#include <gtest/gtest.h>
#include "lib.hpp"
#include <memory>

//Test IsContinuous function
TEST(test, continuity)
{
  //Initialize class PID using smart pointer in c++ 11
  std::shared_ptr<PID> pid = std::make_shared < PID > (0.1, 0.01, 0.5);

  EXPECT_TRUE(pid->isContinuous());  //check whether the system is continuous

}

//Test setPoint function
TEST(test, setPoint)
{
  //Initialize class PID using smart pointer in c++ 11
  std::shared_ptr<PID> pid = std::make_shared < PID > (0.1, 0.01, 0.5);

  EXPECT_EQ(0, pid->setPoint());  // test the default setPoint
  pid->compute(1, 2);
  EXPECT_EQ(1, pid->setPoint());  // test the new setPoint

}

//Test acutalVelocity function
TEST(test, actualVelocity)
{
  //Initialize class PID using smart pointer in c++ 11
  std::shared_ptr<PID> pid = std::make_shared < PID > (0.1, 0.01, 0.5);

  EXPECT_EQ(0, pid->setPoint());  // test the default setPoint
  pid->compute(1, 2);
  EXPECT_NEAR(1, pid->actualVelocity(), 0.001);  // test the actual velocity
}


//Test compute function
TEST(test, compute)
{
  //Initialize class PID using smart pointer in c++ 11
  std::shared_ptr<PID> pid = std::make_shared < PID > (0.1, 0.01, 0.5);

  EXPECT_NEAR(1, pid->compute(1, 2), 0.001);  // with the given PID gains, pass in a setpoint of 1 with actual velocity 2. should get close to 1
}

