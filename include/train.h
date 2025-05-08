// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Car {
    bool light;
    Car* next;
    Car* prev;
  };

  Car* head;
  int opCounter;

 public:
  Train();
  void attachCar(bool isLightOn);
  int calculateLength();
  int getOpCounter() const;
};

#endif  // INCLUDE_TRAIN_H_
