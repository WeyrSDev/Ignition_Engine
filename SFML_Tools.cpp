#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
//#include<GameObjects!!!!>		Theyre coming, they really are!!!
#include <math.h>
#include "SFML_Tools.h"








// this whole class is horrible, but there doesnt really seem to be any 
// alternatives that I can see at the moment. Its just too integral to how the
// engine handles inputs with regards to internal objects

key_commands::key_commands()
{	enter = false;
	space = false;
	period = false;
	left = false;
	right = false;
	up = false;
	down = false;
	tilde = false;
	v = false;
	z= false;
	x = false;
	t = false;
	r = false;
	q = false;
	w = false;
	e = false;
	a = false;
	s = false;
	d = false;
	c = false;
	l = false;
	equal = false;
	dash = false;
	plus = false;
	numpad0 = false;
	numpad1 = false;
	numpad2 = false;
	numpad3 = false;
	numpad4 = false;
	numpad5 = false;
	numpad6 = false;
	numpad7 = false;
	numpad8 = false;
	numpad9 = false;
	plus = false;
	minus = false;
}

key_commands::~key_commands()
{
}

// the function for handling which keyboard input was sent //

void Log_keystroke(sf::Keyboard::Key input_event, key_commands * icommands, bool key_down)
{	// The Enter or Return key
	if(input_event == sf::Keyboard::Return)
	{	icommands->enter = key_down;
		if(key_down == true)
		{	icommands->Enter();
		}
	}
	// Spacebar, space oddity, space pressme
	else if(input_event == sf::Keyboard::Space)
	{	icommands->space = key_down;
		if(key_down == true)
		{	icommands->Space();
		}
	}
	// The Arrow Keys
	else if(input_event == sf::Keyboard::Up)
	{	icommands->up = key_down;
		if(key_down == true)
		{	icommands->Up();
		}
	}
	else if(input_event == sf::Keyboard::Down)
	{	icommands->down = key_down;
		if(key_down == true)
		{	icommands->Down();
		}
	}
	else if(input_event == sf::Keyboard::Right)
	{	icommands->right = key_down;
		if(key_down == true)
		{	icommands->Right();
		}
	}
	else if(input_event == sf::Keyboard::Left)
	{	icommands->left = key_down;
		if(key_down == true)
		{	icommands->Left();
		}
	}
	// Tab Key
	else if(input_event == sf::Keyboard::Tab)
	{
	}
	// Tilde Key
	else if(input_event == sf::Keyboard::Tilde)
	{	icommands->tilde = key_down;
		if(key_down == true)
		{	icommands->Tilde();
		}
	}	
	// Alphabetical keys A-Z
	else if(input_event == sf::Keyboard::A)
	{	icommands->a = key_down;
		if(key_down == true)
		{	icommands->A();
		}
	}
	else if(input_event == sf::Keyboard::B)
	{
	}
	else if(input_event == sf::Keyboard::C)
	{	icommands->c = key_down;
		if(key_down == true)
		{	icommands->C();
		}
	}
	else if(input_event == sf::Keyboard::D)
	{	icommands->d = key_down;
		if(key_down == true)
		{	icommands->D();
		}
	}
	else if(input_event == sf::Keyboard::E)
	{	icommands->e = key_down;
		if(key_down == true)
		{	icommands->E();
		}
	}
	else if(input_event == sf::Keyboard::F)
	{	icommands->f = key_down;
		if(key_down == true)
		{	icommands->F();
		}
	}
	//else if(input_event == sf::Keyboard::G)
	//{
	//}
	else if(input_event == sf::Keyboard::H)
	{
	}
	else if(input_event == sf::Keyboard::I)
	{	icommands->i = key_down;
		if(key_down == true)
		{	icommands->I();
		}
	}
	else if(input_event == sf::Keyboard::J)
	{
	}
	else if(input_event == sf::Keyboard::K)
	{
	}
	else if(input_event == sf::Keyboard::L)
	{	icommands->l = key_down;
		if(key_down == true)
		{	icommands->L();
		}
	}
	else if(input_event == sf::Keyboard::M)
	{
	}
	else if(input_event == sf::Keyboard::N)
	{	icommands->n = key_down;
		if(key_down == true)
		{	icommands->N();
		}
	}
	else if(input_event == sf::Keyboard::O)
	{
	}
	else if(input_event == sf::Keyboard::P)
	{
	}
	else if(input_event == sf::Keyboard::Q)
	{	icommands->q = key_down;
		if(key_down == true)
		{	icommands->Q();
		}
	}
	else if(input_event == sf::Keyboard::R)
	{	icommands->r = key_down;
		if(key_down == true)
		{	icommands->R();
		}
	}
	else if(input_event == sf::Keyboard::S)
	{	icommands->s = key_down;
		if(key_down == true)
		{	icommands->S();
		}
	}
	else if(input_event == sf::Keyboard::T)
	{	icommands->t = key_down;
		if(key_down == true)
		{	icommands->T();
		}
	}
	else if(input_event == sf::Keyboard::U)
	{
	}
	else if(input_event == sf::Keyboard::V)
	{	icommands->v = key_down;
		if(key_down == true)
		{	icommands->V();
		}
	}
	else if(input_event == sf::Keyboard::W)
	{	icommands->w = key_down;
		if(key_down == true)
		{	icommands->W();
		}
	}
	else if(input_event == sf::Keyboard::X)
	{	icommands->x = key_down;
		if(key_down == true)
		{	icommands->X();
		}
	}
	else if(input_event == sf::Keyboard::Y)
	{
	}
	else if(input_event == sf::Keyboard::Z)
	{	icommands->z = key_down;
		if(key_down == true)
		{	icommands->Z();
		}
	}	// Assorted keys, without any real category
	else if(input_event == sf::Keyboard::Comma)
	{	icommands->comma = key_down;
		if(key_down == true)
		{	icommands->Comma();
		}
	}
	else if(input_event == sf::Keyboard::Dash)
	{	icommands->dash = key_down;
		if(key_down == true)
		{	icommands->Dash();
		}
	}
	else if(input_event == sf::Keyboard::Delete)
	{
	}
	else if(input_event == sf::Keyboard::Divide)
	{
	}
	else if(input_event == sf::Keyboard::BackSlash)
	{
	}
	else if(input_event == sf::Keyboard::BackSpace)
	{	
	}
	else if(input_event == sf::Keyboard::Equal)
	{	icommands->equal = key_down;
		if(key_down == true)
		{	icommands->Equal();
		}
	}
	else if(input_event == sf::Keyboard::Escape)
	{
	}
	else if(input_event == sf::Keyboard::LAlt)
	{
	}
	else if(input_event == sf::Keyboard::LBracket)
	{
	}
	else if(input_event == sf::Keyboard::RBracket)
	{
	}
	else if(input_event == sf::Keyboard::LControl)
	{
	}
	else if(input_event == sf::Keyboard::RControl)
	{
	}
	else if(input_event == sf::Keyboard::LShift)
	{
	}
	else if(input_event == sf::Keyboard::RShift)
	{
	}
	else if(input_event == sf::Keyboard::Menu)
	{
	}
	else if(input_event == sf::Keyboard::Multiply)
	{
	}
	else if(input_event == sf::Keyboard::Period)
	{	icommands->period = key_down;
		if(key_down == true)
		{	icommands->Period();
		}
	}
	else if(input_event == sf::Keyboard::Quote)
	{
	}
	else if(input_event == sf::Keyboard::Slash)
	{
	}	// Pageup/Pagedown
	else if(input_event == sf::Keyboard::PageDown)
	{
	}
	else if(input_event == sf::Keyboard::PageUp)
	{
	}	// Windows/OSX/Super key whatever you wanna call it
	else if(input_event == sf::Keyboard::LSystem)
	{
	}
	else if(input_event == sf::Keyboard::RSystem)
	{
	}	// Numeric inputs (row beneath the F## keys)
	else if(input_event == sf::Keyboard::Num0)
	{	
	}
	else if(input_event == sf::Keyboard::Num1)
	{
	}
	else if(input_event == sf::Keyboard::Num2)
	{
	}
	else if(input_event == sf::Keyboard::Num3)
	{
	}
	else if(input_event == sf::Keyboard::Num4)
	{
	}
	else if(input_event == sf::Keyboard::Num5)
	{
	}
	else if(input_event == sf::Keyboard::Num6)
	{
	}
	else if(input_event == sf::Keyboard::Num7)
	{
	}
	else if(input_event == sf::Keyboard::Num8)
	{
	}
	else if(input_event == sf::Keyboard::Num9)
	{
	}	// The Numpad. Beware Vaughan!!!
	else if(input_event == sf::Keyboard::Numpad0)
	{	icommands->numpad0 = key_down;
		if(key_down == true)
		{	std::cout << "numpad0 keydown" << std::endl;
			icommands->Numpad_0();
		}
	}
	else if(input_event == sf::Keyboard::Numpad1)
	{	std::cout << "numpad1 keyevent" << std::endl;
		icommands->numpad1 = key_down;
		if(key_down == true)
		{	icommands->Numpad_1();
		}
	}
	else if(input_event == sf::Keyboard::Numpad2)
	{	std::cout << "numpad1 keyevent" << std::endl;
		icommands->numpad2 = key_down;
		if(key_down == true)
		{	icommands->Numpad_2();
		}
	}
	else if(input_event == sf::Keyboard::Numpad3)
	{	icommands->numpad3 = key_down;
		if(key_down == true)
		{	icommands->Numpad_3();
		}
	}
	else if(input_event == sf::Keyboard::Numpad4)
	{	icommands->numpad4 = key_down;
		if(key_down == true)
		{	icommands->Numpad_4();
		}
	}
	else if(input_event == sf::Keyboard::Numpad5)
	{	icommands->numpad5 = key_down;
		if(key_down == true)
		{	icommands->Numpad_5();
		}
	}
	else if(input_event == sf::Keyboard::Numpad6)
	{	icommands->numpad6 = key_down;
		if(key_down == true)
		{	icommands->Numpad_6();
		}
	}
	else if(input_event == sf::Keyboard::Numpad7)
	{	icommands->numpad7 = key_down;
		if(key_down == true)
		{	icommands->Numpad_7();
		}
	}
	else if(input_event == sf::Keyboard::Numpad8)
	{	icommands->numpad8 = key_down;
		if(key_down == true)
		{	icommands->Numpad_8();
		}
	}
	else if(input_event == sf::Keyboard::Numpad9)
	{	icommands->numpad9 = key_down;
		if(key_down == true)
		{	icommands->Numpad_9();
		}
	}
	else if(input_event == sf::Keyboard::Add)
	{	icommands->plus = key_down;
		if(key_down == true)
		{	icommands->Plus();
		}
	}		// must add minus
	else if(input_event == sf::Keyboard::Subtract)
	{	icommands->minus = key_down;
		if(key_down == true)
		{	icommands->Minus();
		}
	}
}

// SFML_Window Utility class ///////////////////////////////////////////////////

SFML_Window::SFML_Window(std::string title, unsigned int h, unsigned int w)
{	Title = title;
	Height = h;
	Width = w;
	Aperture_height = h*10;
	Aperture_width = w*10;
	Set_origin();
	window = new sf::RenderWindow(sf::VideoMode(w, h), Title);
	window->setSize(sf::Vector2u(h, w));
	window->setTitle(Title);
}

void SFML_Window::Set_origin()
{	origin.x = 0;
	origin.y = 0;
}

void SFML_Window::Set_origin(long double x, long double y)
{	origin.x = x;
	origin.y = y;
}

void SFML_Window::Set_aperture_dimensions(long long unsigned int ap_w, long long unsigned int ap_h)
{	Aperture_width = ap_w;
	Aperture_height = ap_h;
}

SFML_Window::~SFML_Window()
{	delete window;
}

// SFML splash screen class ////////////////////////////////////////////////////

SFML_loadscreen::SFML_loadscreen(std::string texture_path, bool fadein, double fade_in_length, double fade_out_length)
{	Active = true;
	splash_texture = new sf::Texture();
	if(!splash_texture->loadFromFile(texture_path))
	{	this->~SFML_loadscreen();
	}
	else
	{	splash_sprite = new sf::Sprite();
		splash_sprite->setTexture(*splash_texture);
	}	Fader = 0;
	Fading_out = false;
	Fade_clock = new sf::Clock();
	if(fadein == true)
	{	Fade_in();
	}
	else
	{	Fading_in = false;
	}	Fade_in_time = fade_in_length;
	Fade_out_time = fade_out_length;
	splash_sprite->setColor(sf::Color(255, 255, 255, ((Fader)*255)));
}

void SFML_loadscreen::Fade_in()
{	Fading_in = true;
	Fade_clock->restart();
}

void SFML_loadscreen::Fade_out()
{	Fading_out = true;
	Fade_clock->restart();
}

void SFML_loadscreen::Toggle_fade()
{	if(Fading_in == true)
	{	if((Fading_out == false)&&(Fader != 1.000))
		{	std::cout << "Toggle Fadein" << std::endl;
			Fade_in();
		}
		else
		{	Fade_out();
			std::cout << "Toggle Fadeout" << std::endl;
		}
	}
}

void SFML_loadscreen::Update_screen()
{	if(((Fading_in == true)&&(Fader != 1.000))||((Fading_out == true)||(Fader != 0.000)))
	{	sf::Time time = Fade_clock->getElapsedTime();
		if(time.asMilliseconds() > 100)
		{	double increment = time.asMilliseconds();
			if((Fading_in == true)&&(Fading_out == false))
			{	Fader += (increment/(Fade_in_time*1000));
				if(Fader > 1.0000)
				{	Fader = 1.0000;
				}
			}
			else if((Fading_in == true)&&(Fading_out == true))
			{	Fader -= (increment/(Fade_in_time*1000));
				if(Fader < 0.0000)
				{	Fader = 0.0000;
				}
			}	splash_sprite->setColor(sf::Color(255, 255, 255, ((Fader)*255)));
			Fade_clock->restart();
		}
	}
	if((Fader == 0.000)&&(Fading_in == true)&&(Fading_out == true)&&(Active == true))
	{	std::cout << "Loadscreen Dropout" << std::endl;
		Active = false;
	}
}

SFML_loadscreen::~SFML_loadscreen()
{	delete splash_sprite;
	delete splash_texture;
	delete Fade_clock;
}

// SFML title screen class /////////////////////////////////////////////////////

SFML_titlescreen::SFML_titlescreen(std::string texture_path, bool fadein, double fade_in_length, double fade_out_length, std::string title, std::string font_path, unsigned int textr, unsigned int textg, unsigned int textb, unsigned int pfont, sf::Vector2f Title_pos)
{	Active = true;
	splash_texture = new sf::Texture();
	splash_sprite = new sf::Sprite();
	if(!splash_texture->loadFromFile(texture_path))
	{	this->~SFML_titlescreen();
	}
	else
	{	splash_sprite->setTexture(*splash_texture);
	}	Fader = 0;
	Fading_out = false;
	Fade_clock = new sf::Clock();
	if(fadein == true)
	{	Fade_in();
	}
	else
	{	Fading_in = false;
	}	Fade_in_time = fade_in_length;
	Fade_out_time = fade_out_length;
	splash_sprite->setColor(sf::Color(255, 255, 255, 0));
	Title_font = new sf::Font();
	if(!Title_font->loadFromFile(font_path))
	{	this->~SFML_titlescreen();
	}
	else
	{	Title_text = new sf::Text(title, *Title_font, pfont);
		Title_text->setColor(sf::Color(textr, textg, textb, 0));
		r = textr;
		g = textg;
		b = textb;
	}	Title_position = Title_pos;
	Title_text->setPosition(Title_position);
	finished = false;
}

void SFML_titlescreen::Fade_in()
{	Fading_in = true;
	Fade_clock->restart();
}

void SFML_titlescreen::Fade_out()
{	Fading_out = true;
	Fade_clock->restart();
}

void SFML_titlescreen::Toggle_fade()
{	if(Fading_in == true)
	{	if((Fading_out == false)&&(Fader != 1.000))
		{	std::cout << "Toggle Fadein" << std::endl;
			Fade_in();
		}
		else
		{	Fade_out();
			std::cout << "Toggle Fadeout" << std::endl;
		}
	}
}

void SFML_titlescreen::Update_screen()
{	if(((Fading_in == true)&&(Fader != 1.000))||((Fading_out == true)||(Fader != 0.000)))
	{	sf::Time time = Fade_clock->getElapsedTime();
		if(time.asMilliseconds() > 100)
		{	double increment = time.asMilliseconds();
			if((Fading_in == true)&&(Fading_out == false))
			{	Fader += (increment/(Fade_in_time*1000));
				if(Fader > 1.0000)
				{	Fader = 1.0000;
				}
			}
			else if((Fading_in == true)&&(Fading_out == true))
			{	Fader -= (increment/(Fade_in_time*1000));
				if(Fader < 0.0000)
				{	Fader = 0.0000;
					finished = true;
					//Deallocate_me();
				}
			}	splash_sprite->setColor(sf::Color(255, 255, 255, ((Fader)*255)));
			Title_text->setColor(sf::Color(r, g, b, Fader*(255)));
			Fade_clock->restart();
		}
	}
	if((Fader == 0.000)&&(Fading_in == true)&&(Fading_out == true)&&(Active == true))
	{	std::cout << "Loadscreen Dropout" << std::endl;
		Active = false;
	}
}
 



SFML_titlescreen::~SFML_titlescreen()
{	delete Title_text;
	delete Title_font;
	delete splash_sprite;
	delete splash_texture;
	delete Fade_clock;
}

// SFML Audio Class ////////////////////////////////////////////////////////////

SFML_gameaudio::SFML_gameaudio(std::string Intro_audiopath, std::string Game_musicpath)
{	Intro_audio = new sf::SoundBuffer();
	Intro_finished = false;
	Game_music = new sf::Music();
	if((!Intro_audio->loadFromFile(Intro_audiopath))||(!Game_music->openFromFile(Game_musicpath)))
	{	std::cout << "Unable to load game audio" << std::endl;
		this->~SFML_gameaudio();
	}	
	else
	{	Music_paths.emplace_back(Game_musicpath);
		it_music = (Music_paths.begin()+1);
		Audio = new sf::Sound(*Intro_audio);
	}	
	Play_intro();
}

void SFML_gameaudio::Update_game_audio()
{	if((Intro_finished == false)&&(Audio->getStatus() == sf::Sound::Status::Stopped))
	{	Intro_finished = true;
		Play_music(false);				// Start playing the game music & loop
	}
	else if((Game_music->getStatus() == sf::Sound::Status::Stopped)&&(Intro_finished == true))
	{	Increment_game_music();
		Play_music(false);
	}
}

void SFML_gameaudio::Increment_game_music()
{	if(Music_paths.size() > 1)
	{	unsigned int cy = 0;
		for(std::vector<std::string>::iterator it = Music_paths.begin(); it != Music_paths.end(); ++it)
		{	if((*it) == (*it_music))
			{	if(it == Music_paths.begin())
				{	(*it_music) = Music_paths.at(Music_paths.size() - 1);
				}
				else if (it > Music_paths.begin())
				{	(*it_music) = Music_paths.at(cy - 1);
				}
				break;
			}
			cy++;
		}
		Game_music->openFromFile(*it_music);
	}
	else
	{	Play_music(false);
	}
}

void SFML_gameaudio::Play_intro()
{	Audio->play();
}

void SFML_gameaudio::Play_music(bool loop)
{	Game_music->play();
	Game_music->setLoop(loop);
}

void SFML_gameaudio::Stop_music()	// Please dont call the Stop_music(), Stop_music()
{	Game_music->stop();
}

SFML_gameaudio::~SFML_gameaudio()
{	delete Audio;
	delete Intro_audio;
	delete Game_music;
}

std::string Input_string(std::string prompt)		// this should go, not
{	std::string data = "";	// a great idea in a project primarily focused
	while(true)				// on gui
	{	std::cout << std::endl;
		std::cout << prompt;
		while(std::getline(std::cin, data))
		{	if (data.size() == 0)
			{	continue;	
			}	
			else
			{	return data;
			}	
		}
	}
}