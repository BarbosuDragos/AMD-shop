#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

class Produs {
protected:
	float weight;
	float height;
	int TDP;
	int nms;
	int memory;
	std::string clock_frequency;
public:
	Produs() {
		weight = 0;
		height = 0;
		TDP = 0;
		nms = 0;
		memory = 0;
		clock_frequency = "";
	}
	Produs(float weight, float height, int TDP, int nms, int memory, std::string frequency) {
		this->weight = weight;
		this->height = height;
		this->TDP = TDP;
		this->nms = nms;
		this->clock_frequency = frequency;
	}
};
class CPU : public Produs {
private:
	int cores;
	int threads;
	std::string socket;
public:
	CPU() {
		cores = 0;
		threads = 0;
		socket = "";
	}
	CPU(int cores, int threads, std::string socket, float weight, float height, int TDP, int nms, int memory, std::string frequency) {
		this->weight = weight;
		this->height = height;
		this->TDP = TDP;
		this->nms = nms;
		this->memory = memory;
		this->clock_frequency = frequency;
		this->cores = cores;
		this->threads = threads;
		this->socket = socket;

	}
};
class GPU : public Produs {
private:
	int maximum_resolution;
	std::string Technologies;
public:
	GPU() {
		maximum_resolution = 0;
		Technologies = "";
	}
	GPU(int resolution, std::string Technologies, float weight, float height, int TDP, int nms, int memory, std::string frequency) {
		this->weight = weight;
		this->height = height;
		this->TDP = TDP;
		this->nms = nms;
		this->memory = memory;
		this->clock_frequency = frequency;
		this->maximum_resolution = resolution;
		this->Technologies = Technologies;
	}
};
class APU : public Produs {
private:
	int cores;
	int threads;
	std::string socket;
	int maximum_resolution;
	std::string Tehnologies;
public:
	APU() {
		cores = 0;
		threads = 0;
		socket = "";
		maximum_resolution = 0;
		Tehnologies = "";
	}
	APU(float weight, float height, int TDP, int nms, int memory, std::string frequency, int cores, int threads, std::string socket, int resolution, std::string Tehnologies) {
		this->weight = weight;
		this->height = height;
		this->TDP = TDP;
		this->nms = nms;
		this->memory = memory;
		this->clock_frequency = frequency;
		this->cores = cores;
		this->threads = threads;
		this->socket = socket;
		this->maximum_resolution = resolution;
		this->Tehnologies = Tehnologies;
	}

};