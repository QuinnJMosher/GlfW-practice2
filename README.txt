QuinnFramework

This is a C++ framework for making small 2D games with a working test program

This framework uses the libraries:
GLFW
GLEW
GLM
SOIL
tinyxml2

Use:
 To get to functions used handel the framework include the header"QuinnFramework.h"

 Before using the framework it must be initalized and a window must be opened:
  First call FrameworkInitalize()
  Then call OpenWindow(windowWidth, windowHeight, windowName)

 Your game loop should folow this basic pattern:
  Each frame call:
   FrameWorkUpdate() to check if the program should close and poll events
   -this function returns true if the program should close
   FrameworkClearScreen() to swap the buffers and clear now hidden screen
  
  When the program should exit, call:
   CallExit();
    -this will tell your program to exit the next iteration of the loop

  If you need to see the width and height of your screen use:
   GetWindowWidth();
  And
   GetWindowHeight();

 To draw a shape:

  Instanitate the Shape class:
   Shape shape = Shape(shapetype, positionX, positionY, width, height, color<not required>);
  Then call DrawShape(shape)

  shapes must be properly deleted to avoid memory leaks:
   DeleteShape(shape)
  
  To change a shape's color use:
   shape.SetColor(r, g, b, a);
   -the input of this function should be given float values between 0 and 1

  To change a shape's position use:
   shape.SetPos(x, y);
  You can get the current position values with:
   shape.GetX();
  And
   shape.GetY();

  To change a shape's width:
   shape.SetWidth(width);
  To get the current width:
   shape.GetWidth();

  To change a shape's height:
   shape.SetHeight(height);
  To get the current height:
   shape.GetHeight();

 To draw an image:

  Instantiate the shape class,
  Instantiate the texture class:
   Texture texture = Texture(filename);
  Then call DrawSprite(shape, texture)

  Textures should also be deleted properly:
   DeleteTexture(texture);

  Textures keep values that can be accesed freely:
   texture.width;
   texture.height;
   texture.bpp;

  UVs can be set directly in the Shape class:
   shape.SetUVStart(U, V);
   shape.SetUVLength(Ulength, VLength);
  To Get the current UV values:
   shape.GetUStart();
   shape.GetVStart();
   shape.GetULength();
   shape.GetVLength();

 To Use the animated sprite class:

  Instanitate the Animation class:
   Animation animation = Animation(spriteSheetName, positionX, positionY, Width, Height, numFramesWide, numFramesTall);
  Or
   Animation animation = Animation(Texture, shape, numFramesWide, numFramesTall;

  To change frame, use:
   animation.NextFrameX();
    -moves to the next frame on the right, loops when it reaches the edge.
   animation.NextFrameY();
    -moves down one frame, loops when it reaches the edge.
   animation.NextFrameAll();
    -moves to the next frame on the right and one frame down, loops when it reaches the edge.
   animation.SetFrame(frameX, frameY);
    -moves to the specified frame (starting at 1), does not compensate for OOB input.

  To draw the Animation use DrawAnimation(animation)

  To avoid memory leaks on deletion call:
   DeleteAnimation(animation);

 To draw text:
  call DrawString(text, positionX, positionY, color<not required>)
 
 To change the size of the drawn text:
  call SetFontSize(size);

 To chage the font used:
  call setFont(fontName);
   -this framework uses xml described bitmap fonts

 To read user input:
  
  To read from a keyboard:
   call GetKeyDown(key) to see if a key is pressed
   call GetKeyUp(key) to see if a key is not being pressed
    -keys are represented by capital lettered char values
    -Non letter keys use the standard specal key values from GLFW

  To read frome the mouse:
   Call GetMouseX() to find the mouse's X position
  And
   Call GetMouseY() to find the mouse's Y position
  Or
   Call GetMousePos(x, y)
    -the inputs of this function are read as refrences that will be set to the mouse's current position

  The mouse can be hidden and unhidden with:
   HideMouse();
  And
   ShowMouse();