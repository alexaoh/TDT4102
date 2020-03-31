#include "utilities.h"

class Track : public Fl_Widget{
	std::vector<std::pair<double, double>> goals;
public: 
	Track();
	void draw() override;
};
