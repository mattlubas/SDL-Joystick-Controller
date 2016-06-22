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

  //Initializes Joystick in SDL SDL_Init(SDL_INIT_JOYSTICK);

  // Open joystick 
  SDL_Joystick * Joy = SDL_JoystickOpen(0);

  //Main Loop
  while(1) {  
    
    SDL_Event event;
    
    // Found information based on: https://wiki.libsdl.org/SDL_Event
    switch (event.type)
	{
    	case SDL_JOYAXISMOTION:
            {        
            int yaw      = SDL_JoystickGetAxis (Joy,0);
            int throttle = SDL_JoystickGetAxis (Joy,1);
            int roll     = SDL_JoystickGetAxis (Joy,2);
            int pitch    = SDL_JoystickGetAxis (Joy,3);

            printf("Yaw: %d\t", yaw);
            printf("Throttle: %d\t", throttle);
            printf("Roll: %d\t", roll);
            printf("Pitch: %d\n", pitch);
            }
        case SDL_JOYBUTTONDOWN:  
            {
            // PS3 Controller part for Aux
            bool circle   = SDL_JoystickGetButton(Joy, 1);
            bool triangle = SDL_JoystickGetButton(Joy, 0);
            bool square   = SDL_JoystickGetButton(Joy, 3);

            printf("Cir: %d\t", circle);
            printf("Tri: %d\t", triangle);
            printf("Squ: %d\n", square);

            }
        /*
	    case SDL_JOYBUTTONDOWN:

	        printf("Button: %hhu\t",event.jbutton.button);
	        printf("State: %hhu\n",event.jbutton.state);
	   
	    case SDL_JOYBUTTONUP:

	        printf("Button: %hhu\t",event.jbutton.button);
	        printf("State: %hhu\n",event.jbutton.state); 
        */
    }

    //Sleep program for 0.1 Seconds
    usleep(100000);
 
    //Updates Controller
    //int SDL_JoystickEventState(SDL_ENABLE);

    while( SDL_PollEvent(&event ) )
    {
        
        // Quit on CTRL-C
        if (event.type == 256)
           return 0;
          
    }
  } 

  SDL_JoystickClose(Joy);
  SDL_Quit();
 
  return 0;
}
