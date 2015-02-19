#include <string>
#include <iostream>
#include <math.h>
#include "Keplerian_objects.hpp"

// Force handling class ////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

Force::Force(VectorVictor::Vector2 attack_point, VectorVictor::Vector2 force)
{	Attack_point = attack_point;
	Force_vector = force;
	// simple assignment using standard operators
}

double Force::Get_force_torque(VectorVictor::Vector2 reference_point)
{	double torque = 0;
	VectorVictor::Vector2 new_attack_point = Attack_point;
	new_attack_point -= reference_point;
	// new_attack_point needs to be the relative offset of the attack point from
	// the reference point, probably the new center of mass
	torque += VectorVictor::Get_cross_product(new_attack_point, Force_vector);
	// obtain our torque component in the z axis using the VV function & return
	return torque;
}

// ^ this isnt used yet, but will come into play soon enough

double Force::Get_force_torque()
{	double torque = 0;
	torque += VectorVictor::Get_cross_product(Attack_point, Force_vector);
	// same deal as before, just we assume the reference point is still (0,0)
	return torque;
}

VectorVictor::Vector2 Force::Get_force_vector()
{	return Force_vector;
	// simple return
}

VectorVictor::Vector2 Force::Get_force_vector(double angle)
{	return Force_vector.Get_rotated_vector(angle);
	// same as before, but rotated clockwise about the origin by 'angle' degrees
	// dont recall exactly why this is, here, but coordinate system transforms
	// are probably involved
}

Force::~Force()
{
}


// Planetary_surface //////////////////////////////////////////////////////////
// A class to render planet surface segments piece by piece when the main /////
// window is close enough to the ground that it is required ///////////////////
///////////////////////////////////////////////////////////////////////////////

Planetary_surface::Planetary_surface()
{	// ummm...
}

Planetary_surface::Planetary_surface(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{	if(!this->load(tileset, tileSize, tiles, width, height))
	{	std::cout << "Failed to load planetary surface in Planetary_surface::Planetary_surface(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)" << std::endl;
		std::cout << "Unable to load tileset at " << tileset << std::endl;
	}
}
	
Planetary_surface::Planetary_surface(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)
{	if(!this->load(tileset, tileSize, tiles, width, height))
	{	std::cout << "Failed to load planetary surface in Planetary_surface::Planetary_surface(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)" << std::endl;
		std::cout << "Unable to load tileset at " << tileset << std::endl;
	}
}

Planetary_surface::Planetary_surface(sf::Texture &tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)
{	if(!this->load(tileset, tileSize, tiles, width, height))
	{	std::cout << "Failed to load planetary surface in Planetary_surface::Planetary_surface(sf::Texture &tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)" << std::endl;
		// this should never come up, cause this version of the function cant
		// even return false anyways
		
		// we'll see
	}
}
	

bool Planetary_surface::load(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)
{	// load the tileset texture
	if(!m_tileset.loadFromFile(tileset))
	{	return false;
	}
	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);
	// populate the vertex array, with one quad per tile
	// why is it 4 though...
	for(unsigned int i = 0; i < width; ++i)
	{	for(unsigned int j = 0; j < height; ++j)
		{	// get the current tile number
			int tileNumber = tiles.at(i+(j*width));
			// find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];
			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	}
	return true;
}

bool Planetary_surface::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{	// load the tileset texture
	if(!m_tileset.loadFromFile(tileset))
	{	return false;
	}
	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);
	// populate the vertex array, with one quad per tile
	// why is it 4 though...
	for(unsigned int i = 0; i < width; ++i)
	{	for(unsigned int j = 0; j < height; ++j)
		{	// get the current tile number
			int tileNumber = tiles[i+(j*width)];
			// find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];
			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	}
	return true;
}

bool Planetary_surface::load(sf::Texture &tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)
{	// set the tileset sf texture to the same point in memory as what was passed
	// this is risky, but yolo
	//(m_tileset&) = tileset;
	
	// it just dont wanna work
	
	// and if this really doesnt work, we can do it the conventional way
	m_tileset = tileset;
	
	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);
	// populate the vertex array, with one quad per tile
	// why is it 4 though...
	for(unsigned int i = 0; i < width; ++i)
	{	for(unsigned int j = 0; j < height; ++j)
		{	// get the current tile number
			int tileNumber = tiles[i+(j*width)];
			// find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];
			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	}
	return true;
}


void Planetary_surface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{	// apply the transform
	states.transform *= getTransform();
	// apply the tileset texture
	states.texture = &m_tileset;
	// draw the vertex array
	target.draw(m_vertices, states);
}

Planetary_surface::~Planetary_surface()
{	
}


// Terrain_point ///////////////////////////////////////////////////////////////
// The info about each point on the planetary surface that is stored in a big //
// list for each celestial body ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

Terrain_point::Terrain_point()
{	Terrain_type = 0;
	// set the terrain to our default type
	Radius = -1;
	// hopefully flags it as set up by the default constructor
	Point_id = -1;
	// definitely flags it as something wrong...
}

Terrain_point::Terrain_point(int terrain_type, long double radius, int point_id)
{	Terrain_type = terrain_type;
	Radius = radius;
	Point_id = point_id;
}

bool Terrain_point::Init_object(int terrain_type, long double radius, int point_id)
{	Terrain_type = terrain_type;
	Radius = radius;
	Point_id = point_id;
}

bool Terrain_point::Match_point(int point_id)
{	if(Point_id == point_id)
	{	return true;
	}
	return false;
	// why do I need this again...
}

Terrain_point::~Terrain_point()
{
}

// Celestial Bodies ////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void CKeplerian_Object::Frame(double dt, long double simtime)
{	std::cout << "Bad call to CKeplerian_Object::Frame(double dt)" << std::endl;
	// dont wanna call this, would be bad
}

long double CKeplerian_Object::Get_theta_in_degrees()
{	return Theta;
}

long double CKeplerian_Object::Get_theta_in_radians()
{	long double rad_theta = Theta;
	rad_theta *= 6.283185308;		// 4/3 pau actually ;)
	rad_theta /= 360;
	// just converts over to radians, then returns
	return rad_theta;	
}

long double CKeplerian_Object::Get_omega()
{	return Omega;
}

long double CKeplerian_Object::Get_radius(double longitude)
{	return Radius;
	// constant for now, but that will change
}

long double CKeplerian_Object::Get_mass()
{	return Mass;							
}

VectorVictor::Vector2 CKeplerian_Object::Get_position(long double sim_time)
{	//std::cout << "Bad call to CKeplerian_Object::Get_position(double sim_time)" << std::endl;
	VectorVictor::Vector2 origin(0.00000000000000000000,0.00000000000000000000);
	// not sure why all that was necessary, must have been bug-hunting
	return origin;
}	// this should be temporary, planets and moons really need to update
	// their own positions


void CKeplerian_Object::Gravitate(long double satellite_mass, long double satellite_rotation,VectorVictor::Vector2 satellite_position, std::vector<Force> &parent_force_list)
{	long double G = 6.673e-11; 
	long double M = this->Get_mass();	
	VectorVictor::Vector2 origin(0.0000000000000000,0.000000000000000);
	// get the mass of the gravitating body in question
	VectorVictor::Vector2 Vf(0,0);	 
	//this really needs to be fixed to the relative keplerian position
	// was a hack to get things to work, but needs to call the Keplerians
	// position function itself
	
	// * VERY IMPORTANT MUST FIX * //
	Vf -=  satellite_position;
	// Get the relative offset vector between the two objects
	
	long double radial_distance_squared = Vf.Get_vector_magnitude_squared();
	// get the r squared as you would expect
	
	Vf.Normalize();	
	// reduce our direction vector so we have only direction & magnitude 1
		
	long double Fmag = ((G*M)*satellite_mass);
	Fmag /= radial_distance_squared;
	// calculate the value of Fg
	Vf *= Fmag;
	// and multiply our vector by it
		
	long double rotation = (-satellite_rotation);
	// the force is originally in the global coordinates, but it needs to be
	// rotated into the reference frame of the vessels coordinate system
	// this is because the vessel reorients them all when it has its frame
	// call, and to it, a spade is a spade for any Force in the Force vector 
	Force New_force(origin, Vf.Get_rotated_vector(rotation));
	parent_force_list.insert(parent_force_list.end(), New_force); 
	// we construct the Force object, pin it onto the vessel in question
	// and we are done!
}

VectorVictor::Vector2 CKeplerian_Object::Gravity_acceleration(VectorVictor::Vector2 satellite_position, long double simtime)
{	long double G = 6.673e-11; 
	// universal gravitational constant. Because I said so, thats why!!!
	long double M = this->Get_mass();	
	// The mass of the large body doing the pulling here
	
	// sigh...
	
	//VectorVictor::Vector2 origin(0.00,0.00);
	
	
	VectorVictor::Vector2 gravity(0,0);	 
	gravity = this->Get_position(simtime);
	gravity -= satellite_position;
	
	long double radius_squared = gravity.Get_vector_magnitude_squared();
	// get the square of the distance in meters between the two objects
	
	gravity.Normalize();
	// normalize the vector, since we just need the direction of gravity with
	// a magnitude of 1 here
	gravity *= G;
	gravity *= M;
	gravity *= (1/radius_squared);
	// I really need to write that /= operator for VV2
	return gravity;
	// ignore everything after this line, theyre like the siren song of
	// commented code
	
	//this really needs to be fixed to the relative keplerian position
	// was a hack to get things to work, but needs to call the Keplerians
	// position function itself
	
	// * VERY IMPORTANT MUST FIX * //
	//Vf -=  satellite_position;
	// Get the relative offset vector between the two objects
	
	//long double radial_distance_squared = Vf.Get_vector_magnitude_squared();
	// get the r squared as you would expect
	
	//Vf.Normalize();	
	// reduce our direction vector so we have only direction & magnitude 1
		
	//long double Fmag = ((G*M)*satellite_mass);
	//Fmag /= radial_distance_squared;
	// calculate the value of Fg
	//Vf *= Fmag;
	// and multiply our vector by it
		
	//long double rotation = (-satellite_rotation);
	// the force is originally in the global coordinates, but it needs to be
	// rotated into the reference frame of the vessels coordinate system
	// this is because the vessel reorients them all when it has its frame
	// call, and to it, a spade is a spade for any Force in the Force vector 
	//Force New_force(origin, Vf.Get_rotated_vector(rotation));
	//parent_force_list.insert(parent_force_list.end(), New_force); 
	// we construct the Force object, pin it onto the vessel in question
	// and we are done!
}

std::string CKeplerian_Object::Get_object_name()
{	return Object_name;
}	

bool CKeplerian_Object::In_view(SFML_Window * window, int zoom_factor, long double simtime)
{	std::cout << "Bad call to CKeplerian_Object::In_view(SFML_Window * window, int zoom_factor, VectorVictor::Rectangle * view_frame)" << std::endl;
	return false;
}

bool CKeplerian_Object::In_view(SFML_Window * window, long double cam_scale, long double simtime)
{	std::cout << "Bad call to CKeplerian_Object::In_view(SFML_Window * window, long double cam_scale, long double simtime)" << std::endl;
	return false;
}

void CKeplerian_Object::Draw_flag(SFML_Window * iwindow, int zoom_factor)
{	std::cout << "Bad call to CKeplerian_Object::Draw_flag(SFML_Window * iwindow, int zoom_factor)" << std::endl;
}

void CKeplerian_Object::Draw_flag(SFML_Window * iwindow, long double cam_scale, long double sim_time)
{	std::cout << "Bad call to CKeplerian_Object::Draw_flag(SFML_Window * iwindow, long double cam_scale, long double sim_time)" << std::endl;
}

sf::Color CKeplerian_Object::Get_atmosphere_mask(VectorVictor::Vector2 window_origin, long double sim_time)
{	sf::Color transparent(255,255,255,0);
	// all transparent baby
	return transparent;
}

int CKeplerian_Object::Get_terrain_points()
{	return -1;
	// say whaaat
}

void CKeplerian_Object::Draw_surface(SFML_Window * iwindow)
{	// just yeah, dont look at this too hard just yet
}


CKeplerian_Object * CKeplerian_Object::Get_keplerian_pointer()
{	return this;
}

// cant call either of these functions, since info is required that is not
// available at this level. Buuut, if all the Keplerians get a position vector
// variable, it could work!

// changing this should be a priority














// TPlanet /////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

TPlanet::TPlanet(long double initial_theta, long double omega, long double radius, long double atmosphere_height, long double mass, std::string planet_texture_path, sf::Color top_atm_color, sf::Color surf_atm_color)
{	Theta = initial_theta;
	Omega = omega;
	Radius = radius;
	Mass = mass;
	
	Top_atmosphere_colour = top_atm_color;
	Top_atmosphere_colour.a = 0;
	// force it to 0 even if it aint so that we dont get some weirdly defined
	// atmosphere that doesnt smoothly fade to transparent as we go up
	Surface_atmosphere_colour = surf_atm_color;
	Surface_atmosphere_colour.a = 255;
	// it just is, okay?
	
	Atmosphere_height = atmosphere_height;
	
	Object_texture = new sf::Texture();
	if(!Object_texture->loadFromFile(planet_texture_path))
	{	std::cout << "Planet " << Get_object_name() << " unable to load texture at " << planet_texture_path << std::endl;
		// Houston, we have a problem.
	}
	else
	{	// the first part was just simple value copying, 
		// but this part gets hairy
		
		// we want to create sprites to represent the body in the map view at
		// multiple scales, specifically powers of 10, so we run a loop
		
		long double pix_length = Get_radius(0) + atmosphere_height;		
		// this was a decent fix for issues that popped up with the terrible
		// png circle the first time around
		
		// our pix length is going to be the diameter of the object in meters
		// ie, the dimensions of the image shown at the greatest zoom factor
		// This is a slight problem since large objects need massively scaled up
		// textures from their original dimensions
		
		// basically the idea here is that we run a loop that creates
		// consecutively smaller images by a factor of 10 to show at zoom levels
		// farther and farther out.
		pix_length /= 5;
		// in other words, multiply our radius by 2 to get diameter, then divide
		// by 10 to get the scale of the first zoom level (zoomed out by 10x)
		float sprite_x, sprite_y;
		// dimensions in pixels of the sprite at the given zoom level 
		for(unsigned int cy = 1; cy != Max_map_scale; ++cy)
		{	sf::Sprite * planet_sprite;
			planet_sprite = new sf::Sprite();
			planet_sprite->setTexture(*Object_texture);
			// we create the sprite at the given zoom level and assign it
			// the default texture
			
			// this really needs to be done without pointers, just pass the
			// reference of a normal object to the vector
			sprite_x = Object_texture->getSize().x;	sprite_x *= planet_sprite->getScale().x;
			sprite_y = Object_texture->getSize().y;  sprite_y *= planet_sprite->getScale().y;
			// for each axis, we find the size of the base texture in pixels,
			// and set the sprite dimensions to it
			
			// the second call involving getScale() seems to be redundant
			// since the scale is always (1,1) they dont seem to do anything
			// needs to be tested more just to be sure though
			std::cout << "sprite dimensions: " << sprite_x << " , " << sprite_y << std::endl;
			
			planet_sprite->setOrigin((sprite_x/2), (sprite_y/2));
			// set the origin of the sprite to the center instead of the top
			// left corner, much eaasier to deal with
			if(Object_texture->getSize().y != pix_length)
			{	planet_sprite->setScale((pix_length/(Object_texture->getSize().x)),(pix_length/(Object_texture->getSize().y)));			
				// unless we get really lucky, the size of the sprite needs to
				// be adjusted to match its size in the game universe.
				// This means multiplying the scale of the object so that
				// the new size of the sprite in pixels is equivalent to the
				// pix length
			}
			planet_sprite->setRotation(Theta);
			Planet_sprites.insert(Planet_sprites.end(), planet_sprite);
			// rotate the sprite to the appropriate angle supplied in the
			// constructor arguments and insert it into the vector of planet
			// sprites at the end. This means that the sprites go from larger
			// to smaller as we go along
			pix_length /= 10;
			// at the end of the loop, scale back the size by 10x, since each
			// consecutive image should be 10x smaller than the previous one
		}
	}
	float sprite_x = Object_texture->getSize().x;	
	//sprite_x *= planet_sprite->getScale().x;
	
	float sprite_y = Object_texture->getSize().y;  
	//sprite_y *= planet_sprite->getScale().y;	
	
	Planet_sprite.setOrigin((sprite_x/2), (sprite_y/2));
	Planet_sprite.setTexture(*Object_texture);
}	// once more, my code works and I dont know why ^^
// I need to ask Vaughan or someone about this
// odd that the relative location of the sprite origin stays the same relative
// to the sprites internal scale when scaled up...


void TPlanet::Frame(double dt, long double simtime)
{	// normal update call for the planet
	Theta += (Omega*dt);
	// update our rotation based on the planets normal spin
	for(std::vector<sf::Sprite*>::iterator it = Planet_sprites.begin(); it != Planet_sprites.end(); ++it)
	{	(*it)->setRotation(Theta);
	}
	// updates the sprites based on current orientation
	// might be better done by the draw call instead, more efficient
	Simulation_time = simtime;
	// and sync the internal clock to the in-universe time
}

VectorVictor::Vector2 TPlanet::Get_position(long double sim_time)
{	VectorVictor::Vector2 origin(0,0);
	// for the moment this is sufficient for testing. Eventually this should
	// just return the planets vector position member, after it is incremented
	// in the frame call
	return origin;
}


bool TPlanet::In_view(SFML_Window * window, int zoom_factor, long double simtime)
{	long double radius = this->Get_radius(0);
	return window->Intersection(this->Get_position(simtime), radius, 1);
	// 1 is a placeholder for the cam scale here
}

bool TPlanet::In_view(SFML_Window * window, long double cam_scale, long double simtime)
{	long double radius = this->Get_radius(0);
	return window->Intersection(this->Get_position(simtime), radius, 1);
}

void TPlanet::Draw_flag(SFML_Window * iwindow, int zoom_factor)
{	sf::Vector2f camera_offset = Get_window_coordinates(Get_position(Simulation_time), iwindow, zoom_factor);
	
	// looks like 1/10, 1/100, 1/1000, ... etc.	
	for(std::vector<sf::Sprite*>::iterator it = Planet_sprites.begin(); it != Planet_sprites.end(); ++it)
	{	(*it)->setPosition(camera_offset);
	}
	for(std::vector<sf::Sprite*>::iterator it = Planet_sprites.begin(); it != Planet_sprites.end(); ++it)
	{	(*it)->setRotation(Theta - iwindow->Aperture_rotation);
	}
	// eh, just easier to do it this way. I should probably change it
	// eventually so that it only positions the one that we need
	iwindow->window->draw(*(Planet_sprites.at(zoom_factor-1)));
	// pretty simple. Note the zoom - 1 offset to get the right location
	// inside the vector
}

void TPlanet::Draw_flag(SFML_Window * iwindow, long double cam_scale, long double sim_time)
{	long double pix_length = this->Get_radius(0) + Atmosphere_height;
	// aww damn, this isnt gonna work indefinitely
	
	// the atmosphere height... knew there was something off
	pix_length *= 2;
	// make it equivalent to our diameter instead of the radius
	pix_length *= 10;
	// and do the funky scale thing so the camera view is 10 pixels per meter
	long double scale_factor = pix_length/((Object_texture->getSize().y)*cam_scale);
	// adjust the scale factor to match
	Planet_sprite.setScale(sf::Vector2f(scale_factor,scale_factor));
	// rescale the axes of the texture to match pix_length in the y and the
	// appropriate scale for the x dimension
		
	// not sure why they both use y, but I think this was distorted when
	// it used x & y.
	// This area needs to be looked over again
	sf::Vector2f camera_offset = Get_window_coordinates(this->Get_position(sim_time), iwindow, cam_scale);
	// I just dont get it, this should work just fine
	// translation looks okay, but the thing goes nuts rotating twice over the
	// full 360 degrees 
	Planet_sprite.setPosition(camera_offset);
	Planet_sprite.setRotation(this->Theta - iwindow->Aperture_rotation);
	// that should work just fine and dandy
	iwindow->window->draw(Planet_sprite);
	// this looks sorta workable I suppose
}

sf::Color TPlanet::Get_atmosphere_mask(VectorVictor::Vector2 window_origin, long double sim_time)
{	VectorVictor::Vector2 offset(0,0);
	offset = this->Get_position(sim_time);
	window_origin -= offset;
	long double altitude = window_origin.Get_vector_magnitude();
	altitude -= this->Get_radius(0);
	// hackaround for the moment
	
	// use our altitude to get the proper value of the atmo mask
	if(altitude < (-100))
	{	// if the camera is really deep underground, just draw gray to show that
		// we're in rock
		return sf::Color(43,43,43,255);
		// the value of -100 here is just a guess, needs to be more specific
		// maybe using a passed parameter for this
		
		// but a hundred meters seems reasonable for now
		// soon we should not have any need to be underground anyways
	}
	else if(altitude == 0)
	{	return Surface_atmosphere_colour;
	}
	else if(altitude < Atmosphere_height)
	{	// we interpolate between the two colour end members depending on what
		// our value of altitude is
		float r, g, b, a;
		a = (float)altitude;
		a /= (float)Atmosphere_height;
		//a *= 255;
		r = Top_atmosphere_colour.r - Surface_atmosphere_colour.r;
		g = Top_atmosphere_colour.g - Surface_atmosphere_colour.g;
		b = Top_atmosphere_colour.b - Surface_atmosphere_colour.b;				
		// get the relative differences between the colour components of our
		// two end members. just ignore the cast thing, it should be all right
		
		r = (float)Surface_atmosphere_colour.r + (r*a);
		g = (float)Surface_atmosphere_colour.g + (g*a);	
		b = (float)Surface_atmosphere_colour.b + (b*a);
		// and interpolate the rgb between the two end members
		a = 1-a;
		// bahahaha, winnah, winnah
		a *= 255;
		// this works, but linear interpolation against altitude still doesnt
		// look quite right, it probably needs to scale with atmosphere density
		
		sf::Color atmosphere(r, g, b, a);
		return atmosphere;
		// this should work from here on out
	}
	else
	{	sf::Color transparent(255,255,255,0);
		// if we are above the atmosphere height, dont draw anything at all
		// cause we just wanna see them pretty stars
		return transparent;
	}
}

int TPlanet::Get_terrain_points()
{	long double density = this->Get_radius(0);
	// get the radius of the planet in meters
	density *= (2*Pi);
	// convert it to the circumference of the planet
	density /= 100;
	// make the density the number of 100m segments required to cover the planet
	// just 100m because it works here, but  in the future this will be more
	// complex with the size of the segments determined by how many points the
	// planets terrain has in total
	int point_number = (int)density;
	// and convert it to an integer. This will of course lose some precision,
	// but we can get the proper length of the segment later using vector maths
	// so there is no real issue with losing precision here
	
	// we just want a number of points for a segment length approximately 100m
	// long for each one
	return point_number;
	// and send it on its way
}

void TPlanet::Draw_surface(SFML_Window * iwindow)
{	// just yeah, dont look at this too hard just yet
}

TPlanet::~TPlanet()
{	delete Object_texture;
}


