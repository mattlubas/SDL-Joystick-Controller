// By Matt Lubas and Simon Levy
//
//Marks the location of Axis and Aux buttons on different controllers
// using SDL.
//Sets variables of Axis and buttons depending on controller for Mac OS X.
//

/*
   PS3 Controller: 4 axes and 12 buttons
   Axis 0 = Yaw
   Axis 1 = Throttle
   Axis 2 = Roll
   Axis 4 = Pitch

   Button 0 = Triangle
   Button 1 = Circle
   Button 2 = X
   Button 3 = Square
*/

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

  //Initialization and Selection of controller
  //Shows the index of the joystick so that the joystick can be specialized.
  //
  //For Logitech: Logitech Extreme 3D
  //For PS3:
  //For Taranis:
  //For Spektrum:
  //
  printf("Name: %s\n", SDL_JoystickNameForIndex(0));
  
  if (strcmp( SDL_JoystickNameForIndex(0) , "Logitech Extreme 3D") == 0)
    printf("Works! \n ");
  
  else
    printf("Not Connected \n ");


  //Delay for 5 seconds
  usleep(5000000);

  



  //Main Loop
  while(1) {  
    // printf("Number of Axes: %d\n", SDL_JoystickNumAxes(Joy));
 
    SDL_Event event;
    
    // Found information based on: https://wiki.libsdl.org/SDL_Event
    switch (event.type)
	{
/*       
        case SDL_JOYAXISMOTION:
            printf("Axis: %d\t",event.jaxis.axis);
            printf("Value: %d\n",event.jaxis.value);
            

        case SDL_JOYBUTTONDOWN:
            printf("Button: %hhu\t", event.jbutton.button);
            printf("State: %hhu\n", event.jbutton.state);
*/   

    
    	case SDL_JOYAXISMOTION:
            {
            //Axes are for the PS3 Controller
            int Axis_0 = SDL_JoystickGetAxis (Joy,0);
            int Axis_1 = SDL_JoystickGetAxis (Joy,1);
            int Axis_2 = SDL_JoystickGetAxis (Joy,2);
            int Axis_3 = SDL_JoystickGetAxis (Joy,3);
            
            
            int Axis_4 = SDL_JoystickGetAxis (Joy,4);
            int Axis_5 = SDL_JoystickGetAxis (Joy,5);


            printf("Axis_0: %d\t", Axis_0);
            printf("Axis_1: %d\t", Axis_1);
            printf("Axis_2: %d\t", Axis_2);
            printf("Axis_3: %d\t", Axis_3); 
            
            printf("Axis_4: %d\t", Axis_4);
            printf("Axis_5: %d\n", Axis_5);
            
            }
/*
        case SDL_JOYBUTTONDOWN:  
            {
            // PS3 Controller part for Aux
            bool circle   = SDL_JoystickGetButton(Joy, 1);
            bool triangle = SDL_JoystickGetButton(Joy, 0);
            bool square   = SDL_JoystickGetButton(Joy, 3);
            bool x        = SDL_JoystickGetButton(Joy, 2);


            printf("Squ: %d\t", square); 
            printf("Tri: %d\t", triangle);
            printf("X:   %d\t", x);
            printf("Cir: %d\n", circle);
            }
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
