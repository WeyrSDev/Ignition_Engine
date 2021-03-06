// Ignition_Engine.h ///////////////////////////////////////////////////////////
// The class wrapper for the Ignition Engine as a whole ////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include "Deltaglider.hpp"

#ifndef IgnitionEngine
#define IgnitionEngine

class DeltaGlider;
// I dont think this forward declare is necessary anymore
// dont even recall why it was there in the first place

class Ignition_engine
{	public:
	Ignition_engine(std::string title, unsigned int initial_window_width, unsigned int initial_window_height, std::string program_version, double redraw_displays_interval, std::string standard_display_font, std::string starfield);
	// base constructor
	// future versions should eventually have more overloads for things like
	// start on construction, loading from a scn file or somesuch...
	// constructors always seem to be such exhausting work for some reason...
	
	bool Init_standard_displays();
	
	void Update_standard_displays();
	
	void Draw_standard_displays();
	
	
	SFML_Window * Main_Window;
	// pointer to our main window object, containing a sf::RenderWindow along
	// with some info about its title, viewport size & so on...
	
	key_commands * commands;
	// the awkward but effective method of handling inputs to objects
	// gets sent to the current vessel each frame
	
	Cursor_commands * cursor_commands;
	// same thing as key commands, but this time for the mouse
	
	TVessel * Current_vessel;
	// Reference to the current vessel the player is controlling. Might be
	// better to replace this with something less risky like a string handle
	
	sf::Texture * Background_tex;
	sf::Sprite * Background_sprite;
	// texture and sprite for our background starfield

	
	sf::Font standard_font;
	sf::Color standard_display_colour;
	
	Ignition_text fps_meter, map_scale_meter, time_accel_meter, sim_time_meter;
	
	Ignition_text camera_target_name;
	// right now it is always a vessel, but eventually it can be to anything
	// so ya
	
	bool map_view;
	// is the map view active? False denotes normal camera view
	
	int zoom_exponent;
	// the exponent a of the scale of our map view (ie base scale*(10^a))
	// 10^a is multiplied by the dimensions of the base map view (1024 x 609?)
	// originally this was some sort of issue with resets over a certain scale,
	// but its fixed now. I think this is safe to transfer back to a normal
	// int, the problem was located elsewhere I believe
	
	long double camera_scale;
	// the relative scale of the camera, with the default at 1 being the normal 
	// camera scale of 10 pixels per meter? Larger camera_scale values than one
	// indicate that the camera is zooming out, while smaller ones are for
	// zooming in
	
	double k_camera;
	//controls how fast the camera scales in and out, bigger values mean faster
	
	long double deltat;	
	// length of the frame previous to the current one in seconds. 
	// retrieved by a lovely sf::Clock in our main loop.
	// since the whole ignition may be passed by reference back to the game
	// objects themselves, this might be better to separate into actual deltat
	// and the modified value based on time acceleration
	
	double Redraw_interval;	
	// uhhh... oh yeah, the period for the refresh cycle of the onscreen
	// feedback displays, so that we arent wasting lots of processing power
	// updating their contents every frame when every 1-2 s or so is just fine. 
	// Also makes them easier to read too IIRC
	
	// this should also be tied into MFD/DAI display refresh methinks, since
	// the same problem applies there
	
	int time_acceleration_exponent;
	// same concept as the zoom exponent, just multiplied by the base deltat
	// time so that we can run the program faster than just real time
	
	
	long double simulation_time;
	// the total time the simulation has been open in in-universe seconds
	// (ie time accelerated time, not real time). This is a prime candidate
	// for merging with the time class from Countdown, seconds are unwieldy
	// for long timescales like this
	
	std::string Program_version;
	// ahhh... this might be the window titles last few digits indicating the
	// project number (0.1, 0.11, 0.71, 0.9, 1.0, etc...). Or maybe it was	double width_value = (double)initial_window_width;
	// something else entirely, I dont remember right now
	
	// this should be investigated soon, although I see no reason why it would
	// cause instability, so no worries
	
	bool Displays_active;	
	// indicates whether the feedback displays are on or off, toggled by hitting
	// the i key just like in Orbiter. This turns off everything save the basic
	// rendering (stars, ships, planets, etc)
	
	int Ignition();		
	// Lights this candle!
	// Basically the function that runs everything in the Ignition_Engine object
	// automatically
	
	// so you simply need to create a ignition engine object with its
	// constructor, call Ignition, and everything is handled from there
	
	// or at least thats the goal at the moment
	
	std::vector<CKeplerian_Object*> Celestial_list;
	std::vector<CNewtonian_Object*> Newtonian_list;
	std::vector<TVessel*> Vessel_list;
	
	void Handle_inputs();
	
	void Next_vessel();
	void Previous_vessel();
	
	void Map_view();
	void Increase_map_scale();
	// zooming out, making the area it covers bigger
	void Decrease_map_scale();
	// zooming in, making the area it covers smaller
	
	void Camera_view();
	
	void Increase_camera_scale();
	void Change_camera_scale(double wheel_delta);
	void Decrease_camera_scale();
	
	void Set_aperture_scale();
	
	void Increase_time_acceleration();
	void Decrease_time_acceleration();
	
	VectorVictor::Vector2 Camera_target;
	long double Camera_rotation;
	// the target for the camera and its rotation around the target point,
	// clockwise in degrees
	
	void Position_window(TVessel * target_vessel);
	// locate the window wherever we request
	// this can eventually be overloaded as we please to set focus on other
	// types of ingame objects
	
	~Ignition_engine();
};

void Init_assets(CKeplerian_Object * planet);
// load up our external assets in a baddish way. really needs fixing soon

void Exit_program();
// ugly cleanup function that never seems to have everything it needs.
// again, should be superseded by the Ignition destructor
// just ugly remnants of a young project

double Larger_of(double value1, double value2);

#endif
