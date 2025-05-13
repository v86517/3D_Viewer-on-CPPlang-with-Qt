#include <iostream>

#include "../controller/s21_controller_obj.h"
#include "gtest/gtest.h"

TEST(ControllerTest, GetDataObj) {
  s21::Controller* controller_obj_;
  controller_obj_ = s21::Controller::getInstance();
  s21::Facade facade;
  const char* file = "./tests/obj/tetrahedron.obj";
  controller_obj_->SetModel(&facade);
  controller_obj_->OpenObj(file);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().count_of_vertexes, 12);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().count_of_facets, 12);
}

TEST(ControllerTest, MoveX) {
  s21::Controller* controller_obj_;
  controller_obj_ = s21::Controller::getInstance();
  s21::Facade facade;
  const char* file = "./tests/obj/Low-Poly-Racing-Car.obj";
  controller_obj_->SetModel(&facade);
  controller_obj_->OpenObj(file);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[1],
                   0.010974303039961133);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[2],
                   -0.026114404762789117);
  controller_obj_->MoveObj('x', 15.0);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[1],
                   0.010974303039961133);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[2],
                   -0.026114404762789117);
}

TEST(ControllerTest, TurnX) {
  s21::Controller* controller_obj_;
  controller_obj_ = s21::Controller::getInstance();
  s21::Facade facade;
  const char* file = "./tests/obj/Low-Poly-Racing-Car.obj";
  controller_obj_->SetModel(&facade);
  controller_obj_->OpenObj(file);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[1],
                   0.010974303039961133);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[2],
                   -0.026114404762789117);
  controller_obj_->RotateObj('x', 5.0);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[1],
                   0.0086565221601479815);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[2],
                   -0.026971505101097901);
}

TEST(ControllerTest, ScaleX) {
  s21::Controller* controller_obj_;
  controller_obj_ = s21::Controller::getInstance();
  s21::Facade facade;
  const char* file = "./tests/obj/Low-Poly-Racing-Car.obj";
  controller_obj_->SetModel(&facade);
  controller_obj_->OpenObj(file);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[1],
                   0.010974303039961133);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[2],
                   -0.026114404762789117);
  controller_obj_->ScaleObj('x', 5.0);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[1],
                   0.010974303039961133);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[2],
                   -0.026114404762789117);
}

TEST(ControllerTest, ChangeSize) {
  s21::Controller* controller_obj_;
  controller_obj_ = s21::Controller::getInstance();
  s21::Facade facade;
  const char* file = "./tests/obj/Low-Poly-Racing-Car.obj";
  controller_obj_->SetModel(&facade);
  controller_obj_->OpenObj(file);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[1],
                   0.010974303039961133);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[2],
                   -0.026114404762789117);
  controller_obj_->ScaleObj('0', 5.0);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[1],
                   0.054871515199805668);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[2],
                   -0.13057202381394559);
}

TEST(ControllerTest, ResetObj) {
  s21::Controller* controller_obj_;
  controller_obj_ = s21::Controller::getInstance();
  s21::Facade facade;
  const char* file = "./tests/obj/Low-Poly-Racing-Car.obj";
  controller_obj_->SetModel(&facade);
  controller_obj_->OpenObj(file);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[1],
                   0.010974303039961133);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[2],
                   -0.026114404762789117);
  controller_obj_->ScaleObj('0', 5.0);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[1],
                   0.054871515199805668);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[2],
                   -0.13057202381394559);
  controller_obj_->ResetObj();
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[1],
                   0.010974303039961133);
  EXPECT_DOUBLE_EQ(controller_obj_->GetObject().vertexes[2],
                   -0.026114404762789117);
}
