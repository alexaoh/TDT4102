#include "Task4.h"

Layer::Layer(int N, int M):N{N}, M{M}{
    for (int i = 0; i<N; ++i){
        a.push_back(0);
    }

    for (int i = 0; i<M*N; ++i){
        w.push_back(1);
    }
}

void Layer::setWeight(int j, int i, double weight){
    w[j*M + 1] = weight;
}

double Layer::getWeight(int j, int i){
    return w[j*M + i];
}

void Layer::forward(const std::vector<double>& input){
    if (input.size() != M) throw;
    for (int j = 0; j < a.size(); ++j){
        int sum{0};
        for (int i = 0; i<M; ++i){
            sum += getWeight(j, i)*input[i];
            
        }
        a[j] = fn(sum);
    }
}

void Layer::forward(Layer* lay){
    forward(lay->a);
}

void NeuralNet::addLayer(Layer* layer){
    if (layers.size()){
        assert(layers[layers.size()-1]->getSize() == layer->getInputSize());
    }
    layers.push_back(layer);
}

Layer* NeuralNet::forward(const std::vector<double>& input){
    layers[0]->forward(input);
    for (int i = 1; i < layers.size(); ++i){
        layers[i]->forward(layers[i-1]);
    }
    return layers[layers.size()-1];
}
