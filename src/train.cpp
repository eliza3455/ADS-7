// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : opCounter(0), head(nullptr) {}

void Train::attachCar(bool isLightOn) {
  Car* newCar = new Car{isLightOn, nullptr, nullptr};

  if (!head) {
    newCar->next = newCar;
    newCar->prev = newCar;
    head = newCar;
  } else {
    Car* tail = head->prev;
    tail->next = newCar;
    newCar->prev = tail;
    newCar->next = head;
    head->prev = newCar;
  }
}

int Train::calculateLength() {
  if (!head) return 0;

  int total = 0;
  bool hasDarkCar = false;
  const Car* temp = head;

  do {
    if (!temp->light) hasDarkCar = true;
    ++total;
    temp = temp->next;
  } while (temp != head);

  opCounter = hasDarkCar ? 2 * total : total * (total + 1);
  return total;
}

int Train::getOpCounter() const {
  return opCounter;
}
