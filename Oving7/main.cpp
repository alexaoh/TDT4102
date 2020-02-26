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

	Vector_ref<Emoji> emojis;
	
	EmptyFace faceEmpty{Point{200, 200},emojiRadius, Color::yellow, Color::white};
	emojis.push_back(faceEmpty);

	SmilingFace faceSmiley{Point{350, 200}, emojiRadius, Color::blue, Color::green};
	emojis.push_back(faceSmiley);

	SadFace faceSad{Point{500, 200}, emojiRadius, Color::red, Color::black};
	emojis.push_back(faceSad);

	AngryFace faceAngry{Point{650, 200}, emojiRadius, Color::red, Color::black};
	emojis.push_back(faceAngry);


	attachAllEmojis(emojis, win);

	win.wait_for_button();
}
