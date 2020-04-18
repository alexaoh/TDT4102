#include "Task2.h"

void plotPoints(Plot& plt, float x[], float v[], int n){
    for (int i = 0; i < n; ++i){
        //plt.circle(x[i], y[i], 3, sf::Color::Red);
    }
}

void plotPointLines(Plot& plt, float x[], float v[], int n){
    for (int i = 0; i<n-1; ++i){
        //plt.line(x[i], y[i], x[i+1], y[i+1], sf::Color::Blue);
    }
}

void alim(float a[], int n, float& amin, float& amax){
    amin = a[0];
    amax = a[0];
    for (int i = 0; i<n; ++i){
        if (a[i]<amin) amin = a[i];
        if (a[i]>amax) amax = a[i];
    }
}

float scaleX(Plot& plt, float x, float xmin, float xmax){
    int pixels{1}; // = plt.getWidth()
    return pixels*(x-xmin)/(xmax-xmin);
}

float scaleY(Plot& plt, float y, float ymin, float ymax){
    int pixels{1}; // = plt.getHeight()
    return pixels*(y-ymin)/(ymax-ymin);
}

void plotScaled(Plot& plt, float x[], float y[], int n, std::string color, float xmin, float xmax, float ymin, float ymax){
    for (int i = 0; i<n-1; ++i){
        float x0 = scaleX(plt, x[i], xmin, xmax);
        float x1 = scaleX(plt, x[i+1], xmin, xmax);
        float y0 = scaleY(plt, y[i], ymin, ymax);
        float y1 = scaleY(plt, y[i+1], ymin, ymax);
        //plt.line(x0, x1, y0, y1, color);
    }
}

void plotScaled(Plot& plt, float x[], float y[], int n, std::string color = "black"){
    float xmin{x[0]};
    float xmax{x[0]};
    float ymin{y[0]};
    float ymax{y[0]};
    alim(x, n, xmin, xmax);
    alim(y, n, ymin, ymax);
    plotScaled(plt, x, y, n, color, xmin, xmax, ymin, ymax);
}


void plotMathFuncs(Plot& plt){
    const int N{360};
    float x[N];
    float sinX[N];
    float cosX[N];
    for(int i = 0; i<N; ++i){
        x[i] = i;
        sinX[i] = sin(i*M_PI / 180);
        cosX[i] = cos(i*M_PI / 180);

    }

    plotScaled(plt, x, sinX, N, "blue");
    plotScaled(plt, x, cosX, N, "red");
    
}

void plotSeries(Plot& plt, float** x, float** y, int n, int m){
    float xmin = x[0][0];
    float xmax = x[0][0];
    float ymin = y[0][0];
    float ymax = y[0][0];

    for (int i = 0; i<m, ++i){
        for (int e = 0; e<n, ++e){
            xmin = std::min(xmin, x[i][e]);
            xmax = std::max(xmax, x[i][e]);
            ymin = std::min(ymin, y[i][e]);
            ymax = std::max(ymax, y[i][e]);
        }
    }
    for (int i = 0; i<n; ++i){
        plotScaled(plt, x[i], y[i], n, "getColor", xmin, xmax, ymin, ymax);
    }
}

Series loadSeries(std::string filename){
    std::ifstream ist{filename};
    if (!ist) throw std::invalid_argument("Cannot open file "+filename);
    std::string line;
    getline(ist, line);
    std::stringstream ss{line};
    int n{0};
    int m{0};
    ss >> n >> m; 
    Series s;
    s.n = n; 
    s.m = m;
    s.x = new float*[m];
    s.y = new float*[m];

    for (int i = 0; i<m; ++i){
        s.x[i] = new float[n];
        s.y[i] = new float[n];
    }   
    //Se mye mer på denne oppgaven!!
    for (int ser = 0; ser<m; ++ser){
        getline(ist, line);
        std::stringstream ss{line};
        float value;
        int i = 0;
        float xValue = 0.0;
        while (ss >> value){
            s.y[ser][i] = value;
            s.x[ser][i] = xValue;
            i++;
            xValue = xValue + 1.0;
        }
    }
    return s;
}
