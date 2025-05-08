// Copyright 2022 NNTU-CS
#include "train.h"

Train::Train() : head(nullptr), operations(0) {}

Train::~Train() {
  if (!head) return;
  Car* current = head->next;
  while (current != head) {
    Car* temp = current;
    current = current->next;
    delete temp;
  }
  delete head;
  head = nullptr;
}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};

  if (!head) {
    newCar->next = newCar;
    newCar->prev = newCar;
    head = newCar;
  } else {
    Car* last = head->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = head;
    head->prev = newCar;
  }
}

int Train::getLength() {
  if (!head)
    return 0;

  int count = 0;
  bool hasUnlit = false;
  Car* current = head;

  do {
    if (!current->light)
      hasUnlit = true;
    current = current->next;
    ++count;
  } while (current != head);

  operations = hasUnlit ? 2 * count : count * (count + 1);
  return count;
}

int Train::getOpCount() const {
  return operations;
}
