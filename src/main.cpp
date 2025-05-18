// Copyright 2022 NNTU-CS
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include "train.h"

void printHeader() {
  std::cout << "Train Length\tMode\t\tOperations\tTime (µs)\n";
  std::cout << "----------------------------------------------------------\n";
}

void runExperiment(int numCars, const std::string& mode) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<> dist(0, 1);
  Train train;

  // Добавление вагонов с соответствующим состоянием лампочки
  for (int i = 0; i < numCars; ++i) {
    bool light = (mode == "random") ? dist(gen) : (mode == "all_on");
    train.addCar(light);
  }

  auto start = std::chrono::high_resolution_clock::now();
  train.getLength();
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

  std::cout << numCars << "\t\t" << mode << "\t\t"
            << train.getOpCount() << "\t\t"
            << duration << "\n";
}

int main() {
  printHeader();
  const int tests[] = { 60, 120, 300, 600, 900, 1200 };
  for (int n : tests) {
    runExperiment(n, "all_off");
    runExperiment(n, "all_on");
    runExperiment(n, "random");
    std::cout << "----------------------------------------------------------\n";
  }
  return 0;
}
