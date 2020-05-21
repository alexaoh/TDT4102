#include "Task4.h"

bool is_inside_rectangle(int x, int y, int r_x, int r_y, int r_width, int r_height){
    //antar at (r_x, r_y) er øvre venstre hjørne til rektangelet. 
    //y vokser nedover. 
    return (x>r_x) && (x<r_x+r_width) && (y>r_y) && (y<r_y+r_height);
}

bool is_inside_circle(int x, int y, int c_x, int c_y, int c_rad){
    return (pow(x-c_x,2)+pow(y-c_y, 2)) < pow(c_rad, 2);
}


Color string_to_color(string color){
    return colors.at(color); //.at kaster unntaket dersom color ikke finnes i colors. 
}

string color_to_string(Color color){
    for (const auto pair : colors){
        if (pair.second == color){ //antar at == er definert for Color.
            return pair.first;
        }
    }
    return "unknown color";
}

string DAKRectangle::to_string() const {
    ostringstream os;
    Point point = rectangle.point(0);
    os << "rect " << color_to_string(get_color()) << " "
    << point.x << " " << point.y << rectangle.width() << " " << rectangle.height();
    return os.str();
}

bool DAKRectangle::is_inside(Point p){
    return is_inside_rectangle(p.x, p.y, rectangle.point(0).x, rectangle.point(0).y, rectangle.width(), rectangle.height());
}

void MiniDAK::on_enter_pressed(){
    string command = cmd_box.get_string(); 
    try{
        do_command(command);
        cmd_box.clear_value();
    } catch (exception& e){
        cerr << "do_command() kastet et unntak: " << e.what() << endl;
    }   
}

void MiniDAK::on_mouse_click(int x, int y){
    mouse = {x, y};
    selected_shape = -1;
    for (int i = 0; i < shapes.size(); ++i){
        if (shapes[i].is_inside(mouse)) selected_shape = i;
    }
}

void MiniDAK::on_mouse_drag(int x, int y){
    if (selected_shape != -1){
        shapes[selected_shape].move(x-mouse.x, y-mouse.y); //Siden move bruker dx og dy. 

        mouse = {x,y};
    }
}

void MiniDAK::save(string filename){
    ofstream ost{filename};
    if(!ost) throw runtime_error("Cannot open file "+filename);
    for (const auto shape : shapes){
        ost << shape->to_string() << endl;
    }
}

void MiniDAK::load(string filename){
    ifstream ist{filename};
    if (!ist) throw runtime_error("Cannot open file "+filename);
    int lineNumber{1};
    for (string command; getline(ist, command); ){
        try{
            do_command(command);
        } catch (exception& e){
            cerr << "Exception caught in do_command(): " << e.what() << ". Something went wrong i line " << lineNumber;
        }
        lineNumber++;
    }
}

void MiniDAK::do_command(string command){
    istringstream iss{command};
    string first, second, x, y, w, h;
    iss >> first >> second;
    if (first == "save"){
        if (second.size() == 0) throw runtime_error("Missing filename as second argument");
        save(second);
    } else if (first == "load"){
        if (second.size() == 0) throw runtime_error("Missing filename as second argument");
        load(second);
    } else if (first == "rect" || first == "circle"){
        Color color = string_to_color(second);
        iss >> x >> y >> w;
        if (first == "rect"){
             iss >> h;
             DAKRectangle rect{Point{stoi(x), stoi(y)}, stoi(w), stoi(h)};
        } else {
            DAKCircle circle{Point{stoi(x), stoi(y)}, stoi(r)};
        }
    } else {
        throw runtime_error("Unknown command "+first);
    }
}