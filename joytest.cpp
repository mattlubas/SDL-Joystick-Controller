#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



static void error(const char * msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1); // nonzero exit code = error
}


int main(int argc, char *argv[])
{ 

  //Quits if Joystick is not attached
  if (SDL_Init(SDL_INIT_JOYSTICK))
    error("Failed to initialize SDL");

  //Initializes Joystick in SDL
  SDL_Init(SDL_INIT_JOYSTICK);

  SDL_Joystick * Joy;

  SDL_JoystickOpen(0);



  int value_0, value_1, value_2, value_3 = 0;  

  //Main Loop
  while(1) {  
    
    

    SDL_Event event;
    
    SDL_JoyAxisEvent * jaxis;


    // Found information based on: https://wiki.libsdl.org/SDL_Event
    switch (event.type)
	{
	case SDL_JOYAXISMOTION:

	   printf("Axis:  %d\t",event.jaxis.axis);
	   printf("Value: %d\n",event.jaxis.value);
    	
 
	}



    /*
    // SDL_JoyAxisEvent(which,axis, value) Axis range from -32768 to 32767
    // SDL_JoyAxisEvent(value_0);
    // SDL_JoyAxisEvent(0,1,value_1);
    // SDL_JoyAxisEvent(0,2,value_2);
    // SDL_JoyAxisEvent(0,3,value_3);

    short axis_0 = value_0;
    int axis_1 = value_1;
    int axis_2 = value_2;
    int axis_3 = value_3;
    */

    // Sint16 axis_0, axis_1, axis_2, axis_3, axis_4;
    /*
    axis_0 = SDL_JoystickGetAxis(Joy,0);
    axis_1 = SDL_JoystickGetAxis(Joy,1);
    axis_2 = SDL_JoystickGetAxis(Joy,2);
    axis_3 = SDL_JoystickGetAxis(Joy,3);
    */
    /* 
    printf("Axis_0: %hd\t",axis_0);
    printf("Axis_1: %hd\t",axis_1);
    printf("Axis_2: %hd\t",axis_2);
    printf("Axis_3: %hd\n",axis_3);
    */


    //Sleep program for 0.1 Seconds
    usleep(100000);
 
    //Updates Controller
    int SDL_JoystickEventState(SDL_ENABLE);

    while( SDL_PollEvent(&event ) )
    {
      
        // Quit on CTRL-C
        if (event.type == 256)
           return 0;
          
        printf("%d\n", event.type);
    }
  } 
  SDL_JoystickClose(Joy);
  void SDL_Quit(void);
 
  return 0;
}
