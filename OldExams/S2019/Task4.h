#include <cmath>
#include <map>
#include <string>
#include <Graph.h>
#include <Window.h>
#include <sstream>
#include <GUI.h>
#include <stdexcept>
#include <fstream>

using namespace std;
using namespace Graph_lib;

map<string, Color> colors = {
    {"red", Color::red},
    {"blue", Color::blue},
    {"yellow", Color::yellow}, 
    {"cyan", Color::cyan}, 
    {"green", Color::green}
    //... and more. 
};

bool is_inside_rectangle(int x, int y, int r_x, int r_y, int r_width, int r_height);
bool is_inside_circle(int x, int y, int c_x, int c_y, int c_rad);
Color string_to_color(string color);
string color_to_string(Color color);

class DAKShape{
protected: 
    Shape& shape;
    DAKShape(Shape& s):shape{s}{}
public: 
    virtual bool is_inside(const Point xy) const = 0;
    virtual string to_string() const = 0;
    virtual ~DAKShape() {}
    void attach_to(Graph_lib::Window& win){ win.attach(shape); }
    void move(int dx, int dy){ shape.move(dx, dy); }
    void set_color(Color c){ shape.set_fill_color(c); }
    Color get_color() const { return shape.fill_color(); }
};

class DAKRectangle : public DAKShape {
    Rectangle rectangle;
public: 
    DAKRectangle(Point xy, int w, int h):rectangle{xy, w, h}, DAKShape(rectangle){}
    string to_string() const override; 
    bool is_inside(Point p);
};

class DAKCircle : public DAKShape {
    //Implementert på samme måte som DAKRectangle
};

class MiniDAK : public Graph_lib::Window {
    In_box cmd_box;
    Vector_ref<DAKShape> shapes;
    int selected_shape;
    Point mouse; 
public: 
    MiniDAK(int w, int h);
    void add_shape(DAKShape* shape);
    int handle(int event);
    void on_enter_pressed();
    void on_mouse_click(int x, int y);
    void on_mouse_drag(int x, int y);
    void save(string filename);
    void load(string filename);
    void do_command(string command);
};  

