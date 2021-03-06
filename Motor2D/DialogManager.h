#ifndef __DIALOG_MANAGER_H__
#define __DIALOG_MANAGER_H__


#include "PugiXml\src\pugixml.hpp"
#include <string>
#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1FileSystem.h"
#include "j1GameLayer.h"
#include "j1App.h"
#include "UI_String.h"

class Entity;
class Player;
class Enemy;
class UI_element;
class UI_String;
enum ENTITY_TYPE;
enum ENEMY_TYPE;

class TextLine
{
public:

	TextLine(int state, std::string text);
	~TextLine();

	int state;
	std::string* line = nullptr;
};

class Dialogue
{
public:

	Dialogue(int id);
	~Dialogue();

	uint id;
	std::vector<TextLine*> texts;
};

class DialogueManager : public j1Module
{
public:

	DialogueManager();
	~DialogueManager();
	bool Awake(pugi::xml_node& config);
	bool Start();
	bool PostUpdate();
	bool BlitDialog(uint id, uint state);

private:

	int dialogueStep = 0; //Allows to order the conversarion correctly

	std::vector<Dialogue*> dialog;

	/*-- Data to load XML --*/
	std::string folder;
	std::string path;
	pugi::xml_document dialogueDataFile;
	pugi::xml_node dialogueNode;
	/*-- END --*/

	/*--- UI elements to print dialogues on screen ---*/
	UI_element* screen = nullptr;
	UI_String* text_on_screen = nullptr;
	/*-- END --*/

	/*---CODE TO TEST IN-GAME RESULTS ---*/
	uint id = 1;
	uint NPCstate = 0;
	/*--- END ---*/
};

#endif