#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

class Produs {
protected:
	std::string Name;
	float price;
	float weight;
	float height;
	int TDP;
	int nms;
	int memory;
	std::string clock_frequency;
public:
	Produs() {
		Name = "";
		price = 0;
		weight = 0;
		height = 0;
		TDP = 0;
		nms = 0;
		memory = 0;
		clock_frequency = "";
	}
	Produs(float price, std::string Name, float weight, float height, int TDP, int nms, int memory, std::string frequency) {
		this->price = price;
		this->Name = Name;
		this->weight = weight;
		this->height = height;
		this->TDP = TDP;
		this->nms = nms;
		this->clock_frequency = frequency;
	}
	virtual void Pafisare() {

	}
	virtual void citire() {

	}
};
class CPU : virtual public Produs {
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
	CPU(float price, std::string Name, int cores, int threads, std::string socket, float weight, float height, int TDP, int nms, int memory, std::string frequency)
	 {
		this->price = price;
		this->Name = Name;
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
	void Pafisare() {
		std::ofstream pout("Produse.txt", std::ios::app);
		pout << "CPU " << " " << price << " " << Name << " " << weight << " " << height << " " << TDP << " " << nms << " " << memory << " " << clock_frequency << " " << cores << " " << threads << " " << socket << std::endl;

	}
	
};
class GPU : virtual public Produs {
private:
	std::string maximum_resolution;
	std::string Technologies;
public:
	GPU() {
		maximum_resolution = "";
		Technologies = "";
	}
	GPU(float price, std::string Name, std::string resolution, std::string Technologies, float weight, float height, int TDP, int nms, int memory, std::string frequency)
	 {
		this->price = price;
		this->Name = Name;
		this->weight = weight;
		this->height = height;
		this->TDP = TDP;
		this->nms = nms;
		this->memory = memory;
		this->clock_frequency = frequency;
		this->maximum_resolution = resolution;
		this->Technologies = Technologies;
	}
	void Pafisare() {
		std::ofstream pout("Produse.txt", std::ios::app);
		pout << "GPU " << " " << price << " " << Name << " " << weight << " " << height << " " << TDP << " " << nms << " " << memory << " " << clock_frequency << " " << maximum_resolution << " " << Technologies<< std::endl;

	}
};
class APU : public CPU, public GPU {
private:
	int cores;
	int threads;
	std::string socket;
	std::string maximum_resolution;
	std::string Tehnologies;
public:
	APU() {
		cores = 0;
		threads = 0;
		socket = "";
		maximum_resolution = "";
		Tehnologies = "";
	}
	APU(float price, std::string Name, float weight, float height, int TDP, int nms, int memory, std::string frequency, int cores, int threads, std::string socket, std::string resolution, std::string Tehnologies)
		:Produs(price, Name, weight, height,  TDP, nms,  memory,  frequency){
		this->price = price;
		this->Name = Name;
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
	void Pafisare() {
		std::ofstream pout("Produse.txt", std::ios::app);
		pout << "APU " << " " << price << " " << Name << " " << weight << " " << height << " " << TDP << " " << nms << " " << memory << " " << clock_frequency << " " << cores << " " << threads << " " << socket << " " << maximum_resolution << " " << Tehnologies << std::endl;

	}
};