//Kelly Honsinger
#include "cImageTextures.h"

/*
...................................................................
cImageTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer)

Purpose:Class contructor; Initialize the class' private data members.

Entry: SDL_Texture * tempTexture :initializes object texture.
 SDL_Renderer * tempRenderer :initializes object renderer.

Exit: None
...................................................................*/
cImageTextures::cImageTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer)
{
	imageTexture= tempTexture;
	imageRenderer = tempRenderer;
	imageRect = new SDL_Rect;
	imageRect -> x = 0;
	imageRect -> y = 0;
	imageRect -> w = RENDERWIDTH;
	imageRect -> h = RENDERHEIGHT;
}

/*
...................................................................
cImageTextures(cImageTextures & imgCpy)

Purpose:copy contructor; Initialize the class' private data members.

Entry: cImageTextures & imgCpy

Exit: None
...................................................................*/
cImageTextures::cImageTextures(cImageTextures & imgCpy)
{
	imageTexture = imgCpy.imageTexture;
	imageRenderer = imgCpy.imageRenderer;
	imageRect = imgCpy.imageRect;
}

/*
...................................................................
cImageTextures& operator=(cImageTextures& imgCPY)

Purpose:assignment operator; Initialize the class' private data members when equal sign is used.

Entry: cImageTextures& imgCPY; copy object to initialize to.

Exit: Invoking object
...................................................................*/
cImageTextures& cImageTextures::operator=(cImageTextures& imgCPY)
{
	imageTexture = imgCPY.imageTexture;
	imageRenderer = imgCPY.imageRenderer;
	imageRect = imgCPY.imageRect;

	return * this;
}

/*
...................................................................
~cImageTextures()

Purpose:destructor; Deletes all dynamically allocated memory and sets pointers to null.

Entry: None

Exit: none
...................................................................*/
cImageTextures::~cImageTextures()
{
	delete imageRect;
	imageRect = nullptr;
	SDL_DestroyTexture(imageTexture);
	imageTexture = nullptr;
	SDL_DestroyRenderer(imageRenderer);
	imageRenderer = nullptr;
}

/*
...................................................................
void Render()

Purpose:Method that takes the image texture and renderer and prints them to screen.

Entry: None

Exit: none
...................................................................*/
void cImageTextures::Render()
{
	SDL_Rect * tempRect = imageRect;
	for (int i = RENDERWIDTH; i > 0; i--)
	{
		(tempRect -> x) = i;
		SDL_RenderClear(imageRenderer);
		
		SDL_RenderCopy(imageRenderer, imageTexture, nullptr, tempRect);//SDL_RenderCopy(RENDERER, Texture your loading from, rectangle you're drawing from, rectangle you're drawing to)
		SDL_RenderPresent(imageRenderer);
		SDL_Delay(TIME);
	}
}

