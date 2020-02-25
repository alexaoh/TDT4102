#include "Simple_window.h"
#include "Emoji.h"
#include "task1.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 75;

int main()
{
	/*Task 1: 
    Forskjellen er på public, private og protected er: 
    - Public => Alle har tilgang til dataene
    - Private => Kun medlemsfunskjoner i samme klasse/struct har tilgang til dataene
    - Protected => Kun "childs", dvs klasser som arver fra den gitte klassen, 
	kan få tak i dataene/benytte funksjonene som står der. 
    Dette sikrer at den gitte klassen kun brukes som abstract klasse, 
    som f.eks Shape-klassen i Graph_lib (ikke mulig å lage objekter av den). 


	//testAnimal();
	*/
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 **/

	EmptyFace face1{Point{200, 200},emojiRadius, Color::yellow, Color::white};
	face1.attach_to(win);

	SmilingFace face2{Point{350, 200}, emojiRadius, Color::blue, Color::green};
	face2.attach_to(win);

	SadFace face3{Point{500, 200}, emojiRadius, Color::red, Color::black};
	face3.attach_to(win);

	//Se oppgaven: Emojien skal festes til skjerm på en annen måte enn jeg har gjort"
	//Se over øvingen på nytt, og pass på at jeg har gjort den på en fornuftig måte!
	//Det virker lite fornuftig per nå!

	win.wait_for_button();
}
