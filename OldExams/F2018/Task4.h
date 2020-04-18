#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>

class Layer{
    int N;
    int M;
    std::vector<double> a; 
    std::vector<double> w;
public: 
    Layer(int N, int M);
    int getSize() const { return N; }
    int getInputSize() const { return M; }
    void setWeight(int j, int i, double weight);
    double getWeight(int j, int i);
    virtual double fn(double x) { return x; }
    //Denne må være virtual for at den skal kunne overskrives av klasser som arver fra Layer-klassen. 
    void forward(const std::vector<double>& input);
    void forward(Layer* lay);

};

class SigmoidLayer : public Layer{
public: 
    SigmoidLayer(int N, int M):Layer(N, M){}
    virtual double fn(double x) override { return 1/(1+exp(-x)); }
};

class NeuralNet{
protected: 
    std::vector<Layer*> layers;
public: 
    NeuralNet(){}
    void addLayer(Layer* layer);
    Layer* forward(const std::vector<double>& input);
};
